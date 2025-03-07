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

#include <cgx.h>

#define HORIZONTAL_STRESS 0    /* 1: calculate xx+yy stress */ 

extern Faces *face;

/* Display-lists */
extern GLuint list_anim_light, list_anim_model_edges, list_anim_surf_edges, list_anim_elem_edges;
extern GLuint *list_animate, *list_animate_model_edges, *list_animate_surf_edges, *list_animate_elem_edges;
extern Scale     scale[1];
extern char datin[MAX_LINE_LENGTH];
extern int   cur_lc, cur_entity;
extern int   basCol[3];       /* color indexes due to basic colormap: 0=black 1=white 2=sliver (grey) */
extern GLfloat   edgeWidth;             /* width of the model edges, changed with 'view' */

/* the copied node-sets which have to be filled with values from new loaded Datasets */
extern CopiedNodeSets copiedNodeSets[1];

int scalFlag=0;

void descalNodes ( int anz_n, Nodes *node, Scale *scale )
{
  int  j;

  //printf(" descale nodes\n");
  if(scalFlag)
  {
   scalFlag=0;
   for (j=0; j<anz_n; j++ )
   {
    node[node[j].nr].nx = (node[node[j].nr].nx* scale->w+scale->x);
    node[node[j].nr].ny = (node[node[j].nr].ny* scale->w+scale->y);
    node[node[j].nr].nz = (node[node[j].nr].nz* scale->w+scale->z);
   }
  }
  //else{ printf("WARNING: try to descale already descaled data\n"); }
}


/* nodes scalieren wg. zb. beleuchtung!  */
void scalNodes ( int anz_n, Nodes *node, Scale *scale )
{
  int  j;

  //printf(" scale nodes\n");
  if(!scalFlag)
  {
   scalFlag=1;
   for (j=0; j<anz_n; j++ )
   {
    node[node[j].nr].nx = (node[node[j].nr].nx-scale->x)/scale->w;
    node[node[j].nr].ny = (node[node[j].nr].ny-scale->y)/scale->w;
    node[node[j].nr].nz = (node[node[j].nr].nz-scale->z)/scale->w;
   }
  }
  //else{ printf("WARNING: try to scale already scaled data\n"); }
}



