/* --------------------------------------------------------------------  */
/*                          CALCULIX                                     */
/*                   - GRAPHICAL INTERFACE -                             */
/*                                                                       */
/*     A 3-dimensional pre- and post-processor for finite elements       */
/*              Copyright (C) 1996 Klaus Wittig                          */
/*                                                                       */
/*     This program is free software; you can redistribute it and/or     */
/*     modify it under the terms of the GNU General Public License as    */
/*     published by the Free Software Foundation; version 2 of           */
/*     the License.                                                      */
/*                                                                       */
/*     This program is distributed in the hope that it will be useful,   */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of    */ 
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the      */
/*     GNU General Public License for more details.                      */
/*                                                                       */
/*     You should have received a copy of the GNU General Public License */
/*     along with this program; if not, write to the Free Software       */
/*     Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.         */
/* --------------------------------------------------------------------  */

/* do do:  */
/* merge point, check all nurbs if that point is used  */

#include <cgx.h>
#define TEST 0


extern double     gtol;

extern Scale     scale[1];
extern Summen    anz[1];
extern Edges     *edge;
extern Nodes     *n_anim;

extern Nodes     *node;
extern Elements  *e_enqire;
extern Datasets *lcase;
extern Faces     *face;

extern Alias     *alias;
extern Sets      *set; 
extern Points    *point;
extern Lines     *line;
extern Lcmb      *lcmb;
extern Gsur      *surf;
extern Gbod      *body;
extern Nurbl     *nurbl;
extern Nurbs     *nurbs;
extern SumGeo    anzGeo[1];

extern char  printFlag;                     /* printf 1:on 0:off */



/* additional entities from setFunktions */




/*---------------------------------------------------------------------*/
/* returns a field with sum and indexes of the entities inside a space */
/* of a radius of tol around mrgnod                                    */
/* type:  'n' node, 'p' point                                          */
/* rsort: radius and index of the entity, sorted by the radius         */
/* indx:  index of the entity for which the close ones are searched    */
/* anz_n: number of entities (indx is a member of rsort )              */
/* gtol:  geometric tolerance for which the search is done             */
/*---------------------------------------------------------------------*/
int *findCloseEntity( char type, Nodes *node, Points *point, Rsort *rsort, int indx, int anz_n, double local_gtol)
{
  static int *nodes=NULL;
  int n,m,i, n_low, n_high;
  double rref, dx=0, dy=0, dz=0;

  /* find all nodes (nod_dr) which are in the intervall of rref-tol to rref+tol */
  if( (nodes=(int *)malloc((1)*sizeof(int) ) )==NULL) 
  { printf(" ERROR: malloc failure\n"); return(NULL); }
  nodes[0]=0;

  /* search the intersection on the lower bound */
  rref=rsort[indx].r-local_gtol;
  n_low=0;                              
  n=anz_n;                            
  do
  {                     
    m=(n+n_low)*.5;                      
    if(rref >= rsort[m].r ) n_low=m;              
    else n=m;              
  }while((n-n_low) != 1);

  /* search the intersection on the upper bound */
  rref=rsort[indx].r+local_gtol;
  n_high=0;                              
  n=anz_n;                            
  do
  {                     
    m=(n+n_high)*.5;                      
    if(rref >= rsort[m].r ) n_high=m;              
    else n=m;              
  }while((n-n_high) != 1);

#if TEST
  printf(" dn: %d n_low[%d]:%d n_high[%d]:%d\n", n_high-n_low, n_low,rsort[n_low].i, n_high,rsort[n_high].i); 
#endif

  /* check all nodes inbetween */
  for(i=n_low; i<=n_high; i++)
  {
    if((i!=indx)&&(rsort[i].i>-1))
    {
      /* is the entity relative to the master-entity in the tolerance-sphere? */
      if(type=='n')
      {
        dx=node[rsort[indx].i].nx-node[rsort[i].i].nx; if(dx>local_gtol) goto nexti; 
        dy=node[rsort[indx].i].ny-node[rsort[i].i].ny; if(dy>local_gtol) goto nexti;
        dz=node[rsort[indx].i].nz-node[rsort[i].i].nz; if(dz>local_gtol) goto nexti;
      }
      else if(type=='p')
      {
        dx=point[rsort[indx].i].px-point[rsort[i].i].px; if(dx>local_gtol) goto nexti;
        dy=point[rsort[indx].i].py-point[rsort[i].i].py; if(dy>local_gtol) goto nexti;
        dz=point[rsort[indx].i].pz-point[rsort[i].i].pz; if(dz>local_gtol) goto nexti;
      }
      if((dx*dx+dy*dy+dz*dz)<=local_gtol*local_gtol)
      {
        if( (nodes=(int *)realloc((int *)nodes, (nodes[0]+2)*sizeof(int) ) )==NULL) 
        { printf(" ERROR: realloc failure\n"); return(NULL); }
        nodes[0]++;
        nodes[nodes[0]]=i;
      }
#if TEST
      if(nodes[0])
      {
        printf(" entity:%d r:%lf \n", rsort[i].i, (dx*dx+dy*dy+dz*dz) ); 
      }
#endif
    }
    nexti:;
  }
  return(nodes);
}

