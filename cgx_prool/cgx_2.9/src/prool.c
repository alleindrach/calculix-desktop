// prool code
// http://calculixforwin.com http://prool.kharkov.org <proolix@gmail.com>

FILE *f; // prool

void  prool_version()
{
printf("Built by Prool %s %s proolix@gmail.com\n\
http://calculixforwin.com\n\
Use PROOL command in CGX main window for additional info\n\
",__DATE__,__TIME__);
}

void debug()
{
printf("fprintf\n");
}

void flag (void) // prool
{
FILE *flag_;

#if 1
flag_=fopen("flag.txt","w");
fputs("flag-semafor file by prool ;-)", flag_);
fclose(flag_);
#endif
fflush(NULL);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// pre_area2() begin // prool!

double pre_area2(char *setname)
{
  int   i,j,k,n;
  int   nr, setNr;
  double A=0., Ae, Abuf, p[3][3], pcg[3], Ix, Iy, Ixy;
  double xcg=0., ycg=0., zcg=0.;
  double sum_valAe=0., value=0.;

  setNr=getSetNr(setname);
  if (setNr<0)
  {
    printf (" ERROR: set:%s does not exist\n", setname);
	   fprintf(f,"n/a\n0\n0\n0\n"); // prool
    return(-1);
  }
  if (set[setNr].anz_f<1)
  {
    printf (" ERROR: set:%s does not contain faces\n", setname);
	   fprintf(f,"n/a\n0\n0\n0\n"); // prool
    return(-1);
  }

  for(i=0; i<set[setNr].anz_f; i++)
  {
    Abuf=A;
    nr=set[setNr].face[i];
    switch(face[nr].type)
    {
      case 7:
      for(j=0; j<3; j++)
      {
        p[j][0]=node[face[nr].nod[j]].nx*scale->w+scale->x;
        p[j][1]=node[face[nr].nod[j]].ny*scale->w+scale->y;
        p[j][2]=node[face[nr].nod[j]].nz*scale->w+scale->z;
      }
      if(getGeoDataTria( p[0], p[1], p[2], &Ix, &Iy, &Ixy, &Ae, pcg)==0) break;

      A+=Ae;
      xcg+=pcg[0]*Ae;
      ycg+=pcg[1]*Ae;
      zcg+=pcg[2]*Ae;
      break;


      case 8:
      p[0][0]=node[face[nr].nod[0]].nx*scale->w+scale->x;
      p[0][1]=node[face[nr].nod[0]].ny*scale->w+scale->y;
      p[0][2]=node[face[nr].nod[0]].nz*scale->w+scale->z;
      p[1][0]=node[face[nr].nod[3]].nx*scale->w+scale->x;
      p[1][1]=node[face[nr].nod[3]].ny*scale->w+scale->y;
      p[1][2]=node[face[nr].nod[3]].nz*scale->w+scale->z;
      p[2][0]=node[face[nr].nod[5]].nx*scale->w+scale->x;
      p[2][1]=node[face[nr].nod[5]].ny*scale->w+scale->y;
      p[2][2]=node[face[nr].nod[5]].nz*scale->w+scale->z;
      if(getGeoDataTria( p[0], p[1], p[2], &Ix, &Iy, &Ixy, &Ae, pcg)==0) break;

      A+=Ae;
      xcg+=pcg[0]*Ae;
      ycg+=pcg[1]*Ae;
      zcg+=pcg[2]*Ae;

      p[0][0]=node[face[nr].nod[3]].nx*scale->w+scale->x;
      p[0][1]=node[face[nr].nod[3]].ny*scale->w+scale->y;
      p[0][2]=node[face[nr].nod[3]].nz*scale->w+scale->z;
      p[1][0]=node[face[nr].nod[4]].nx*scale->w+scale->x;
      p[1][1]=node[face[nr].nod[4]].ny*scale->w+scale->y;
      p[1][2]=node[face[nr].nod[4]].nz*scale->w+scale->z;
      p[2][0]=node[face[nr].nod[5]].nx*scale->w+scale->x;
      p[2][1]=node[face[nr].nod[5]].ny*scale->w+scale->y;
      p[2][2]=node[face[nr].nod[5]].nz*scale->w+scale->z;
      if(getGeoDataTria( p[0], p[1], p[2], &Ix, &Iy, &Ixy, &Ae, pcg)==0) break;

      A+=Ae;
      xcg+=pcg[0]*Ae;
      ycg+=pcg[1]*Ae;
      zcg+=pcg[2]*Ae;

      p[0][0]=node[face[nr].nod[3]].nx*scale->w+scale->x;
      p[0][1]=node[face[nr].nod[3]].ny*scale->w+scale->y;
      p[0][2]=node[face[nr].nod[3]].nz*scale->w+scale->z;
      p[1][0]=node[face[nr].nod[1]].nx*scale->w+scale->x;
      p[1][1]=node[face[nr].nod[1]].ny*scale->w+scale->y;
      p[1][2]=node[face[nr].nod[1]].nz*scale->w+scale->z;
      p[2][0]=node[face[nr].nod[4]].nx*scale->w+scale->x;
      p[2][1]=node[face[nr].nod[4]].ny*scale->w+scale->y;
      p[2][2]=node[face[nr].nod[4]].nz*scale->w+scale->z;
      if(getGeoDataTria( p[0], p[1], p[2], &Ix, &Iy, &Ixy, &Ae, pcg)==0) break;

      A+=Ae;
      xcg+=pcg[0]*Ae;
      ycg+=pcg[1]*Ae;
      zcg+=pcg[2]*Ae;

      p[0][0]=node[face[nr].nod[4]].nx*scale->w+scale->x;
      p[0][1]=node[face[nr].nod[4]].ny*scale->w+scale->y;
      p[0][2]=node[face[nr].nod[4]].nz*scale->w+scale->z;
      p[1][0]=node[face[nr].nod[2]].nx*scale->w+scale->x;
      p[1][1]=node[face[nr].nod[2]].ny*scale->w+scale->y;
      p[1][2]=node[face[nr].nod[2]].nz*scale->w+scale->z;
      p[2][0]=node[face[nr].nod[5]].nx*scale->w+scale->x;
      p[2][1]=node[face[nr].nod[5]].ny*scale->w+scale->y;
      p[2][2]=node[face[nr].nod[5]].nz*scale->w+scale->z;
      if(getGeoDataTria( p[0], p[1], p[2], &Ix, &Iy, &Ixy, &Ae, pcg)==0) break;

      A+=Ae;
      xcg+=pcg[0]*Ae;
      ycg+=pcg[1]*Ae;
      zcg+=pcg[2]*Ae;
      break;


      case 9:
      for(j=0; j<3; j++)
      {
        p[j][0]=node[face[nr].nod[j]].nx*scale->w+scale->x;
        p[j][1]=node[face[nr].nod[j]].ny*scale->w+scale->y;
        p[j][2]=node[face[nr].nod[j]].nz*scale->w+scale->z;
      }
      if(getGeoDataTria( p[0], p[1], p[2], &Ix, &Iy, &Ixy, &Ae, pcg)==0) break;

      A+=Ae;
      xcg+=pcg[0]*Ae;
      ycg+=pcg[1]*Ae;
      zcg+=pcg[2]*Ae;

      n=j=0;
      p[n][0]=node[face[nr].nod[j]].nx*scale->w+scale->x;
      p[n][1]=node[face[nr].nod[j]].ny*scale->w+scale->y;
      p[n++][2]=node[face[nr].nod[j]].nz*scale->w+scale->z;
      for(j=2; j<4; j++)
      {
        p[n][0]=node[face[nr].nod[j]].nx*scale->w+scale->x;
        p[n][1]=node[face[nr].nod[j]].ny*scale->w+scale->y;
        p[n++][2]=node[face[nr].nod[j]].nz*scale->w+scale->z;
      }
      if(getGeoDataTria( p[0], p[1], p[2], &Ix, &Iy, &Ixy, &Ae, pcg)==0) break;

      A+=Ae;
      xcg+=pcg[0]*Ae;
      ycg+=pcg[1]*Ae;
      zcg+=pcg[2]*Ae;
      break;


      case 10:
      p[0][0]=node[face[nr].nod[0]].nx*scale->w+scale->x;
      p[0][1]=node[face[nr].nod[0]].ny*scale->w+scale->y;
      p[0][2]=node[face[nr].nod[0]].nz*scale->w+scale->z;
      p[1][0]=node[face[nr].nod[4]].nx*scale->w+scale->x;
      p[1][1]=node[face[nr].nod[4]].ny*scale->w+scale->y;
      p[1][2]=node[face[nr].nod[4]].nz*scale->w+scale->z;
      p[2][0]=node[face[nr].nod[7]].nx*scale->w+scale->x;
      p[2][1]=node[face[nr].nod[7]].ny*scale->w+scale->y;
      p[2][2]=node[face[nr].nod[7]].nz*scale->w+scale->z;
      if(getGeoDataTria( p[0], p[1], p[2], &Ix, &Iy, &Ixy, &Ae, pcg)==0) break;

      A+=Ae;
      xcg+=pcg[0]*Ae;
      ycg+=pcg[1]*Ae;
      zcg+=pcg[2]*Ae;

      p[0][0]=node[face[nr].nod[4]].nx*scale->w+scale->x;
      p[0][1]=node[face[nr].nod[4]].ny*scale->w+scale->y;
      p[0][2]=node[face[nr].nod[4]].nz*scale->w+scale->z;
      p[1][0]=node[face[nr].nod[6]].nx*scale->w+scale->x;
      p[1][1]=node[face[nr].nod[6]].ny*scale->w+scale->y;
      p[1][2]=node[face[nr].nod[6]].nz*scale->w+scale->z;
      p[2][0]=node[face[nr].nod[7]].nx*scale->w+scale->x;
      p[2][1]=node[face[nr].nod[7]].ny*scale->w+scale->y;
      p[2][2]=node[face[nr].nod[7]].nz*scale->w+scale->z;
      if(getGeoDataTria( p[0], p[1], p[2], &Ix, &Iy, &Ixy, &Ae, pcg)==0) break;

      A+=Ae;
      xcg+=pcg[0]*Ae;
      ycg+=pcg[1]*Ae;
      zcg+=pcg[2]*Ae;

      p[0][0]=node[face[nr].nod[7]].nx*scale->w+scale->x;
      p[0][1]=node[face[nr].nod[7]].ny*scale->w+scale->y;
      p[0][2]=node[face[nr].nod[7]].nz*scale->w+scale->z;
      p[1][0]=node[face[nr].nod[6]].nx*scale->w+scale->x;
      p[1][1]=node[face[nr].nod[6]].ny*scale->w+scale->y;
      p[1][2]=node[face[nr].nod[6]].nz*scale->w+scale->z;
      p[2][0]=node[face[nr].nod[3]].nx*scale->w+scale->x;
      p[2][1]=node[face[nr].nod[3]].ny*scale->w+scale->y;
      p[2][2]=node[face[nr].nod[3]].nz*scale->w+scale->z;
      if(getGeoDataTria( p[0], p[1], p[2], &Ix, &Iy, &Ixy, &Ae, pcg)==0) break;

      A+=Ae;
      xcg+=pcg[0]*Ae;
      ycg+=pcg[1]*Ae;
      zcg+=pcg[2]*Ae;

      p[0][0]=node[face[nr].nod[4]].nx*scale->w+scale->x;
      p[0][1]=node[face[nr].nod[4]].ny*scale->w+scale->y;
      p[0][2]=node[face[nr].nod[4]].nz*scale->w+scale->z;
      p[1][0]=node[face[nr].nod[1]].nx*scale->w+scale->x;
      p[1][1]=node[face[nr].nod[1]].ny*scale->w+scale->y;
      p[1][2]=node[face[nr].nod[1]].nz*scale->w+scale->z;
      p[2][0]=node[face[nr].nod[5]].nx*scale->w+scale->x;
      p[2][1]=node[face[nr].nod[5]].ny*scale->w+scale->y;
      p[2][2]=node[face[nr].nod[5]].nz*scale->w+scale->z;
      if(getGeoDataTria( p[0], p[1], p[2], &Ix, &Iy, &Ixy, &Ae, pcg)==0) break;

      A+=Ae;
      xcg+=pcg[0]*Ae;
      ycg+=pcg[1]*Ae;
      zcg+=pcg[2]*Ae;

      p[0][0]=node[face[nr].nod[5]].nx*scale->w+scale->x;
      p[0][1]=node[face[nr].nod[5]].ny*scale->w+scale->y;
      p[0][2]=node[face[nr].nod[5]].nz*scale->w+scale->z;
      p[1][0]=node[face[nr].nod[6]].nx*scale->w+scale->x;
      p[1][1]=node[face[nr].nod[6]].ny*scale->w+scale->y;
      p[1][2]=node[face[nr].nod[6]].nz*scale->w+scale->z;
      p[2][0]=node[face[nr].nod[4]].nx*scale->w+scale->x;
      p[2][1]=node[face[nr].nod[4]].ny*scale->w+scale->y;
      p[2][2]=node[face[nr].nod[4]].nz*scale->w+scale->z;
      if(getGeoDataTria( p[0], p[1], p[2], &Ix, &Iy, &Ixy, &Ae, pcg)==0) break;

      A+=Ae;
      xcg+=pcg[0]*Ae;
      ycg+=pcg[1]*Ae;
      zcg+=pcg[2]*Ae;

      p[0][0]=node[face[nr].nod[5]].nx*scale->w+scale->x;
      p[0][1]=node[face[nr].nod[5]].ny*scale->w+scale->y;
      p[0][2]=node[face[nr].nod[5]].nz*scale->w+scale->z;
      p[1][0]=node[face[nr].nod[2]].nx*scale->w+scale->x;
      p[1][1]=node[face[nr].nod[2]].ny*scale->w+scale->y;
      p[1][2]=node[face[nr].nod[2]].nz*scale->w+scale->z;
      p[2][0]=node[face[nr].nod[6]].nx*scale->w+scale->x;
      p[2][1]=node[face[nr].nod[6]].ny*scale->w+scale->y;
      p[2][2]=node[face[nr].nod[6]].nz*scale->w+scale->z;
      if(getGeoDataTria( p[0], p[1], p[2], &Ix, &Iy, &Ixy, &Ae, pcg)==0) break;

      A+=Ae;
      xcg+=pcg[0]*Ae;
      ycg+=pcg[1]*Ae;
      zcg+=pcg[2]*Ae;
      break;


      printf("ERROR: type:%d of face:%d not known. Interrupt\n",face[nr].type,nr); 
   	fprintf(f,"n/a\n0\n0\n0\n"); // prool
      return(-1.);
    }

    /* determine the average node-value */
    if(anz->l)
    {
      if (face[nr].type == 7) n = 3;  /* TRI3  */
      else if (face[nr].type == 8) n = 6;  /* TRI6  */
      else if (face[nr].type == 9) n = 4;  /* QUAD4 */
      else if (face[nr].type == 10) n = 8; /* QUAD8 */
      else if (face[nr].type == 11) n = 2; /* beam2 */
      else if (face[nr].type == 12) n = 3; /* beam3 */
      else n=0;
      k=0;
      value=0.;
      for (j=0; j<n; j++)
      {
        if(sequenceFlag) value+=lcase[lcase_animList].dat[animList][face[nr].nod[j]];
        else value+=lcase[cur_lc].dat[cur_entity][face[nr].nod[j]];
      }
      sum_valAe+=value/n*(A-Abuf);
    }
  }
  if(anz->l) printf("AREA:%lf  CENTER OF GRAVITY: %lf %lf %lf AVERAGE-VALUE:%f\n", A,xcg/A,ycg/A,zcg/A, sum_valAe/A);
  else   printf("AREA:%lf  CENTER OF GRAVITY: %lf %lf %lf\n", A,xcg/A,ycg/A,zcg/A);
	debug(); fprintf(f,"%lf\n%lf\n%lf\n%lf\n", A,xcg/A,ycg/A,zcg/A); // prool // ???

  if(valuestackFlag)
  {
    if(anz->l) n=5; else n=4;
    if ((valuestack = (char **)realloc( (char **)valuestack, (valuestack_ptr+n)*sizeof(char *)) ) == NULL )
    { printf("\n\nERROR: realloc failure, valuestack\n\n"); return(-1); }
    for(i=0; i<n; i++)
    {
      if ((valuestack[valuestack_ptr+i] = (char *)malloc( MAX_LINE_LENGTH*sizeof(char)) ) == NULL )
      { printf("\n\nERROR: realloc failure, valuestack\n\n"); return(-1); }
    }
    if(anz->l) sprintf(valuestack[valuestack_ptr++],"%e", sum_valAe/A );
    sprintf(valuestack[valuestack_ptr++],"%e", zcg/A );
    sprintf(valuestack[valuestack_ptr++],"%e", ycg/A );
    sprintf(valuestack[valuestack_ptr++],"%e", xcg/A );
    sprintf(valuestack[valuestack_ptr++],"%e", A );
    printf(" in inverse order written to stack\n");
  }

  return(A);
}
// pre_area2() end

// pre_volu2() begin // prool
double pre_volu2(char *setname)
{
  int   i,j;
  int   nr, setNr, massFlag=1, volFlag=1, elFlag=0;
  int   istat[3]={0,0,0};
  double vol=0., mass=0., vole, masse, x[20],y[20],z[20];
  double xcg=0., ycg=0., zcg=0., xcge, ycge, zcge;

  setNr=getSetNr(setname);
  if (setNr<0)
  {
    printf (" ERROR: set:%s does not exist\n", setname);
	 fprintf(f,"0\n0\n0\n0\n"); // prool
    return(-1);
  }

  for(i=0; i<set[setNr].anz_e; i++)
  {
    nr=set[setNr].elem[i];
    if((e_enqire[nr].type==1)||(e_enqire[nr].type==4))
    {
      for(j=0; j<8; j++)
      {
        x[j]=node[e_enqire[nr].nod[j]].nx*scale->w+scale->x;
        y[j]=node[e_enqire[nr].nod[j]].ny*scale->w+scale->y;
        z[j]=node[e_enqire[nr].nod[j]].nz*scale->w+scale->z;
      }
      hexaeder_(&nr, istat, x,y,z, &vole, &xcge, &ycge, &zcge );
    }
    else if((e_enqire[nr].type==2)||(e_enqire[nr].type==5))
    {
      /* calc as collapsed hex */
      for(j=0; j<3; j++)
      {
        x[j]=node[e_enqire[nr].nod[j]].nx*scale->w+scale->x;
        y[j]=node[e_enqire[nr].nod[j]].ny*scale->w+scale->y;
        z[j]=node[e_enqire[nr].nod[j]].nz*scale->w+scale->z;
      }
      x[j]=node[e_enqire[nr].nod[2]].nx*scale->w+scale->x;
      y[j]=node[e_enqire[nr].nod[2]].ny*scale->w+scale->y;
      z[j]=node[e_enqire[nr].nod[2]].nz*scale->w+scale->z;
      for(j=3; j<6; j++)
      {
        x[j+1]=node[e_enqire[nr].nod[j]].nx*scale->w+scale->x;
        y[j+1]=node[e_enqire[nr].nod[j]].ny*scale->w+scale->y;
        z[j+1]=node[e_enqire[nr].nod[j]].nz*scale->w+scale->z;
      }
      x[7]=node[e_enqire[nr].nod[5]].nx*scale->w+scale->x;
      y[7]=node[e_enqire[nr].nod[5]].ny*scale->w+scale->y;
      z[7]=node[e_enqire[nr].nod[5]].nz*scale->w+scale->z;
      hexaeder_(&nr, istat, x,y,z, &vole, &xcge, &ycge, &zcge );
    }
    else if((e_enqire[nr].type==3)||(e_enqire[nr].type==6))
    {
      for(j=0; j<4; j++)
      {
        x[j]=node[e_enqire[nr].nod[j]].nx*scale->w+scale->x;
        y[j]=node[e_enqire[nr].nod[j]].ny*scale->w+scale->y;
        z[j]=node[e_enqire[nr].nod[j]].nz*scale->w+scale->z;
      }
      tetraeder_(&nr, istat, x,y,z, &vole, &xcge, &ycge, &zcge );
    }
    else
    {
      printf("ERROR: type:%d of elem:%d not known. Interrupt\n",e_enqire[nr].type,nr); 
	 fprintf(f,"0\n0\n0\n0\n"); // prool
      return(-1.);
    }

    /*
       Berechnung globaler Größen:
    */

    /* get material properties */
    masse=-1.;
    elFlag=-1;
    for(j=0; j<anz->sets; j++)
    {
      if((set[j].name!=(char *)NULL) && (!set[j].type) && (set[j].name[0]!='-') && (set[j].material>-1)) 
      {
        if(( getIndex(&set[j].elem,set[j].anz_e,nr) >-1) && (material[set[j].material].rho>-1.))
        {
          if(elFlag!=-1)
          {
            printf("ERROR: found material-definition for elem:%d in set:%s and %s\n", nr, set[j].name,set[elFlag].name );  
            break;
          }
          elFlag=j;
          volFlag=0;
          masse= vole * material[set[j].material].rho;
          mass+= masse;
        }
      }
    }
    if (masse<0)
    {
      massFlag=0;
      masse=vole;
    }
              
    vol+=vole;
    xcg+=xcge*masse;
    ycg+=ycge*masse;
    zcg+=zcge*masse;
  }
  if (massFlag)     
	{
	printf("VOLUME:%lf  MASS:%e CENTER OF GRAVITY: %lf %lf %lf\n", vol,mass,xcg/mass,ycg/mass,zcg/mass);
	debug(); fprintf(f,"%lf\n%lf\n%lf\n%lf\n", vol,xcg/mass,ycg/mass,zcg/mass); // prool
	}
  else if (volFlag) 
	{
	printf("VOLUME:%lf CENTER OF GRAVITY: %lf %lf %lf\n", vol,xcg/vol,ycg/vol,zcg/vol);
	debug(); fprintf(f,"%lf\n%lf\n%lf\n%lf\n", vol,xcg/vol,ycg/vol,zcg/vol); // prool
	}
  else  
	{            
	printf("VOLUME:%lf\n", vol);
	debug(); fprintf(f,"%lf\n0\n0\n0\n", vol); // prool
	}
  return(vol);
}

// pre_volu2() end
void prool_commands (void)
{
printf("CGX is modified by Prool\n\
Prool's additional commands:\n\
PROOL - prool's commands info\n\
WRITE SE - write group names to file cgx.out (first column of PRNT SE)\n\
WRITE LIST - write PRINT SE output to file cgx.out (one value in one line)\n\
WRITEONE [path]- SEND ALL ABQ;SEND ALL ABQ NAM -> file [path]allinone.msh\n\
WRITEINONE - ... \n\
WRITE4SHELL - ... \n\
ECHO - test kommand\n\
SENDPRES group pressure filename - ...\n\
SENDPRES4SHELL group pressure filename - ...\n\
SENDASTER path - send all aster -> path\n\
SENDANS path - send all ans -> path\n\
SENDNAS path - send all nas -> path\n\
SENDSTL path - send all stl -> path\n\
	For example: sendstl c:\\files\\msh\\my_mesh.stl\n\
\n\
");
printf("Prool timer is ");
if (prool_timer) printf("on");
else printf("off");
printf("\n\n");
}

// print2() begin // prool's mod of prnt() function

int prnt2(char *record)
{
  int   setNr, nr, p, l, nc,nl, args;
  int i,j,k,n;
  int length, bias_fbd, foundSubString;
  char name[MAX_LINE_LENGTH], typ[MAX_LINE_LENGTH], param[MAX_LINE_LENGTH], **dat;
  char parameter[20][MAX_LINE_LENGTH];
  char *str=NULL, *token=NULL, *saveptr=NULL;

	f=fopen("cgx.out", "w"); // prool

  param[0]=0;
  length=sscanf(record,"%s%s%s",typ,name,param);
  if((length==2)&&(compareStrings(name, "*")>0)) length--;

  /* generate the set-indexes */
  generateSetIndexes();

  if ((compare( typ, "usr", 3) == 3) ||(compare( typ, "USR", 3) == 3))
  {
    if (!anz->u) printf(" no user headers defined\n");
    /* list all existing parameters */
    for (i=0; i<anz->u; i++)
    {
        if( anz->uheader[i] != (char *)NULL )
        {
          printf ("%s\n", &anz->uheader[i][6]);
          strcpy(parameter[0], &anz->uheader[i][6]);
          write2stack(1, parameter);
        }
    }
    fflush(NULL); fclose(f); flag(); return(1);
  }
  if ((compare( typ, "par", 3) == 3) ||(compare( typ, "PAR", 3) == 3))
  {
    if (!lcase[cur_lc].npheader) printf(" no parameters for active dataset:%d defined\n", cur_lc+1);
    if (length==1)
    {
      /* list all existing parameters */
      for (i=0; i<lcase[cur_lc].npheader; i++)
      {
        if( lcase[cur_lc].pheader[i] != (char *)NULL )
        {
          printf ("%s\n", &lcase[cur_lc].pheader[i][6]);
          strcpy(parameter[0], &lcase[cur_lc].pheader[i][6]);
          write2stack(1, parameter);
        }
      }
      fflush(NULL); fclose(f); flag(); return(1);
    }
    else
    {
      for (i=0; i<lcase[cur_lc].npheader; i++)
      {
        if( lcase[cur_lc].pheader[i] != (char *)NULL )
        {
          if(compare(&lcase[cur_lc].pheader[i][6],name,strlen(name))==strlen(name))
	  {
            printf ("%s\n", &lcase[cur_lc].pheader[i][6]);
            strcpy(parameter[0], &lcase[cur_lc].pheader[i][6]);
            write2stack(1, parameter);
	  }
        }
      } 
      fflush(NULL); fclose(f); flag(); return(1);
    }
  }

  if ((compare( typ, "amp", 3) == 3) ||(compare( typ, "AMP", 3) == 3))
  {
    if (!anz->amps) printf(" no amplitudes defined\n");
    if (length==1)
    {
      /* list all existing amplitudes */
      for (i=0; i<anz->amps; i++)
      {
        if( amplitude[i].name != (char *)NULL )
        {
          printf ("%s xy-pairs:%d\n", amplitude[i].name, amplitude[i].n);
        }
      }
      fflush(NULL); fclose(f); flag(); return(1);
    }
    else
    {
      setNr=getAmplitudeNr(name,1);
      if (setNr<0)
      {
        /* amp was not found. check if wildcards (*) were used */
        length= strsplt( name, '*', &dat);
        if ((length>0)&&(strstr(name, "*") !=NULL))
	{
          j=0;
          for(setNr=0; setNr<anz->amps; setNr++)
	  {
            for(i=0; i<length; i++)
	    {
              if(strstr(amplitude[setNr].name, dat[i]) !=NULL)
	      {
                if( amplitude[setNr].name != (char *)NULL )
                {
                  printf ("%s xy-pairs:%d\n", amplitude[setNr].name, amplitude[setNr].n);
                }
	      }
	    }
	  }
          fflush(NULL); fclose(f); flag(); return(0);
	}
        printf (" prnt: amplitude:'%s' does not exist\n", name);
        fflush(NULL); fclose(f); flag(); return (-1);
      }
    }
    printf ("i      x:            y:\n");
    for (i=0; i<amplitude[setNr].n; i++)
    {
      printf (" %8d %12e %12e\n", i+1, amplitude[setNr].x[i],amplitude[setNr].y[i]);
    }
  }

  if ((compare( typ, "mat", 3) == 3) ||(compare( typ, "MAT", 3) == 3))
  {
    if (!anz->mats) printf(" no materials defined\n");
    if (length==1)
    {
      /* list all existing amplitudes */
      for (i=0; i<anz->mats; i++)
      {
        if( material[i].name != (char *)NULL )
        {
          printf ("%s elastic:%d expansion:%d conductivity:%d specific heat:%d \n", material[i].name, material[i].nela, material[i].nexp, material[i].ncon, material[i].nsph);
        }
      }
      fflush(NULL); fclose(f); flag(); return(1);
    }
    else
    {
      setNr=getMatNr(name,1);
      if (setNr<0)
      {
        /* amp was not found. check if wildcards (*) were used */
        length= strsplt( name, '*', &dat);
        if ((length>0)&&(strstr(name, "*") !=NULL))
	{
          j=0;
          for(setNr=0; setNr<anz->mats; setNr++)
	  {
            for(i=0; i<length; i++)
	    {
              if(strstr(material[setNr].name, dat[i]) !=NULL)
	      {
                if( material[setNr].name != (char *)NULL )
                {
                  printf ("%s elastic:%d expansion:%d conductivity:%d specific heat:%d \n", material[setNr].name, material[setNr].nela, material[setNr].nexp, material[setNr].ncon, material[setNr].nsph);
                }
	      }
	    }
	  }
          fflush(NULL); fclose(f); flag(); return(0);
	}
        printf (" prnt: material:'%s' does not exist\n", name);
        fflush(NULL); fclose(f); flag(); return(-1);
      }
    }
    printf ("density:%e\n", material[setNr].rho);
    printf ("\ni      elastic:      nue:      temperature:\n");
    for (i=0; i<material[setNr].nela; i++)
    {
      printf (" %8d %12e %12e %12e\n", i+1, material[setNr].ela[i],material[setNr].nue[i],material[setNr].tela[i]);
    }
    printf ("\ni      expansion:      temperature:\n");
    for (i=0; i<material[setNr].nexp; i++)
    {
      printf (" %8d %12e %12e\n", i+1, material[setNr].exp[i],material[setNr].texp[i]);
    }
    printf ("\ni      conductivity:      temperature:\n");
    for (i=0; i<material[setNr].ncon; i++)
    {
      printf (" %8d %12e %12e\n", i+1, material[setNr].con[i],material[setNr].tcon[i]);
    }
    printf ("\ni      sp. heat:      temperature:\n");
    for (i=0; i<material[setNr].nsph; i++)
    {
      printf (" %8d %12e %12e\n", i+1, material[setNr].sph[i],material[setNr].tsph[i]);
    }
  }

  if ((compare( typ, "se", 2) == 2) ||(compare( typ, "SE", 2) == 2))
  {
    if (!anz->sets)
    {
      printf("ERROR: no sets defined\n");
      strcpy(parameter[0], "ERROR: no sets defined");
      write2stack(1, parameter);
    }
    if (length==1)
    {
      /* list all existing sets */
      for (i=0; i<anz->sets; i++)
      {
        if( set[i].name != (char *)NULL )
        {
          if (!set[i].type)
          {
            printf ("%-5d %s stat:%c n:%d e:%d f:%d p:%d l:%d s:%d b:%d L:%d S:%d se:%d sh:%d v:%d\n", set[i].index, set[i].name, set[i].flag, set[i].anz_n, set[i].anz_e, set[i].anz_f, set[i].anz_p, set[i].anz_l, set[i].anz_s, set[i].anz_b, set[i].anz_nurl, set[i].anz_nurs, set[i].anz_se, set[i].anz_sh, set[i].anz_v);
          }
        }
      }
      fflush(NULL); fclose(f); flag(); return(1);
    }
    else
    {
      setNr=getSetNr(name);
      if((setNr>=0)&&(compare(param,"range",3)==3))
      {
        if((set[setNr].anz_n>2)&&(set[setNr].anz_e>2))
	{
          param[0]=0;
          /* check for holes */
          for(i=0; i<set[setNr].anz_n-1; i++)
            if((set[setNr].node[i]+1)!=(set[setNr].node[i+1])) break;
	  if(i<set[setNr].anz_n-1) printf("Warning set %s has holes in the node numbering starting between node %d and %d\n", set[setNr].name, set[setNr].node[i], set[setNr].node[i+1]);
          for(i=0; i<set[setNr].anz_e-1; i++)
            if((set[setNr].elem[i]+1)!=(set[setNr].elem[i+1])) break;
	  if(i<set[setNr].anz_e-1) printf("Warning set %s has holes in the elem numbering starting between elem %d and %d\n", set[setNr].name, set[setNr].elem[i], set[setNr].elem[i+1]);			       					       

          printf ("%-5d %s nr %d %d er %d %d\n", set[setNr].index, set[setNr].name, set[setNr].node[0], set[setNr].node[set[setNr].anz_n-1], set[setNr].elem[0], set[setNr].elem[set[setNr].anz_e-1]);
	}
        fflush(NULL); fclose(f); flag(); return(1);
      }

      if (setNr<0)
      {
        /* set was not found. check if wildcards (*) were used */
        length= strsplt( name, '*', &dat);
        if ((length>0)&&(strstr(name, "*") !=NULL))
	{
          j=0;
          for(setNr=0; setNr<anz->sets; setNr++) if(set[setNr].name!=(char *)NULL)
	  {
            foundSubString=0;
            for(i=0; i<length; i++)
	    {
              if(strstr(set[setNr].name, dat[i]) !=NULL)
	      {
	        foundSubString++;
	        /* check if the first or the last char is no '*' then the dat[] must be at start or end */
	        if(i==0) { if(name[0]!='*')  { if(name[0]!=set[setNr].name[0])  foundSubString--; }  }
         	if(i==length-1) { if(name[strlen(name)-1]!='*') { if(name[strlen(name)-1]!=set[setNr].name[strlen(set[setNr].name)-1])  foundSubString--; } }
	      }
	    }
            if(foundSubString==length)
	    {
	      i=setNr;
              if (!set[i].type)
              {
		j++;
                printf ("%-5d %s stat:%c n:%d e:%d f:%d p:%d l:%d s:%d b:%d L:%d S:%d se:%d sh:%d v:%d", set[i].index, set[i].name, set[i].flag, set[i].anz_n, set[i].anz_e, set[i].anz_f, set[i].anz_p, set[i].anz_l, set[i].anz_s, set[i].anz_b, set[i].anz_nurl, set[i].anz_nurs, set[i].anz_se, set[i].anz_sh, set[i].anz_v);
                if(compare(param,"range",3)==3)
		{
                  printf (" nr %d %d er %d %d", set[setNr].node[0], set[setNr].node[set[setNr].anz_n-1], set[setNr].elem[0], set[setNr].elem[set[setNr].anz_e-1]);
		}
                else printf ("\n");
              }
	    }
	  }
          if(j!=0) {fflush(NULL); fclose(f); flag(); return(1);}
	}
        /* free dat */
        for(i=0; i<length; i++) free(dat[i]);
        free(dat);

        printf ("ERROR: set %s does not exist\n", name);
        sprintf(parameter[0], "ERROR: set %s does not exist", name);
        write2stack(1, parameter);
        fflush(NULL); fclose(f); flag(); return (-1);
      }
    }
    if (set[setNr].type) {fflush(NULL); fclose(f); flag(); return(0);}

    if(anz->l)
    {
      printf (" node:    value:       x:            y:           z:\n");
      for (i=0; i<set[setNr].anz_n; i++)
      {
        sprintf(parameter[0],"%8d",set[setNr].node[i]);
        sprintf(parameter[1],"%6e",lcase[cur_lc].dat[cur_entity][set[setNr].node[i]]);
        sprintf(parameter[2],"%12f",node[set[setNr].node[i]].nx* scale->w+scale->x);
        sprintf(parameter[3],"%12f",node[set[setNr].node[i]].ny* scale->w+scale->y);
        sprintf(parameter[4],"%12f",node[set[setNr].node[i]].nz* scale->w+scale->z);
        printf (" %s %s %s %s %s\n",parameter[0],parameter[1],parameter[2],parameter[3],parameter[4]);
        write2stack(5, parameter);
      }
    }
    else
    {
      printf (" node:       x:            y:           z:\n");
      for (i=0; i<set[setNr].anz_n; i++)
      {
        sprintf(parameter[0],"%8d",set[setNr].node[i]);
        sprintf(parameter[1],"%12f",node[set[setNr].node[i]].nx* scale->w+scale->x);
        sprintf(parameter[2],"%12f",node[set[setNr].node[i]].ny* scale->w+scale->y);
        sprintf(parameter[3],"%12f",node[set[setNr].node[i]].nz* scale->w+scale->z);
        printf (" %s %s %s %s\n",parameter[0],parameter[1],parameter[2],parameter[3]);
        write2stack(4, parameter);
      }
    }
    for (i=0; i<set[setNr].anz_e; i++)
    {
      nr=set[setNr].elem[i];
      printf (" elem:%d type:%d n:", nr, e_enqire[nr].type);
      if     (e_enqire[nr].type==1) k=8;
      else if(e_enqire[nr].type==2) k=6;
      else if(e_enqire[nr].type==3) k=4;
      else if(e_enqire[nr].type==4) k=20;
      else if(e_enqire[nr].type==5) k=15;
      else if(e_enqire[nr].type==6) k=10;
      else if(e_enqire[nr].type==7) k=3;
      else if(e_enqire[nr].type==8) k=6;
      else if(e_enqire[nr].type==9) k=4;
      else if(e_enqire[nr].type==10) k=8;
      else if(e_enqire[nr].type==11) k=2;
      else if(e_enqire[nr].type==12) k=3;
      else k=0;
      for (n=0; n<k; n++) printf("%d ",e_enqire[nr].nod[n]);
      printf("\n"); 
    }
    for (i=0; i<set[setNr].anz_f; i++)
    {
      nr=set[setNr].face[i];
      printf (" face:%d elem:%d side:%d nodes:",  nr, face[nr].elem_nr, face[nr].nr+1);
      if(face[nr].type==7) k=3;
      else if(face[nr].type==8) k=6;
      else if(face[nr].type==9) k=4;
      else if(face[nr].type==10) k=8;
      else if(face[nr].type==11) k=2;
      else if(face[nr].type==12) k=3;
      else k=0;
      for (n=0; n<k; n++) printf("%d ",face[nr].nod[n]);
      printf("\n"); 
    }
    for (i=0; i<set[setNr].anz_p; i++)
    {
      p=set[setNr].pnt[i];
      if( point[p].name != (char *)NULL ) 
        printf (" pnt:%s %lf %lf %lf\n", point[p].name,
        (point[p].px* scale->w+scale->x),
        (point[p].py* scale->w+scale->y),
        (point[p].pz* scale->w+scale->z) );
      sprintf(parameter[0],"%s", point[p].name);
      sprintf(parameter[1],"%lf", point[p].px* scale->w+scale->x);
      sprintf(parameter[2],"%lf", point[p].py* scale->w+scale->y);
      sprintf(parameter[3],"%lf", point[p].pz* scale->w+scale->z);
      write2stack(4, parameter);
    }
    for (i=0; i<set[setNr].anz_l; i++)
    {
      l=set[setNr].line[i];
      if( line[l].name != (char *)NULL ) 
      {
        bias_fbd=getBias_fbd(l, line);

        if( line[l].typ=='a' )  /* arc-line */
        {
          printf (" line:%s typ:a p1:%s p2:%s pc:%s div:%d bias:%d bias_el:%lf etyp:%d attr:%d\n"
          , line[l].name, point[line[l].p1].name,
          point[line[l].p2].name, point[line[l].trk].name, line[l].div, bias_fbd, line[l].bias, line[l].etyp, line[l].eattr);
          sprintf(parameter[4],"%s",point[line[l].trk].name);
        }
        else if( line[l].typ=='s' )  /* seq-line */
        {
          printf (" line:%s typ:s p1:%s p2:%s set:%s div:%d bias:%d bias_el:%lf etyp:%d attr:%d\n"
          , line[l].name, point[line[l].p1].name,
          point[line[l].p2].name, set[line[l].trk].name, line[l].div, bias_fbd, line[l].bias, line[l].etyp, line[l].eattr);
          sprintf(parameter[4],"%s",set[line[l].trk].name);
        }
        else  /* its a straight line   */
        {
          printf (" line:%s typ:l p1:%s p2:%s trk:- div:%d bias:%d bias_el:%lf etyp:%d attr:%d\n"
          , line[l].name, point[line[l].p1].name,
          point[line[l].p2].name, line[l].div, bias_fbd, line[l].bias, line[l].etyp, line[l].eattr);
          sprintf(parameter[4],"-");
        }
        sprintf(parameter[0],"%s",line[l].name);
        sprintf(parameter[1],"%c",line[l].typ);
        sprintf(parameter[2],"%s",point[line[l].p1].name);
        sprintf(parameter[3],"%s",point[line[l].p2].name);
        sprintf(parameter[5],"%d",line[l].div);
        sprintf(parameter[6],"%d",bias_fbd);
        sprintf(parameter[7],"%f",line[l].bias);
        sprintf(parameter[8],"%d",line[l].etyp);
        sprintf(parameter[9],"%d",line[l].eattr);
        write2stack(10, parameter);
      }
    }
    for (i=0; i<set[setNr].anz_c; i++)
    {
      p=set[setNr].lcmb[i];
      if( lcmb[p].name != (char *)NULL ) 
      {
        printf (" lcmb:%s ", lcmb[p].name );
        for (j=0; j<lcmb[p].nl; j++)
          printf (" %1c %s", lcmb[p].o[j], line[lcmb[p].l[j]].name );
        printf (" \n");
      }
    }
    for (i=0; i<set[setNr].anz_s; i++)
    {
      p=set[setNr].surf[i];
      if( surf[p].name != (char *)NULL ) 
      {
	  // printf("sh:%d\n",surf[p].sh);
        if (surf[p].sh==-1) printf (" surf:%s %1c BLEND ", surf[p].name, surf[p].ori );
        else if (surf[p].sh>-1) printf (" surf:%s %1c %s ", surf[p].name, surf[p].ori, shape[surf[p].sh].name );
        for (j=0; j<surf[p].nl; j++)
        {
          nl=surf[p].l[j];
          if (surf[p].typ[j]=='l')
          {
            printf (" %1c %s", surf[p].o[j], line[nl].name );
          }
          else
          {
            printf (" %1c %s", surf[p].o[j], lcmb[nl].name );
            for (k=0; k<lcmb[nl].nl; k++ )
            {
              nc=lcmb[nl].l[k];
              printf (" (%c) (%s)", lcmb[nl].o[k], line[nc].name );
            }
          }
        }
        printf (" etyp:%d attr:%d\n", surf[p].etyp, surf[p].eattr);
      }
    }
    for (i=0; i<set[setNr].anz_b; i++)
    {
      p=set[setNr].body[i];
      if( body[p].name != (char *)NULL ) 
      {
        printf (" body:%s %1c", body[p].name, body[p].ori );
        for (j=0; j<body[p].ns; j++)
          printf (" %1c %s", body[p].o[j], surf[body[p].s[j]].name );
        printf (" etyp:%d attr:%d\n", body[p].etyp, body[p].eattr);
      }
    }
    for (i=0; i<set[setNr].anz_nurl; i++)
    {
      nr=set[setNr].nurl[i];
      if( nurbl[nr].name != (char *)NULL ) 
      {
        printf (" nurl:%s\n", nurbl[nr].name );
        printf (" coefficients: exp:%d pnts:%d nods:%d End:%d\n", nurbl[nr].u_exp, nurbl[nr].u_npnt, nurbl[nr].u_nknt, nurbl[nr].endFlag);
        for (k=0; k<nurbl[nr].u_nknt; k++) printf("u-node[%d] = %lf\n", k+1, nurbl[nr].uknt[k]);
        for (k=0; k<nurbl[nr].u_npnt; k++)
        {
          printf("cpnt[%d]:%s x=%lf y=%lf z=%lf w=%lf\n", k+1, point[nurbl[nr].ctlpnt[k]].name, point[nurbl[nr].ctlpnt[k]].px,
          point[nurbl[nr].ctlpnt[k]].py, point[nurbl[nr].ctlpnt[k]].pz, nurbl[nr].weight[k]);
        }
      }
    }
    for (i=0; i<set[setNr].anz_nurs; i++)
    {
      nr=set[setNr].nurs[i];
     if( nurbs[nr].name != (char *)NULL ) 
     {
      printf (" nurs:%s\n", nurbs[nr].name );

      printf (" coefficients: u_exp:%d v_exp:%d u_npnt:%d v_npnt:%d u_nnod:%d v_nnod:%d End:%d\n", nurbs[nr].u_exp, nurbs[nr].v_exp,
        nurbs[nr].u_npnt, nurbs[nr].v_npnt, nurbs[nr].u_nknt, nurbs[nr].v_nknt, nurbs[nr].endFlag);
      for (k=0; k<nurbs[nr].u_nknt; k++) printf("u-node[%d] = %lf\n", k+1, nurbs[nr].uknt[k]);
      for (k=0; k<nurbs[nr].v_nknt; k++) printf("v-node[%d] = %lf\n", k+1, nurbs[nr].vknt[k]);
      for (k=0; k<nurbs[nr].u_npnt; k++)
      {
        for (j=0; j<nurbs[nr].v_npnt; j++)
        {
          printf("cpnt[%d][%d]:%s x=%lf y=%lf z=%lf w=%lf \n", k+1, j+1, point[nurbs[nr].ctlpnt[k][j]].name, point[nurbs[nr].ctlpnt[k][j]].px,
          point[nurbs[nr].ctlpnt[k][j]].py, point[nurbs[nr].ctlpnt[k][j]].pz, nurbs[nr].weight[k][j]);
        }
      }
     }
    }
    for (i=0; i<set[setNr].anz_se; i++)
    {
      p=set[setNr].set[i];
      if( set[p].name != (char *)NULL ) 
      {
        printf (" set:%s ", set[p].name );
        printf (" \n");
      }
    }
    for (i=0; i<set[setNr].anz_sh; i++)
    {
      p=set[setNr].shp[i];
      if( shape[p].name != (char *)NULL ) 
      {
        printf (" shape:%s p1:%s p2:%s p3:%s\n", shape[p].name, point[shape[p].p[0]].name, point[shape[p].p[1]].name, point[shape[p].p[2]].name );
      }
    }
    for (i=0; i<set[setNr].anz_v; i++)
    {
      p=set[setNr].valu[i];
      if( value[p].name != (char *)NULL ) 
      {
        printf (" value:%s string:%s\n", value[p].name, value[p].string);
      }
    }
    printf (" %d nodes, %d elements, %d faces, %d Points, %d Lines, %d Lcmb, %d Surfs, %d Bodys, %d Nurl, %d Nurs, %d sets, %d shapes, %d values stored\n", set[setNr].anz_n, set[setNr].anz_e, set[setNr].anz_f, set[setNr].anz_p, set[setNr].anz_l, set[setNr].anz_c, set[setNr].anz_s, set[setNr].anz_b, set[setNr].anz_nurl, set[setNr].anz_nurs, set[setNr].anz_se, set[setNr].anz_sh, set[setNr].anz_v );
  }
//-------------------------------------------------
// begin "LIST" subcommand
  if ((compare( typ, "list", 2) == 2) ||(compare( typ, "LIST", 2) == 2))
  {
    if (!anz->sets)
    {
      printf("ERROR: no sets defined\n");
      strcpy(parameter[0], "ERROR: no sets defined");
      write2stack(1, parameter);
    }
    if (length==1)
    {
      /* list all existing sets */
      for (i=0; i<anz->sets; i++)
      {
        if( set[i].name != (char *)NULL )
        {
          if (!set[i].type)
          {
          //  printf ("%-5d %s stat:%c n:%d e:%d f:%d p:%d l:%d s:%d b:%d L:%d S:%d se:%d sh:%d v:%d\n", set[i].index, set[i].name, set[i].flag, set[i].anz_n, set[i].anz_e, set[i].anz_f, set[i].anz_p, set[i].anz_l, set[i].anz_s, set[i].anz_b, set[i].anz_nurl, set[i].anz_nurs, set[i].anz_se, set[i].anz_sh, set[i].anz_v);
            printf ("%s\n%c\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", set[i].name, set[i].flag, set[i].anz_n, set[i].anz_e, set[i].anz_f, set[i].anz_p, set[i].anz_l, set[i].anz_s, set[i].anz_b, set[i].anz_nurl, set[i].anz_nurs, set[i].anz_se, set[i].anz_sh);
            if (set[i].anz_n+set[i].anz_e+set[i].anz_f+set[i].anz_p+set[i].anz_l+set[i].anz_s+set[i].anz_b+set[i].anz_nurl+set[i].anz_nurs+set[i].anz_se+set[i].anz_sh)
                {
                debug(); fprintf (f, "%s\n%c\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", set[i].name, set[i].flag, set[i].anz_n, set[i].anz_e, set[i].anz_f, set[i].anz_p, set[i].anz_l, set[i].anz_s, set[i].anz_b, set[i].anz_nurl, set[i].anz_nurs, set[i].anz_se, set[i].anz_sh);
                pre_area2(set[i].name);
                pre_volu2(set[i].name);
                }
          }
        }
      }
      fflush(NULL); fclose(f); flag(); return(1);
    }
    else
    {
      setNr=getSetNr(name);
      if((setNr>=0)&&(compare(param,"range",3)==3))
      {
        if((set[setNr].anz_n>2)&&(set[setNr].anz_e>2))
	{
          param[0]=0;
          /* check for holes */
          for(i=0; i<set[setNr].anz_n-1; i++)
            if((set[setNr].node[i]+1)!=(set[setNr].node[i+1])) break;
	  if(i<set[setNr].anz_n-1) printf("Warning set %s has holes in the node numbering starting between node %d and %d\n", set[setNr].name, set[setNr].node[i], set[setNr].node[i+1]);
          for(i=0; i<set[setNr].anz_e-1; i++)
            if((set[setNr].elem[i]+1)!=(set[setNr].elem[i+1])) break;
	  if(i<set[setNr].anz_e-1) printf("Warning set %s has holes in the elem numbering starting between elem %d and %d\n", set[setNr].name, set[setNr].elem[i], set[setNr].elem[i+1]);			       					       

          printf ("%-5d %s nr %d %d er %d %d\n", set[setNr].index, set[setNr].name, set[setNr].node[0], set[setNr].node[set[setNr].anz_n-1], set[setNr].elem[0], set[setNr].elem[set[setNr].anz_e-1]);
	}
        fflush(NULL); fclose(f); flag(); return(1);
      }

      if (setNr<0)
      {
        /* set was not found. check if wildcards (*) were used */
        length= strsplt( name, '*', &dat);
        if ((length>0)&&(strstr(name, "*") !=NULL))
	{
          j=0;
          for(setNr=0; setNr<anz->sets; setNr++) if(set[setNr].name!=(char *)NULL)
	  {
            foundSubString=0;
            for(i=0; i<length; i++)
	    {
              if(strstr(set[setNr].name, dat[i]) !=NULL)
	      {
	        foundSubString++;
	        /* check if the first or the last char is no '*' then the dat[] must be at start or end */
	        if(i==0) { if(name[0]!='*')  { if(name[0]!=set[setNr].name[0])  foundSubString--; }  }
         	if(i==length-1) { if(name[strlen(name)-1]!='*') { if(name[strlen(name)-1]!=set[setNr].name[strlen(set[setNr].name)-1])  foundSubString--; } }
	      }
	    }
            if(foundSubString==length)
	    {
	      i=setNr;
              if (!set[i].type)
              {
		j++;
                printf ("%-5d %s stat:%c n:%d e:%d f:%d p:%d l:%d s:%d b:%d L:%d S:%d se:%d sh:%d v:%d", set[i].index, set[i].name, set[i].flag, set[i].anz_n, set[i].anz_e, set[i].anz_f, set[i].anz_p, set[i].anz_l, set[i].anz_s, set[i].anz_b, set[i].anz_nurl, set[i].anz_nurs, set[i].anz_se, set[i].anz_sh, set[i].anz_v);
                if(compare(param,"range",3)==3)
		{
                  printf (" nr %d %d er %d %d", set[setNr].node[0], set[setNr].node[set[setNr].anz_n-1], set[setNr].elem[0], set[setNr].elem[set[setNr].anz_e-1]);
		}
                else printf ("\n");
              }
	    }
	  }
          if(j!=0) {fflush(NULL); fclose(f); flag(); return(1);}
	}
        /* free dat */
        for(i=0; i<length; i++) free(dat[i]);
        free(dat);

        printf ("ERROR: set %s does not exist\n", name);
        sprintf(parameter[0], "ERROR: set %s does not exist", name);
        write2stack(1, parameter);
        fflush(NULL); fclose(f); flag(); return (-1);
      }
    }
    if (set[setNr].type) {fflush(NULL); fclose(f); flag(); return(0);}

    if(anz->l)
    {
      printf (" node:    value:       x:            y:           z:\n");
      for (i=0; i<set[setNr].anz_n; i++)
      {
        sprintf(parameter[0],"%8d",set[setNr].node[i]);
        sprintf(parameter[1],"%6e",lcase[cur_lc].dat[cur_entity][set[setNr].node[i]]);
        sprintf(parameter[2],"%12f",node[set[setNr].node[i]].nx* scale->w+scale->x);
        sprintf(parameter[3],"%12f",node[set[setNr].node[i]].ny* scale->w+scale->y);
        sprintf(parameter[4],"%12f",node[set[setNr].node[i]].nz* scale->w+scale->z);
        printf (" %s %s %s %s %s\n",parameter[0],parameter[1],parameter[2],parameter[3],parameter[4]);
        write2stack(5, parameter);
      }
    }
    else
    {
      printf (" node:       x:            y:           z:\n");
      for (i=0; i<set[setNr].anz_n; i++)
      {
        sprintf(parameter[0],"%8d",set[setNr].node[i]);
        sprintf(parameter[1],"%12f",node[set[setNr].node[i]].nx* scale->w+scale->x);
        sprintf(parameter[2],"%12f",node[set[setNr].node[i]].ny* scale->w+scale->y);
        sprintf(parameter[3],"%12f",node[set[setNr].node[i]].nz* scale->w+scale->z);
        printf (" %s %s %s %s\n",parameter[0],parameter[1],parameter[2],parameter[3]);
        write2stack(4, parameter);
      }
    }
    for (i=0; i<set[setNr].anz_e; i++)
    {
      nr=set[setNr].elem[i];
      printf (" elem:%d type:%d n:", nr, e_enqire[nr].type);
      if     (e_enqire[nr].type==1) k=8;
      else if(e_enqire[nr].type==2) k=6;
      else if(e_enqire[nr].type==3) k=4;
      else if(e_enqire[nr].type==4) k=20;
      else if(e_enqire[nr].type==5) k=15;
      else if(e_enqire[nr].type==6) k=10;
      else if(e_enqire[nr].type==7) k=3;
      else if(e_enqire[nr].type==8) k=6;
      else if(e_enqire[nr].type==9) k=4;
      else if(e_enqire[nr].type==10) k=8;
      else if(e_enqire[nr].type==11) k=2;
      else if(e_enqire[nr].type==12) k=3;
      else k=0;
      for (n=0; n<k; n++) printf("%d ",e_enqire[nr].nod[n]);
      printf("\n"); 
    }
    for (i=0; i<set[setNr].anz_f; i++)
    {
      nr=set[setNr].face[i];
      printf (" face:%d elem:%d side:%d nodes:",  nr, face[nr].elem_nr, face[nr].nr+1);
      if(face[nr].type==7) k=3;
      else if(face[nr].type==8) k=6;
      else if(face[nr].type==9) k=4;
      else if(face[nr].type==10) k=8;
      else if(face[nr].type==11) k=2;
      else if(face[nr].type==12) k=3;
      else k=0;
      for (n=0; n<k; n++) printf("%d ",face[nr].nod[n]);
      printf("\n"); 
    }
    for (i=0; i<set[setNr].anz_p; i++)
    {
      p=set[setNr].pnt[i];
      if( point[p].name != (char *)NULL ) 
        printf (" pnt:%s %lf %lf %lf\n", point[p].name,
        (point[p].px* scale->w+scale->x),
        (point[p].py* scale->w+scale->y),
        (point[p].pz* scale->w+scale->z) );
      sprintf(parameter[0],"%s", point[p].name);
      sprintf(parameter[1],"%lf", point[p].px* scale->w+scale->x);
      sprintf(parameter[2],"%lf", point[p].py* scale->w+scale->y);
      sprintf(parameter[3],"%lf", point[p].pz* scale->w+scale->z);
      write2stack(4, parameter);
    }
    for (i=0; i<set[setNr].anz_l; i++)
    {
      l=set[setNr].line[i];
      if( line[l].name != (char *)NULL ) 
      {
        bias_fbd=getBias_fbd(l, line);

        if( line[l].typ=='a' )  /* arc-line */
        {
          printf (" line:%s typ:a p1:%s p2:%s pc:%s div:%d bias:%d bias_el:%lf etyp:%d attr:%d\n"
          , line[l].name, point[line[l].p1].name,
          point[line[l].p2].name, point[line[l].trk].name, line[l].div, bias_fbd, line[l].bias, line[l].etyp, line[l].eattr);
          sprintf(parameter[4],"%s",point[line[l].trk].name);
        }
        else if( line[l].typ=='s' )  /* seq-line */
        {
          printf (" line:%s typ:s p1:%s p2:%s set:%s div:%d bias:%d bias_el:%lf etyp:%d attr:%d\n"
          , line[l].name, point[line[l].p1].name,
          point[line[l].p2].name, set[line[l].trk].name, line[l].div, bias_fbd, line[l].bias, line[l].etyp, line[l].eattr);
          sprintf(parameter[4],"%s",set[line[l].trk].name);
        }
        else  /* its a straight line   */
        {
          printf (" line:%s typ:l p1:%s p2:%s trk:- div:%d bias:%d bias_el:%lf etyp:%d attr:%d\n"
          , line[l].name, point[line[l].p1].name,
          point[line[l].p2].name, line[l].div, bias_fbd, line[l].bias, line[l].etyp, line[l].eattr);
          sprintf(parameter[4],"-");
        }
        sprintf(parameter[0],"%s",line[l].name);
        sprintf(parameter[1],"%c",line[l].typ);
        sprintf(parameter[2],"%s",point[line[l].p1].name);
        sprintf(parameter[3],"%s",point[line[l].p2].name);
        sprintf(parameter[5],"%d",line[l].div);
        sprintf(parameter[6],"%d",bias_fbd);
        sprintf(parameter[7],"%f",line[l].bias);
        sprintf(parameter[8],"%d",line[l].etyp);
        sprintf(parameter[9],"%d",line[l].eattr);
        write2stack(10, parameter);
      }
    }
    for (i=0; i<set[setNr].anz_c; i++)
    {
      p=set[setNr].lcmb[i];
      if( lcmb[p].name != (char *)NULL ) 
      {
        printf (" lcmb:%s ", lcmb[p].name );
        for (j=0; j<lcmb[p].nl; j++)
          printf (" %1c %s", lcmb[p].o[j], line[lcmb[p].l[j]].name );
        printf (" \n");
      }
    }
    for (i=0; i<set[setNr].anz_s; i++)
    {
      p=set[setNr].surf[i];
      if( surf[p].name != (char *)NULL ) 
      {
	  // printf("sh:%d\n",surf[p].sh);
        if (surf[p].sh==-1) printf (" surf:%s %1c BLEND ", surf[p].name, surf[p].ori );
        else if (surf[p].sh>-1) printf (" surf:%s %1c %s ", surf[p].name, surf[p].ori, shape[surf[p].sh].name );
        for (j=0; j<surf[p].nl; j++)
        {
          nl=surf[p].l[j];
          if (surf[p].typ[j]=='l')
          {
            printf (" %1c %s", surf[p].o[j], line[nl].name );
          }
          else
          {
            printf (" %1c %s", surf[p].o[j], lcmb[nl].name );
            for (k=0; k<lcmb[nl].nl; k++ )
            {
              nc=lcmb[nl].l[k];
              printf (" (%c) (%s)", lcmb[nl].o[k], line[nc].name );
            }
          }
        }
        printf (" etyp:%d attr:%d\n", surf[p].etyp, surf[p].eattr);
      }
    }
    for (i=0; i<set[setNr].anz_b; i++)
    {
      p=set[setNr].body[i];
      if( body[p].name != (char *)NULL ) 
      {
        printf (" body:%s %1c", body[p].name, body[p].ori );
        for (j=0; j<body[p].ns; j++)
          printf (" %1c %s", body[p].o[j], surf[body[p].s[j]].name );
        printf (" etyp:%d attr:%d\n", body[p].etyp, body[p].eattr);
      }
    }
    for (i=0; i<set[setNr].anz_nurl; i++)
    {
      nr=set[setNr].nurl[i];
      if( nurbl[nr].name != (char *)NULL ) 
      {
        printf (" nurl:%s\n", nurbl[nr].name );
        printf (" coefficients: exp:%d pnts:%d nods:%d End:%d\n", nurbl[nr].u_exp, nurbl[nr].u_npnt, nurbl[nr].u_nknt, nurbl[nr].endFlag);
        for (k=0; k<nurbl[nr].u_nknt; k++) printf("u-node[%d] = %lf\n", k+1, nurbl[nr].uknt[k]);
        for (k=0; k<nurbl[nr].u_npnt; k++)
        {
          printf("cpnt[%d]:%s x=%lf y=%lf z=%lf w=%lf\n", k+1, point[nurbl[nr].ctlpnt[k]].name, point[nurbl[nr].ctlpnt[k]].px,
          point[nurbl[nr].ctlpnt[k]].py, point[nurbl[nr].ctlpnt[k]].pz, nurbl[nr].weight[k]);
        }
      }
    }
    for (i=0; i<set[setNr].anz_nurs; i++)
    {
      nr=set[setNr].nurs[i];
     if( nurbs[nr].name != (char *)NULL ) 
     {
      printf (" nurs:%s\n", nurbs[nr].name );

      printf (" coefficients: u_exp:%d v_exp:%d u_npnt:%d v_npnt:%d u_nnod:%d v_nnod:%d End:%d\n", nurbs[nr].u_exp, nurbs[nr].v_exp,
        nurbs[nr].u_npnt, nurbs[nr].v_npnt, nurbs[nr].u_nknt, nurbs[nr].v_nknt, nurbs[nr].endFlag);
      for (k=0; k<nurbs[nr].u_nknt; k++) printf("u-node[%d] = %lf\n", k+1, nurbs[nr].uknt[k]);
      for (k=0; k<nurbs[nr].v_nknt; k++) printf("v-node[%d] = %lf\n", k+1, nurbs[nr].vknt[k]);
      for (k=0; k<nurbs[nr].u_npnt; k++)
      {
        for (j=0; j<nurbs[nr].v_npnt; j++)
        {
          printf("cpnt[%d][%d]:%s x=%lf y=%lf z=%lf w=%lf \n", k+1, j+1, point[nurbs[nr].ctlpnt[k][j]].name, point[nurbs[nr].ctlpnt[k][j]].px,
          point[nurbs[nr].ctlpnt[k][j]].py, point[nurbs[nr].ctlpnt[k][j]].pz, nurbs[nr].weight[k][j]);
        }
      }
     }
    }
    for (i=0; i<set[setNr].anz_se; i++)
    {
      p=set[setNr].set[i];
      if( set[p].name != (char *)NULL ) 
      {
        printf (" set:%s ", set[p].name );
        printf (" \n");
      }
    }
    for (i=0; i<set[setNr].anz_sh; i++)
    {
      p=set[setNr].shp[i];
      if( shape[p].name != (char *)NULL ) 
      {
        printf (" shape:%s p1:%s p2:%s p3:%s\n", shape[p].name, point[shape[p].p[0]].name, point[shape[p].p[1]].name, point[shape[p].p[2]].name );
      }
    }
    for (i=0; i<set[setNr].anz_v; i++)
    {
      p=set[setNr].valu[i];
      if( value[p].name != (char *)NULL ) 
      {
        printf (" value:%s string:%s\n", value[p].name, value[p].string);
      }
    }
    printf (" %d nodes, %d elements, %d faces, %d Points, %d Lines, %d Lcmb, %d Surfs, %d Bodys, %d Nurl, %d Nurs, %d sets, %d shapes, %d values stored\n", set[setNr].anz_n, set[setNr].anz_e, set[setNr].anz_f, set[setNr].anz_p, set[setNr].anz_l, set[setNr].anz_c, set[setNr].anz_s, set[setNr].anz_b, set[setNr].anz_nurl, set[setNr].anz_nurs, set[setNr].anz_se, set[setNr].anz_sh, set[setNr].anz_v );
  }
// end "LIST"
//-------------------------------------------------
  else if ((compare( typ, "sh", 2) == 2) ||(compare( typ, "SH", 2) == 2))
  {
    l=getShapeNr(name);
    if (l<0)
    {
      printf (" prnt: shape:%s does not exist\n", name);
      fflush(NULL); fclose(f); flag(); return (-1);
    }
    if( shape[l].name != (char *)NULL ) 
    {
      printf (" shape:%s p1:%s p2:%s p3:%s\n", shape[l].name, point[shape[l].p[0]].name, point[shape[l].p[1]].name, point[shape[l].p[2]].name);
    }
  }
  else if ((compare( typ, "sq", 2) == 2) ||(compare( typ, "SQ", 2) == 2))
  {
    if (length==1)
    {
      /* list all existing sequential sets */
      l=0;
      for (i=0; i<anz->sets; i++)
      {
        if( set[i].name != (char *)NULL )
        {
          if (set[i].type)
	  {
            l++;
            printf (" %s type:SEQ stat:%c n:%d p:%d\n", set[i].name, set[i].flag, set[i].anz_n, set[i].anz_p);
	  }
        }
      }
      if (!l) printf(" no sequences defined\n");
      fflush(NULL); fclose(f); flag(); return(1);
    }
    else 
    {
      setNr=getSetNr(name);
      if (setNr<0)
      {
        /* set was not found. check if wildcards (*) were used */
        length= strsplt( name, '*', &dat);
        if ((length>0)&&(strstr(name, "*") !=NULL))
	{
          j=0;
          for(setNr=0; setNr<anz->sets; setNr++) if(set[setNr].name!=(char *)NULL)
	  {
            foundSubString=0;
            for(i=0; i<length; i++)
            {
              if(strstr(set[setNr].name, dat[i]) !=NULL)
	      {
	        foundSubString++;
	        /* check if the first or the last char is no '*' then the dat[] must be at start or end */
	        if(i==0) { if(name[0]!='*')  { if(name[0]!=set[setNr].name[0])  foundSubString--; }  }
         	if(i==length-1) { if(name[strlen(name)-1]!='*') { if(name[strlen(name)-1]!=set[setNr].name[strlen(set[setNr].name)-1])  foundSubString--; } }
	      }
	    }
            if(foundSubString==length)
	    {
	      i=setNr;
              if (set[i].type)
              {
                printf ("%s type:SEQ stat:%c n:%d p:%d\n", set[i].name, set[i].flag, set[i].anz_n, set[i].anz_p);
		j++;
              }
	    }
	  }
          if(j!=0) {fflush(NULL); fclose(f); flag(); return(1);}
	}
        printf (" prnt: seq:%s does not exist\n", name);
        fflush(NULL); fclose(f); flag(); return(-1);
      }
    }
    if (!set[setNr].type) {fflush(NULL); fclose(f); flag(); return(0);}

    if(anz->l)
    {
      printf (" node:    value:       x:            y:           z:\n");
      for (i=0; i<set[setNr].anz_n; i++)
      {
        sprintf(parameter[0],"%8d",set[setNr].node[i]);
        sprintf(parameter[1],"%6e",lcase[cur_lc].dat[cur_entity][set[setNr].node[i]]);
        sprintf(parameter[2],"%12f",node[set[setNr].node[i]].nx* scale->w+scale->x);
        sprintf(parameter[3],"%12f",node[set[setNr].node[i]].ny* scale->w+scale->y);
        sprintf(parameter[4],"%12f",node[set[setNr].node[i]].nz* scale->w+scale->z);
        printf (" %s %s %s %s %s\n",parameter[0],parameter[1],parameter[2],parameter[3],parameter[4]);
        write2stack(5, parameter);
      }
    }
    else
    {
      printf (" node:       x:            y:           z:\n");
      for (i=0; i<set[setNr].anz_n; i++)
      {
        sprintf(parameter[0],"%8d",set[setNr].node[i]);
        sprintf(parameter[1],"%12f",node[set[setNr].node[i]].nx* scale->w+scale->x);
        sprintf(parameter[2],"%12f",node[set[setNr].node[i]].ny* scale->w+scale->y);
        sprintf(parameter[3],"%12f",node[set[setNr].node[i]].nz* scale->w+scale->z);
        printf (" %s %s %s %s\n",parameter[0],parameter[1],parameter[2],parameter[3]);
        write2stack(4, parameter);
      }
    }
    for (i=0; i<set[setNr].anz_p; i++)
    {
      p=set[setNr].pnt[i];
      if( point[p].name != (char *)NULL ) 
        printf (" pnt:%s x:%lf y:%lf z:%lf\n", point[p].name,
        (point[p].px* scale->w+scale->x),
        (point[p].py* scale->w+scale->y),
        (point[p].pz* scale->w+scale->z) );
    }
  }


  else if ((typ[0]=='n')||(typ[0]=='N'))
  {
    nr=atoi(name);
    if(anz->l)
    {
      printf (" node:%d v:%lf x:%lf y:%lf z:%lf\n", nr, lcase[cur_lc].dat[cur_entity][nr],
        (node[nr].nx* scale->w+scale->x),
        (node[nr].ny* scale->w+scale->y),
        (node[nr].nz* scale->w+scale->z) );
      sprintf(parameter[0],"%d", nr);
      sprintf(parameter[1],"%lf",lcase[cur_lc].dat[cur_entity][nr]);
      sprintf(parameter[1],"%lf",node[nr].nx * scale->w+scale->x);
      sprintf(parameter[2],"%lf",node[nr].ny * scale->w+scale->y);
      sprintf(parameter[3],"%lf",node[nr].nz * scale->w+scale->z);
      write2stack(5, parameter);
    }
    else
    {
      printf (" node:%d xyz: %lf %lf %lf\n", nr,
        (node[nr].nx* scale->w+scale->x),
        (node[nr].ny* scale->w+scale->y),
        (node[nr].nz* scale->w+scale->z) );
      sprintf(parameter[0],"%d", nr);
      sprintf(parameter[1],"%lf",node[nr].nx * scale->w+scale->x);
      sprintf(parameter[2],"%lf",node[nr].ny * scale->w+scale->y);
      sprintf(parameter[3],"%lf",node[nr].nz * scale->w+scale->z);
      write2stack(4, parameter);
    }
  }
  else if ((typ[0]=='e')||(typ[0]=='E'))
  {
    nr=atoi(name);
    printf (" elem:%d ",  nr);
    if     (e_enqire[nr].type==1) k=8;
    else if(e_enqire[nr].type==2) k=6;
    else if(e_enqire[nr].type==3) k=4;
    else if(e_enqire[nr].type==4) k=20;
    else if(e_enqire[nr].type==5) k=15;
    else if(e_enqire[nr].type==6) k=10;
    else if(e_enqire[nr].type==7) k=3;
    else if(e_enqire[nr].type==8) k=6;
    else if(e_enqire[nr].type==9) k=4;
    else if(e_enqire[nr].type==10) k=8;
    else if(e_enqire[nr].type==11) k=2;
    else if(e_enqire[nr].type==12) k=3;
    else k=0;
    for (n=0; n<k; n++) printf("%d ",e_enqire[nr].nod[n]);
    printf("\n"); 
  }
  else if ((typ[0]=='f')||(typ[0]=='F'))
  {
    nr=atoi(name);
    printf (" face:%d elem:%d side:%d nodes:",  nr, face[nr].elem_nr, face[nr].nr+1);
      if(face[nr].type==7) k=3;
      else if(face[nr].type==8) k=6;
      else if(face[nr].type==9) k=4;
      else if(face[nr].type==10) k=8;
      else if(face[nr].type==11) k=2;
      else if(face[nr].type==12) k=3;
      else k=0;
      for (n=0; n<k; n++) printf("%d ",face[nr].nod[n]);
      printf("\n"); 
  }
  else if ((typ[0]=='p')||(typ[0]=='P'))
  {
    p=getPntNr(name);
    if (p<0)
    {
      printf (" prnt: point:%s does not exist\n", name);
      fflush(NULL); fclose(f); flag(); return (-1);
    }
    if( point[p].name != (char *)NULL )
    {
      printf (" pnt:%s x:%lf y:%lf z:%lf\n", point[p].name,
      (point[p].px* scale->w+scale->x),
      (point[p].py* scale->w+scale->y),
      (point[p].pz* scale->w+scale->z) );
      sprintf(parameter[0],"%s", point[p].name);
      sprintf(parameter[1],"%lf", point[p].px* scale->w+scale->x);
      sprintf(parameter[2],"%lf", point[p].py* scale->w+scale->y);
      sprintf(parameter[3],"%lf", point[p].pz* scale->w+scale->z);
      write2stack(4, parameter);
    }
  }
  else if ((typ[0]=='l')||(typ[0]=='L'))
  {
    l=getLineNr(name);
    if (l<0)
    {
      printf (" prnt: line:%s does not exist\n", name);
      fflush(NULL); fclose(f); flag(); return (-1);
    }
    if( line[l].name != (char *)NULL ) 
    {
      bias_fbd=getBias_fbd(l, line);

      if( line[l].typ=='a' )  /* arc-line */
      {
        printf (" line:%s p1:%s p2:%s pc:%s div:%d bias:%d bias_el:%lf etyp:%d attr:%d\n"
        , line[l].name, point[line[l].p1].name,
        point[line[l].p2].name, point[line[l].trk].name, line[l].div, bias_fbd, line[l].bias, line[l].etyp, line[l].eattr);
      }
      else if( line[l].typ=='s' )  /* seq-line */
      {
        printf (" line:%s p1:%s p2:%s set:%s div:%d bias:%d bias_el:%lf etyp:%d attr:%d\n"
        , line[l].name, point[line[l].p1].name,
        point[line[l].p2].name, set[line[l].trk].name, line[l].div, bias_fbd, line[l].bias, line[l].etyp, line[l].eattr);
      }
      else  /* its a straight line   */
      {
        printf (" line:%s p1:%s p2:%s div:%d bias:%d bias_el:%lf etyp:%d attr:%d\n"
        , line[l].name, point[line[l].p1].name,
        point[line[l].p2].name, line[l].div, bias_fbd, line[l].bias, line[l].etyp, line[l].eattr);
      }
    }
  }
  else if ((typ[0]=='c')||(typ[0]=='C'))
  {
    l=getLcmbNr(name);
    if (l<0)
    {
      printf (" prnt: lcmb:%s does not exist\n", name);
      fflush(NULL); fclose(f); flag(); return (-1);
    }  
    if( lcmb[l].name != (char *)NULL ) 
    {
      printf (" lcmb:%s ", lcmb[l].name );
      for (j=0; j<lcmb[l].nl; j++)
        printf (" %1c %s", lcmb[l].o[j], line[lcmb[l].l[j]].name );
      printf (" \n");
    }
  }
  else if ((typ[0]=='s')||(typ[0]=='S'))
  {
    p=getSurfNr(name);
    if (p<0)
    {
      printf (" prnt: surf:%s does not exist\n", name);
      fflush(NULL); fclose(f); flag(); return (-1);
    }  
    if( surf[p].name != (char *)NULL ) 
    {
      if (surf[p].sh==-1) printf (" surf:%s %1c BLEND ", surf[p].name, surf[p].ori );
      else if (surf[p].sh>-1) printf (" surf:%s %1c %s ", surf[p].name, surf[p].ori, shape[surf[p].sh].name );
      for (j=0; j<surf[p].nl; j++)
      {
        nl=surf[p].l[j];
        if (surf[p].typ[j]=='l')
        {
          printf (" %1c %s", surf[p].o[j], line[nl].name );
        }
        else
        {
          printf (" %1c %s", surf[p].o[j], lcmb[nl].name );
          for (k=0; k<lcmb[nl].nl; k++ )
          {
            nc=lcmb[nl].l[k];
            printf (" (%c) (%s)", lcmb[nl].o[k], line[nc].name );
          }
        }
      }
      printf (" etyp:%d attr:%d\n", surf[p].etyp, surf[p].eattr);
    }
  }
  else if ((typ[0]=='b')||(typ[0]=='B'))
  {
    p=getBodyNr(name);
    if (p<0)
    {
      printf (" prnt: body:%s does not exist\n", name);
      fflush(NULL); fclose(f); flag(); return (-1);
    }  
    if( body[p].name != (char *)NULL ) 
    {
      printf (" body:%s %1c", body[p].name, body[p].ori );
      for (j=0; j<body[p].ns; j++)
        printf (" %1c %s", body[p].o[j], surf[body[p].s[j]].name );
      printf (" etyp:%d attr:%d\n", body[p].etyp, body[p].eattr);
    }
  }
  else if ((typ[0]=='v')||(typ[0]=='V'))
  {
    if (length==1)
    {
      /* list all existing values */
      for (i=0; i<anz->v; i++)
      {
        if( value[i].name != (char *)NULL )
        {
          printf (" value %s stores %s\n", value[i].name, value[i].string );
        }
      }
      fflush(NULL); fclose(f); flag(); return(1);
    }
    p=getValuNr(name);
    if (p<0)
    {
      printf (" prnt: value:%s does not exist\n", name);
      fflush(NULL); fclose(f); flag(); return (-1);
    }  
    if( value[p].name != (char *)NULL ) 
    {
      printf (" value %s stores %s\n", value[p].name, value[p].string );

      /* split the value[p].string in separate strings at ' ' occurences and write them to the stack */
      strcpy(param,value[p].string);
      for(args=0, str=param; ; args++, str=NULL)
      {
        token = strtok_r(str," ", &saveptr);
        if(token == NULL) break;
        if(args == 20) break;
        strcpy(parameter[args],token);
      }
      write2stack(args, parameter);
    }
  }
  fflush(NULL); fclose(f); flag(); return(1);
}

// prnt2() end

void process_string (char str[]) // prool
{
char *set;

if (set=strstr(str,"SET="))
	{
	//printf("process_string `%s'",str);
	strcpy(set+4,set+5);
	//printf("->`%s'\n",str);
	}
}

void filter_string (char str[]) // prool
{
char *set;

if (set=strstr(str,"TYPE=STRI65"))
	{
	printf("filter_string `%s`\n",str);
	strcpy(set,"TYPE=S6");
	strcpy(set+7,set+11);
	printf("->`%s'\n",str);
	}
}

void process_string2 (char str[]) // prool
{
char *set;

if (set=strstr(str,"NAME="))
	{
	//printf("1. %s\n",str);
	strcpy(set+5,set+6);
	//printf("2. %s\n",str);
	}
}

void echo (char *str) // prool
{
char param1 [STRLEN], param2[STRLEN], *pp;
int i;

printf("echo `%s'", str);
strcpy(param1,str);
param2[0]=0;
for (i=0;i<STRLEN;i++)
	if (param1[i]==' ')
		{
		param1[i]=0;
		strcpy(param2,str+i+1);
		break;
		}
	else    if (param1[i]==0) break;
printf(" param1=`%s' param2=`%s'\n", param1, param2);
}

int get_parameter(char parameter[STRLEN], char string[STRLEN])
{int i;

if (string[0]==0) {parameter[0]=0; return 0;}

strcpy(parameter, string);

//printf("get_parameter: `%s', `%s'\n", string, parameter);

for (i=0;i<STRLEN;i++)
	if (parameter[i]==' ')
		{
		parameter[i]=0;
		strcpy(string,string+i+1);
		return 1;
		}
	else    if (parameter[i]==0)
			{
			string[0]=0;
			return 0;
			}
}

int zamena_spos(char *str) // prool
{
char buffer[STRLEN];
char *pp;

if (pp=strstr(str,", SPOS"))
	{
	printf("DEBUG zamena_spos(). str=`%s'\n", str);
	strcpy(buffer,pp+6);
	strcpy(pp,", P");
	strcpy(pp+3,buffer);
	printf("DEBUG zamena_spos(). buffer=`%s'\n", buffer);
	printf("DEBUG zamena_spos(). str=`%s'\n", str);
	}
}

int zamena_ppos(char *str) // prool
{
char buffer[STRLEN];
char *pp;

if (pp=strstr(str,", PPOS"))
	{
	printf("DEBUG zamena_ppos(). str=`%s'\n", str);
	strcpy(buffer,pp+6);
	strcpy(pp,", P");
	strcpy(pp+3,buffer);
	printf("DEBUG zamena_ppos(). buffer=`%s'\n", buffer);
	printf("DEBUG zamena_ppos(). str=`%s'\n", str);
	}
}

int zamena_s8(char *str) // prool
{
char buffer[STRLEN];
char *pp;

if (!strstr(str,"TYPE=S8R")) if (pp=strstr(str,"TYPE=S8"))
	{
	printf("DEBUG zamena_s8(). str=`%s'\n", str);
	strcpy(buffer,pp+7);
	*(pp+7)='R';
	strcpy(pp+8,buffer);
	printf("DEBUG zamena_s8(). buffer=`%s'\n", buffer);
	printf("DEBUG zamena_s8(). str=`%s'\n", str);
	}
}

void sendaster (char *path) // prool
{
pre_write(" all aster ");
move_file("all.mail", path);
}

void sendans (char *path) // prool
{
pre_write(" all ans ");
move_file("all.msh", path);
}

void sendnas (char *path) // prool
{
pre_write(" all nas ");
move_file("all.bdf", path);
}

void sendstl (char *path) // prool
{
pre_write(" all stl ");
move_file("mesh.stl", path);
}

void sendpres (char *str) // prool
{
char param1 [STRLEN], param2[STRLEN], param3[STRLEN];
char komando[STRLEN], buf[STRLEN], name_from[STRLEN], *pp;
FILE *file_to, *file_from;
int i;

printf("str=`%s'\n", str);

if (str[0]==0) return;

param1[0]=0; param2[0]=0; param3[0]=0;
if (get_parameter(param1, str)) if (get_parameter(param2, str)) get_parameter(param3, str);

if ((param1[0]*param2[0]*param3[0])==0) return;

printf("p1=%s p2=%s p3=%s\n", param1, param2, param3);
//printf("p1=`%s'\n", param1);

sprintf(komando, " %s abq pres %s \n", param1, param2);
printf("komando=%s\n", komando);
pre_write(komando);
if (1)
	{// move file
	sprintf(name_from,"%s.dlo",param1);
	printf(" `%s' -> `%s'\n", name_from, param3);
	file_to=fopen(param3,"w");
	if (file_to==NULL) {printf("sendpres error 1\n"); return;}

	file_from=fopen(name_from,"r");
	if (file_from==NULL) {printf("sendpres error 2\n"); return;}

	while (fgets(buf, STRLEN, file_from))
		{
		printf("#");
		fputs(buf, file_to);
		}
	fflush(NULL);
	fclose(file_from);
	fclose(file_to);
	fflush(NULL);
	printf("\n");

	unlink(name_from);

	}// move file

}

int move_file (char *file1, char *file2) // prool
	{FILE *file_from, *file_to;
	char buf[STRLEN];

	printf("move_file `%s' -> `%s'\n", file1, file2);

	file_from=fopen(file1,"r");
	if (file_from==NULL) {printf("move_file error 1: file1 not opened\n"); return 1;}

	file_to=fopen(file2,"w");
	if (file_to==NULL) {printf("move_file error 2: file2 not opened\n"); return 2;}

	while (fgets(buf, STRLEN, file_from))
		{
		fputs(buf, file_to);
		}
	fflush(NULL);
	fclose(file_from);
	fclose(file_to);
	fflush(NULL);

	unlink(file1);

	return 0;
	}// move_file

int s_flag(char *str) // prool
{
// this is BYDLOKOD. prool
if (strstr(str,", S"))
	{
	if (strstr(str,", S3")) return 1;
	if (strstr(str,", S4")) return 1;
	if (strstr(str,", S5")) return 1;
	if (strstr(str,", S6")) return 1;
	}
return 0;
}

int p_flag(char *str) // prool
{
// this is BYDLOKOD. prool
if (strstr(str,", P"))
	{
	if (strstr(str,", P3")) return 1;
	if (strstr(str,", P4")) return 1;
	if (strstr(str,", P5")) return 1;
	if (strstr(str,", P6")) return 1;
	}
return 0;
}

void sendpres4shell (char *str) // prool
{
char param1 [STRLEN], param2[STRLEN], param3[STRLEN];
char komando[STRLEN], buf[STRLEN], name_from[STRLEN], *pp;
FILE *file_to, *file_from;
int i;

printf("str=`%s'\n", str);

if (str[0]==0) return;

param1[0]=0; param2[0]=0; param3[0]=0;
if (get_parameter(param1, str)) if (get_parameter(param2, str)) get_parameter(param3, str);

if ((param1[0]*param2[0]*param3[0])==0) return;

printf("p1=%s p2=%s p3=%s\n", param1, param2, param3);
//printf("p1=`%s'\n", param1);

sprintf(komando, " %s abq pres %s \n", param1, param2);
printf("komando=%s\n", komando);
pre_write(komando);
if (1)
	{// move file
	sprintf(name_from,"%s.dlo",param1);
	printf(" `%s' -> `%s'\n", name_from, param3);
	file_to=fopen(param3,"w");
	if (file_to==NULL) {printf("sendpres4 error 1\n"); return;}

	file_from=fopen(name_from,"r");
	if (file_from==NULL) {printf("sendpres4 error 2\n"); return;}

	while (fgets(buf, STRLEN, file_from))
		{
		if (p_flag(buf)) continue;
		zamena_ppos(buf);
		printf("#");
		fputs(buf, file_to);
		}
	fflush(NULL);
	fclose(file_from);
	fclose(file_to);
	fflush(NULL);
	printf("\n");

	unlink(name_from);

	}// move file

}

void writeone(char *path) // prool
{
FILE *allinone;
DIR *dir;
struct dirent *file;
char buf[STRLEN];
int string_num=1, node_num=0;
char current_dir[255], fullname[255];

printf("WRITEONE command:\n");
printf("path = `%s'\n", path);
//if (path[0]==0) printf("path is zero ;)\n");

printf("exec SEND ALL ABQ\n");
pre_write(" all abq ");
                                    
printf("execute SEND ALL ABQ NAM\n");
pre_write(" all abq nam ");

getcwd(current_dir, 255);
printf("current dir = %s\n", current_dir);

#define ALLINONE "allinone.inp"

if (path[0]) {strcpy(fullname,path); strcat(fullname,"\\"); strcat(fullname,ALLINONE);}
else strcpy(fullname,ALLINONE);

printf("fullname = %s\n", fullname);
printf("copy all.msh ->\n");

allinone=fopen(fullname,"w");
if (allinone==NULL) {printf("writeone error 1\n"); return;}

f=fopen("all.msh","r");
if (f==NULL) {printf("writeone error 2\n"); return;}

while (fgets(buf, STRLEN, f))
	{
	if (string_num++==2)
		{
		sscanf(buf,"%i",&node_num);
		if (node_num==0)
			{
			printf("zero node skipped :)\n");
			continue;
			}
		}
	// process_string(buf);
	filter_string(buf);
	zamena_s8(buf);
	fputs(buf, allinone);
	}
fclose(f);

unlink("all.msh");

fputs("", allinone); // empty string

dir=opendir(".");
while(file=readdir(dir))
	{char *fn;
	fn=file->d_name;
	if (strlen(fn)>4)
		if (!strcmp(fn+strlen(fn)-4,".nam"))
			{
			if (!strcmp(fn,"all.nam"))  { unlink(fn); continue; }
			if (!strcmp(fn,"Eall.nam")) { unlink(fn); continue; }
			if (!strcmp(fn,"Nall.nam")) { unlink(fn); continue; }
			{
			printf("copy %s ->\n",fn);
			f=fopen(fn,"r");
			if (f==NULL) {printf("writeone error 2A\n"); return;}
			while (fgets(buf, STRLEN, f))
				{
				process_string(buf);
				filter_string(buf);
				zamena_s8(buf);
				fputs(buf, allinone);
				}
			fclose(f);
			unlink(fn);
			fputs("", allinone); // empty string
			}
			}
	}
closedir(dir);

fflush(NULL);
fclose(allinone);
flag(); 
}

void writeinone(char *path) // prool
{
FILE *allinone;
DIR *dir;
struct dirent *file;
char buf[STRLEN];
int string_num=1, node_num=0;
char current_dir[255], fullname[255];

printf("WRITEONE command:\n");
printf("path = `%s'\n", path);
//if (path[0]==0) printf("path is zero ;)\n");

printf("exec SEND ALL ABQ\n");
pre_write(" all abq ");
                                    
printf("execute SEND ALL ABQ NAM\n");
pre_write(" all abq nam ");

printf("execute SEND ALL ABQ SUR\n");
pre_write(" all abq sur ");

getcwd(current_dir, 255);
printf("current dir = %s\n", current_dir);

#define ALLINONE "allinone.inp"

if (path[0]) {strcpy(fullname,path); strcat(fullname,"\\"); strcat(fullname,ALLINONE);}
else strcpy(fullname,ALLINONE);

printf("fullname = %s\n", fullname);
printf("copy all.msh ->\n");

allinone=fopen(fullname,"w");
if (allinone==NULL) {printf("writeone error 1\n"); return;}

f=fopen("all.msh","r");
if (f==NULL) {printf("writeone error 2\n"); return;}

while (fgets(buf, STRLEN, f))
	{
	if (string_num++==2)
		{
		sscanf(buf,"%i",&node_num);
		if (node_num==0)
			{
			printf("zero node skipped :)\n");
			continue;
			}
		}
	// process_string(buf);
	filter_string(buf);
//	if (strstr(buf,", SPOS")) continue;
	zamena_s8(buf);
	fputs(buf, allinone);
	}
fclose(f);

unlink("all.msh");

fputs("", allinone); // empty string

dir=opendir(".");
while(file=readdir(dir))
	{char *fn, *pp2, gruppa[255], komanda[255];
	fn=file->d_name;
	if (strlen(fn)>4)
		if (!strcmp(fn+strlen(fn)-4,".nam"))
			{
			if (!strcmp(fn,"all.nam"))  { unlink(fn); continue; }
			if (!strcmp(fn,"Eall.nam")) { unlink(fn); continue; }
			if (!strcmp(fn,"Nall.nam")) { unlink(fn); continue; }
			{
			printf("copy %s ->\n",fn);

				// send <èìÿ ãðóïïû> abq sur
				strcpy(gruppa,fn);
				pp2=strchr(gruppa,'.');
				if (pp2) *pp2=0;
				sprintf(komanda," %s abq sur ",gruppa);
				printf("execute %s\n", komanda);
				pre_write(komanda);
				
			f=fopen(fn,"r");
			if (f==NULL) {printf("writeone error 2A\n"); return;}
			while (fgets(buf, STRLEN, f))
				{
				process_string(buf);
				filter_string(buf);
//				if (strstr(buf,", SPOS")) continue;
				zamena_s8(buf);
				fputs(buf, allinone);
				}
			fclose(f);
			unlink(fn);
			fputs("", allinone); // empty string
			}
			}
	}
closedir(dir);

fputs("", allinone); // empty string

dir=opendir(".");
while(file=readdir(dir))
	{char *fn, *pp2, gruppa[255], komanda[255];
	fn=file->d_name;
	if (strlen(fn)>4)
		if (!strcmp(fn+strlen(fn)-4,".sur"))
			{
			if (!strcmp(fn,"all.nam"))  { unlink(fn); continue; }
			if (!strcmp(fn,"Eall.nam")) { unlink(fn); continue; }
			if (!strcmp(fn,"Nall.nam")) { unlink(fn); continue; }
			{
			printf("copy %s ->\n",fn);
			f=fopen(fn,"r");
			if (f==NULL) {printf("writeone error 2A\n"); return;}
			while (fgets(buf, STRLEN, f))
				{
				process_string2(buf);
				filter_string(buf);
//				if (strstr(buf,", SPOS")) continue;
				zamena_s8(buf);
				fputs(buf, allinone);
				}
			fclose(f);
			unlink(fn);
			fputs("", allinone); // empty string
			}
			}
	}
closedir(dir);

fflush(NULL);
fclose(allinone);
flag(); 
}
// end of writeinone() // by prool

void write4shell(char *path) // prool
{
FILE *allinone;
DIR *dir;
struct dirent *file;
char buf[STRLEN];
int string_num=1, node_num=0;
char current_dir[255], fullname[255];

printf("WRIT4SHELL command:\n");
printf("path = `%s'\n", path);
//if (path[0]==0) printf("path is zero ;)\n");

printf("exec SEND ALL ABQ\n");
pre_write(" all abq ");
                                    
printf("execute SEND ALL ABQ NAM\n");
pre_write(" all abq nam ");

printf("execute SEND ALL ABQ SUR\n");
pre_write(" all abq sur ");

getcwd(current_dir, 255);
printf("current dir = %s\n", current_dir);

#define ALLINONE "allinone.inp"

if (path[0]) {strcpy(fullname,path); strcat(fullname,"\\"); strcat(fullname,ALLINONE);}
else strcpy(fullname,ALLINONE);

printf("fullname = %s\n", fullname);
printf("copy all.msh ->\n");

allinone=fopen(fullname,"w");
if (allinone==NULL) {printf("write4shell error 1\n"); return;}

f=fopen("all.msh","r");
if (f==NULL) {printf("writ4shell error 2\n"); return;}

while (fgets(buf, STRLEN, f))
	{
	if (string_num++==2)
		{
		sscanf(buf,"%i",&node_num);
		if (node_num==0)
			{
			printf("zero node skipped :)\n");
			continue;
			}
		}
	// process_string(buf);
	filter_string(buf);
//	zamena_spos(buf);
	if (s_flag(buf)) continue;
	zamena_s8(buf);
	fputs(buf, allinone);
	}
fclose(f);

unlink("all.msh");

fputs("", allinone); // empty string

dir=opendir(".");
while(file=readdir(dir))
	{char *fn, *pp2, gruppa[255], komanda[255];
	fn=file->d_name;
	if (strlen(fn)>4)
		if (!strcmp(fn+strlen(fn)-4,".nam"))
			{
			if (!strcmp(fn,"all.nam"))  { unlink(fn); continue; }
			if (!strcmp(fn,"Eall.nam")) { unlink(fn); continue; }
			if (!strcmp(fn,"Nall.nam")) { unlink(fn); continue; }
			{
			printf("copy %s ->\n",fn);

				// send <èìÿ ãðóïïû> abq sur
				strcpy(gruppa,fn);
				pp2=strchr(gruppa,'.');
				if (pp2) *pp2=0;
				sprintf(komanda," %s abq sur ",gruppa);
				printf("execute %s\n", komanda);
				pre_write(komanda);
				
			f=fopen(fn,"r");
			if (f==NULL) {printf("writ4shell error 2A\n"); return;}
			while (fgets(buf, STRLEN, f))
				{
				process_string(buf);
				filter_string(buf);
//				zamena_spos(buf);
				if (s_flag(buf)) continue;
				zamena_s8(buf);
				fputs(buf, allinone);
				}
			fclose(f);
			unlink(fn);
			fputs("", allinone); // empty string
			}
			}
	}
closedir(dir);

fputs("", allinone); // empty string

dir=opendir(".");
while(file=readdir(dir))
	{char *fn, *pp2, gruppa[255], komanda[255];
	fn=file->d_name;
	if (strlen(fn)>4)
		if (!strcmp(fn+strlen(fn)-4,".sur"))
			{
			if (!strcmp(fn,"all.nam"))  { unlink(fn); continue; }
			if (!strcmp(fn,"Eall.nam")) { unlink(fn); continue; }
			if (!strcmp(fn,"Nall.nam")) { unlink(fn); continue; }
			{
			printf("copy %s ->\n",fn);
			f=fopen(fn,"r");
			if (f==NULL) {printf("write4shell error 2A\n"); return;}
			while (fgets(buf, STRLEN, f))
				{
				process_string2(buf);
				filter_string(buf);
//				zamena_spos(buf);
				if (s_flag(buf)) continue;
				zamena_s8(buf);
				fputs(buf, allinone);
				}
			fclose(f);
			unlink(fn);
			fputs("", allinone); // empty string
			}
			}
	}
closedir(dir);

fflush(NULL);
fclose(allinone);
flag(); 
}
// end of write4shell() // by prool