void calcDatasets( int lc, Summen *anz, Nodes *node, Datasets *lcase )
{
  register int   i, j, l, n;
  int    comp, lcp, layers=0, system=0;
  int stressFlag=-1;
  double s[6], p[3], y[3], alfap[3][3];
  double octaStress, vMises, dx,dy,dz, max_val=0., max_alfa=0., disp, alfa, dalfa, dalfa_grd=10., pi180;
  double vMises_stresstostrain=2./3.;
  char buffer[MAX_LINE_LENGTH];

  pi180=PI/180.;

  /* in case stress-phases for shells are to be regarded its necessary how much layers exist. All STRESP must show up first */
  if(( compare( lcase[lc].name, "STRESP", 6) == 6)&&(strlen(lcase[lc].name)==8)) layers=atoi(&lcase[lc].name[6])+1;

  if( (compare( lcase[lc].name, "STRESS", 6) == 6)||(compare( lcase[lc].name, "PSTRESS", 6) == 6)||( compare( lcase[lc].name, "ZZS", 3) == 3)) stressFlag=1;

  if( (compare( lcase[lc].name, "STRAIN", 6) == 6)||( compare( lcase[lc].name, "TOSTRAIN", 6) == 6)||( compare( lcase[lc].name, "MESTRAIN", 6) == 6)||( compare( lcase[lc].name, "ELSTRAIN", 6) == 6)||( compare( lcase[lc].name, "PLSTRAIN", 6) == 6)||( compare( lcase[lc].name, "CRSTRAIN", 6) == 6)||( compare( lcase[lc].name, "LE", 2) == 2)) stressFlag=0;

    // if( lcase[lc].ictype[0] == 4) /* check first comp if its a tensor (STRESS) */
  if(stressFlag!=-1)
  {
    /* check if the STRESS has six valid components */
    if(lcase[lc].ncomps < 6 ) goto jumpStresses;
    if((lcase[lc].ictype[0] != 4 )&&(lcase[lc].ictype[0] != 14 )) goto jumpStresses;
    n=0; while(((lcase[lc].compName[0][n]!='X')&&(lcase[lc].compName[0][n]!='R')&&(lcase[lc].compName[0][n]!='Z'))&&(n<6)) n++;
    if((compare(&lcase[lc].compName[0][n], "XX",2)==2)&&(compare(&lcase[lc].compName[1][n], "YY",2)==2)&&(compare(&lcase[lc].compName[2][n], "ZZ",2)==2)&&   
       (compare(&lcase[lc].compName[3][n], "XY",2)==2)&&(compare(&lcase[lc].compName[4][n], "YZ",2)==2)&&(compare(&lcase[lc].compName[5][n], "ZX",2)==2)) system=1;  
    else if((compare(&lcase[lc].compName[0][n], "XX",2)==2)&&(compare(&lcase[lc].compName[1][n], "YY",2)==2)&&(compare(&lcase[lc].compName[2][n], "ZZ",2)==2)&&   
       (compare(&lcase[lc].compName[3][n], "YX",2)==2)&&(compare(&lcase[lc].compName[4][n], "ZY",2)==2)&&(compare(&lcase[lc].compName[5][n], "XZ",2)==2)) system=1;  
    else if((compare(&lcase[lc].compName[0][n], "RR",2)==2)&&(compare(&lcase[lc].compName[1][n], "ZZ",2)==2)&&(compare(&lcase[lc].compName[2][n], "TT",2)==2)&&   
       (compare(&lcase[lc].compName[3][n], "RZ",2)==2)&&(compare(&lcase[lc].compName[4][n], "ZT",2)==2)&&(compare(&lcase[lc].compName[5][n], "TR",2)==2)) system=2;  
    else if((compare(&lcase[lc].compName[0][n], "RR",2)==2)&&(compare(&lcase[lc].compName[1][n], "ZZ",2)==2)&&(compare(&lcase[lc].compName[2][n], "TT",2)==2)&&   
       (compare(&lcase[lc].compName[3][n], "ZR",2)==2)&&(compare(&lcase[lc].compName[4][n], "TZ",2)==2)&&(compare(&lcase[lc].compName[5][n], "RT",2)==2)) system=2;  
    else if((compare(&lcase[lc].compName[0][n], "ZZ",2)==2)&&(compare(&lcase[lc].compName[1][n], "RR",2)==2)&&(compare(&lcase[lc].compName[2][n], "TT",2)==2)&&   
       (compare(&lcase[lc].compName[3][n], "ZR",2)==2)&&(compare(&lcase[lc].compName[4][n], "RT",2)==2)&&(compare(&lcase[lc].compName[5][n], "TZ",2)==2)) system=3;  
    else { goto jumpStresses; }

    if(system==2) printf("assume abaqus results in a cylindrical system\n");
    if(system==3) printf("assume marc results in a cylindrical system\n");

    /* special feature for abaqus, calc MESTRAIN from ELSTRAIN and IESTRAIN */
    /*
    if((lc>0)&&( compare( lcase[lc].name, "IESTRAIN",6) == 6)&&( compare( lcase[lc-1].name, "ELSTRAIN", 6) == 6))
    {
      printf(" WARNING: Foind IESTRAIN and ELSTRAIN. IESTRAIN will be replaced by MESTRAIN=IESTRAIN+ELSTRAIN\n");
      strcpy(lcase[lc].name,"MESTRAIN");
      if(!lcase[lc-1].loaded)
      {
        if( pre_readfrdblock(copiedNodeSets , lc-1, anz, node, lcase )==-1) 
        {
          printf(" ERROR in nodalDataset: Could not read data for Dataset:%d\n", lc); 
          return;
        }
        calcDatasets( lc-1, anz, node, lcase );
        recompileEntitiesInMenu(lc-1);
      }
      for(i=0; i<anz->n; i++)
      {
        lcase[lc].dat[0][node[i].nr]+=lcase[lc-1].dat[0][node[i].nr];
        lcase[lc].dat[1][node[i].nr]+=lcase[lc-1].dat[1][node[i].nr];
        lcase[lc].dat[2][node[i].nr]+=lcase[lc-1].dat[2][node[i].nr];
        lcase[lc].dat[3][node[i].nr]+=lcase[lc-1].dat[3][node[i].nr];
        lcase[lc].dat[4][node[i].nr]+=lcase[lc-1].dat[4][node[i].nr];
        lcase[lc].dat[5][node[i].nr]+=lcase[lc-1].dat[5][node[i].nr];
      }
      recompileEntitiesInMenu(lc);
      createDatasetEntries();
    }
    */

    /* check if related stress-phase-angles are available. */
    lcp=0;
    sprintf(buffer, "STRESP%c%c", lcase[lc].name[6], lcase[lc].name[7]);
    if((lc>=layers)&&( compare( lcase[lc-layers].name, buffer, strlen(buffer)) == strlen(buffer))&&(lcase[lc-layers].value==lcase[lc].value)) lcp=-layers;

    if(lcp!=0) printf("calculate additional values for %s regarding %s\n", lcase[lc].name, lcase[lc+lcp].name);

    /* overwrite the derivatives (iexist[]!=0) */
    comp=lcase[lc].ncomps;
    while(lcase[lc].iexist[comp-1]!=0) comp--;
    lcase[lc].ncomps=comp;
#if HORIZONTAL_STRESS
    lcase[lc].ncomps+=20;
#else
    lcase[lc].ncomps+=19;
#endif
    lcase[lc].irtype=1;

    if ( (lcase[lc].nmax = (int *)realloc( (int *)lcase[lc].nmax, lcase[lc].ncomps * sizeof(int))) == NULL )
      printf("\n\n ERROR: malloc failure\n\n" );
    if ( (lcase[lc].nmin = (int *)realloc( (int *)lcase[lc].nmin, lcase[lc].ncomps * sizeof(int))) == NULL )
      printf("\n\n ERROR: malloc failure\n\n" );
    if ( (lcase[lc].max = (float *)realloc((float *)lcase[lc].max, lcase[lc].ncomps * sizeof(float))) == NULL )
      printf("\n\n ERROR: malloc failure\n\n" );
    if ( (lcase[lc].min = (float *)realloc((float *)lcase[lc].min, lcase[lc].ncomps * sizeof(float))) == NULL )
      printf("\n\n ERROR: malloc failure\n\n" );
    if ( (lcase[lc].dat = (float **)realloc((float **)lcase[lc].dat, lcase[lc].ncomps * sizeof(float *))) == NULL )
      printf("\n\n ERROR: malloc failure\n\n" );
    if ( (lcase[lc].compName = (char **)realloc((char **)lcase[lc].compName, lcase[lc].ncomps * sizeof(char *))) == NULL )
      printf("\n\n ERROR: malloc failure\n\n" );
    if ( (lcase[lc].icname = (char **)realloc((char **)lcase[lc].icname, lcase[lc].ncomps * sizeof(char *))) == NULL )
      printf("\n\n ERROR: malloc failure\n\n" );
    if ( (lcase[lc].menu = (int *)realloc((int *)lcase[lc].menu, lcase[lc].ncomps * sizeof(int))) == NULL )
      printf("\n\n ERROR: malloc failure\n\n" );
    if ( (lcase[lc].ictype = (int *)realloc((int *)lcase[lc].ictype, lcase[lc].ncomps * sizeof(int))) == NULL )
      printf("\n\n ERROR: malloc failure\n\n" );
    if ( (lcase[lc].icind1 = (int *)realloc((int *)lcase[lc].icind1, lcase[lc].ncomps * sizeof(int))) == NULL )
      printf("\n\n ERROR: malloc failure\n\n" );
    if ( (lcase[lc].icind2 = (int *)realloc((int *)lcase[lc].icind2, lcase[lc].ncomps * sizeof(int))) == NULL )
      printf("\n\n ERROR: malloc failure\n\n" );
    if ( (lcase[lc].iexist = (int *)realloc((int *)lcase[lc].iexist, lcase[lc].ncomps * sizeof(int))) == NULL )
      printf("\n\n ERROR: malloc failure\n\n" );

    for(i=comp; i<lcase[lc].ncomps; i++)
    {
      if ( (lcase[lc].dat[i] = (float *)calloc( (anz->nmax+1), sizeof(float))) == NULL )
        printf("\n\n ERROR: malloc failure\n\n" );	               
      if ( (lcase[lc].compName[i] = (char *)malloc( MAX_LINE_LENGTH * sizeof(char))) == NULL )
        printf("\n\n ERROR: malloc failed\n\n" );
      if ( (lcase[lc].icname[i] = (char *)malloc( MAX_LINE_LENGTH * sizeof(char))) == NULL )
        printf("\n\n ERROR: malloc failed\n\n" );
      lcase[lc].max[i]=-MAX_INTEGER;
      lcase[lc].min[i]=MAX_INTEGER;
    }

    /* calculate von Mises Stress  */

    strcpy ( lcase[lc].compName[comp], "Mises   ");
    lcase[lc].menu[comp] = 1;
    lcase[lc].ictype[comp] = 1;
    lcase[lc].icind1[comp] = 0;
    lcase[lc].icind2[comp] = 0;
    lcase[lc].iexist[comp] = 1;

    for (i=0; i<anz->n; i++ )
    {
      if(node[node[i].nr].pflag!=0) continue;
      if(lcase[lc].ictype[0] == 14 )
      {
        /* go over 180 degree in coarse steps */
        max_val=alfa=0.;
        dalfa=dalfa_grd*pi180;
        for ( l=0; l<PI/dalfa; l++ )
        {
          alfa+= dalfa;
          s[0]=lcase[lc].dat[0][node[i].nr]* cos(alfa+pi180*lcase[lc].dat[6][node[i].nr]);
          s[1]=lcase[lc].dat[1][node[i].nr]* cos(alfa+pi180*lcase[lc].dat[7][node[i].nr]);
          s[2]=lcase[lc].dat[2][node[i].nr]* cos(alfa+pi180*lcase[lc].dat[8][node[i].nr]);
          s[3]=lcase[lc].dat[3][node[i].nr]* cos(alfa+pi180*lcase[lc].dat[9][node[i].nr]);
          s[4]=lcase[lc].dat[4][node[i].nr]* cos(alfa+pi180*lcase[lc].dat[10][node[i].nr]);
          s[5]=lcase[lc].dat[5][node[i].nr]* cos(alfa+pi180*lcase[lc].dat[11][node[i].nr]);
          octaStress=
            1./3. *sqrt( ((s[0]-s[1])*(s[0]-s[1])) +((s[1]-s[2])*(s[1]-s[2])) +((s[2]-s[0])*(s[2]-s[0])) +(6.*s[4]*s[4]) +(6.*s[5]*s[5]) +(6.*s[3]*s[3]) );
          vMises = (3./1.4142136) * octaStress;
          if( stressFlag==0) vMises*=vMises_stresstostrain;
          if(vMises>max_val) { max_val=vMises; max_alfa=alfa; }
          /* if(node[i].nr==87) printf("1vMises[%d]:%f  max_val:%f alfa:%f max_alfa=%f\n", l, vMises,max_val,alfa,max_alfa); */
        }
        /* go again over the values close to the maximum in 2 degree steps */
        max_val=0.;
        alfa=max_alfa-dalfa;
        dalfa/=dalfa_grd*.5;
        for ( l=0; l<dalfa_grd; l++ )
        {
          alfa+= dalfa;
          s[0]=lcase[lc].dat[0][node[i].nr]* cos(alfa+pi180*lcase[lc].dat[6][node[i].nr]);
          s[1]=lcase[lc].dat[1][node[i].nr]* cos(alfa+pi180*lcase[lc].dat[7][node[i].nr]);
          s[2]=lcase[lc].dat[2][node[i].nr]* cos(alfa+pi180*lcase[lc].dat[8][node[i].nr]);
          s[3]=lcase[lc].dat[3][node[i].nr]* cos(alfa+pi180*lcase[lc].dat[9][node[i].nr]);
          s[4]=lcase[lc].dat[4][node[i].nr]* cos(alfa+pi180*lcase[lc].dat[10][node[i].nr]);
          s[5]=lcase[lc].dat[5][node[i].nr]* cos(alfa+pi180*lcase[lc].dat[11][node[i].nr]);
          octaStress=
            1./3. *sqrt( ((s[0]-s[1])*(s[0]-s[1])) +((s[1]-s[2])*(s[1]-s[2])) +((s[2]-s[0])*(s[2]-s[0])) +(6.*s[4]*s[4]) +(6.*s[5]*s[5]) +(6.*s[3]*s[3]) );
          vMises = (3./1.4142136) * octaStress;  
          if( stressFlag==0) vMises*=vMises_stresstostrain;
          if(vMises>max_val) max_val=vMises;
        }
        lcase[lc].dat[comp][node[i].nr]=max_val;
      }
      else if(lcp!=0)
      {
        /* go over 180 degree in coarse steps */
        max_val=alfa=0.;
        dalfa=dalfa_grd*pi180;
        for ( l=0; l<PI/dalfa; l++ )
        {
          alfa+= dalfa;
          s[0]=lcase[lc].dat[0][node[i].nr]* cos(alfa+pi180*lcase[lc+lcp].dat[0][node[i].nr]);
          s[1]=lcase[lc].dat[1][node[i].nr]* cos(alfa+pi180*lcase[lc+lcp].dat[1][node[i].nr]);
          s[2]=lcase[lc].dat[2][node[i].nr]* cos(alfa+pi180*lcase[lc+lcp].dat[2][node[i].nr]);
          s[3]=lcase[lc].dat[3][node[i].nr]* cos(alfa+pi180*lcase[lc+lcp].dat[3][node[i].nr]);
          s[4]=lcase[lc].dat[4][node[i].nr]* cos(alfa+pi180*lcase[lc+lcp].dat[4][node[i].nr]);
          s[5]=lcase[lc].dat[5][node[i].nr]* cos(alfa+pi180*lcase[lc+lcp].dat[5][node[i].nr]);
          octaStress=
            1./3. *sqrt( ((s[0]-s[1])*(s[0]-s[1])) +((s[1]-s[2])*(s[1]-s[2])) +((s[2]-s[0])*(s[2]-s[0])) +(6.*s[4]*s[4]) +(6.*s[5]*s[5]) +(6.*s[3]*s[3]) );
          vMises = (3./1.4142136) * octaStress;  
          if( stressFlag==0) vMises*=vMises_stresstostrain;
          if(vMises>max_val) { max_val=vMises; max_alfa=alfa; }
          /* if(node[i].nr==87) printf("1vMises[%d]:%f  max_val:%f alfa:%f max_alfa=%f\n", l, vMises,max_val,alfa,max_alfa); */
        }
        /* go again over the values close to the maximum in 2 degree steps */
        max_val=0.;
        alfa=max_alfa-dalfa;
        dalfa/=dalfa_grd*.5;
        for ( l=0; l<dalfa_grd; l++ )
        {
          alfa+= dalfa;
          s[0]=lcase[lc].dat[0][node[i].nr]* cos(alfa+pi180*lcase[lc+lcp].dat[0][node[i].nr]);
          s[1]=lcase[lc].dat[1][node[i].nr]* cos(alfa+pi180*lcase[lc+lcp].dat[1][node[i].nr]);
          s[2]=lcase[lc].dat[2][node[i].nr]* cos(alfa+pi180*lcase[lc+lcp].dat[2][node[i].nr]);
          s[3]=lcase[lc].dat[3][node[i].nr]* cos(alfa+pi180*lcase[lc+lcp].dat[3][node[i].nr]);
          s[4]=lcase[lc].dat[4][node[i].nr]* cos(alfa+pi180*lcase[lc+lcp].dat[4][node[i].nr]);
          s[5]=lcase[lc].dat[5][node[i].nr]* cos(alfa+pi180*lcase[lc+lcp].dat[5][node[i].nr]);
          octaStress=
            1./3. *sqrt( ((s[0]-s[1])*(s[0]-s[1])) +((s[1]-s[2])*(s[1]-s[2])) +((s[2]-s[0])*(s[2]-s[0])) +(6.*s[4]*s[4]) +(6.*s[5]*s[5]) +(6.*s[3]*s[3]) );
          vMises = (3./1.4142136) * octaStress;  
          if( stressFlag==0) vMises*=vMises_stresstostrain;
          if(vMises>max_val) max_val=vMises;
        }
        lcase[lc].dat[comp][node[i].nr]=max_val;
      }
      else
      {
        s[0]=lcase[lc].dat[0][node[i].nr];
        s[1]=lcase[lc].dat[1][node[i].nr];
        s[2]=lcase[lc].dat[2][node[i].nr];
        s[3]=lcase[lc].dat[3][node[i].nr];
        s[4]=lcase[lc].dat[4][node[i].nr];
        s[5]=lcase[lc].dat[5][node[i].nr];
        octaStress=
          1./3. *sqrt( ((s[0]-s[1])*(s[0]-s[1])) +((s[1]-s[2])*(s[1]-s[2])) +((s[2]-s[0])*(s[2]-s[0])) +(6.*s[4]*s[4]) +(6.*s[5]*s[5]) +(6.*s[3]*s[3]) );
        vMises = (3./1.4142136) * octaStress;  
        if( stressFlag==0) vMises*=vMises_stresstostrain;
        lcase[lc].dat[comp][node[i].nr]  = vMises;
      }
    }

#if HORIZONTAL_STRESS
    /* calculate horizontal Stress xx+yy */
    j=comp+1;
    strcpy ( lcase[lc].compName[j], "xx+yy   ");
    lcase[lc].menu[j] = 1;
    lcase[lc].ictype[j] = 1;
    lcase[lc].icind1[j] = 0;
    lcase[lc].icind2[j] = 0;
    lcase[lc].iexist[j] = 1;

    for (i=0; i<anz->n; i++ )
    {
      if(node[node[i].nr].pflag!=0) continue;
      if(lcase[lc].ictype[0] == 14 )
      {
        /* go over 180 degree in coarse steps */
        max_val=alfa=0.;
        dalfa=dalfa_grd*pi180;
        for ( l=0; l<PI/dalfa; l++ )
        {
          alfa+= dalfa;
          s[0]=lcase[lc].dat[0][node[i].nr]* cos(alfa+pi180*lcase[lc].dat[6][node[i].nr]);
          s[1]=lcase[lc].dat[1][node[i].nr]* cos(alfa+pi180*lcase[lc].dat[7][node[i].nr]);
          dx=s[0]+s[1];
          if((dx*dx)>max_val) { max_val=(dx*dx); max_alfa=alfa; }
          /* if(node[i].nr==21607) printf("1dx[%d]:%f  max_val:%f alfa:%f max_alfa=%f\n", l, dx,max_val,alfa,max_alfa); */
        }
        /* go again over the values close to the maximum in 2 degree steps */
        max_val=0.;
        alfa=max_alfa-dalfa;
        dalfa/=dalfa_grd*.5;
        for ( l=0; l<dalfa_grd; l++ )
        {
          alfa+= dalfa;
          s[0]=lcase[lc].dat[0][node[i].nr]* cos(alfa+pi180*lcase[lc].dat[6][node[i].nr]);
          s[1]=lcase[lc].dat[1][node[i].nr]* cos(alfa+pi180*lcase[lc].dat[7][node[i].nr]);
          dx=s[0]+s[1];
          if((dx*dx)>max_val) max_val=(dx*dx);
        }
        lcase[lc].dat[j][node[i].nr]=sqrt(max_val);
      }
      else if(lcp!=0)
      {
        /* go over 180 degree in coarse steps */
        max_val=alfa=0.;
        dalfa=dalfa_grd*pi180;
        for ( l=0; l<PI/dalfa; l++ )
        {
          alfa+= dalfa;
          s[0]=lcase[lc].dat[0][node[i].nr]* cos(alfa+pi180*lcase[lc+lcp].dat[0][node[i].nr]);
          s[1]=lcase[lc].dat[1][node[i].nr]* cos(alfa+pi180*lcase[lc+lcp].dat[1][node[i].nr]);
          dx=s[0]+s[1];
          if((dx*dx)>max_val) { max_val=(dx*dx); max_alfa=alfa; }
          /* if(node[i].nr==21607) printf("1dx[%d]:%f  max_val:%f alfa:%f max_alfa=%f\n", l, dx,max_val,alfa,max_alfa); */
        }
        /* go again over the values close to the maximum in 2 degree steps */
        max_val=0.;
        alfa=max_alfa-dalfa;
        dalfa/=dalfa_grd*.5;
        for ( l=0; l<dalfa_grd; l++ )
        {
          alfa+= dalfa;
          s[0]=lcase[lc].dat[0][node[i].nr]* cos(alfa+pi180*lcase[lc+lcp].dat[0][node[i].nr]);
          s[1]=lcase[lc].dat[1][node[i].nr]* cos(alfa+pi180*lcase[lc+lcp].dat[1][node[i].nr]);
          dx=s[0]+s[1];
          if((dx*dx)>max_val) max_val=(dx*dx);
        }
        lcase[lc].dat[j][node[i].nr]=sqrt(max_val);
      }
      else
      {
        lcase[lc].dat[j][node[i].nr]=lcase[lc].dat[0][node[i].nr]+lcase[lc].dat[1][node[i].nr];
      }
    }
#else
    comp--;
#endif

    /* calculate maximum Principal  */

    if(stressFlag==1)
    {
      strcpy ( lcase[lc].compName[comp+2], "PS1x    ");
      strcpy ( lcase[lc].compName[comp+3], "PS1y    ");
      strcpy ( lcase[lc].compName[comp+4], "PS1z    ");
      strcpy ( lcase[lc].compName[comp+5], "PS1     ");
      strcpy ( lcase[lc].compName[comp+6], "PS2x    ");
      strcpy ( lcase[lc].compName[comp+7], "PS2y    ");
      strcpy ( lcase[lc].compName[comp+8], "PS2z    ");
      strcpy ( lcase[lc].compName[comp+9], "PS2     ");
      strcpy ( lcase[lc].compName[comp+10], "PS3x    ");
      strcpy ( lcase[lc].compName[comp+11], "PS3y    ");
      strcpy ( lcase[lc].compName[comp+12], "PS3z    ");
      strcpy ( lcase[lc].compName[comp+13], "PS3     ");
      strcpy ( lcase[lc].compName[comp+14], "worstPSx");
      strcpy ( lcase[lc].compName[comp+15], "worstPSy");
      strcpy ( lcase[lc].compName[comp+16], "worstPSz");
      strcpy ( lcase[lc].compName[comp+17], "worstPS ");
      strcpy ( lcase[lc].compName[comp+18], "maxShear");
      strcpy ( lcase[lc].compName[comp+19], "Snorm  ");
    }
    else if(stressFlag==0)
    {
      strcpy ( lcase[lc].compName[comp+2], "PE1x    ");
      strcpy ( lcase[lc].compName[comp+3], "PE1y    ");
      strcpy ( lcase[lc].compName[comp+4], "PE1z    ");
      strcpy ( lcase[lc].compName[comp+5], "PE1     ");
      strcpy ( lcase[lc].compName[comp+6], "PE2x    ");
      strcpy ( lcase[lc].compName[comp+7], "PE2y    ");
      strcpy ( lcase[lc].compName[comp+8], "PE2z    ");
      strcpy ( lcase[lc].compName[comp+9], "PE2     ");
      strcpy ( lcase[lc].compName[comp+10], "PE3x    ");
      strcpy ( lcase[lc].compName[comp+11], "PE3y    ");
      strcpy ( lcase[lc].compName[comp+12], "PE3z    ");
      strcpy ( lcase[lc].compName[comp+13], "PE3     ");
      strcpy ( lcase[lc].compName[comp+14], "worstPEx");
      strcpy ( lcase[lc].compName[comp+15], "worstPEy");
      strcpy ( lcase[lc].compName[comp+16], "worstPEz");
      strcpy ( lcase[lc].compName[comp+17], "worstPE ");
      strcpy ( lcase[lc].compName[comp+18], "maxShear  ");
      strcpy ( lcase[lc].compName[comp+19], "Enorm  ");
    }
    else 
    {
      strcpy ( lcase[lc].compName[comp+2], "P1x     ");
      strcpy ( lcase[lc].compName[comp+3], "P1y     ");
      strcpy ( lcase[lc].compName[comp+4], "P1z     ");
      strcpy ( lcase[lc].compName[comp+5], "P1      ");
      strcpy ( lcase[lc].compName[comp+6], "P2x     ");
      strcpy ( lcase[lc].compName[comp+7], "P2y     ");
      strcpy ( lcase[lc].compName[comp+8], "P2z     ");
      strcpy ( lcase[lc].compName[comp+9], "P2      ");
      strcpy ( lcase[lc].compName[comp+10], "P3x     ");
      strcpy ( lcase[lc].compName[comp+11], "P3y     ");
      strcpy ( lcase[lc].compName[comp+12], "P3z     ");
      strcpy ( lcase[lc].compName[comp+13], "P3      ");
      strcpy ( lcase[lc].compName[comp+14], "worstPx ");
      strcpy ( lcase[lc].compName[comp+15], "worstPy ");
      strcpy ( lcase[lc].compName[comp+16], "worstPz ");
      strcpy ( lcase[lc].compName[comp+17], "worstP  ");
      strcpy ( lcase[lc].compName[comp+18], "maxShear  ");
      strcpy ( lcase[lc].compName[comp+19], "Tnorm  ");
    }

    j=1;
    for (i=2; i<19; i++ )
    {
      lcase[lc].ictype[comp+i] = 2;
      if(j<4)
      {
        lcase[lc].menu[comp+i] = 0;
        lcase[lc].icind1[comp+i] = j;
      }
      else
      {
        lcase[lc].menu[comp+i] = 1;
        lcase[lc].icind1[comp+i] = 0;
      }
      lcase[lc].icind2[comp+i] = 0;
      lcase[lc].iexist[comp+i] = 1;
      if(j>=4) j=1;
      else j++;
    }
    for (i=18; i<20; i++ )
    {
      lcase[lc].menu[comp+i] = 1;
      lcase[lc].ictype[comp+i] = 1;
      lcase[lc].icind1[comp+i] = 0;
      lcase[lc].icind2[comp+i] = 0;
      lcase[lc].iexist[comp+i] = 1;
    }


    for (i=0; i<anz->n; i++ )
    {
      if(node[node[i].nr].pflag!=0) continue;
      if(lcase[lc].ictype[0] == 14 )
      {
        /* go over 180 degree in coarse steps */
        max_val=alfa=0.;
        dalfa=dalfa_grd*pi180;
        for ( l=0; l<PI/dalfa; l++ )
        {
          alfa+= dalfa;
          s[0]=lcase[lc].dat[0][node[i].nr]* cos(alfa+pi180*lcase[lc].dat[6][node[i].nr]);
          s[1]=lcase[lc].dat[1][node[i].nr]* cos(alfa+pi180*lcase[lc].dat[7][node[i].nr]);
          s[2]=lcase[lc].dat[2][node[i].nr]* cos(alfa+pi180*lcase[lc].dat[8][node[i].nr]);
          s[3]=lcase[lc].dat[3][node[i].nr]* cos(alfa+pi180*lcase[lc].dat[9][node[i].nr]);
          s[4]=lcase[lc].dat[4][node[i].nr]* cos(alfa+pi180*lcase[lc].dat[10][node[i].nr]);
          s[5]=lcase[lc].dat[5][node[i].nr]* cos(alfa+pi180*lcase[lc].dat[11][node[i].nr]);
          j=calcPrinc( s, p, &alfap[0][0], &alfap[1][0], &alfap[2][0], 2 );
          if( p[0]*p[0]>max_val) { max_val= p[0]*p[0]; max_alfa=alfa; }
          /* if(node[i].nr==87) printf("1p[%d]:%f %f %f max_val:%f alfa:%f max_alfa=%f\n", l,p[0],p[1],p[2],max_val,alfa,max_alfa); */
        }
        /* go again over the values close to the maximum in 2 degree steps */
        max_val=0.;
        alfa=max_alfa-dalfa;
        dalfa/=dalfa_grd*.5;
        for ( l=0; l<dalfa_grd; l++ )
        {
          alfa+= dalfa;
          s[0]=lcase[lc].dat[0][node[i].nr]* cos(alfa+pi180*lcase[lc].dat[6][node[i].nr]);
          s[1]=lcase[lc].dat[1][node[i].nr]* cos(alfa+pi180*lcase[lc].dat[7][node[i].nr]);
          s[2]=lcase[lc].dat[2][node[i].nr]* cos(alfa+pi180*lcase[lc].dat[8][node[i].nr]);
          s[3]=lcase[lc].dat[3][node[i].nr]* cos(alfa+pi180*lcase[lc].dat[9][node[i].nr]);
          s[4]=lcase[lc].dat[4][node[i].nr]* cos(alfa+pi180*lcase[lc].dat[10][node[i].nr]);
          s[5]=lcase[lc].dat[5][node[i].nr]* cos(alfa+pi180*lcase[lc].dat[11][node[i].nr]);
          j=calcPrinc( s, p, &alfap[0][0], &alfap[1][0], &alfap[2][0], 2 );
          if( p[0]*p[0]>max_val) { max_val= p[0]*p[0]; max_alfa=alfa; }
        }
        s[0]=lcase[lc].dat[0][node[i].nr]* cos(max_alfa+pi180*lcase[lc].dat[6][node[i].nr]);
        s[1]=lcase[lc].dat[1][node[i].nr]* cos(max_alfa+pi180*lcase[lc].dat[7][node[i].nr]);
        s[2]=lcase[lc].dat[2][node[i].nr]* cos(max_alfa+pi180*lcase[lc].dat[8][node[i].nr]);
        s[3]=lcase[lc].dat[3][node[i].nr]* cos(max_alfa+pi180*lcase[lc].dat[9][node[i].nr]);
        s[4]=lcase[lc].dat[4][node[i].nr]* cos(max_alfa+pi180*lcase[lc].dat[10][node[i].nr]);
        s[5]=lcase[lc].dat[5][node[i].nr]* cos(max_alfa+pi180*lcase[lc].dat[11][node[i].nr]);
      }
      else if(lcp!=0)
      {
        /* go over 180 degree in coarse steps */
        max_val=alfa=0.;
        dalfa=dalfa_grd*pi180;
        for ( l=0; l<PI/dalfa; l++ )
        {
          alfa+= dalfa;
          s[0]=lcase[lc].dat[0][node[i].nr]* cos(alfa+pi180*lcase[lc].dat[6][node[i].nr]);
          s[1]=lcase[lc].dat[1][node[i].nr]* cos(alfa+pi180*lcase[lc].dat[7][node[i].nr]);
          s[2]=lcase[lc].dat[2][node[i].nr]* cos(alfa+pi180*lcase[lc].dat[8][node[i].nr]);
          s[3]=lcase[lc].dat[3][node[i].nr]* cos(alfa+pi180*lcase[lc].dat[9][node[i].nr]);
          s[4]=lcase[lc].dat[4][node[i].nr]* cos(alfa+pi180*lcase[lc].dat[10][node[i].nr]);
          s[5]=lcase[lc].dat[5][node[i].nr]* cos(alfa+pi180*lcase[lc].dat[11][node[i].nr]);
          j=calcPrinc( s, p, &alfap[0][0], &alfap[1][0], &alfap[2][0], 2 );
          if( p[0]*p[0]>max_val) { max_val= p[0]*p[0]; max_alfa=alfa; }
          /* if(node[i].nr==87) printf("1p[%d]:%f %f %f max_val:%f alfa:%f max_alfa=%f\n", l,p[0],p[1],p[2],max_val,alfa,max_alfa); */
        }
        /* go again over the values close to the maximum in 2 degree steps */
        max_val=0.;
        alfa=max_alfa-dalfa;
        dalfa/=dalfa_grd*.5;
        for ( l=0; l<dalfa_grd; l++ )
        {
          alfa+= dalfa;
          s[0]=lcase[lc].dat[0][node[i].nr]* cos(alfa+pi180*lcase[lc].dat[6][node[i].nr]);
          s[1]=lcase[lc].dat[1][node[i].nr]* cos(alfa+pi180*lcase[lc].dat[7][node[i].nr]);
          s[2]=lcase[lc].dat[2][node[i].nr]* cos(alfa+pi180*lcase[lc].dat[8][node[i].nr]);
          s[3]=lcase[lc].dat[3][node[i].nr]* cos(alfa+pi180*lcase[lc].dat[9][node[i].nr]);
          s[4]=lcase[lc].dat[4][node[i].nr]* cos(alfa+pi180*lcase[lc].dat[10][node[i].nr]);
          s[5]=lcase[lc].dat[5][node[i].nr]* cos(alfa+pi180*lcase[lc].dat[11][node[i].nr]);
          j=calcPrinc( s, p, &alfap[0][0], &alfap[1][0], &alfap[2][0], 2 );
          if( p[0]*p[0]>max_val) { max_val= p[0]*p[0]; max_alfa=alfa; }
        }
        s[0]=lcase[lc].dat[0][node[i].nr]* cos(max_alfa+pi180*lcase[lc].dat[6][node[i].nr]);
        s[1]=lcase[lc].dat[1][node[i].nr]* cos(max_alfa+pi180*lcase[lc].dat[7][node[i].nr]);
        s[2]=lcase[lc].dat[2][node[i].nr]* cos(max_alfa+pi180*lcase[lc].dat[8][node[i].nr]);
        s[3]=lcase[lc].dat[3][node[i].nr]* cos(max_alfa+pi180*lcase[lc].dat[9][node[i].nr]);
        s[4]=lcase[lc].dat[4][node[i].nr]* cos(max_alfa+pi180*lcase[lc].dat[10][node[i].nr]);
        s[5]=lcase[lc].dat[5][node[i].nr]* cos(max_alfa+pi180*lcase[lc].dat[11][node[i].nr]);
      }
      else
      {
        s[0]=lcase[lc].dat[0][node[i].nr];
        s[1]=lcase[lc].dat[1][node[i].nr];
        s[2]=lcase[lc].dat[2][node[i].nr];
        s[3]=lcase[lc].dat[3][node[i].nr];
        s[4]=lcase[lc].dat[4][node[i].nr];
        s[5]=lcase[lc].dat[5][node[i].nr];
      }

      /* if flag=0  x[0]  >  x[1]  >  x[2]                              */
      /* if flag=1 |x[0]| > |x[1]| > |x[2]|                             */
      /* if flag=2 |x[0]| > |x[1]| > |x[2]| and no angle calculation    */
      //printf("n:%d ",node[i].nr);
      //for(j=0; j<6; j++) printf("%f ", s[j]);
      //printf("\n");
      j=calcPrinc( s, p, &alfap[0][0], &alfap[1][0], &alfap[2][0], 0 );
      if ( j == -9999 ) /* to activate this: -1 */
      {
        printf("Warning: at node:%d\n", node[i].nr );
      }
      else if ( j == -2 )
      {
        printf("Warning: at node:%d, directions and values of maxPrinc set to 0.\n", node[i].nr );
        for(j=comp+2; j<comp+20; j++) lcase[lc].dat[j][node[i].nr] = 0.;
      }
      else
      {
	j=0;
        l=2;
        do
	{
          lcase[lc].dat[comp+l++][node[i].nr] = alfap[j][0]*p[j];
          lcase[lc].dat[comp+l++][node[i].nr] = alfap[j][1]*p[j];
          lcase[lc].dat[comp+l++][node[i].nr] = alfap[j][2]*p[j];
          lcase[lc].dat[comp+l++][node[i].nr]= p[j++];
	}while(l<14);

        /* worstP */
        y[0] = p[0]*p[0];
        y[1] = p[1]*p[1];
        y[2] = p[2]*p[2];
        if ( (y[0]>=y[1]) && (y[0]>=y[2]) )
        { 
          lcase[lc].dat[comp+14][node[i].nr] = alfap[0][0]*p[0];
          lcase[lc].dat[comp+15][node[i].nr] = alfap[0][1]*p[0];
          lcase[lc].dat[comp+16][node[i].nr] = alfap[0][2]*p[0];
          if((lcp!=0)&& (p[0]<0)) lcase[lc].dat[comp+17][node[i].nr]=-p[0];
          else       lcase[lc].dat[comp+17][node[i].nr] = p[0];
        } 
        else if( (y[1]>=y[0]) && (y[1]>=y[2]) )
        {        
          lcase[lc].dat[comp+14][node[i].nr] = alfap[1][0]*p[1];
          lcase[lc].dat[comp+15][node[i].nr] = alfap[1][1]*p[1];
          lcase[lc].dat[comp+16][node[i].nr] = alfap[1][2]*p[1];
          if((lcp!=0)&& (p[1]<0)) lcase[lc].dat[comp+17][node[i].nr]=-p[1];
          else       lcase[lc].dat[comp+17][node[i].nr] = p[1];
        } 
        else if ( (y[2]>=y[0]) && (y[2]>=y[1]) )
        {        
          lcase[lc].dat[comp+14][node[i].nr] = alfap[2][0]*p[2];
          lcase[lc].dat[comp+15][node[i].nr] = alfap[2][1]*p[2];
          lcase[lc].dat[comp+16][node[i].nr] = alfap[2][2]*p[2];
          if((lcp!=0)&& (p[2]<0)) lcase[lc].dat[comp+17][node[i].nr]=-p[2];
          else       lcase[lc].dat[comp+17][node[i].nr] = p[2];
        }
        else
        {
          printf("ERROR in calcDatasets()\n"); exit(-1);
        }

        /* maxShear (Tau ==  0.5*max((Pi-Pn)) */
        y[0]=p[0]-p[2];
        y[1]=p[0]-p[1];
        y[2]=p[1]-p[2];
        lcase[lc].dat[comp+18][node[i].nr]=y[0];
        for(l=1; l<3; l++) { if(y[l]>lcase[lc].dat[comp+18][node[i].nr]) lcase[lc].dat[comp+18][node[i].nr]=y[l]; }
        lcase[lc].dat[comp+18][node[i].nr]*=0.5;
	
        /* normal stress */
        if(v_betrag(node[node[i].nr].nv))
	{
        /* calculate the stress in normal direction */
        p[0]=
        s[0]*node[node[i].nr].nv[0]+
        s[3]*node[node[i].nr].nv[1]+
        s[5]*node[node[i].nr].nv[2];
        p[1]=
        s[3]*node[node[i].nr].nv[0]+
        s[1]*node[node[i].nr].nv[1]+
        s[4]*node[node[i].nr].nv[2];
        p[2]=
        s[5]*node[node[i].nr].nv[0]+
        s[4]*node[node[i].nr].nv[1]+
        s[2]*node[node[i].nr].nv[2];
        lcase[lc].dat[comp+19][node[i].nr]= v_sprod(node[node[i].nr].nv, p);
	}
	else lcase[lc].dat[comp+19][node[i].nr]=0.;
      }
    }

    /* max and min */
    for(j=comp; j<lcase[lc].ncomps; j++)
    {
      for (i=0; i<anz->n; i++ )
      {
        if(node[node[i].nr].pflag!=0) continue;
        if(lcase[lc].dat[j][node[i].nr] > lcase[lc].max[j])
        {
          lcase[lc].max[j]=lcase[lc].dat[j][node[i].nr];
          lcase[lc].nmax[j]=node[i].nr;
        }
        if(lcase[lc].dat[j][node[i].nr] < lcase[lc].min[j])
        {
          lcase[lc].min[j]=lcase[lc].dat[j][node[i].nr];
          lcase[lc].nmin[j]=node[i].nr;
        }
      }
    }

    jumpStresses:;
  }
  else if(( lcase[lc].ictype[0] == 2)||(lcase[lc].ictype[0]== 12)) /* check first comp if its a vector (DISP, VELO etc.) */
  {
    /* overwrite the derivatives (iexist[]!=0) */
    comp=lcase[lc].ncomps;
    while(lcase[lc].iexist[comp-1]!=0) comp--;
    lcase[lc].ncomps=comp+1;
    lcase[lc].irtype=1;

    if ( (lcase[lc].nmax = (int *)realloc( (int *)lcase[lc].nmax, lcase[lc].ncomps * sizeof(int))) == NULL )
      printf("\n\n ERROR: malloc failure\n\n" );
    if ( (lcase[lc].nmin = (int *)realloc( (int *)lcase[lc].nmin, lcase[lc].ncomps * sizeof(int))) == NULL )
      printf("\n\n ERROR: malloc failure\n\n" );
    if ( (lcase[lc].max = (float *)realloc((float *)lcase[lc].max, lcase[lc].ncomps * sizeof(float))) == NULL )
      printf("\n\n ERROR: malloc failure\n\n" );
    if ( (lcase[lc].min = (float *)realloc((float *)lcase[lc].min, lcase[lc].ncomps * sizeof(float))) == NULL )
      printf("\n\n ERROR: malloc failure\n\n" );
    if ( (lcase[lc].dat = (float **)realloc((float **)lcase[lc].dat, lcase[lc].ncomps * sizeof(float *))) == NULL )
      printf("\n\n ERROR: malloc failure\n\n" );
    if ( (lcase[lc].compName = (char **)realloc((char **)lcase[lc].compName, lcase[lc].ncomps * sizeof(char *))) == NULL )
      printf("\n\n ERROR: malloc failure\n\n" );
    if ( (lcase[lc].icname = (char **)realloc((char **)lcase[lc].icname, lcase[lc].ncomps * sizeof(char *))) == NULL )
      printf("\n\n ERROR: malloc failure\n\n" );
    if ( (lcase[lc].menu = (int *)realloc((int *)lcase[lc].menu, lcase[lc].ncomps * sizeof(int))) == NULL )
      printf("\n\n ERROR: malloc failure\n\n" );
    if ( (lcase[lc].ictype = (int *)realloc((int *)lcase[lc].ictype, lcase[lc].ncomps * sizeof(int))) == NULL )
      printf("\n\n ERROR: malloc failure\n\n" );
    if ( (lcase[lc].icind1 = (int *)realloc((int *)lcase[lc].icind1, lcase[lc].ncomps * sizeof(int))) == NULL )
      printf("\n\n ERROR: malloc failure\n\n" );
    if ( (lcase[lc].icind2 = (int *)realloc((int *)lcase[lc].icind2, lcase[lc].ncomps * sizeof(int))) == NULL )
      printf("\n\n ERROR: malloc failure\n\n" );
    if ( (lcase[lc].iexist = (int *)realloc((int *)lcase[lc].iexist, lcase[lc].ncomps * sizeof(int))) == NULL )
      printf("\n\n ERROR: malloc failure\n\n" );

    for(i=comp; i<lcase[lc].ncomps; i++)
    {
      if ( (lcase[lc].dat[i] = (float *)calloc( (anz->nmax+1), sizeof(float))) == NULL )
        printf("\n\n ERROR: malloc failure\n\n" );	               
      if ( (lcase[lc].compName[i] = (char *)malloc( MAX_LINE_LENGTH * sizeof(char))) == NULL )
        printf("\n\n ERROR: malloc failed\n\n" );
      if ( (lcase[lc].icname[i] = (char *)malloc( MAX_LINE_LENGTH * sizeof(char))) == NULL )
        printf("\n\n ERROR: malloc failed\n\n" );
      lcase[lc].max[i]=-MAX_INTEGER;
      lcase[lc].min[i]=MAX_INTEGER;
    }

    /* calculate total displacement  */

    strcpy ( lcase[lc].compName[comp], "ALL     ");
    lcase[lc].menu[comp] = 1;
    lcase[lc].ictype[comp] = 2;
    lcase[lc].icind1[comp] = 0;
    lcase[lc].icind2[comp] = 0;
    lcase[lc].iexist[comp] = 1;
    strcpy(lcase[lc].icname[comp], "ALL");

    pi180=PI/180.;
    dalfa=3.*pi180;
    for (i=0; i<anz->n; i++ )
    {
      if(node[node[i].nr].pflag!=0) continue;
      if (lcase[lc].ictype[0]== 12)
      {
        max_val=alfa=0.;
        for ( l=0; l<60; l++ )
        {
          alfa+= dalfa;
          dx=(lcase[lc].dat[0][node[i].nr]* cos(alfa+pi180*lcase[lc].dat[3][node[i].nr]));
          dy=(lcase[lc].dat[1][node[i].nr]* cos(alfa+pi180*lcase[lc].dat[4][node[i].nr]));
          dz=(lcase[lc].dat[2][node[i].nr]* cos(alfa+pi180*lcase[lc].dat[5][node[i].nr]));
          disp=dx*dx+dy*dy+dz*dz;
          if(disp>max_val) max_val=disp;
        }
        lcase[lc].dat[comp][node[i].nr]=sqrt(max_val);
      }
      else if (lcase[lc].ictype[0]== 2)
      {
        lcase[lc].dat[comp][node[i].nr]=sqrt(
        (lcase[lc].dat[0][node[i].nr]*lcase[lc].dat[0][node[i].nr]) +
        (lcase[lc].dat[1][node[i].nr]*lcase[lc].dat[1][node[i].nr]) +
        (lcase[lc].dat[2][node[i].nr]*lcase[lc].dat[2][node[i].nr]) );
      }
      else
      {
        lcase[lc].dat[comp][node[i].nr]=0.; 
      }

      if(lcase[lc].dat[comp][node[i].nr] > lcase[lc].max[comp])
      {
        lcase[lc].max[comp]=lcase[lc].dat[comp][node[i].nr];
        lcase[lc].nmax[comp]=node[i].nr;
      }
      if(lcase[lc].dat[comp][node[i].nr] < lcase[lc].min[comp])
      {
        lcase[lc].min[comp]=lcase[lc].dat[comp][node[i].nr];
        lcase[lc].nmin[comp]=node[i].nr;
      }

    }
  }
}