/*------------------------------------------------------------------*/
/* merge node deletes that node if near one exists                */
/*------------------------------------------------------------------*/

int mergeNode( Rsort *rsort, int anz_n, int indx, double local_gtol, int lock )
{
  int i, j, k,n,l;
  int  ipuf, nod2, nod;
  int *nodes=NULL;

  nod=rsort[indx].i;
  if(( nod<1 )||( node[nod].pflag)) return(-1);

#if TEST
  printf("node:%d indx:%d anz_n:%d\n", nod, indx, anz_n); 
#endif

  nodes= findCloseEntity('n', node, 0, rsort, indx, anz_n, local_gtol/scale->w); 

  for (i=1; i<=nodes[0]; i++)
  {
    if (rsort[nodes[i]].i > 0)
    {
      nod2=rsort[nodes[i]].i;

      /* check if nod exists in related elements */
      for (j=0; j<anz->e; j++)
      { 
        if (e_enqire[e_enqire[j].nr].type == 1) ipuf = 8;  /* CHEXA8  */
        else if (e_enqire[e_enqire[j].nr].type == 2) ipuf = 6; /* PENTA6 */
        else if (e_enqire[e_enqire[j].nr].type == 3) ipuf = 4;  /* CTET4   */
        else if (e_enqire[e_enqire[j].nr].type == 4) ipuf = 20; /* CHEXA20 */
        else if (e_enqire[e_enqire[j].nr].type == 5) ipuf = 15; /* PENTA15 */
        else if (e_enqire[e_enqire[j].nr].type == 6) ipuf = 10; /* CTET10  */
        else if (e_enqire[e_enqire[j].nr].type == 7) ipuf = 3;  /* CTRI3   */
        else if (e_enqire[e_enqire[j].nr].type == 8) ipuf = 6;  /* CTRI6   */
        else if (e_enqire[e_enqire[j].nr].type == 9) ipuf = 4;  /* CQUAD4  */
        else if (e_enqire[e_enqire[j].nr].type == 10) ipuf = 8;  /* CQUAD8  */
        else if (e_enqire[e_enqire[j].nr].type == 11) ipuf = 2; /* CBEAM2   */
        else if (e_enqire[e_enqire[j].nr].type == 12) ipuf = 3; /* CBEAM3   */
        else ipuf=0;
        for (k=0; k<ipuf; k++)
        {
          if( e_enqire[e_enqire[j].nr].nod[k] == nod2 )
          {
            if (lock) for (l=0; l<ipuf; l++)
            {
              if( e_enqire[e_enqire[j].nr].nod[l] == nod )
              {
                printf(" node %d can not replace %d in element %d without collapsing it\n", nod, nod2, e_enqire[j].nr );
                goto nextNode;
              }
            }
            /* ersetze node */
            printf(" %d replace %d with %d in elem:%d type:%d\n", j, nod2, nod, e_enqire[j].nr, e_enqire[e_enqire[j].nr].type );
            /* change node in elems if that node is used  */
            e_enqire[e_enqire[j].nr].nod[k] =nod;
            
            /* delete all elements which are defined by unique nodes */
            if(!lock)
            {
              for(n=1; n<ipuf; n++) if(e_enqire[e_enqire[j].nr].nod[n]!=e_enqire[e_enqire[i].nr].nod[0]) break;
              if(n==ipuf)
              { delElem(1,&e_enqire[j].nr); j--; }

              /* if two nodes of a tr3 are unique */
              if (e_enqire[e_enqire[j].nr].type == 7) if((e_enqire[e_enqire[j].nr].nod[0]==e_enqire[e_enqire[j].nr].nod[1])||(e_enqire[e_enqire[j].nr].nod[0]==e_enqire[e_enqire[j].nr].nod[2])||(e_enqire[e_enqire[j].nr].nod[1]==e_enqire[e_enqire[j].nr].nod[2]))
              { delElem(1,&e_enqire[j].nr); j--; }
	    }
          }
        }
      }

      /* check if nod exists in related entities */
      for (j=0; j<anzGeo->p; j++) for (k=0; k<point[j].nn; k++) if( point[j].nod[k] == nod2 ) point[j].nod[k] =nod;
      for (j=0; j<anzGeo->l; j++) for (k=0; k<line[j].nn; k++) if( line[j].nod[k] == nod2 ) line[j].nod[k] =nod;
      for (j=0; j<anzGeo->s; j++) for (k=0; k<surf[j].nn; k++) if( surf[j].nod[k] == nod2 ) surf[j].nod[k] =nod;
      for (j=0; j<anzGeo->b; j++) for (k=0; k<body[j].nn; k++) if( body[j].nod[k] == nod2 ) body[j].nod[k] =nod;
      for(j=1; j<anz->sets; j++)
      {
        if(!set[j].type)
        {
          if((set[j].name!=(char *)NULL)&&( getIndex(&set[j].node,set[j].anz_n,nod2) >-1)) seta(j,"n",nod);
	}
      }

      /* check if nod exists in faces */
      /* -> not necessary because all faces will be destroyed and newly created after merge */
      /* 
      for (j=0; j<num_stype[0]; j++)
      { 
        if (face[j].type == 7) ipuf = 3;      
        else if (face[j].type == 8) ipuf = 6; 
        else if (face[j].type == 9) ipuf = 4; 
        else if (face[j].type == 10) ipuf = 10;
        else ipuf=0;
        for (k=0; k<ipuf; k++) if( face[j].nod[k] == nod2 ) face[j].nod[k] =nod;
      }
      */

      delNod( 1, &nod2 );
      rsort[nodes[i]].i=0;
    }
    nextNode:;
  }
  free(nodes);
  return(1);
}

