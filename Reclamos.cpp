#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <wchar.h>
#include <locale.h>

struct reclamo ingresoreclamo (int o);
struct reclamo modificacion (int p, char *u,char *d);
struct reclamo eliminacion (void);
void listar (FILE *fps, char*n);
void AltEnter();

struct reclamo{
	int baja;
	//char codigo[20];
	//char equipo[20];
	//char fecharec[25];
	//char horarec[25];
	//char fechavis[25];
	//char fechares[25];
	//char horaini[25];
	//char horafin[25];
	//char titulo[60];
	//char descripcion[60];
	//char tareavis[60];
	//char tareares[60];
	//char tecnico[40];
	int id;
	char codigo[10];
	char fecha [25];
	char edificio [60];
	char ascensor [40];
	char datos [260];
};

int main (int argc, char *argv[])
{
	setlocale(LC_CTYPE, "Spanish");
	SetConsoleCP(1252); 
    SetConsoleOutputCP(1252);
	system ("color 8F");
	int i,j;
	int o,p,q;
	int v=0;
	char u[10];
	char d[25];
	char nombre[100];
	char k=1;
	char t[60];
	char aux[60];
	char aux2[20];
	char extension[10]=".dat";
	char directorio[100];
	char copia[100]="C:\\Users\\nico_\\Desktop\\HWA\\Reclamos\\DAT\\";
	int aux3,aux4,aux5;
	FILE *fp;
	struct reclamo r;
	AltEnter ();
	while (k!='S')
	{
	j=1;  
	printf ("SOFTWARE DE RECLAMOS v1.0\n");
	printf ("\n***Menu***\n");
	printf ("\n1-  Abrir archivo de datos");
	printf ("\n2-  Ingresar reclamos");
	printf ("\n3-  Listar reclamos");
	printf ("\n4-  Exportar listado de reclamos");
	printf ("\n5-  Buscar reclamos por edificio");
	printf ("\n6-  Buscar reclamos por edificio y ascensor");
	printf ("\n7-  Modificar reclamos");
	printf ("\n8-  Eliminar reclamos");
	printf ("\n9-  Recuperar reclamos eliminados");
	printf ("\n10- Invertir iluminacion");
	printf ("\n0-  Salir\n");
	printf ("\nOpcion: ");
	scanf ("%d",&i);
    system ("cls");
	switch (i)
	{
		case 1:  
				strcpy(directorio," ");
				strcpy(directorio,copia);
				printf ("APERTURA DE ARCHIVOS");
		        printf ("\nIngrese nombre del archivo a abrir: ");   
		        scanf ("%s",&nombre);
		        strcat(nombre,extension);
		        strcat(directorio,nombre);
		        if ((fp=fopen(directorio,"rb+"))==NULL)
	            {
    	        printf ("\nARCHIVO NO ENCONTRADO!!");
    	        }else{
    	        printf ("\nARCHIVO ABIERTO!!");
				}
			    printf ("\n\nIngrese cualquier tecla para volver o 'S' para salir: ");
			    scanf ("%s",&k);
			    system ("cls");
			    break;        
		case 2:
	        	if ((fp=fopen(directorio,"rb+"))==NULL)
	            {
    	        printf ("ERROR AL ABRIR EL ARCHIVO!!");
			    printf ("\n\nIngrese cualquier tecla para volver o 'S' para salir: ");
			    scanf ("%s",&k);
			    system ("cls");
			    break;
	            }
	            fread (&r,sizeof(struct reclamo),1,fp);
	            while (!feof(fp))	
	            {
	        	o=r.id;
	        	fread (&r,sizeof(struct reclamo),1,fp);
			    }
	            while(j)
	            {
	            system ("cls");
	            printf ("INGRESO DE RECLAMOS\n\n");	
	            printf ("\n ID    Codigo     Fecha                      Nombre de edificio                 Ascensor                              Observaciones");
	            printf ("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
				rewind (fp);
	            fread (&r,sizeof(struct reclamo),1,fp);
		        while (!feof(fp))
			    {
				if (r.baja==0)
				{
				printf ("\n# %-5d%-10s %-10s   %-35s%-35s   %-10s\n",r.id,r.codigo,r.fecha,r.edificio,r.ascensor,r.datos);
			    }
			    fread (&r,sizeof(struct reclamo),1,fp);
			    }
			    o++;
	            printf ("\n\n");
	            r=ingresoreclamo(o);
		        fwrite (&r,sizeof(struct reclamo),1,fp);
		        system ("cls");
		        printf ("LISTADO DE RECLAMOS\n");
	            printf ("\n ID    Codigo     Fecha                      Nombre de edificio                 Ascensor                              Observaciones");
	            printf ("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
				rewind (fp);
	            fread (&r,sizeof(struct reclamo),1,fp);
		        while (!feof(fp))
			    {
				if (r.baja==0)
				{
				printf ("\n# %-5d%-10s %-10s   %-35s%-35s   %-10s\n",r.id,r.codigo,r.fecha,r.edificio,r.ascensor,r.datos);
			    }
			    fread (&r,sizeof(struct reclamo),1,fp);
			    }
		        printf ("\n\n\nIngrese cualquier tecla para ingresar un nuevo reclamo o '0' para volver: ");
	            scanf ("%d",&j);
	            }
	            fclose (fp);
			    system ("cls");
			    break;
		case 3:
			    if ((fp=fopen(directorio,"rb"))==NULL)
			    {
				printf ("ERROR AL ABRIR EL ARCHIVO!!");
			    printf ("\n\nIngrese cualquier tecla para volver o 'S' para salir: ");
			    scanf ("%s",&k);
			    system ("cls");
			    break;
			    }
			    printf ("LISTADO DE RECLAMOS\n");
	            printf ("\n ID    Codigo     Fecha                      Nombre de edificio                 Ascensor                              Observaciones");
	            printf ("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
			    fread (&r,sizeof(struct reclamo),1,fp);
			    while (!feof(fp))
			    {
				if (r.baja==0)
				{
				printf ("\n# %-5d%-10s %-10s   %-35s%-35s   %-10s\n",r.id,r.codigo,r.fecha,r.edificio,r.ascensor,r.datos); 
			    }
			    fread (&r,sizeof(struct reclamo),1,fp);
			    }
			    fclose (fp);
			    printf ("\n\nIngrese cualquier tecla para volver: ");
		    	scanf ("%s",&t);
			    system ("cls");
			    break;
		case 4:
			    fp=fopen ("C:\\Users\\nico_\\Desktop\\HWA\\Reclamos\\Reclamos.txt","wt");
			    listar (fp,directorio);
			    fclose(fp); 
			  	system ("C:\\Users\\nico_\\Desktop\\HWA\\Reclamos\\Reclamos.txt");	
			    system ("cls");	
			    break;	    
		case 5:
			    if ((fp=fopen(directorio,"rb"))==NULL)
		        {
				printf ("ERROR AL ABRIR EL ARCHIVO!!");
			    printf ("\n\nIngrese cualquier tecla para volver o 'S' para salir: ");
			    scanf ("%s",&k);
			    system ("cls");
			    break;
		    	}	
		        while(j)
		        { 	
		        system ("cls");
		        int l=0;
		   	    fflush (stdin);
				printf ("BUSCADOR DE RECLAMOS\n");	
		        printf ("\nIngrese edificio a buscar: ");	      
                gets (aux);
                rewind (fp);
                fread (&r,sizeof(struct reclamo),1,fp);	
                system ("cls");
                printf ("BUSCADOR DE RECLAMOS\n");
	            printf ("\n ID    Codigo     Fecha                      Nombre de edificio                 Ascensor                              Observaciones");
	            printf ("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
	            while (!feof(fp))
	            {
                // if (!strcmp(r.edificio,aux))
                if (strstr(r.edificio,aux)!=NULL)
                {
                if (r.baja==0)
                {
			    printf ("\n# %-5d%-10s %-10s   %-35s%-35s   %-10s\n",r.id,r.codigo,r.fecha,r.edificio,r.ascensor,r.datos); 
			    l++;	
			    } 
			    }
			    fread (&r,sizeof(struct reclamo),1,fp);    
			   	}   
				if (l<1)	
				{
				printf ("\n\nEdificio no encontrado\n");
				}	
		        printf ("\n\nIngrese cualquier tecla para una nueva consulta o '0' para volver: ");
	            scanf ("%d",&j);
	            }
	            fclose (fp);	
			    system ("cls");
			    break;
		case 6:
		 	    if ((fp=fopen(directorio,"rb"))==NULL)
		        {
				printf ("ERROR AL ABRIR EL ARCHIVO!!");
			    printf ("\n\nIngrese cualquier tecla para volver o 'S' para salir: ");
			    scanf ("%s",&k);
			    system ("cls");
			    break;
		    	}	
		        while(j)
		        { 	
		        int l=0;
		        int m=0;
		        fflush(stdin); 
		        printf ("BUSCADOR DE RECLAMOS\n");
		        printf ("\nIngrese edificio a buscar: ");
			    gets (aux);	      
                fflush (stdin);
                printf ("Ingrese ascensor a buscar: "); 
			    gets (aux2);
                rewind (fp);
                fread (&r,sizeof(struct reclamo),1,fp);	
                system ("cls");
                printf ("BUSCADOR DE RECLAMOS\n");
	            printf ("\n ID    Codigo     Fecha                      Nombre de edificio                 Ascensor                              Observaciones");
	            printf ("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
	            while (!feof(fp))
	             {
	             	if (r.baja==0)
					{
                    //if (!strcmp(r.edificio,aux))
                    if (strstr(r.edificio,aux)!=NULL)
                    {
                    	l++;
                    	//if (!strcmp(r.ascensor,aux2))
                    	if (strstr(r.ascensor,aux2)!=NULL)
                    	{
                    	printf ("\n# %-5d%-10s %-10s   %-35s%-35s   %-10s\n",r.id,r.codigo,r.fecha,r.edificio,r.ascensor,r.datos); 
					    m++;
					    }
					}
			        } 
			    fread (&r,sizeof(struct reclamo),1,fp);    
			   	}   
				if (l<1)	
				{
				printf ("\n\nEdificio no encontrado");
				}	
				if (m<1)
				{
				printf ("\n\nAscensor no encontrado");
				}
		        printf ("\n\n\nIngrese cualquier tecla para una nueva consulta o '0' para volver: ");
	            scanf ("%d",&j);
	            system ("cls");
	            }
	            fclose (fp);	
		    	system ("cls");
		    	break;
		case 7:
		 	    if ((fp=fopen(directorio,"rb+"))==NULL)
		        {
				printf ("ERROR AL ABRIR EL ARCHIVO!!");
			    printf ("\n\nIngrese cualquier tecla para volver o 'S' para salir: ");
			    scanf ("%s",&k);
			    system ("cls");
			    break;
		    	}	
		        while(j)
		        {	
		        system ("cls");
		        int l=0;
		   	    fflush (stdin);	
		   	    printf ("MODIFICADOR DE RECLAMOS\n");
	            printf ("\n ID    Codigo     Fecha                      Nombre de edificio                 Ascensor                              Observaciones");
	            printf ("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
	            rewind (fp);
	            fread (&r,sizeof(struct reclamo),1,fp);
		        while (!feof(fp))
			    {
				if (r.baja==0)
				{
			    printf ("\n# %-5d%-10s %-10s   %-35s%-35s   %-10s\n",r.id,r.codigo,r.fecha,r.edificio,r.ascensor,r.datos); 
			    }
			    fread (&r,sizeof(struct reclamo),1,fp);
			    }
				printf ("\n\nIngrese ID de reclamo a modificar: ");	      
                scanf ("%d",&aux3);
                rewind (fp);
                fread (&r,sizeof(struct reclamo),1,fp);	
                system ("cls");
                printf ("MODIFICADOR DE RECLAMOS\n");
	            printf ("\n ID    Codigo     Fecha                      Nombre de edificio                 Ascensor                              Observaciones");
	            printf ("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
	             while (!feof(fp))
	             {
                    if (r.id==aux3 && r.baja==0)
                    {
                    printf ("\n# %-5d%-10s %-10s   %-35s%-35s   %-10s\n",r.id,r.codigo,r.fecha,r.edificio,r.ascensor,r.datos); 
					p=r.id;	
					strcpy(u,r.codigo);
					strcpy(d,r.fecha);
					l++;
				    r=modificacion(p,u,d);
		            fseek (fp,(-1L)*sizeof(struct reclamo),1);
		            fwrite (&r,sizeof(struct reclamo),1,fp); 
		            printf ("\nReclamo modificado!!");
		            break;
			        } 
			        fread (&r,sizeof(struct reclamo),1,fp);	 	
			   	 }  
				if (l<1)	
				{
				printf ("\n\nReclamo no encontrado");
				}	
			    printf ("\n\n\nIngrese cualquier tecla para una nueva modificacion o '0' para volver: ");
	            scanf ("%d",&j);
			    }
		 	    fclose (fp);	
		        system ("cls");
		    	break;
		case 8:	
		        if ((fp=fopen(directorio,"rb+"))==NULL)
		        {
				printf ("ERROR AL ABRIR EL ARCHIVO!!");
			    printf ("\n\nIngrese cualquier tecla para volver o 'S' para salir: ");
			    scanf ("%s",&k);
			    system ("cls");
			    break;
		    	}	
		        while(j)
		        {	
		        system ("cls");
		        int l=0;
		   	    fflush (stdin);	
		   	    printf ("ELIMINADOR DE RECLAMOS\n");
	            printf ("\n ID    Codigo     Fecha                      Nombre de edificio                 Ascensor                              Observaciones");
	            printf ("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");	
	            rewind (fp);
	            fread (&r,sizeof(struct reclamo),1,fp);
		        while (!feof(fp))
			    {
				if (r.baja==0)
				{
		    	printf ("\n# %-5d%-10s %-10s   %-35s%-35s   %-10s\n",r.id,r.codigo,r.fecha,r.edificio,r.ascensor,r.datos); 
			    }
			    fread (&r,sizeof(struct reclamo),1,fp);
			    }
				printf ("\n\nIngrese ID de reclamo a eliminar: ");	      
                scanf ("%d",&aux4);
                rewind (fp);
                fread (&r,sizeof(struct reclamo),1,fp);	
                system ("cls");
                printf ("ELIMINADOR DE RECLAMOS\n");
	            printf ("\n ID    Codigo     Fecha                      Nombre de edificio                 Ascensor                              Observaciones");
	            printf ("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
	             while (!feof(fp))
	             {
                    if (r.id==aux4 && r.baja==0)
                    {
                    printf ("\n# %-5d%-10s %-10s   %-35s%-35s   %-10s\n",r.id,r.codigo,r.fecha,r.edificio,r.ascensor,r.datos); 
					l++;
					printf ("\n\nIngrese cualquier tecla para eliminar o '0' para cancelar: ");
	                scanf ("%d",&q);
	                if (q)
	                {
				    r.baja=1;
				    fseek (fp,(-1L)*sizeof(struct reclamo),1);
		            fwrite (&r,sizeof(struct reclamo),1,fp);
		            printf ("\nReclamo eliminado!!");
		            break;
		            }else{
		            printf ("\nCancelado!!");
					}
			        } 
			        fread (&r,sizeof(struct reclamo),1,fp);	 	
			   	 }  
				if (l<1)	
				{
				printf ("\n\nReclamo no encontrado");
				}	
			    printf ("\n\n\nIngrese cualquier tecla para una nueva eliminacion o '0' para volver: ");
	            scanf ("%d",&j);
			    }
		 	    fclose (fp);	
		        system ("cls");
		    	break;
		case 9:		
		 	    if ((fp=fopen(directorio,"rb+"))==NULL)
		        {
				printf ("ERROR AL ABRIR EL ARCHIVO!!");
			    printf ("\n\nIngrese cualquier tecla para volver o 'S' para salir: ");
			    scanf ("%s",&k);
			    system ("cls");
			    break;
		    	}	
		        while(j)
		        {	
		        system ("cls");
		        int l=0;
		        int s=0;
		   	    fflush (stdin);	
		   	    printf ("RECUPERADOR DE RECLAMOS");
		        printf ("\n\nRECLAMOS ELIMINADOS");
	            printf ("\n ID    Codigo     Fecha                      Nombre de edificio                 Ascensor                              Observaciones");
	            printf ("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
	            rewind (fp);
                fread (&r,sizeof(struct reclamo),1,fp);
				 while (!feof(fp))
	             {
                    if (r.baja==1)
                    {
                    printf ("\n# %-5d%-10s %-10s   %-35s%-35s   %-10s\n",r.id,r.codigo,r.fecha,r.edificio,r.ascensor,r.datos); 	
                    l++;
	                }
			        fread (&r,sizeof(struct reclamo),1,fp);	 	
			   	 }  
				 if (l<1)	
				 {
				 printf ("\n\nNo se encontraron reclamos eliminados");
				 } else
				 {
				 printf ("\nIngrese ID de reclamo a recuperar: ");	      
                 scanf ("%d",&aux5);
                 rewind (fp);
                 fread (&r,sizeof(struct reclamo),1,fp);
				 while (!feof(fp))
	             {
                    if (r.id==aux5 && r.baja==1)
                    {
				    r.baja=0;
		            fseek (fp,(-1L)*sizeof(struct reclamo),1);
		            fwrite (&r,sizeof(struct reclamo),1,fp);
		            printf ("\nReclamo recuperado!!");
		            s++;
		            break;
		            }
			        fread (&r,sizeof(struct reclamo),1,fp);	 	
			   	 }  
		         if(s<1)
		         {
		         printf ("\n\nReclamo no encontrado/eliminado");
				 }
			     }
			    printf ("\n\n\nIngrese cualquier tecla para una nueva recuperacion o '0' para volver: ");
	            scanf ("%d",&j);
			    }
		 	    fclose (fp);	
		        system ("cls");
		    	break;	
		case 10:
			    if (v==0)
			    {
			    system ("color F8");
				v=1;	
				} else{
				system ("color 8F");
				v=0;
				}
			    break;  	
		case 0:
		        return k='S';
		        system ("cls");
		        break;
		default:
		    	printf ("OPCION INCORRECTA!!");
		    	printf ("\n\nIngrese cualquier tecla para volver o 'S' para salir: ");
			    scanf ("%s",&k);
		    	system ("cls");
		     	break;
    }
    }
    return 0;
}
struct reclamo ingresoreclamo (int o){	
	struct reclamo x;
	fflush(stdin);
	x.id=o;
	x.baja=0;
	printf("\nIngrese codigo: ");
	gets(x.codigo);
    printf ("Ingrese fecha: ");
	gets (x.fecha);
	printf ("Ingrese edificio: ");
	gets (x.edificio);
	printf ("Ingrese ascensor: ");
	gets (x.ascensor);
	printf ("Ingrese datos: ");
	gets (x.datos);
	fflush(stdin);
	return x;
	system ("cls");
}

struct reclamo modificacion (int p,char *u, char *d){
	struct reclamo y;
	fflush (stdin);
	y.id=p;
	y.baja=0;
	strcpy(y.codigo,u);
	strcpy(y.fecha,d);
	//printf ("\nIngrese nuevo codigo: ");
	//gets (y.codigo);
    //printf ("Ingrese nueva fecha: ");
	//gets (y.fecha);
	printf ("\nIngrese nuevo edificio: ");
	gets (y.edificio);
	printf ("Ingrese nuevo ascensor: ");
	gets (y.ascensor);
	printf ("Ingrese nuevos datos: ");
	gets (y.datos);
	fflush (stdin);
	return y;
	system ("cls");
}

struct reclamo eliminacion (void){
	struct reclamo z;
	z.baja=1;
	return z;
}

struct reclamo recuperacion (void){
	struct reclamo z;
	z.baja=0;
	return z;
}

void listar (FILE *fps, char*n)
{
struct reclamo h;
FILE *fp;
  if ((fp=fopen(n,"rb"))==NULL)
    {
	fprintf (fps, "ERROR AL ABRIR EL ARCHIVO!!");
    return;
	}	
fread (&h,sizeof(struct reclamo),1,fp);
fprintf (fps, "LISTADO DE RECLAMOS\n");
fprintf (fps, "\n ID    Codigo     Fecha                      Nombre de edificio                 Ascensor                              Observaciones");
fprintf (fps, "\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
while (!feof(fp))
	             {
	             	if (h.baja==0)
	             	{
	             	fprintf (fps,"\n# %-5d%-10s %-10s   %-35s%-35s   %-10s\n",h.id,h.codigo,h.fecha,h.edificio,h.ascensor,h.datos); 
					}
			        fread (&h,sizeof(struct reclamo),1,fp);	 	
			   	 }  				   	    
fclose(fp);
}

void AltEnter(){
    keybd_event(VK_MENU,
                0x38,
                0,
                0);
    keybd_event(VK_RETURN,
                0x1c,
                0,
                0);
    keybd_event(VK_RETURN,
                0x1c,
                KEYEVENTF_KEYUP,
                0);
    keybd_event(VK_MENU,
                0x38,
                KEYEVENTF_KEYUP,
                0);
    return;
} 