void transformDatasets( int lc, Summen *anz, Nodes *node, Datasets *lcase, char *method, char *axis )
{
  register int   i, j, n;
  int    lcp, layers=0, dim, mode=0, dir[3];
  double p1[3];
  double phi=0., r_mat[3][3], s_mat[3][3], prod_mat[3][3];
  double dx,dy,dz,du, rad,dr;
  char buffer[MAX_LINE_LENGTH];

  double er[3], et[3], ex[3]={0.,0.,0.}, vval[3];


  if (toupper(axis[0])=='X')      mode =1;
  else if (toupper(axis[0])=='Y') mode =2;
  else if (toupper(axis[0])=='Z') mode =3;

  if(mode==1) { dir[0]=0; dir[1]=1; dir[2]=2; }
  else if(mode==2) { dir[0]=1; dir[1]=2; dir[2]=0; }
  else if(mode==3) { dir[0]=2; dir[1]=0; dir[2]=1; }
  else { printf("ERROR: axis defined with arguments not supported so far\n"); return; }


  /* determine the mode of transformation */
  for(i=0; i<strlen(method); i++) method[i]=toupper(method[i]);

  /* check if this transformation method is already stored in a parameter */
  sprintf(buffer,"%s %s", method, axis);
  if(createDSparam(lc,"TRFM",buffer) == 1) { printf("ERROR trfm not done: The data are already defined in:%s. Please inverse the transformation before applying it again.\n", method); return; }

  if(compareStrings(method,"CYL")>0)
  {
    /* in case stress-phases for shells are to be regarded its necessary how much layers exist. All STRESP must show up first */
    if(( compare( lcase[lc].name, "STRESP", 6) == 6)&&(strlen(lcase[lc].name)==8)) layers=atoi(&lcase[lc].name[6])+1;
  
    if( (compare( lcase[lc].name, "STRESS", 6) == 6)||(compare( lcase[lc].name, "TOSTRAIN", 6) == 6)||( compare( lcase[lc].name, "ZZS", 3) == 3))
      // if( lcase[lc].ictype[0] == 4) /* check first comp if its a tensor (STRESS) */
    {
      /* check if the STRESS has six valid components */
      if(lcase[lc].ncomps < 6 ) goto jumpStresses;
      for (i=1; i<6; i++) if(lcase[lc].ictype[i] != 4 ) goto jumpStresses;
      n=0; while(((lcase[lc].compName[0][n]!='X')&&(lcase[lc].compName[0][n]!='R'))&&(n<6)) n++;
      //printf("n:%d %s\n", n, lcase[lc].compName[0]);
      if (compare(&lcase[lc].compName[0][n], "XX", 2) < 2 )  goto jumpStresses;
      if (compare(&lcase[lc].compName[1][n], "YY", 2) < 2 )  goto jumpStresses;
      if (compare(&lcase[lc].compName[2][n], "ZZ", 2) < 2 )  goto jumpStresses;
      if((compare(&lcase[lc].compName[3][n], "XY", 2) < 2 ) && (compare(&lcase[lc].compName[3][n], "YX", 2) < 2 )) goto jumpStresses;
      if((compare(&lcase[lc].compName[4][n], "YZ", 2) < 2 ) && (compare(&lcase[lc].compName[4][n], "ZY", 2) < 2 )) goto jumpStresses;
      if((compare(&lcase[lc].compName[5][n], "ZX", 2) < 2 ) && (compare(&lcase[lc].compName[5][n], "XZ", 2) < 2 )) goto jumpStresses;
  
  
      /* check if related stress-phase-angles are available. */
      lcp=0;
      sprintf(buffer, "STRESP%c%c", lcase[lc].name[6], lcase[lc].name[7]);
      if((lc>=layers)&&( compare( lcase[lc-layers].name, buffer, strlen(buffer)) == strlen(buffer))&&(lcase[lc-layers].value==lcase[lc].value)) lcp=-layers;
  
      if(lcp!=0) printf("calculate additional values for %s regarding %s\n", lcase[lc].name, lcase[lc+lcp].name); 

      /* calc stresses in cylinder-system around x */
      strcpy ( lcase[lc].compName[0], "RR    ");
      strcpy ( lcase[lc].compName[1], "ZZ    ");
      strcpy ( lcase[lc].compName[2], "TT    ");
      strcpy ( lcase[lc].compName[3], "RZ    ");
      strcpy ( lcase[lc].compName[4], "ZT    ");
      strcpy ( lcase[lc].compName[5], "TR    ");

      for (i=0; i<anz->n; i++ ) if(!node[node[i].nr].pflag)
      {
        /* calc the node coordinates in r,phi,x */
        p1[0] = node[node[i].nr].nx* scale->w+scale->x;
        p1[1] = node[node[i].nr].ny* scale->w+scale->y;
        p1[2] = node[node[i].nr].nz* scale->w+scale->z;
        if((p1[dir[1]]!=0.)||(p1[dir[2]]!=0.))
        {
          phi= p_angle(p1[dir[2]], p1[dir[1]]);
  
          if(mode==1)
  	{
            r_mat[0][0]=1.;
            r_mat[0][1]=0.;
            r_mat[0][2]=0.;
            r_mat[1][0]=0.;
            r_mat[1][1]=cos(phi);
            r_mat[1][2]=sin(phi);
            r_mat[2][0]=0.;
            r_mat[2][1]=-sin(phi);
            r_mat[2][2]=cos(phi);
  	}
          else if(mode==2)
  	{
            r_mat[0][0]=cos(phi);
            r_mat[0][1]=0.;
            r_mat[0][2]=-sin(phi);
            r_mat[1][0]=0.;
            r_mat[1][1]=1.;
            r_mat[1][2]=0.;
            r_mat[2][0]=sin(phi);
            r_mat[2][1]=0.;
            r_mat[2][2]=cos(phi);
  	}
          else if(mode==3)
  	{
            r_mat[0][0]=cos(phi);
            r_mat[0][1]=sin(phi);
            r_mat[0][2]=0.;
            r_mat[1][0]=-sin(phi);
            r_mat[1][1]=cos(phi);
            r_mat[1][2]=0.;
            r_mat[2][0]=0.;
            r_mat[2][1]=0.;
            r_mat[2][2]=1.;
  	}
          else { printf("ERROR: axis not implemented so far\n"); return; }
  
          s_mat[0][0]= lcase[lc].dat[0][node[i].nr];//   xx;
          s_mat[0][1]= lcase[lc].dat[3][node[i].nr];//   xy;
          s_mat[0][2]= lcase[lc].dat[5][node[i].nr];//   zx;
                     
          s_mat[1][0]= lcase[lc].dat[3][node[i].nr];//   xy;
          s_mat[1][1]= lcase[lc].dat[1][node[i].nr];//   yy;
          s_mat[1][2]= lcase[lc].dat[4][node[i].nr];//   yz;
                    
          s_mat[2][0]= lcase[lc].dat[5][node[i].nr];//   zx;
          s_mat[2][1]= lcase[lc].dat[4][node[i].nr];//   yz;
          s_mat[2][2]= lcase[lc].dat[2][node[i].nr];//   zz;
      
          dim=3;
          m_prod( &dim, &r_mat[0][0], &s_mat[0][0], &prod_mat[0][0]);
          m_prodtr( &dim, &prod_mat[0][0], &r_mat[0][0], &s_mat[0][0]);
  
          if(mode==1)
          {
            lcase[lc].dat[0][node[i].nr]  = s_mat[2][2]; //rr
            lcase[lc].dat[1][node[i].nr]  = s_mat[0][0]; //zz
            lcase[lc].dat[2][node[i].nr]  = s_mat[1][1]; //tt
            lcase[lc].dat[3][node[i].nr]  = s_mat[0][2]; //rz
            lcase[lc].dat[4][node[i].nr]  = s_mat[1][0]; //zt
            lcase[lc].dat[5][node[i].nr]  = s_mat[1][2]; //tr 
          }
          else if(mode==2)
          {
            lcase[lc].dat[0][node[i].nr]  = s_mat[0][0]; //rr
            lcase[lc].dat[1][node[i].nr]  = s_mat[1][1]; //zz
            lcase[lc].dat[2][node[i].nr]  = s_mat[2][2]; //tt
            lcase[lc].dat[3][node[i].nr]  = s_mat[1][0]; //rz
            lcase[lc].dat[4][node[i].nr]  = s_mat[1][2]; //zt
            lcase[lc].dat[5][node[i].nr]  = s_mat[0][2]; //tr 
          }
          else if(mode==3)
          {
            lcase[lc].dat[0][node[i].nr]  = s_mat[1][1]; //rr
            lcase[lc].dat[1][node[i].nr]  = s_mat[2][2]; //zz
            lcase[lc].dat[2][node[i].nr]  = s_mat[0][0]; //tt
            lcase[lc].dat[3][node[i].nr]  = s_mat[1][2]; //rz
            lcase[lc].dat[4][node[i].nr]  = s_mat[0][2]; //zt
            lcase[lc].dat[5][node[i].nr]  = s_mat[1][0]; //tr 
          }
        }
        else
        {
          lcase[lc].dat[0][node[i].nr]  = 0;
          lcase[lc].dat[1][node[i].nr]  = 0;
          lcase[lc].dat[2][node[i].nr]  = 0;
          lcase[lc].dat[3][node[i].nr]  = 0;
          lcase[lc].dat[4][node[i].nr]  = 0;
          lcase[lc].dat[5][node[i].nr]  = 0;
        }
      }
 
      /* max and min */
      for(j=0; j<lcase[lc].ncomps; j++)
      {        
        lcase[lc].max[j]=-MAX_INTEGER;
        lcase[lc].min[j]=MAX_INTEGER;
        for (i=0; i<anz->n; i++ ) if(!node[node[i].nr].pflag)
        {
          if(lcase[lc].dat[j][node[i].nr] > lcase[lc].max[j])
          {
            lcase[lc].max[j]=lcase[lc].dat[j][node[i].nr];
            lcase[lc].nmax[j]=node[i].nr;
          }
          if(lcase[lc].dat[j][node[i].nr] < lcase[lc].min[j])
          {
            lcase[lc].min[j]=lcase[lc].dat[j][node[i].nr];
            lcase[lc].nmin[j]=node[i].nr;
          }
        }
      }
  
      goto fine;
      jumpStresses:;
      printf("ERROR: Entities of Dataset %d not suited for operation.\n", lc+1);
      fine:; 
    }
    else if ( lcase[lc].ictype[0] == 2) /* check first comp if its a vector (DISP, VELO etc.) */
    {  
      /* calculate rotated components  */
  
      for(i=0; i<lcase[lc].ncomps-1; i++)
      {
        sprintf( lcase[lc].compName[i], "DCYL%d  ",i+1);
      }
 
      for (i=0; i<anz->n; i++ ) if(!node[node[i].nr].pflag)
      {
        /* values will be projected in r,t,x direction of each node */
        /* normalized vectors in r,t,x */
        er[0] = node[node[i].nr].nx* scale->w+scale->x;
        er[1] = node[node[i].nr].ny* scale->w+scale->y;
        er[2] = node[node[i].nr].nz* scale->w+scale->z;
        er[dir[0]]= 0.;       
        v_norm(er,er);

        ex[dir[0]]=1.;       

        v_prod(ex, er, et);
        v_norm(et,et);

        /* projection of the value-vector in the rtx direction (|vproj|=v*e/|e|). */
        vval[0] =lcase[lc].dat[0][node[i].nr];
        vval[1] =lcase[lc].dat[1][node[i].nr];
        vval[2] =lcase[lc].dat[2][node[i].nr];
        dr=v_sprod(vval,er);
        dx=v_sprod(vval,ex);
        du=v_sprod(vval,et);
  
        // printf("n:%d rtx: %e %e %e\n", node[i].nr, dr, du, dx);
        lcase[lc].dat[0][node[i].nr]=dr;
        lcase[lc].dat[1][node[i].nr]=du;
        lcase[lc].dat[2][node[i].nr]=dx;
      }
  
      /* max and min */
      for(j=0; j<lcase[lc].ncomps; j++)
      {
        lcase[lc].max[j]=-MAX_INTEGER;
        lcase[lc].min[j]=MAX_INTEGER;
         for (i=0; i<anz->n; i++ ) if(!node[node[i].nr].pflag)
         {        
          if(lcase[lc].dat[j][node[i].nr] > lcase[lc].max[j])
          {
            lcase[lc].max[j]=lcase[lc].dat[j][node[i].nr];
            lcase[lc].nmax[j]=node[i].nr;
          }
          if(lcase[lc].dat[j][node[i].nr] < lcase[lc].min[j])
          {
            lcase[lc].min[j]=lcase[lc].dat[j][node[i].nr];
            lcase[lc].nmin[j]=node[i].nr;
          }
        }
      }
    }
    else { printf("ERROR: Dataset %d of type: %s not supported.\n", lc+1, lcase[lc].name); return; }
  }
  else if(compareStrings(method,"REC")>0)
  {
    //if(compare( lcase[lc].name, "STRESS", 6) == 6)
    if( lcase[lc].ictype[0] == 4) /* check first comp if its a tensor (STRESS) */
    {
      /* check if the STRESS has six valid components */
      if(lcase[lc].ncomps < 6 ) goto jumpStresses2;
      for (i=1; i<6; i++) if(lcase[lc].ictype[i] != 4 ) goto jumpStresses2;  
      n=0; while(((lcase[lc].compName[0][n]!='X')&&(lcase[lc].compName[0][n]!='R'))&&(n<6)) n++;
      //printf("n:%d %s\n", n, lcase[lc].compName[0]);
      if (compare(&lcase[lc].compName[0][n], "RR", 2) < 2 ) goto jumpStresses2;
      if (compare(&lcase[lc].compName[1][n], "ZZ", 2) < 2 ) goto jumpStresses2;
      if (compare(&lcase[lc].compName[2][n], "TT", 2) < 2 ) goto jumpStresses2;
      if (compare(&lcase[lc].compName[3][n], "RZ", 2) < 2 ) goto jumpStresses2;
      if (compare(&lcase[lc].compName[4][n], "ZT", 2) < 2 ) goto jumpStresses2;
      if (compare(&lcase[lc].compName[5][n], "TR", 2) < 2 ) goto jumpStresses2;
  
      strcpy ( lcase[lc].compName[0], "XX    ");
      strcpy ( lcase[lc].compName[1], "YY    ");
      strcpy ( lcase[lc].compName[2], "ZZ    ");
      strcpy ( lcase[lc].compName[3], "XY    ");
      strcpy ( lcase[lc].compName[4], "YZ    ");
      strcpy ( lcase[lc].compName[5], "ZX    ");

      for (i=0; i<anz->n; i++ ) if(!node[node[i].nr].pflag)
      {
        /* calc the node coordinates in r,phi,x */
        p1[0] = node[node[i].nr].nx* scale->w+scale->x;
        p1[1] = node[node[i].nr].ny* scale->w+scale->y;
        p1[2] = node[node[i].nr].nz* scale->w+scale->z;
        if((p1[dir[1]]!=0.)||(p1[dir[2]]!=0.))
        {
          phi= p_angle(p1[dir[2]], p1[dir[1]]) *-1;
  
          if(mode==1)
  	  {
            r_mat[0][0]=1.;
            r_mat[0][1]=0.;
            r_mat[0][2]=0.;
            r_mat[1][0]=0.;
            r_mat[1][1]=cos(phi);
            r_mat[1][2]=sin(phi);
            r_mat[2][0]=0.;
            r_mat[2][1]=-sin(phi);
            r_mat[2][2]=cos(phi);

            s_mat[0][0]= lcase[lc].dat[1][node[i].nr];//   xx; 
            s_mat[0][1]= lcase[lc].dat[4][node[i].nr];//   xy; 
            s_mat[0][2]= lcase[lc].dat[3][node[i].nr];//   zx; 
                       
            s_mat[1][0]= lcase[lc].dat[4][node[i].nr];//   xy; 
            s_mat[1][1]= lcase[lc].dat[2][node[i].nr];//   yy; 
            s_mat[1][2]= lcase[lc].dat[5][node[i].nr];//   yz; 
                      
            s_mat[2][0]= lcase[lc].dat[3][node[i].nr];//   zx; 
            s_mat[2][1]= lcase[lc].dat[5][node[i].nr];//   yz; 
            s_mat[2][2]= lcase[lc].dat[0][node[i].nr];//   zz; 
  	  }
          else if(mode==2)
  	  {
            r_mat[0][0]=cos(phi);
            r_mat[0][1]=0.;
            r_mat[0][2]=-sin(phi);
            r_mat[1][0]=0.;
            r_mat[1][1]=1.;
            r_mat[1][2]=0.;
            r_mat[2][0]=sin(phi);
            r_mat[2][1]=0.;
            r_mat[2][2]=cos(phi);

            s_mat[0][0]= lcase[lc].dat[0][node[i].nr];//   xx; 
            s_mat[0][1]= lcase[lc].dat[3][node[i].nr];//   xy; 
            s_mat[0][2]= lcase[lc].dat[5][node[i].nr];//   zx; 
                       
            s_mat[1][0]= lcase[lc].dat[3][node[i].nr];//   xy; 
            s_mat[1][1]= lcase[lc].dat[1][node[i].nr];//   yy; 
            s_mat[1][2]= lcase[lc].dat[4][node[i].nr];//   yz; 
                      
            s_mat[2][0]= lcase[lc].dat[5][node[i].nr];//   zx; 
            s_mat[2][1]= lcase[lc].dat[4][node[i].nr];//   yz; 
            s_mat[2][2]= lcase[lc].dat[2][node[i].nr];//   zz; 
  	  }
          else if(mode==3)
  	  {
            r_mat[0][0]=cos(phi);
            r_mat[0][1]=sin(phi);
            r_mat[0][2]=0.;
            r_mat[1][0]=-sin(phi);
            r_mat[1][1]=cos(phi);
            r_mat[1][2]=0.;
            r_mat[2][0]=0.;
            r_mat[2][1]=0.;
            r_mat[2][2]=1.;

            s_mat[0][0]= lcase[lc].dat[2][node[i].nr];//   xx; 
            s_mat[0][1]= lcase[lc].dat[5][node[i].nr];//   xy; 
            s_mat[0][2]= lcase[lc].dat[4][node[i].nr];//   zx; 
                       
            s_mat[1][0]= lcase[lc].dat[5][node[i].nr];//   xy; 
            s_mat[1][1]= lcase[lc].dat[0][node[i].nr];//   yy; 
            s_mat[1][2]= lcase[lc].dat[3][node[i].nr];//   yz; 
                      
            s_mat[2][0]= lcase[lc].dat[4][node[i].nr];//   zx; 
            s_mat[2][1]= lcase[lc].dat[3][node[i].nr];//   yz; 
            s_mat[2][2]= lcase[lc].dat[1][node[i].nr];//   zz; 
  	  }
          else { printf("ERROR: axis not implemented so far\n"); return; }
  
          dim=3;
          m_prod( &dim, &r_mat[0][0], &s_mat[0][0], &prod_mat[0][0]);
          m_prodtr( &dim, &prod_mat[0][0], &r_mat[0][0], &s_mat[0][0]);
  
  	  {
            lcase[lc].dat[0][node[i].nr]  = s_mat[0][0]; 
            lcase[lc].dat[1][node[i].nr]  = s_mat[1][1]; 
            lcase[lc].dat[2][node[i].nr]  = s_mat[2][2]; 
            lcase[lc].dat[3][node[i].nr]  = s_mat[1][0]; 
            lcase[lc].dat[4][node[i].nr]  = s_mat[1][2]; 
            lcase[lc].dat[5][node[i].nr]  = s_mat[0][2]; 
  	  }
        }
        else
        {
          lcase[lc].dat[0][node[i].nr]  = 0;
          lcase[lc].dat[1][node[i].nr]  = 0;
          lcase[lc].dat[2][node[i].nr]  = 0;
          lcase[lc].dat[3][node[i].nr]  = 0;
          lcase[lc].dat[4][node[i].nr]  = 0;
          lcase[lc].dat[5][node[i].nr]  = 0;
        }
      }
  
      /* max and min */
      for(j=0; j<lcase[lc].ncomps; j++)
      {
        lcase[lc].max[j]=-MAX_INTEGER;
        lcase[lc].min[j]=MAX_INTEGER;
        for (i=0; i<anz->n; i++ ) if(!node[node[i].nr].pflag)
        {        
          if(lcase[lc].dat[j][node[i].nr] > lcase[lc].max[j])
          {
            lcase[lc].max[j]=lcase[lc].dat[j][node[i].nr];
            lcase[lc].nmax[j]=node[i].nr;
          }
          if(lcase[lc].dat[j][node[i].nr] < lcase[lc].min[j])
          {
            lcase[lc].min[j]=lcase[lc].dat[j][node[i].nr];
            lcase[lc].nmin[j]=node[i].nr;
          }
        }
      }
  
      goto fine2;
      jumpStresses2:;
      printf("ERROR: Entities of Dataset %d not suited for operation.\n", lc+1);  
      fine2:; 
    }
    else if ( lcase[lc].ictype[0] == 2) /* check first comp if its a vector (DISP, VELO etc.) */
    {  
      /* calculate rotated displacements  */
  
      for(i=0; i<lcase[lc].ncomps-1; i++)
      {
        sprintf( lcase[lc].compName[i], "D%d     ",i+1);
      }
 
      for (i=0; i<anz->n; i++ ) if(!node[node[i].nr].pflag)
      {
        /* calc the node coordinates in r,phi,x */
        p1[0] = node[node[i].nr].nx* scale->w+scale->x;
        p1[1] = node[node[i].nr].ny* scale->w+scale->y;
        p1[2] = node[node[i].nr].nz* scale->w+scale->z;

        rad=sqrt(p1[dir[1]]*p1[dir[1]]+p1[dir[2]]*p1[dir[2]]);
        if(rad)
        {
          phi= p_angle(p1[dir[1]], p1[dir[2]]);
          //if(phi>PI) phi-=2*PI;
        }
        else phi=0.;

        if(mode==1)
	{
          dy=cos(phi)*lcase[lc].dat[0][node[i].nr] - sin(phi)*lcase[lc].dat[1][node[i].nr];
          dz=sin(phi)*lcase[lc].dat[0][node[i].nr] + cos(phi)*lcase[lc].dat[1][node[i].nr];
          dx=lcase[lc].dat[2][node[i].nr];
        }
        if(mode==2)
	{
          dz=cos(phi)*lcase[lc].dat[0][node[i].nr] - sin(phi)*lcase[lc].dat[1][node[i].nr];
          dx=sin(phi)*lcase[lc].dat[0][node[i].nr] + cos(phi)*lcase[lc].dat[1][node[i].nr];
          dy=lcase[lc].dat[2][node[i].nr];
        }
        if(mode==3)
	{
          dx=cos(phi)*lcase[lc].dat[0][node[i].nr] - sin(phi)*lcase[lc].dat[1][node[i].nr];
          dy=sin(phi)*lcase[lc].dat[0][node[i].nr] + cos(phi)*lcase[lc].dat[1][node[i].nr];
          dz=lcase[lc].dat[2][node[i].nr];
        }

        lcase[lc].dat[0][node[i].nr]=dx;
        lcase[lc].dat[1][node[i].nr]=dy;
        lcase[lc].dat[2][node[i].nr]=dz;
      }
  
      /* max and min */
      for(j=0; j<lcase[lc].ncomps; j++)
      {
        lcase[lc].max[j]=-MAX_INTEGER;
        lcase[lc].min[j]=MAX_INTEGER;
        for (i=0; i<anz->n; i++ ) if(!node[node[i].nr].pflag)
        {        
          if(lcase[lc].dat[j][node[i].nr] > lcase[lc].max[j])
          {
            lcase[lc].max[j]=lcase[lc].dat[j][node[i].nr];
            lcase[lc].nmax[j]=node[i].nr;
          }
          if(lcase[lc].dat[j][node[i].nr] < lcase[lc].min[j])
          {
            lcase[lc].min[j]=lcase[lc].dat[j][node[i].nr];
            lcase[lc].nmin[j]=node[i].nr;
          }
        }
      }
    }
    else { printf("ERROR: Dataset %d of type: %s not supported.\n", lc+1, lcase[lc].name); return; }
  }
  else
  {
    printf("ERROR: transformation %s not known\n", method);
    return;
  }

  /* store the transformation in a parameter */
  sprintf(buffer,"%s %s", method, axis);
  createDSparam(lc,"TRFM",buffer);
  calcDatasets( lc, anz, node, lcase );
}