/*------------------------------------------------------------------*/
/* merge elements                                                   */
/*------------------------------------------------------------------*/

/* wird von qsort aufgerufen, vergleicht die ersten drei Zahlen von Integer-Feldern */
typedef struct {
    int nr;
    int nod[20];
}Esort;

int compareNodesOfElems(Esort *a, Esort *b) 
{
  int i;

  /*
    printf("a:");
  for(i=19; i>=0; i--) printf(" %d", a[0].nod[i]);
    printf("\n");
    printf("b:");
  for(i=19; i>=0; i--) printf(" %d", b[0].nod[i]);
    printf("\n");
  */

  for(i=19; i>=0; i--)
  {
    if(a[0].nod[i]>b[0].nod[i]) { return(1); }
    if(a[0].nod[i]<b[0].nod[i]) { return(-1); }
  }
  return(0);
}

void mergeElem( int setNr )
{
  int i, j, indx, ipuf,n;
  int sum_delem=0, *delem=NULL;

  int sum_e=0;
  Esort *esort=NULL;

  /* sort all nodes of all elems in setNr */
  for (i=0; i<set[setNr].anz_e; i++)
  {
    indx=set[setNr].elem[i];
    if (e_enqire[indx].type == 1) ipuf = 8;  /* HEXA8 */
    else if (e_enqire[indx].type == 2) ipuf = 6;  /* PENTA6 */
    else if (e_enqire[indx].type == 3) ipuf = 4;  /* TET4 */
    else if (e_enqire[indx].type == 4) ipuf = 20; /* HEX20 */
    else if (e_enqire[indx].type == 5) ipuf = 15; /* PENTA15 */
    else if (e_enqire[indx].type == 6) ipuf = 10; /* TET10 */
    else if (e_enqire[indx].type == 7) ipuf = 3;  /* TRI3  */
    else if (e_enqire[indx].type == 8) ipuf = 6;  /* TRI6  */
    else if (e_enqire[indx].type == 9) ipuf = 4;  /* QUAD4 */
    else if (e_enqire[indx].type == 10) ipuf = 8; /* QUAD8 */
    else if (e_enqire[indx].type == 11) ipuf = 2; /* BEAM */
    else if (e_enqire[indx].type == 12) ipuf = 3; /* BEAM3 */
    else ipuf=0;

    if((esort=(Esort *)realloc((Esort *)esort, (sum_e+1)*sizeof(Esort)))==NULL)
    { printf("\nERROR: realloc failure in mergElem()\n\n"); return; }
    esort[i].nr=indx;
    for (n=0; n<ipuf; n++) esort[sum_e].nod[n]=e_enqire[indx].nod[n];
    for (; n<20; n++) esort[sum_e].nod[n]=0;

    /* 1st node has lowest number */
    qsort( &esort[sum_e].nod[0], 20, sizeof(int), (void *)compareInt );
    sum_e++;
  }
    
  /* sort all sorted elems */
  qsort( esort, sum_e, sizeof(Esort), (void *)compareNodesOfElems );

  /* delete all elems which are equal to the last elem */
  j=0; i=1; while(i<set[setNr].anz_e)
  {
    n=compareNodesOfElems(&esort[j],&esort[i]); 
    if(n==0)
    {
      if((delem=(int *)realloc((int *)delem, (sum_delem+1)*sizeof(int)))==NULL)
      { printf("\nERROR: realloc failure in mergElem()\n\n"); return; }
      delem[sum_delem]=esort[i].nr;
      sum_delem++;
    }
    else j=i;
    i++;
  };

  /* delete element */
  delElem( sum_delem, delem);
  printf("%d elems deleted\n", sum_delem);

  if(delem) free(delem);
  if(esort) free(esort);
  return;
}

