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

#include <extUtil.h>

#define TEST     0

#define INI_FIELD_SIZE 100000



int readStl( char *datin, Summen *anz, Nodes **nptr, Elements **eptr, Datasets **lptr )
{
  FILE *handle;
  int i=0, elemflag=0;

  char rec_str[MAX_LINE_LENGTH];
  char buffer[MAX_LINE_LENGTH];
  int  node_field_size, elem_field_size;
  int  e_nmax=1, e_nmin=1;
  int  length;

  Nodes     *node=NULL;
  Elements  *elem=NULL;



  node_field_size=INI_FIELD_SIZE;
  do
  {
    if ( (node = (Nodes *)realloc( (Nodes *)node, (node_field_size+1) * sizeof(Nodes))) == NULL )
    {
      printf("WARNING: in readfrd() is INI_FIELD_SIZE:%d to large and is reduced\n", node_field_size );
      node_field_size/=2;
    }
    if(node_field_size<100)
    {
      printf("\n\n ERROR: not enough memory in readfrd()\n\n");
      exit(-1);
    }
  }while(!node);

  elem_field_size=INI_FIELD_SIZE;
  do
  {
    if((elem = (Elements *)realloc( (Elements *)elem, (elem_field_size+1) * sizeof(Elements))) == NULL )
  	{
      printf("WARNING: in readfrd() is INI_FIELD_SIZE:%d to large and is reduced\n", elem_field_size );
      elem_field_size/=2;
    }
    if(elem_field_size<100)
    {
      printf("\n\n ERROR: not enough memory in readfrd()\n\n");
      exit(-1);
    }
  }while(!elem);

  anz->n=anz->e=anz->l=-1;

  /* Open the files and check to see that it was opened correctly */
  handle = fopen (datin, "r");
  if ( handle== NULL )  { printf ("ERROR: The input file \"%s\" could not be opened.\n\n", datin); return(-1); }
  else  printf (" file:%s opened\n", datin);

  printf (" reading stl format\n");

  length = frecord( handle, rec_str);
  sscanf(rec_str, "%s", buffer);
  for(i=0;i<strlen(buffer); i++) buffer[i]=toupper(buffer[i]);
  if(compare(buffer, "SOLID", 5)==5)
  {
    strcpy(anz->model, rec_str);
    printf (" MODEL NAME:  %s", anz->model);
  }
  else
  {
    printf ("\n\nFATAL ERROR: no proper file-format found.\n\n");
    return (-1);
  }

  anz->emax=-MAX_INTEGER;  anz->emin=MAX_INTEGER; elemflag=1;
  anz->nmax=-MAX_INTEGER;  anz->nmin= MAX_INTEGER;
  while(length)
  {
    length = frecord( handle, rec_str);
    if (rec_str[length] == (char)EOF) break;

    sscanf(rec_str, "%s", buffer);
    for(i=0;i<strlen(buffer); i++) buffer[i]=toupper(buffer[i]);
    if(compare(buffer, "FACET", 5)==5)
    {
      /* overread "outer loop" */
      length = frecord( handle, rec_str);
      for(i=0; i<3; i++)
      {
        anz->n++;
        node[anz->n].nr = anz->n+1;
        if (node[anz->n].nr>=node_field_size)
        {
          node_field_size=node[anz->n].nr+100;
          if ( (node = (Nodes *)realloc((Nodes *)node, (node_field_size+1) * sizeof(Nodes))) == NULL )
          {
            printf("\n\n ERROR: realloc failed, nodenr:%d\n\n", node[anz->n].nr) ;
            return(-1);
          }
        }
        node[node[anz->n].nr].indx=anz->n;

        length = frecord( handle, rec_str);
        sscanf(rec_str,"%*s %lf %lf %lf", &node[node[anz->n].nr].nx,&node[node[anz->n].nr].ny,&node[node[anz->n].nr].nz);
        if (node[anz->n].nr >  anz->nmax)  anz->nmax=node[anz->n].nr;
        if (node[anz->n].nr <  anz->nmin)  anz->nmin=node[anz->n].nr;
#if TEST
        printf (" n=%d x=%lf y=%lf z=%lf \n",  node[anz->n].nr,
        node[node[anz->n].nr].nx, node[node[anz->n].nr].ny,
        node[node[anz->n].nr].nz); 
#endif 
      }
      anz->e++;
      if (anz->e>=elem_field_size)
      {
        elem_field_size=anz->e+100;
        if((elem=(Elements *)realloc((Elements *)elem,(elem_field_size+1)*sizeof(Elements)))==NULL)
        {
          printf("\n\n ERROR: realloc failed, elem-index:%d\n\n", anz->e);
          return(-1);
        }
      }
      elem[anz->e].nr    = anz->e+1;
      elem[anz->e].type  = 7;
      elem[anz->e].group = 1;
      elem[anz->e].mat   = 1;
      anz->etype[elem[anz->e].type]++;
      if (elem[anz->e].nr >  anz->emax)  anz->emax=elem[anz->e].nr;
      if (elem[anz->e].nr <  anz->emin)  anz->emin=elem[anz->e].nr;
#if TEST
      printf (" e=%d typ=%d mat=%d \n", elem[anz->e].nr,
      elem[anz->e].type, elem[anz->e].group, elem[anz->e].mat );
#endif
      for (i=0; i<3; i++) elem[anz->e].nod[i]=node[anz->n-2+i].nr;
    }
  }
  anz->n++;
  anz->e++;
  anz->l++;
  fclose(handle);

  node_field_size=anz->nmax+1;
  if((node =(Nodes *)realloc( (Nodes *)node, node_field_size*sizeof(Nodes)))==NULL)
    printf("\n\n ERROR: realloc failed\n\n") ;
  else
    printf ("\n %d nodes reallocated \n",anz->nmax);

  elem_field_size=anz->e+1;
  if ( (elem = (Elements *)realloc((Elements *)elem, elem_field_size * sizeof(Elements))) == NULL )
    printf("\n\n ERROR: in readfrd realloc failed\n\n") ;
  else
    printf ("\n %d elements reallocated \n", anz->e);

  if ( e_nmax > (anz->nmax) )
  {
    printf ("\nWARNING: element requestes a nodename higher than allocated\n\n");
    printf (" e_nmax=%d e_nmin=%d\n", e_nmax, e_nmin );
  }
  if ( e_nmin < 1 )
  {
    printf ("\nWARNING: element requestes a nodename lower than allocated\n\n");
    printf (" e_nmax=%d e_nmin=%d\n", e_nmax, e_nmin );
  }
  elemChecker( anz->e, node, elem);

  *nptr = node; *eptr = elem;
  return(1);
}