void calcAnimation( int anim_steps, double anim_faktor, int *anim_alfa, int halfperiode, int centerNode, Summen *anz, Nodes *node, Elements *e_enqire, Datasets *lcase, int lc, Scale *scale, char surfFlag, double *colNr, int steps )
{
  int  i,l;
  int  foundDisp=0, mode=0, dir[3]={0.,0.,0.};
  double dwmax, amplitude, dalfa, alfa;
  double *colNr_anim=NULL, colour_offset=0.;
  Nodes     *n_anim=NULL;
  char method[MAX_LINE_LENGTH], axis[MAX_LINE_LENGTH];
  double p1[3], phi=0.,rad,dx,dy,dz,dxc=0.,dyc=0.,dzc=0.;

  if ( (colNr_anim = (double *)realloc((double *)colNr_anim, (anz->nmax+1) * sizeof(double))) == NULL )
    printf("\n\n ERROR: realloc failed colNr\n\n") ;
  colour_offset=((double)steps/(double)TEX_PIXELS*0.5);

  if ( (n_anim = (Nodes *)realloc((Nodes *)n_anim, (anz->nmax+1) * sizeof(Nodes))) == NULL )
    printf("\n\n ERROR: malloc failed n_anim\n");
  for ( i=0; i<anz->n; i++ ) { n_anim[node[i].nr].indx = i; n_anim[i].nr = node[i].nr; n_anim[node[i].nr].pflag = node[node[i].nr].pflag; }

  /* if the selected lc is not a disp lc, search a related disp lc */
  if((compare(lcase[lc].name, "DISP", 4)==4)||(compare(lcase[lc].name, "PDISP", 4)==4)) foundDisp=1;
  else
  {
    if(lc) { for (i=lc-1; i>=0; i--) { if(lcase[i].step_number!=lcase[lc].step_number) break; } i++; }
    else i=1;
    while((i<anz->l)&&(lcase[i].step_number==lcase[lc].step_number))
    {
      if((compare(lcase[i].name, "DISP", 4)==4)||(compare(lcase[i].name, "PDISP", 4)==4))
      {
        lc=i;
        foundDisp=1;

        /* check if the data of the specified lcase (Dataset) are already available */
        if (!lcase[lc].loaded)
        {
          if( pre_readfrdblock(copiedNodeSets , lc, anz, node, lcase )==-1) 
          {
            printf("ERROR in nodalDataset: Could not read data for Dataset:%d\n", lc+1); 
            return;
          }
          calcDatasets( lc, anz, node, lcase );
        }
        break;
      }
      i++;
    }
  }

  if(foundDisp==1)
  {
    for(i=0;i<lcase[lc].npheader; i++)
    {
      if(compare(&lcase[lc].pheader[i][5],"PTRFM", 5)==5)
      {
        sscanf(lcase[lc].pheader[i],"%*s %s %s", method, axis);
        printf("trfm %s %s", method, axis);
        if(compare(method, "CYL", 3) == 3)
        {
          if (toupper(axis[0])=='X')      mode =1;
          else if (toupper(axis[0])=='Y') mode =2;
          else if (toupper(axis[0])=='Z') mode =3;
          if(mode==1) { dir[0]=0; dir[1]=1; dir[2]=2; }
          else if(mode==2) { dir[0]=1; dir[1]=2; dir[2]=0; }
          else if(mode==3) { dir[0]=2; dir[1]=0; dir[2]=1; }
        }
        break;
      }
    }
  }

  if (lcase[lc].ictype[0]!=12)
  {
    /* feld fuer Bildbeschriftung  */
    dalfa=2.*PI/anim_steps;
    alfa=0;
    for ( l=0; l<anim_steps; l++ )
    {
      anim_alfa[l]=sin(alfa) *100;
      alfa+= dalfa;
    }

    /* scalierungsfaktor  */
    if (!halfperiode)
    {
      dwmax=lcase[lc].max[0];
      if(foundDisp)
      {
        if (dwmax < lcase[lc].max[1]) { dwmax=lcase[lc].max[1];}
        if (dwmax < lcase[lc].max[2]) { dwmax=lcase[lc].max[2];}
        if (dwmax < -lcase[lc].min[0]) { dwmax=-lcase[lc].min[0];}
        if (dwmax < -lcase[lc].min[1]) { dwmax=-lcase[lc].min[1];}
        if (dwmax < -lcase[lc].min[2]) { dwmax=-lcase[lc].min[2];}
      }
      dwmax*=20.;
      dwmax=1./dwmax;
    }
    else dwmax=1./scale->w;

    /* anlegen der Displaylisten von pi/2 bis pi*3/4  */
    alfa = PI/2.;
    for ( l=anim_steps/4+1; l<anim_steps*3/4+2; l++ )
    {
      amplitude= anim_faktor * sin(alfa) * dwmax;
      printf (" phi:%lf amplitude:%lf\n", alfa*180./PI, amplitude );

      if (!halfperiode)
      {
        for ( i=0; i<anz->n; i++ )
        {
          colNr_anim[node[i].nr] = colNr[node[i].nr]*0.5* sin(alfa) +colour_offset;
        }
      }
      else
      {
        if(sin(alfa)>=0)
	{
          for ( i=0; i<anz->n; i++ )
          {
            colNr_anim[node[i].nr] = colNr[node[i].nr]* sin(alfa);
          }
	}
        else
	{
          for ( i=0; i<anz->n; i++ )
          {
            colNr_anim[node[i].nr] = 0.;
          }
	}
      }
      if (foundDisp)
      {
        for ( i=0; i<anz->n; i++ ) if(!node[node[i].nr].pflag)
        {
          if(mode==0)
          {
            dx=lcase[lc].dat[0][node[i].nr];
            dy=lcase[lc].dat[1][node[i].nr];
            dz=lcase[lc].dat[2][node[i].nr];
          }
          else
	  {
            /* calc the node coordinates in r,phi,x */
            p1[0] = node[node[i].nr].nx* scale->w+scale->x;
            p1[1] = node[node[i].nr].ny* scale->w+scale->y;
            p1[2] = node[node[i].nr].nz* scale->w+scale->z;
  
            rad=sqrt(p1[dir[1]]*p1[dir[1]]+p1[dir[2]]*p1[dir[2]]);
            if(rad)
            {
              phi= p_angle(p1[dir[1]], p1[dir[2]]);
              //if(phi>PI) phi-=2*PI;
            }
            else phi=0.;
    
            if(mode==1)
            {
              dy=cos(phi)*lcase[lc].dat[0][node[i].nr] - sin(phi)*lcase[lc].dat[1][node[i].nr];
              dz=sin(phi)*lcase[lc].dat[0][node[i].nr] + cos(phi)*lcase[lc].dat[1][node[i].nr];
              dx=lcase[lc].dat[2][node[i].nr];
            }
            else if(mode==2)
            {
              dz=cos(phi)*lcase[lc].dat[0][node[i].nr] - sin(phi)*lcase[lc].dat[1][node[i].nr];
              dx=sin(phi)*lcase[lc].dat[0][node[i].nr] + cos(phi)*lcase[lc].dat[1][node[i].nr];
              dy=lcase[lc].dat[2][node[i].nr];
            }
            else if(mode==3)
            {
              dx=cos(phi)*lcase[lc].dat[0][node[i].nr] - sin(phi)*lcase[lc].dat[1][node[i].nr];
              dy=sin(phi)*lcase[lc].dat[0][node[i].nr] + cos(phi)*lcase[lc].dat[1][node[i].nr];
              dz=lcase[lc].dat[2][node[i].nr];
            }
	  }

          n_anim[node[i].nr].indx = i;
          n_anim[i].nr = node[i].nr;
          n_anim[node[i].nr].pflag = node[node[i].nr].pflag;
          n_anim[node[i].nr].nx = node[node[i].nr].nx + dx * amplitude;
          n_anim[node[i].nr].ny = node[node[i].nr].ny + dy * amplitude;
          n_anim[node[i].nr].nz = node[node[i].nr].nz + dz * amplitude;
          if(node[i].nr==centerNode)
          {
            dxc=dx;
            dyc=dy;
            dzc=dz;
	  }
        }

        /* wenn ein centernode existiert (centerNode!=0), fixiere diesen */
        if(centerNode)
	{
          for ( i=0; i<anz->n; i++ ) if(!node[node[i].nr].pflag)
          {
            n_anim[node[i].nr].nx-= dxc * amplitude;
            n_anim[node[i].nr].ny-= dyc * amplitude;
            n_anim[node[i].nr].nz-= dzc * amplitude;
          }
        }

        /* calculate the position of the additional drawing nodes in the deformed mesh */
        posMidsideNodes(n_anim);  

        if(surfFlag)
	{
          getFaceNormalen( face, n_anim, anz );
          drawDispList( (list_anim_light+l), 'f', n_anim, colNr_anim);
          drawDispListEdges(list_anim_surf_edges+l, basCol[0], 1., 'f', n_anim );
	}
        else
	{
          getElemNormalen( e_enqire, n_anim, anz->e );
          drawDispList( (list_anim_light+l), 'e', n_anim, colNr_anim);     
          drawDispListEdges(list_anim_elem_edges+l, basCol[0], 1., 'e', n_anim );
	}
        drawModelEdges( list_anim_model_edges+l, basCol[0], edgeWidth, anz->g, n_anim );
      }
      else
      {
        if(surfFlag)
	{
          drawDispList( (list_anim_light+l), 'f', node, colNr_anim);
          drawDispListEdges(list_anim_surf_edges+l, basCol[0], 1., 'f', node );
	}
        else
	{
          drawDispList( (list_anim_light+l), 'e', node, colNr_anim);     
          drawDispListEdges(list_anim_elem_edges+l, basCol[0], 1., 'e', node );
	}
        drawModelEdges( list_anim_model_edges+l, basCol[0], edgeWidth, anz->g, node );
      }
      alfa+= dalfa;
    }

    /* anlegen des Displaylistenfeldes ueber eine volle Periode  */
    if ( (list_animate = (GLuint *)realloc( list_animate, (anim_steps) * sizeof(GLuint))) == NULL )
      printf("\n\n ERROR: realloc failure\n\n" );
    if ( (list_animate_model_edges = (GLuint *)realloc(list_animate_model_edges, (anim_steps) * sizeof(GLuint))) == NULL )
      printf("\n\n ERROR: realloc failure\n\n" );
    if ( (list_animate_surf_edges = (GLuint *)realloc(list_animate_surf_edges, (anim_steps) * sizeof(GLuint))) == NULL )
      printf("\n\n ERROR: realloc failure\n\n" );
    if ( (list_animate_elem_edges = (GLuint *)realloc(list_animate_elem_edges, (anim_steps) * sizeof(GLuint))) == NULL )
      printf("\n\n ERROR: realloc failure\n\n" );
    if (!halfperiode)
    {
      for ( l=0; l<anim_steps*1/4; l++ )
      {
        list_animate[l] = list_anim_light+(anim_steps*2/4+1) -l ;
        list_animate_model_edges[l] = list_anim_model_edges+(anim_steps*2/4+1) -l ;
        list_animate_surf_edges[l] = list_anim_surf_edges+(anim_steps*2/4+1) -l ;
        list_animate_elem_edges[l] = list_anim_elem_edges+(anim_steps*2/4+1) -l ;
      }
      for ( l=anim_steps/4; l<anim_steps*3/4+1; l++ )
      {
        list_animate[l] = list_anim_light+l+1;
        list_animate_model_edges[l] = list_anim_model_edges+l+1;
        list_animate_surf_edges[l] = list_anim_surf_edges+l+1 ;
        list_animate_elem_edges[l] = list_anim_elem_edges+l+1 ;
      }
      for ( l=anim_steps*3/4+1; l<anim_steps; l++ )
      {
        list_animate[l] = list_anim_light+(anim_steps*3/4+1) -(l-(anim_steps*3/4));
        list_animate_model_edges[l] = list_anim_model_edges+(anim_steps*3/4+1) -(l-(anim_steps*3/4)) ;
        list_animate_surf_edges[l] = list_anim_surf_edges+ (anim_steps*3/4+1) -(l-(anim_steps*3/4));
        list_animate_elem_edges[l] = list_anim_elem_edges+ (anim_steps*3/4+1) -(l-(anim_steps*3/4)) ;
      }
    }
    else
    {
      for ( l=0; l<anim_steps*1/4; l++ )
      {
        list_animate[l] = list_anim_light+(anim_steps*2/4+1) -l ;
        list_animate_model_edges[l] = list_anim_model_edges+(anim_steps*2/4+1) -l ;
        list_animate_surf_edges[l] = list_anim_surf_edges+(anim_steps*2/4+1) -l ;
        list_animate_elem_edges[l] = list_anim_elem_edges+(anim_steps*2/4+1) -l ;
      }
      for ( l=anim_steps/4; l<anim_steps*1/2+1; l++ )
      {
        list_animate[l] = list_anim_light+l+1;
        list_animate_model_edges[l] = list_anim_model_edges+l+1 ;
        list_animate_surf_edges[l] = list_anim_surf_edges+l+1 ;
        list_animate_elem_edges[l] = list_anim_elem_edges+l+1 ;
      }
      for ( l=anim_steps*2/4+1; l<anim_steps; l++ )
      {
        list_animate[l] = list_anim_light+anim_steps*1/2+1;
        list_animate_model_edges[l] = list_anim_model_edges+ anim_steps*1/2+1;
        list_animate_surf_edges[l] = list_anim_surf_edges+ anim_steps*1/2+1 ;
        list_animate_elem_edges[l] = list_anim_elem_edges+ anim_steps*1/2+1 ;
      }
    }
  }
  else if (lcase[lc].ictype[0]== 12)
  {
    /* feld fuer Bildbeschriftung  */
    dalfa=2.*PI/anim_steps;
    alfa=0.;
    for ( l=0; l<anim_steps; l++ )
    {
      anim_alfa[l]=sin(alfa) *100;
      alfa+= dalfa;
    }

    /* scalierungsfaktor  */
    if (!halfperiode)
    {
      dwmax=lcase[lc].max[0];
      if (dwmax < lcase[lc].max[1]){ dwmax=lcase[lc].max[1];}
      if (dwmax < lcase[lc].max[2]){ dwmax=lcase[lc].max[2];}
      if (dwmax < -lcase[lc].min[0]){ dwmax=-lcase[lc].min[0];}
      if (dwmax < -lcase[lc].min[1]){ dwmax=-lcase[lc].min[1];}
      if (dwmax < -lcase[lc].min[2]){ dwmax=-lcase[lc].min[2];}
      dwmax*=20.;
      dwmax =1./dwmax;
    }
    else dwmax=1./scale->w;

    /* anlegen der Displaylisten von 0 bis 2*pi  */
    alfa=-dalfa;
    if ( (list_animate = (GLuint *)realloc( list_animate, (anim_steps+1) * sizeof(GLuint))) == NULL )
      printf("\n\n ERROR: realloc failure\n\n" );
    if ( (list_animate_model_edges = (GLuint *)realloc(list_animate_model_edges, (anim_steps+1) * sizeof(GLuint))) == NULL )
      printf("\n\n ERROR: realloc failure\n\n" );
    if ( (list_animate_surf_edges = (GLuint *)realloc(list_animate_surf_edges, (anim_steps+1) * sizeof(GLuint))) == NULL )
      printf("\n\n ERROR: realloc failure\n\n" );
    if ( (list_animate_elem_edges = (GLuint *)realloc(list_animate_elem_edges, (anim_steps+1) * sizeof(GLuint))) == NULL )
      printf("\n\n ERROR: realloc failure\n\n" );

    for ( l=0; l<anim_steps; l++ )
    {
      alfa+= dalfa;
      amplitude= anim_faktor * cos(alfa) * dwmax;
      printf (" phi:%lf amplitude:%lf \n", alfa*180./PI, amplitude);

      for ( i=0; i<anz->n; i++ ) if(!node[node[i].nr].pflag)
      {
        n_anim[node[i].nr].nx = node[node[i].nr].nx + (lcase[lc].dat[0][node[i].nr] *
                                anim_faktor * cos(alfa+PI/180.*lcase[lc].dat[3][node[i].nr]) * dwmax);
        n_anim[node[i].nr].ny = node[node[i].nr].ny + (lcase[lc].dat[1][node[i].nr] *
                                anim_faktor * cos(alfa+PI/180.*lcase[lc].dat[4][node[i].nr]) * dwmax);
        n_anim[node[i].nr].nz = node[node[i].nr].nz + (lcase[lc].dat[2][node[i].nr] *
                                anim_faktor * cos(alfa+PI/180.*lcase[lc].dat[5][node[i].nr]) * dwmax);
      }

      /* wenn ein centernode existiert (centerNode!=0), fixiere diesen */
      if(centerNode)
      {
        for ( i=0; i<anz->n; i++ ) if(!node[node[i].nr].pflag)
        {
          n_anim[node[i].nr].nx-= lcase[lc].dat[0][centerNode] *
           anim_faktor * cos(alfa+PI/180.*lcase[lc].dat[3][centerNode]) * dwmax ;
          n_anim[node[i].nr].ny-= lcase[lc].dat[1][centerNode] *
           anim_faktor * cos(alfa+PI/180.*lcase[lc].dat[4][centerNode]) * dwmax;
          n_anim[node[i].nr].nz-= lcase[lc].dat[2][centerNode] *
           anim_faktor * cos(alfa+PI/180.*lcase[lc].dat[5][centerNode]) * dwmax;
        }
      }

      /* calculate the position of the additional drawing nodes in the deformed mesh */
      posMidsideNodes(n_anim);

      for ( i=0; i<anz->n; i++ )
      {
        colNr_anim[node[i].nr] = colNr[node[i].nr]*0.5* sin(alfa) +colour_offset;
      }

      if(surfFlag)
      {
        getFaceNormalen( face, n_anim, anz );
        drawDispList( (list_anim_light+l), 'f', n_anim, colNr_anim);
        drawDispListEdges(list_anim_surf_edges+l, basCol[0], 1., 'f', n_anim );
      }
      else
      {
        getElemNormalen( e_enqire, n_anim, anz->e );
        drawDispList( (list_anim_light+l), 'e', n_anim, colNr_anim);     
        drawDispListEdges(list_anim_elem_edges+l, basCol[0], 1., 'e', n_anim );
      }
      drawModelEdges( list_anim_model_edges+l, basCol[0], edgeWidth, anz->g, n_anim );

      list_animate[l] = list_anim_light+l;
      list_animate_model_edges[l] = list_anim_model_edges+l;
      list_animate_surf_edges[l] = list_anim_surf_edges+l;
      list_animate_elem_edges[l] = list_anim_elem_edges+l;
    }
  }
  else
    errMsg ("\n ERROR: Animation only for displacements!\n");

  free(colNr_anim);
}