/*------------------------------------------------------------------*/
/* merge point deletes all matching points                          */
/*------------------------------------------------------------------*/

int mergePnt( Rsort *rsort, int anz_p, int indx, double local_gtol, int lock )
{
  int i, j, k, n;
  int *pnts, pnt, pnt2;

  pnt=rsort[indx].i;
  if ( pnt<0 ) return(-1);
  if ( anz_p<2 ) return(-1);

#if TEST
  printf("  pnt[%d]:%s indx:%d anz_p:%d\n", pnt, point[pnt].name, indx, anz_p); 
#endif

  pnts= findCloseEntity('p', 0, point, rsort, indx, anz_p, local_gtol/scale->w);
  
  for (i=1; i<=pnts[0]; i++)
  {
    if (rsort[pnts[i]].i > -1)
    {
      pnt2=rsort[pnts[i]].i;

      /* check all lines and lcmbs if that point is used  */
      if(lock) for (j=0; j<anzGeo->l; j++)
      {
        if( line[j].name != (char *)NULL )
        {
          if (line[j].p1 == pnt2)
          {
            if (line[j].p2==pnt)
            {
              printf(" P1:%s not changed to %s, would be equal to P2:%s in line:%s\n",
                point[line[j].p1].name, point[pnt].name, point[line[j].p2].name, line[j].name);
              return(-1);
            }
          }
          if (line[j].p2 == pnt2)
          {
            if (line[j].p1==pnt)
            {
              printf(" P2:%s not changed to %s, would be equal to P1:%s in line:%s\n",
                point[line[j].p2].name, point[pnt].name, point[line[j].p1].name, line[j].name);
              return(-1);
            }
          }
          if (line[j].typ=='a')
	  {
            if ((line[j].p1 == pnt2)||(line[j].p2 == pnt2))
            {
              if (line[j].trk==pnt)
              {
                printf(" P:%s not changed to %s, would be equal to cp:%s in line:%s\n",
                  point[pnt2].name, point[pnt].name, point[line[j].trk].name, line[j].name);
                return(-1);
              }
            }
            if ((line[j].p1 == pnt)||(line[j].p2 == pnt))
            {
              if (line[j].trk==pnt2)
              {
                printf(" cp:%s not changed to %s, would be equal to P:%s in line:%s\n",
                   point[pnt2].name, point[pnt].name, point[pnt].name, line[j].name);
                return(-1);
              }
            }
          }
        }
      }

      if(lock) for (j=0; j<anzGeo->c; j++)
      {
        if( lcmb[j].name != (char *)NULL )
        {
          if (lcmb[j].p1 == pnt2)
          {
            if (lcmb[j].p2==pnt)
            {
              printf(" P1:%s not changed to %s, would be equal to P2:%s in lcmb:%s\n",
                point[lcmb[j].p1].name, point[pnt].name, point[lcmb[j].p2].name, lcmb[j].name);
              return(-1);
            }
          }
          if (lcmb[j].p2 == pnt2)
          {
            if (lcmb[j].p1==pnt)
            {
              printf(" P2:%s not changed to %s, would be equal to P1:%s in lcmb:%s\n",
                point[lcmb[j].p2].name, point[pnt].name, point[lcmb[j].p1].name, lcmb[j].name);
              return(-1);
            }
          }
        }
      }


      /* loesche point */
      printf(" replace %s with %s\n", point[pnt2].name, point[pnt].name );

      /* change point in  lines if that point is used  */
      for (j=0; j<anzGeo->l; j++)
      {
        if( line[j].name != (char *)NULL)
        {
          if (line[j].p1 == pnt2) line[j].p1=pnt;
          if (line[j].p2 == pnt2) line[j].p2=pnt;
          if ((line[j].trk == pnt2)&&(line[j].typ == 'a')) line[j].trk=pnt;
        }
      }
      /* change point in  lcmbs if that point is used  */
      for (j=0; j<anzGeo->c; j++)
      {
        if( lcmb[j].name != (char *)NULL)
        {
          if (lcmb[j].p1 == pnt2) lcmb[j].p1=pnt;
          if (lcmb[j].p2 == pnt2) lcmb[j].p2=pnt;
        }
      }
      /* change point in nurbs lines if that point is used  */
      for (j=0; j<anzGeo->nurl; j++)
      {
        if( nurbl[j].name != (char *)NULL)
        {
          for (n=0; n<nurbl[j].u_npnt; n++)
            if ( nurbl[j].ctlpnt[n]== pnt2) nurbl[j].ctlpnt[n]=pnt; 
        }
      }
      /* change point in nurbs-surfs if that point is used  */
      for (j=0; j<anzGeo->nurs; j++)
      {
        if( nurbs[j].name != (char *)NULL)
        {
          for (n=0; n<nurbs[j].u_npnt; n++)
            for (k=0; k<nurbs[j].v_npnt; k++)
              if ( nurbs[j].ctlpnt[n][k]== pnt2) nurbs[j].ctlpnt[n][k]=pnt; 
        }
      }
      /* add point in set if pnt2 is a member and if it is a spline-set */
      for (j=0; j<anz->sets; j++)
      {
        /* warning: for sorted sets use ifind and seta if necessary */
        if(( set[j].name != (char *)NULL)&&( set[j].type==1))
        {
          for (k=0; k<set[j].anz_p; k++)
          { 
            if (set[j].pnt[k] == pnt2)
            {
              /* point to delete is a member of this set */
              /* check if the replace point is already a member */
              /* if not replace the point index by the replace point */
              for (n=0; n<set[j].anz_p; n++)
              {
                if( set[j].pnt[n] == pnt ) goto nextset;
              }
              set[j].pnt[k]=pnt; goto nextset;
            }
          }
        }
        nextset:;
      }
      delPnt( 1, &pnt2 ); rsort[pnts[i]].i=-1;
    }
  }
  return(1);
}

/*------------------------------------------------------------------*/
/* merge line deletes all matching lines                           */
/*------------------------------------------------------------------*/

int mergeLine( int indx, int lock)
{
  int i, j, k, l, delflag, equalFlag;

  if( line[indx].name == (char *)NULL ) return(-1);

  /* check if a line has the same end-points */

  delflag=1;
  for (i=0; i<anzGeo->l; i++)
  {
   if(( line[i].name != (char *)NULL ) && (i!=indx))
   {
    /* is the line principaly deletable? */

    if (line[indx].typ == line[i].typ)
    if ( ((line[indx].p1 == line[i].p1)&&(line[indx].p2 == line[i].p2)) ||
         ((line[indx].p1 == line[i].p2)&&(line[indx].p2 == line[i].p1)) )
    {
      equalFlag=0;
      if(line[indx].trk != line[i].trk)
      {
        /* check if the trks are identicaly formulatet */
        if ((line[indx].typ=='s')&&(line[i].typ=='s'))
        {
          if(set[line[indx].trk].anz_p==set[line[i].trk].anz_p)
          {
            equalFlag=1;
            /* check forward */
            for(j=0; j<set[line[indx].trk].anz_p; j++)
            {   if(set[line[indx].trk].pnt[j]!=set[line[i].trk].pnt[j]) equalFlag=0; }
            /* check backward */
            if(!equalFlag)
            {
              equalFlag=1;
              for(j=0; j<set[line[indx].trk].anz_p; j++)
              {   if(set[line[indx].trk].pnt[j]!=set[line[i].trk].pnt[set[line[indx].trk].anz_p-1-j]) equalFlag=0; }
            }
          }
        }
      }
      if(((line[indx].trk == line[i].trk)||(equalFlag))||(!lock))
      {
       /* check lcmbs for the line[indx]  */
       for (j=0; j<anzGeo->c; j++)
       {
        for (k=0; k<lcmb[j].nl; k++)
        {
          if ((lcmb[j].l[k] == indx)&&( lcmb[j].name != (char *)NULL))
          {
            /* check if the line i would appear twice  */
            for (l=0; l<lcmb[j].nl; l++) 
              if (lcmb[j].l[l]==i)
              {
                errMsg (" can not merge %s, the line would appear twice in lcmb %d\n",
			line[indx].name, lcmb[j].l[l]); 
                delflag=0;
              }
          }
        }
       }
      }
      else { printf(" can not merge line:%s with line:%s. they use different tracks\n",line[indx].name,line[i].name); delflag=0; } 

  goto let_surfs_collapse;
      /* check surfs for line[indx] and line[i] */
      for (j=0; j<anzGeo->s; j++)
      {
        for (k=0; k<surf[j].nl; k++)
        {
          if ((surf[j].l[k] == indx)&&(surf[j].typ[k]=='l')&&( surf[j].name != (char *)NULL))
          {
            /* check if the line i would appear twice  */
            for (l=0; l<surf[j].nl; l++) 
            {
              if ((surf[j].typ[l]=='l')&&(surf[j].l[l]==i))
              {
                /* a surface would collapse, save the surface */
                delflag=0;
              }
            }
          }
        }
      }
  let_surfs_collapse:;

      /* delete the "i" line */
      if (delflag)
      {
        printf(" %s replace with %s\n", line[i].name, line[indx].name );
        /* check for equal oriented lines  */
        if ((line[indx].p1 == line[i].p1)&&(line[indx].p2 == line[i].p2))
        {
          /* check lcmbs for the line[i]  */
          for (j=0; j<anzGeo->c; j++)
          {
            for (k=0; k<lcmb[j].nl; k++)
            {
              if (lcmb[j].l[k] == i) lcmb[j].l[k]=indx;
            }
          }
          /* check surfs for the line[i]  */
          for (j=0; j<anzGeo->s; j++)
          {
            for (k=0; k<surf[j].nl; k++)
            {
              if ((surf[j].l[k] == i)&&(surf[j].typ[k]=='l')) surf[j].l[k]=indx;
            }
          }
        }
        /* line is reverse oriented */
        else
        {
          /* check lcmbs for the line[i]  */
          for (j=0; j<anzGeo->c; j++)
          {
            for (k=0; k<lcmb[j].nl; k++)
            {
              if (lcmb[j].l[k] == i)
              {
                lcmb[j].l[k]=indx;
                if(lcmb[j].o[k]=='+') lcmb[j].o[k]='-';
                else                 lcmb[j].o[k]='+';
              }
            }
          }
          /* check surfs for the line[i]  */
          for (j=0; j<anzGeo->s; j++)
          {
            for (k=0; k<surf[j].nl; k++)
            {
              if ((surf[j].l[k] == i)&&(surf[j].typ[k]=='l'))
              {
                surf[j].l[k]=indx;
                if(surf[j].o[k]=='+') surf[j].o[k]='-';
                else                 surf[j].o[k]='+';
              }
            }
          }
        }
        delLine( 1, &i );
      }
    }
   }
  }
  return(0);
}