void calcSequence( DsSequence dsSequence, double anim_faktor, int halfperiode, int centerNode, Summen *anz, Nodes *node, Elements *e_enqire, Datasets *lcase, Scale *scale, char surfFlag, double *colNr, int steps, int lcase_animList, int dispFlag )
{
  int  i,l;
  int  s, lc=0, lcv, foundDisp=0, mode=0, dir[3]={0.,0.,0.};
  double dwmax, amplitude;
  Nodes     *n_anim=NULL;
  char method[MAX_LINE_LENGTH], axis[MAX_LINE_LENGTH];
  double p1[3], phi=0.,rad,dx,dy,dz,dxc=0.,dyc=0.,dzc=0.;

  if ( (n_anim = (Nodes *)realloc((Nodes *)n_anim, (anz->nmax+1) * sizeof(Nodes))) == NULL )
    printf("\n\n ERROR: malloc failed n_anim\n");
  for ( i=0; i<anz->n; i++ ) { n_anim[node[i].nr].indx = i; n_anim[i].nr = node[i].nr; n_anim[node[i].nr].pflag = node[node[i].nr].pflag; }

  /* load missing data */
  printf (" please wait, loading data\n");
  dwmax=scale->w;
  for(s=0; s<dsSequence.nds; s++)
  {
    lcv=dsSequence.ds[s];

    /* if the selected lc is not a disp lc, search a related disp lc */
    foundDisp=0;
    if((compare(lcase[lcv].name, "DISP", 4)==4)&&(lcase[lcv].ictype[0]!= 12)) { lc=lcv; foundDisp=1; }
    else
    {
      //if(lc>0) { i=lc-1; while((lcase[i].step_number==lcase[lc].step_number)&&(i>0)) i--; i++; }
      if(lcv) { for (i=lcv-1; i>=0; i--) { if(lcase[i].step_number!=lcase[lcv].step_number) break; } i++; }
      else i=1;
      while((i<anz->l)&&(lcase[i].step_number==lcase[lcv].step_number))
      {
        if((compare(lcase[i].name, "DISP", 4)==4)&&(lcase[i].ictype[0]!= 12))
        {
          lc=i;
          foundDisp=1;
  
          /* check if the data of the specified lcase (Dataset) are already available */
          if (!lcase[lc].loaded)
          {
            if( pre_readfrdblock(copiedNodeSets , lc, anz, node, lcase )==-1) 
            {
              printf("ERROR in nodalDataset: Could not read data for Dataset:%d\n", lc+1); 
              return;
            }
            calcDatasets( lc, anz, node, lcase );
          }
          break;
    	  }
        i++;
      }
    }

    if (foundDisp)
    {
      if (!lcase[lc].loaded)
      {
        if( pre_readfrdblock(copiedNodeSets , lc, anz, node, lcase )==-1) 
        {
          printf("ERROR in calcSequence: Could not read data for Dataset:%d\n", lc+1); 
          return;
        }
        calcDatasets( lc, anz, node, lcase );
      }

      /* scalierungsfaktor  */
      if (!halfperiode)
      {
      dwmax=lcase[lc].max[0];
      if (dwmax <  lcase[lc].max[1]){ dwmax=lcase[lc].max[1];}
      if (dwmax <  lcase[lc].max[2]){ dwmax=lcase[lc].max[2];}
      if (dwmax < -lcase[lc].min[0]){ dwmax=-lcase[lc].min[0];}
      if (dwmax < -lcase[lc].min[1]){ dwmax=-lcase[lc].min[1];}
      if (dwmax < -lcase[lc].min[2]){ dwmax=-lcase[lc].min[2];}
      dwmax*=20.;
      }
    }
  }

  /* second loop */
  if(dwmax!=0) amplitude= anim_faktor/dwmax; else amplitude=0.;
  l=0;
  for(s=0; s<dsSequence.nds; s++)
  {
    lcv=dsSequence.ds[s];
    //printf (" disp-list:%d ds:%d time:%lf text:%s\n", l+1, lcv+1, lcase[lcv].value, lcase[lcv].dataset_text );
    sprintf(lcase[lcase_animList].compName[s], lcase[lcv].compName[cur_entity]);

    /* if the selected lc is not a disp lc, search a related disp lc */
    foundDisp=0;
    if((compare(lcase[lcv].name, "DISP", 4)==4)&&(lcase[lcv].ictype[0]!= 12)) { lc=lcv; foundDisp=1; }
    else
    {
      //if(lc>0) { i=lc-1; while((lcase[i].step_number==lcase[lc].step_number)&&(i>0)) i--; i++; }
      if(lcv) { for (i=lcv-1; i>=0; i--) { if(lcase[i].step_number!=lcase[lcv].step_number) break; } i++; }
      else i=1;
      while((i<anz->l)&&(lcase[i].step_number==lcase[lcv].step_number))
      {
        if((compare(lcase[i].name, "DISP", 4)==4)&&(lcase[i].ictype[0]!= 12))
        {
          lc=i;
          foundDisp=1;
  
          /* check if the data of the specified lcase (Dataset) are already available */
          if (!lcase[lc].loaded)
          {
            if( pre_readfrdblock(copiedNodeSets , lc, anz, node, lcase )==-1) 
            {
              printf("ERROR in nodalDataset: Could not read data for Dataset:%d\n", lc+1); 
              return;
            }
            calcDatasets( lc, anz, node, lcase );
          }
          break;
        }
        i++;
      }
    }

    if (lcase[lcv].irtype == 3)
    {
      printf("ERROR: Element data not supported\n"); exit(1);
    }
    else
    { 
      nodalDataset( cur_entity, lcv, anz, scale, node, lcase, colNr, 1 );
      /* datafield for pick */
      //printf("lc:%d e:%d\n",  lcase_animList, l+1);
      for(i=1; i<=anz->nmax; i++) lcase[lcase_animList].dat[l][i]=lcase[lcv].dat[cur_entity][i];
    }

    if ( (list_animate = (GLuint *)realloc( list_animate, (l+1) * sizeof(GLuint))) == NULL )
      printf("\n\n ERROR: realloc failure\n\n" );
    if ( (list_animate_model_edges = (GLuint *)realloc(list_animate_model_edges, (l+1) * sizeof(GLuint))) == NULL )
      printf("\n\n ERROR: realloc failure\n\n" );
    if ( (list_animate_surf_edges = (GLuint *)realloc(list_animate_surf_edges, (l+1) * sizeof(GLuint))) == NULL )
      printf("\n\n ERROR: realloc failure\n\n" );
    if ( (list_animate_elem_edges = (GLuint *)realloc(list_animate_elem_edges, (l+1) * sizeof(GLuint))) == NULL )
      printf("\n\n ERROR: realloc failure\n\n" );
    list_animate[l]=list_anim_light+l;
    list_animate_model_edges[l] = list_anim_model_edges+l;
    list_animate_surf_edges[l] = list_anim_surf_edges+l;
    list_animate_elem_edges[l] = list_anim_elem_edges+l;

    if ((foundDisp)&&(dispFlag))
    {
      mode=0;
      for(i=0;i<lcase[lc].npheader; i++)
      {
        if(compare(&lcase[lc].pheader[i][5],"PTRFM", 5)==5)
        {
          sscanf(lcase[lc].pheader[i],"%*s %s %s", method, axis);
          printf("trfm %s %s", method, axis);
          if(compare(method, "CYL", 3) == 3)
          {
            if (toupper(axis[0])=='X')      mode =1;
            else if (toupper(axis[0])=='Y') mode =2;
            else if (toupper(axis[0])=='Z') mode =3;
            if(mode==1) { dir[0]=0; dir[1]=1; dir[2]=2; }
            else if(mode==2) { dir[0]=1; dir[1]=2; dir[2]=0; }
            else if(mode==3) { dir[0]=2; dir[1]=0; dir[2]=1; }
          }
          break;
        }
      }

      //printf("add ds:%d\n", lc+1);
      for ( i=0; i<anz->n; i++ ) if(!node[node[i].nr].pflag)
      {
        if(mode==0)
        {
          dx=lcase[lc].dat[0][node[i].nr];
          dy=lcase[lc].dat[1][node[i].nr];
          dz=lcase[lc].dat[2][node[i].nr];
        }
        else
	  {
          /* calc the node coordinates in r,phi,x */
          p1[0] = node[node[i].nr].nx* scale->w+scale->x;
          p1[1] = node[node[i].nr].ny* scale->w+scale->y;
          p1[2] = node[node[i].nr].nz* scale->w+scale->z;

          rad=sqrt(p1[dir[1]]*p1[dir[1]]+p1[dir[2]]*p1[dir[2]]);
          if(rad)
          {
            phi= p_angle(p1[dir[1]], p1[dir[2]]);
            //if(phi>PI) phi-=2*PI;
          }
          else phi=0.;
  
          if(mode==1)
          {
            dy=cos(phi)*lcase[lc].dat[0][node[i].nr] - sin(phi)*lcase[lc].dat[1][node[i].nr];
            dz=sin(phi)*lcase[lc].dat[0][node[i].nr] + cos(phi)*lcase[lc].dat[1][node[i].nr];
            dx=lcase[lc].dat[2][node[i].nr];
          }
          else if(mode==2)
          {
            dz=cos(phi)*lcase[lc].dat[0][node[i].nr] - sin(phi)*lcase[lc].dat[1][node[i].nr];
            dx=sin(phi)*lcase[lc].dat[0][node[i].nr] + cos(phi)*lcase[lc].dat[1][node[i].nr];
            dy=lcase[lc].dat[2][node[i].nr];
          }
          else if(mode==3)
          {
            dx=cos(phi)*lcase[lc].dat[0][node[i].nr] - sin(phi)*lcase[lc].dat[1][node[i].nr];
            dy=sin(phi)*lcase[lc].dat[0][node[i].nr] + cos(phi)*lcase[lc].dat[1][node[i].nr];
            dz=lcase[lc].dat[2][node[i].nr];
          }
        }
        n_anim[node[i].nr].nx = node[node[i].nr].nx + dx * amplitude;
        n_anim[node[i].nr].ny = node[node[i].nr].ny + dy * amplitude;
        n_anim[node[i].nr].nz = node[node[i].nr].nz + dz * amplitude;
        if(node[i].nr==centerNode)
        {
          dxc=dx;
          dyc=dy;
          dzc=dz;
	}
      }

      /* wenn ein centernode existiert (centerNode!=0), fixiere diesen */
      if(centerNode)
      {
        for ( i=0; i<anz->n; i++ ) if(!node[node[i].nr].pflag)
        {
          n_anim[node[i].nr].nx-= dxc * amplitude;
          n_anim[node[i].nr].ny-= dyc * amplitude;
          n_anim[node[i].nr].nz-= dzc * amplitude;
        }
      }

      /* calculate the position of the additional drawing nodes in the deformed mesh */
      posMidsideNodes(n_anim);  

      if(surfFlag)
      {
        getFaceNormalen( face, n_anim, anz );
        drawDispList( (list_anim_light+l), 'f', n_anim, colNr);
        drawDispListEdges(list_anim_surf_edges+l, basCol[0], 1., 'f', n_anim );
      }
      else
      {
        getElemNormalen( e_enqire, n_anim, anz->e );
        drawDispList( (list_anim_light+l), 'e', n_anim, colNr);     
        drawDispListEdges(list_anim_elem_edges+l, basCol[0], 1., 'e', n_anim );
      }
      drawModelEdges( list_anim_model_edges+l, basCol[0], edgeWidth, anz->g, n_anim );
    }
    else
    {
      if(surfFlag)
      {
        drawDispList( (list_anim_light+l), 'f', node, colNr);
        drawDispListEdges(list_anim_surf_edges+l, basCol[0], 1., 'f', node );
      }
      else
      {
        drawDispList( (list_anim_light+l), 'e', node, colNr);     
        drawDispListEdges(list_anim_elem_edges+l, basCol[0], 1., 'e', node );
      }
      drawModelEdges( list_anim_model_edges+l, basCol[0], edgeWidth, anz->g, node );
    }
    l++; 
  }
}