/*------------------------------------------------------------------*/
/* merge lcmb deletes all matching lcmbs                            */
/*------------------------------------------------------------------*/

int mergeLcmb( int indx )
{
  int i, j, k, l;

  if( lcmb[indx].name == (char *)NULL) return(-1);

  /* check if a lcmb has the same composition */

  for (i=0; i<anzGeo->c; i++)
  {
    if(( lcmb[i].name != (char *)NULL) && (i!=indx) )
    {
      /* is the lcmb principaly deletable?  */

      if( ((lcmb[indx].p1 == lcmb[i].p1)&&(lcmb[indx].p2 == lcmb[i].p2)) ||
         ((lcmb[indx].p1 == lcmb[i].p2)&&(lcmb[indx].p2 == lcmb[i].p1)) )
      {
        /* check surfs for the lcmb[i] and lcmb[indx] */
        for (j=0; j<anzGeo->s; j++)
        {
          for (k=0; k<surf[j].nl; k++)
          {
            if ((surf[j].l[k] == indx)&&(surf[j].typ[k]=='c')&&( surf[j].name != (char *)NULL))
            {
              /* check if the lcmb indx would appear twice in a surf */
              for (l=0; l<surf[j].nl; l++)
                if ((surf[j].typ[l]=='c')&&(surf[j].l[l]==i))
                {
                  /* a surface would colapse, delete the surface */
                  delSurf( 1, &j );
                }
            }
          }
        }

        /* loesche lcmb */
        printf(" %s replace with %s\n", lcmb[i].name, lcmb[indx].name );

        /* check surfs for the lcmb[i]  */
        for (j=0; j<anzGeo->s; j++)
        {
          for (k=0; k<surf[j].nl; k++)
          {
            if ((surf[j].l[k] == i)&&(surf[j].typ[k]=='c'))
            {
              if((lcmb[indx].p1 == lcmb[i].p1)&&(lcmb[indx].p2 == lcmb[i].p2)) 
              {
                surf[j].l[k]=indx; 
              }
              /* lcmb is reverse oriented */
              else
              {
                surf[j].l[k]=indx;
                if(surf[j].o[k]=='+') surf[j].o[k]='-';
                else                 surf[j].o[k]='+';
              }
            }
          }
        }
        delLcmb( 1, &i );
        return(i);
      }
    }
  }
  return(-1);
}


/*------------------------------------------------------------------*/
/* merge surface                                                    */
/*------------------------------------------------------------------*/

int mergeSurf( int indx, double local_gtol )
{
  int i, j, k, n, l, rev;
  static int *found=NULL;
  double r_indx, r_i;

  if( surf[indx].name == (char *)NULL) return(-1);

  if ( (found = (int *)realloc( (int *)found,(surf[indx].nl+1) * sizeof(int))) == NULL )
  { printf("\n\n ERROR: realloc failed in mergeSurf()\n"); return(-1); }

  /* check if a surf has the same composition */

  for (i=0; i<anzGeo->s; i++)
  {
    /* is the surf principaly deletable?  */

    if( surf[i].name == (char *)NULL) goto nextsi;
    if( i==indx ) goto nextsi; 
    if (surf[indx].nl!=surf[i].nl) goto nextsi;
 
    /* calculate the distance between the surfaces */
    r_indx=sqrt(surf[indx].cx*surf[indx].cx+surf[indx].cy*surf[indx].cy+surf[indx].cz*surf[indx].cz);
    r_i   =sqrt(surf[i].cx*surf[i].cx+surf[i].cy*surf[i].cy+surf[i].cz*surf[i].cz);
    if ( abs(r_indx-r_i)> local_gtol) goto nextsi;

    /* compare the embedded indexes and types */
    for (j=0; j<surf[indx].nl; j++)
    {
      found[j]=-1;
      for (k=0; k<surf[i].nl; k++)
      {
        if( (surf[indx].l[j] == surf[i].l[k])&&(surf[indx].typ[j] == surf[i].typ[k]) ) found[j]=k;
      }
      if (found[j]==-1) goto nextsi;
    }

    /* the surf can be merged */
    /* check bodys for the surf[indx] and surf[i]  */
    for (j=0; j<anzGeo->b; j++)
    {
      for (k=0; k<body[j].ns; k++)
      {
        if ((body[j].s[k] == indx)&&( body[j].name != (char *)NULL ))
        {
           /* check if the surf indx would appear twice in a body */
           for (l=0; l<body[j].ns; l++)
             if (body[j].s[l]==i)
             {
                /* a body would colapse, delete the body */
                delBody( 1, &j );
             }
        }
      }
    }

    /* loesche surf */
    printf(" %s replace with %s\n", surf[i].name, surf[indx].name );

    /* check bodys for the surf[i]  */
    for (j=0; j<anzGeo->b; j++)
    {
      for (k=0; k<body[j].ns; k++)
      {
        if (body[j].s[k] == i)
        {
          /* check the orientation of the entities in surf to replace */
          rev=0;
          for (n=0; n<surf[i].nl; n++)
          {
            if(surf[indx].o[n] != surf[i].o[found[n]]) rev=1;
          }
	  if (!rev) /* the entities of surf i are oriented as in indx */
          {
            /* check the orientation of the surf to replace */
            if (surf[indx].ori!=surf[i].ori) 
	    {
	      if (body[j].o[k]=='+') body[j].o[k]='-';
	      else body[j].o[k]='+';
	    }
            body[j].s[k]=indx;
          }
	  if (rev) /* the entities of surf i are reverse oriented as in indx */
          {
            /* check the orientation of the surf to replace */
            if (surf[indx].ori==surf[i].ori) 
	    {
	      if (body[j].o[k]=='+') body[j].o[k]='-';
	      else body[j].o[k]='+';
	    }
            body[j].s[k]=indx;
          }
        }
      }
    }
    delSurf( 1, &i );
    return(i);
    
 nextsi:;    
  }
  return(-1);
}


/*------------------------------------------------------------------*/
/* merge body                                                      */
/*------------------------------------------------------------------*/

/*------------------------------------------------------------------*/
/* merge Nurbs surface                                             */
/*------------------------------------------------------------------*/