void generateDataset( Summen *anz, Datasets **ptr_lcase, char *name, int ncomps, double value, char *dataset_text, int analysis_type, int step_number, char *analysis_name)
{
  int i,n;
  int anz_l;
  Datasets *lcase;

  lcase=*ptr_lcase;

  /* change the current dataset if ncomps==0 */
  if(!ncomps)
  {
    printf (" change dataset: %d\n", cur_lc+1);
    anz_l=anz->l;
    anz->l=cur_lc;
  }
  else
  {
    printf (" create new dataset\n");

    /* create a new dataset */
    if ( (lcase = (Datasets *)realloc((Datasets *)lcase, (anz->l+1) * sizeof(Datasets))) == NULL )
      printf("\n\n ERROR: malloc failure\n\n" );

    lcase[anz->l].ncomps = ncomps;
    lcase[anz->l].irtype = 1;
    lcase[anz->l].npheader=0 ;
    lcase[anz->l].loaded = 1;
    lcase[anz->l].fileptr = NULL;
    sprintf( lcase[anz->l].dataset_name, "user");

    if ( (lcase[anz->l].nmax = (int *)malloc( lcase[anz->l].ncomps * sizeof(int))) == NULL )
      printf("\n\n ERROR: malloc failure\n\n" );
    if ( (lcase[anz->l].nmin = (int *)malloc( lcase[anz->l].ncomps * sizeof(int))) == NULL )
      printf("\n\n ERROR: malloc failure\n\n" );
    if ( (lcase[anz->l].max = (float *)malloc( lcase[anz->l].ncomps * sizeof(float))) == NULL )
      printf("\n\n ERROR: malloc failure\n\n" );
    if ( (lcase[anz->l].min = (float *)malloc( lcase[anz->l].ncomps * sizeof(float))) == NULL )
      printf("\n\n ERROR: malloc failure\n\n" );
    if ( (lcase[anz->l].dat = (float **)malloc( lcase[anz->l].ncomps * sizeof(float *))) == NULL )
      printf("\n\n ERROR: malloc failure\n\n" );
    if ( (lcase[anz->l].compName = (char **)malloc( lcase[anz->l].ncomps * sizeof(char *))) == NULL )
      printf("\n\n ERROR: malloc failure\n\n" );
    if ( (lcase[anz->l].icname = (char **)malloc( lcase[anz->l].ncomps * sizeof(char *))) == NULL )
      printf("\n\n ERROR: malloc failure\n\n" );
    for(i=0; i<lcase[anz->l].ncomps; i++)
    {
      if ( (lcase[anz->l].dat[i] = (float *)malloc( (anz->nmax+1) * sizeof(float))) == NULL )
        printf("\n\n ERROR: malloc failure\n\n" );	               
      if ( (lcase[anz->l].compName[i] = (char *)malloc( MAX_LINE_LENGTH * sizeof(char))) == NULL )
         printf("\n\n ERROR: malloc failed\n\n" );
      if ( (lcase[anz->l].icname[i] = (char *)malloc( MAX_LINE_LENGTH * sizeof(char))) == NULL )
         printf("\n\n ERROR: malloc failed\n\n" );
      lcase[anz->l].max[i]=-MAX_INTEGER;
      lcase[anz->l].min[i]=MAX_INTEGER;
      for(n=0; n<=anz->nmax; n++)
        lcase[anz->l].dat[i][n]=0.;
    }
    if ( (lcase[anz->l].menu = (int *)malloc( lcase[anz->l].ncomps * sizeof(int))) == NULL )
      printf("\n\n ERROR: malloc failure\n\n" );
    if ( (lcase[anz->l].ictype = (int *)malloc( lcase[anz->l].ncomps * sizeof(int))) == NULL )
      printf("\n\n ERROR: malloc failure\n\n" );
    if ( (lcase[anz->l].icind1 = (int *)malloc( lcase[anz->l].ncomps * sizeof(int))) == NULL )
      printf("\n\n ERROR: malloc failure\n\n" );
    if ( (lcase[anz->l].icind2 = (int *)malloc( lcase[anz->l].ncomps * sizeof(int))) == NULL )
      printf("\n\n ERROR: malloc failure\n\n" );
    if ( (lcase[anz->l].iexist = (int *)malloc( lcase[anz->l].ncomps * sizeof(int))) == NULL )
      printf("\n\n ERROR: malloc failure\n\n" );
    for(i=0; i<lcase[anz->l].ncomps; i++)
    {
      lcase[anz->l].menu[i] = 1;
      lcase[anz->l].ictype[i] = 1;
      lcase[anz->l].icind1[i] = 1;
      lcase[anz->l].icind2[i] = 0;
      lcase[anz->l].iexist[i] = 0;
      sprintf( lcase[anz->l].compName[i],"unused");
    }
  }
  lcase[anz->l].value  = value;
  strcpy(lcase[anz->l].name, name) ;
  strcpy(lcase[anz->l].dataset_text, dataset_text);
  strcpy(lcase[anz->l].analysis_name, analysis_name);
  lcase[anz->l].step_number= step_number;
  lcase[anz->l].analysis_type=analysis_type;

  if(!ncomps)
  {
    anz->l=anz_l;
  }
  else
  {
    *ptr_lcase=lcase;
    cur_lc=anz->l;
    anz->l++;
  }
}