void pre_merge( char *record )
{
  int i,j,k,l,s;
  int *indx=NULL;
  int  sum, lock=1;
  int  length, setNr;
  char type[MAX_LINE_LENGTH], buffer[MAX_LINE_LENGTH], setname[MAX_LINE_LENGTH], alock[MAX_LINE_LENGTH];
  double local_gtol; 
  Rsort *rsort=NULL;

  alock[0]=' ';
  length= sscanf( record, "%s%s%s%s", type, setname, buffer, alock);

  if (length<2) return;

  operateAlias( setname, "se" );
  setNr=getSetNr(setname);
  if (setNr<0)
  {
    printf (" merge: set:%s does not exist\n", setname);
    return;
  }

  local_gtol=gtol;
  if (length==3)
  {
    if(type[0]=='l')
    { if ((buffer[0]=='n')||(buffer[0]=='N')) lock=0; }
    else local_gtol=atof(buffer);
  }
  if (length==4)
  {
    local_gtol=atof(buffer);
    if ((alock[0]=='n')||(alock[0]=='N')) lock=0;
  }

  j=-1;
  if (( type[0]=='n' )||( type[0]=='N' ))
  {
    /* calculate all absolute r of all nodes and sort the indexes according to r */ 
    if ( (rsort = (Rsort *)malloc( (set[setNr].anz_n+1) * sizeof(Rsort))) == NULL )
      printf("ERROR: realloc failed: Rsort\n\n" ); 
    for( i=0; i<set[setNr].anz_n; i++) 
    { 
      rsort[i].r=sqrt(node[set[setNr].node[i]].nx*node[set[setNr].node[i]].nx+node[set[setNr].node[i]].ny*node[set[setNr].node[i]].ny+node[set[setNr].node[i]].nz*node[set[setNr].node[i]].nz);
      rsort[i].i=set[setNr].node[i];
    }
    printf("please wait\n");
    qsort( rsort, set[setNr].anz_n, sizeof(Rsort), (void *)compareRsort );
#if TEST
    for (i=0; i<set[setNr].anz_n; i++)
      printf("%d n:%d r:%lf\n", i, rsort[i].i, rsort[i].r); 
#endif

    k=set[setNr].anz_n;
    for(i=0; i<k; i++)
    {
      j = mergeNode( rsort, k, i, local_gtol, lock );
    }
    free(rsort);

    /* das neue netz muss noch zur beleuchteten ansicht aufbereitet werden  */
    anz->olc       = anz->l;
    makeSurfaces();
    allocUtilityData();
    updateDispLists();
  }
  else if (( type[0]=='p' )||( type[0]=='P' ))
  {
    /* calculate all absolute r of all points and sort the indexes according to r */ 
    if ( (rsort = (Rsort *)malloc( (set[setNr].anz_p+1) * sizeof(Rsort))) == NULL )
      printf("ERROR: realloc failed: Rsort\n\n" ); 
    k=0;
    for( i=0; i<set[setNr].anz_p; i++) 
    {
      rsort[k].r=sqrt(point[set[setNr].pnt[i]].px*point[set[setNr].pnt[i]].px+point[set[setNr].pnt[i]].py*point[set[setNr].pnt[i]].py+point[set[setNr].pnt[i]].pz*point[set[setNr].pnt[i]].pz);
      rsort[k].i=set[setNr].pnt[i];
      k++;
    }
    printf("please wait\n");
    qsort( rsort, k, sizeof(Rsort), (void *)compareRsort );
#if TEST
    for (i=0; i<k; i++)
      printf("%d p:%d point:%s r:%lf\n", i, rsort[i].i, point[rsort[i].i].name, rsort[i].r);
#endif

    for(i=0; i<k; i++)
    {
      j = mergePnt( rsort,k, i, local_gtol, lock );
    }
    free(rsort);

    /* recalculate the line-shapes */
    for (i=0; i<anzGeo->l; i++) repLine(i); 
    /* for (i=0; i<anzGeo->s; i++) repSurf(i);  */
  }
  else if (( type[0]=='e' )||( type[0]=='E' ))
  {
    mergeElem(setNr);
  }
  else if (( type[0]=='l' )||( type[0]=='L' ))
  {
    if((indx=(int *)malloc((set[setNr].anz_l+1)*sizeof(int)))==NULL)
    { errMsg("\nERROR: malloc failure in merge\n");
    return; }
    for (i=0; i<set[setNr].anz_l; i++)
    {
      indx[i]=set[setNr].line[i];
    }
    sum=i;
    for (i=0; i<sum; i++)
    {
      if (indx[i]==-1)
      {
        errMsg("ERROR: line is undefined, check program-code\n" );
      }
      else
      {
        mergeLine( indx[i], lock );
      }
    }
  }
  else if (( type[0]=='s' )||( type[0]=='S' ))
  {
    /* cyrcle through all surfs and add all lcmbs */
    for (i=0; i<set[setNr].anz_s; i++)
    {
      s= set[setNr].surf[i];
      for (j=0; j<surf[s].nl; j++)
      {
        l=surf[s].l[j];
        if (surf[s].typ[j]=='c')
        {
          seta( setNr, "c", l );
        }
      }
    }
    if((indx=(int *)malloc((set[setNr].anz_c+1)*sizeof(int)))==NULL)
    { errMsg("\nERROR: malloc failure in merge\n");
    return; }
    for (i=0; i<set[setNr].anz_c; i++)
    {
      indx[i]=set[setNr].lcmb[i];
    }
    sum=i;
    for (i=0; i<sum; i++)
    {
      if (indx[i]==-1)
      {
        errMsg("ERROR: lcmb is undefined, check program-code\n" );
      }
      else
      {
        j = mergeLcmb( indx[i] );
      }
    }
    free(indx);
    if((indx=(int *)malloc((set[setNr].anz_s+1)*sizeof(int)))==NULL)
    { errMsg("\nERROR: malloc failure in merge\n");
    return; }
    for (i=0; i<set[setNr].anz_s; i++)
    {
      indx[i]=set[setNr].surf[i];
    }
    sum=i;
    for (i=0; i<sum; i++)
    {
      if (indx[i]==-1)
      {
        errMsg("ERROR: surf is undefined, check program-code\n" );
      }
      else
      {
        j = mergeSurf( indx[i], local_gtol );
      }
    }
  }
  else
  {
    printf (" entity:%c not known\n", type[0]);
    return;
  }
  if (indx!=NULL) free(indx); indx=NULL;
  printf("ready\n");
}