int defineEntity( Summen *anz, Datasets *lcase, Nodes *node, char *name, int ncomp, int ictype, int row, int column)
{
  //int i,n;

  if(ncomp>lcase[cur_lc].ncomps) return(1);
  ncomp--;
  cur_entity=ncomp;
  sprintf( lcase[cur_lc].compName[ncomp],name);
  lcase[cur_lc].ictype[ncomp] = ictype;
  lcase[cur_lc].icind1[ncomp] = row;
  lcase[cur_lc].icind2[ncomp] = column;
  lcase[cur_lc].iexist[ncomp] = 0;

  /* search max min */
  //for(i=0; i<lcase[cur_lc].ncomps; i++)
  /*
  i=ncomp;
  {
    for(n=0; n<anz->n; n++)
    {
      if (lcase[cur_lc].dat[i][node[n].nr] >  lcase[cur_lc].max[i])
      {  lcase[cur_lc].max[i]=lcase[cur_lc].dat[i][node[n].nr]; lcase[cur_lc].nmax[i]=node[n].nr;}
      if (lcase[cur_lc].dat[i][node[n].nr] <  lcase[cur_lc].min[i])
      {  lcase[cur_lc].min[i]=lcase[cur_lc].dat[i][node[n].nr]; lcase[cur_lc].nmin[i]=node[n].nr;}
    }
  }
  */
  return(0);
}
