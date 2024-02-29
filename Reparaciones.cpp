#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <wchar.h>
#include <locale.h>

struct reparacion ingresoreparacion (void);
struct reparacion modificacion (char *u);
struct reparacion eliminacion (void);
void listar (FILE *fps, char*n);
void AltEnter();

struct reparacion{
	int baja;
	char fecha [25];
	char placa [60];
	char tarea [100];
	char codigo[10];
	char nota[100];
	char otros[100];
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
	char aux3[10];
	char aux4[10];
	char aux5[10];
	char extension[10]=".dat";
	FILE *fp;
	struct reparacion r;
	AltEnter ();
	while (k!='S')
	{
	j=1;  
	printf ("SOFTWARE DE REPARACIONES v1.0\n");
	if ((fp=fopen("C:\\Users\\nico_\\Desktop\\HWA\\Reparaciones\\Reparaciones.dat","rb+"))==NULL)
	            {
    	        printf ("\nARCHIVO NO ENCONTRADO!!");
    	        }else{
    	        printf ("\nREPARACIONES.DAT ABIERTO!!");
				}
	printf ("\n\n***Menu***\n");
	printf ("\n1-  Ingresar reparacion");
	printf ("\n2-  Listar reparaciones");
	printf ("\n3-  Exportar listado de reparaciones");
	printf ("\n4-  Buscar reparaciones por placa o edificio");
	printf ("\n5-  Modificar reparaciones");
	printf ("\n6-  Eliminar reparaciones");
	printf ("\n7-  Recuperar reparaciones eliminadas");
	printf ("\n8-  Invertir iluminacion");
	printf ("\n0-  Salir\n");
	printf ("\nOpcion: ");
	scanf ("%d",&i);
    system ("cls");
	switch (i)
	{    
		case 1:
	        	if ((fp=fopen("C:\\Users\\nico_\\Desktop\\HWA\\Reparaciones\\Reparaciones.dat","rb+"))==NULL)
	            {
    	        printf ("ERROR AL ABRIR EL ARCHIVO!!");
			    printf ("\n\nIngrese cualquier tecla para volver o 'S' para salir: ");
			    scanf ("%s",&k);
			    system ("cls");
			    break;
	            }
	            fread (&r,sizeof(struct reparacion),1,fp);
	            while (!feof(fp))	
	            {
	        	fread (&r,sizeof(struct reparacion),1,fp);
			    }
	            while(j)
	            {
	            system ("cls");
	            printf ("INGRESO DE REPARACION\n\n");	
	            printf ("ULTIMO INGRESO");
				rewind (fp);
	            fread (&r,sizeof(struct reparacion),1,fp);
		        while (!feof(fp))
			    {
			    fread (&r,sizeof(struct reparacion),1,fp);
		    	}
				if (r.baja==0)
				{	
				printf ("\nCodigo: %s",r.codigo);  
				printf ("\nFecha: %s",r.fecha); 
				printf ("\nPlaca: %s",r.placa); 
				printf ("\nTarea: %s",r.tarea); 	
			    printf ("\nNota: %s",r.nota); 
			    printf ("\nOtros: %s",r.otros); 
			    printf ("\n");
			    }else{
			    printf ("\nUltima reparacion eliminada");
				printf ("\n");
				}
			    printf ("\nNUEVO INGRESO");
			    r=ingresoreparacion();
				fwrite (&r,sizeof(struct reparacion),1,fp);
		        printf ("\nINGRESO CORRECTO\n");
		        printf ("\n\nIngrese cualquier tecla para ingresar una nueva reparacion o [0] para volver: ");
	            scanf ("%d",&j);
	            }
	            fclose (fp);
			    system ("cls");
			    break;
		case 2:
			    if ((fp=fopen("C:\\Users\\nico_\\Desktop\\HWA\\Reparaciones\\Reparaciones.dat","rb"))==NULL)
			    {
				printf ("ERROR AL ABRIR EL ARCHIVO!!");
			    printf ("\n\nIngrese cualquier tecla para volver o 'S' para salir: ");
			    scanf ("%s",&k);
			    system ("cls");
			    break;
			    }
			    printf ("LISTADO DE REPARACIONES\n");
			    printf ("\n Codigo      Fecha            Placa");
	            printf ("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
				rewind (fp);
			    fread (&r,sizeof(struct reparacion),1,fp);
			    while (!feof(fp))
			    {
				if (r.baja==0)
				{
				printf ("\n# %-5s      %-10s       %-10s",r.codigo,r.fecha,r.placa); 
			    }
			    fread (&r,sizeof(struct reparacion),1,fp);
			    }
			    printf ("\n\nIngrese codigo de reparacion a detallar o [0] para volver: ");
		    	scanf ("%s",&t);
		    	rewind (fp);
			    fread (&r,sizeof(struct reparacion),1,fp);
			    o=0;
		    	if(strcmp(t,"0")){
			          while (!feof(fp))
			          {
			          if (r.baja==0 && !strcmp(r.codigo,t))
				      {
				      o++;
					  printf ("\nCodigo: %s",r.codigo); 
				      printf ("\nFecha: %s",r.fecha); 
				      printf ("\nPlaca: %s",r.placa); 
			      	  printf ("\nTarea: %s",r.tarea); 	
			          printf ("\nNota: %s",r.nota); 
			          printf ("\nOtros: %s",r.otros); 
			          printf ("\n");
			    }
			    fread (&r,sizeof(struct reparacion),1,fp);
			    }
			    if (!o){ printf ("\nCodigo no encontrado\n\n");
				}
			    fclose (fp);
				system ("PAUSE");
				system ("cls");
				break;	
				}else{
			    system ("cls");
			    break;
		    	}
		case 3:
			    fp=fopen ("C:\\Users\\nico_\\Desktop\\HWA\\Reparaciones\\Backup_Reparaciones.csv","wt");
			    strcpy(nombre,"C:\\Users\\nico_\\Desktop\\HWA\\Reparaciones\\Reparaciones.dat");
				listar (fp,nombre);
			    fclose(fp); 
			  	system ("C:\\Users\\nico_\\Desktop\\HWA\\Reparaciones\\Backup_Reparaciones.csv");	
			    system ("cls");	
			    break;	    
		case 4:
			    if ((fp=fopen("C:\\Users\\nico_\\Desktop\\HWA\\Reparaciones\\Reparaciones.dat","rb"))==NULL)
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
				printf ("BUSCADOR DE REPARACIONES\n");	
		        printf ("\nIngrese placa o edificio a buscar: ");	      
                gets (aux);
                rewind (fp);
                fread (&r,sizeof(struct reparacion),1,fp);	
                system ("cls");
                printf ("BUSCADOR DE REPARACIONES\n");
	            
	            while (!feof(fp))
	            {
                if (strstr(r.placa,aux)!=NULL || strstr(r.nota,aux)!=NULL)
                {
                if (r.baja==0)
                {
			    printf ("\n\nCodigo: %s",r.codigo); 
				printf ("\nFecha: %s",r.fecha); 
				printf ("\nPlaca: %s",r.placa); 
			    printf ("\nTarea: %s",r.tarea); 	
			    printf ("\nNota: %s",r.nota); 
			    printf ("\nOtros: %s",r.otros); 
			    printf ("\n");
			    l++;	
			    } 
			    }
			    fread (&r,sizeof(struct reparacion),1,fp);    
			   	}   
				if (l<1)	
				{
				printf ("\n\nReparacion no encontrada\n");
				}	
		        printf ("\n\nIngrese cualquier tecla para una nueva consulta o [0] para volver: ");
	            scanf ("%d",&j);
	            }
	            fclose (fp);	
			    system ("cls");
		case 5:
		 	    if ((fp=fopen("C:\\Users\\nico_\\Desktop\\HWA\\Reparaciones\\Reparaciones.dat","rb+"))==NULL)
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
		   	    printf ("MODIFICADOR DE REPARACIONES\n");
	            printf ("\n Codigo      Fecha            Placa");
	            printf ("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
	            rewind (fp);
	            fread (&r,sizeof(struct reparacion),1,fp);
		        while (!feof(fp))
			    {
				if (r.baja==0)
				{
			    printf ("\n# %-5s      %-10s       %-10s",r.codigo,r.fecha,r.placa); 
			    }
			    fread (&r,sizeof(struct reparacion),1,fp);
			    }
				printf ("\n\nIngrese codigo de reparacion a modificar: ");	      
                scanf ("%s",&aux3);
                rewind (fp);
                fread (&r,sizeof(struct reparacion),1,fp);	
                printf ("MODIFICADOR DE RECLAMOS\n");
	              while (!feof(fp))
	              {
                    if (r.baja==0 && !strcmp(r.codigo,aux3))
                    {
                      system ("cls");
					  printf ("\n\nCodigo: %s",r.codigo); 
				      printf ("\nFecha: %s",r.fecha); 
				      printf ("\nPlaca: %s",r.placa); 
			      	  printf ("\nTarea: %s",r.tarea); 	
			          printf ("\nNota: %s",r.nota); 
			          printf ("\nOtros: %s",r.otros); 
			          printf ("\n");	
					  strcpy(u,r.codigo);
					  l++;
				      r=modificacion(u);
		              fseek (fp,(-1L)*sizeof(struct reparacion),1);
		              fwrite (&r,sizeof(struct reparacion),1,fp); 
		              printf ("\n\nReparacion modificada!!");
		              break;
			          } 
			          fread (&r,sizeof(struct reparacion),1,fp);	 	
			   	  }  
				  if (l<1)	
				  {
				  printf ("\n\nReparacion no encontrada");
				  }	
			      printf ("\n\n\nIngrese cualquier tecla para una nueva modificacion o [0] para volver: ");
	              scanf ("%d",&j);
			      }
		 	    fclose (fp);	
		        system ("cls");
		    	break;
		case 6:	
		        if ((fp=fopen("C:\\Users\\nico_\\Desktop\\HWA\\Reparaciones\\Reparaciones.dat","rb+"))==NULL)
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
		   	    printf ("ELIMINADOR DE REPARACIONES\n");
	            printf ("\n Codigo      Fecha            Placa");
	            printf ("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
	            rewind (fp);
	            fread (&r,sizeof(struct reparacion),1,fp);
		        while (!feof(fp))
			    {
				if (r.baja==0)
				{
		    	printf ("\n# %-5s      %-10s       %-10s",r.codigo,r.fecha,r.placa); 
			    }
			    fread (&r,sizeof(struct reparacion),1,fp);
			    }
				printf ("\n\nIngrese codigo de reparacion a eliminar: ");	      
                scanf ("%s",&aux4);
                rewind (fp);
                fread (&r,sizeof(struct reparacion),1,fp);	
                system ("cls");
                printf ("ELIMINADOR DE RECLAMOS\n");
	            printf ("\n Codigo      Fecha            Placa");
	            printf ("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
	             while (!feof(fp))
	             {
                   if (r.baja==0 && !strcmp(r.codigo,aux4))
                   {
                   printf ("\n# %-5s      %-10s       %-10s",r.codigo,r.fecha,r.placa);  
				   l++;
					printf ("\n\nIngrese cualquier tecla para eliminar o [0] para cancelar: ");
	                scanf ("%d",&q);
	                if (q)
	                {
				    r.baja=1;
				    fseek (fp,(-1L)*sizeof(struct reparacion),1);
		            fwrite (&r,sizeof(struct reparacion),1,fp);
		            printf ("\nReclamo eliminado!!");
		            break;
		            }else{
		            printf ("\nCANCELADO!!");
					}
			        } 
			        fread (&r,sizeof(struct reparacion),1,fp);	 	
			   	 }  
				if (l<1)	
				{
				printf ("\n\nCodigo no encontrado");
				}	
			    printf ("\n\n\nIngrese cualquier tecla para una nueva eliminacion o [0] para volver: ");
	            scanf ("%d",&j);
			    }
		 	    fclose (fp);	
		        system ("cls");
		    	break;
		case 7:		
		 	    if ((fp=fopen("C:\\Users\\nico_\\Desktop\\HWA\\Reparaciones\\Reparaciones.dat","rb+"))==NULL)
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
	            printf ("\n Codigo      Fecha            Placa");
	            printf ("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
	            rewind (fp);
                fread (&r,sizeof(struct reparacion),1,fp);
				 while (!feof(fp))
	             {
                    if (r.baja==1)
                    {
                    printf ("\n# %-5s      %-10s       %-10s",r.codigo,r.fecha,r.placa);  
                    l++;
	                }
			        fread (&r,sizeof(struct reparacion),1,fp);	 	
			   	 }  
				 if (l<1)	
				 {
				 printf ("\n\nNo se encontraron reparaciones eliminadas");
				 } else
				 {
				 printf ("\n\nIngrese codigo de reparacion a recuperar: ");	      
                 scanf ("%s",&aux5);
                 rewind (fp);
                 fread (&r,sizeof(struct reparacion),1,fp);
				 while (!feof(fp))
	             {
                    if (r.baja==1 && !strcmp(r.codigo,aux5))
                    {
				    r.baja=0;
		            fseek (fp,(-1L)*sizeof(struct reparacion),1);
		            fwrite (&r,sizeof(struct reparacion),1,fp);
		            printf ("\nReclamo recuperado!!");
		            s++;
		            break;
		            }
			        fread (&r,sizeof(struct reparacion),1,fp);	 	
			   	 }  
		         if(s<1)
		         {
		         printf ("\n\nReclamo no encontrado/eliminado");
				 }
			     }
			    printf ("\n\n\nIngrese cualquier tecla para una nueva recuperacion o [0] para volver: ");
	            scanf ("%d",&j);
			    }
		 	    fclose (fp);	
		        system ("cls");
		    	break;	
		case 8:
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
struct reparacion ingresoreparacion (void){	
	struct reparacion x;
	fflush(stdin);
	x.baja=0;
	printf ("\nIngrese codigo: ");
	gets (x.codigo);
	printf("Ingrese fecha: ");
	gets(x.fecha);
    printf ("Ingrese placa: ");
	gets (x.placa);
	printf ("Ingrese tarea: ");
	gets (x.tarea);
	printf ("Ingrese nota: ");
	gets (x.nota);
	printf ("Ingrese otros: ");
	gets (x.otros);
	fflush(stdin);
	return x;
}

struct reparacion modificacion (char *u){
	struct reparacion y;
	fflush (stdin);
	y.baja=0;
	strcpy(y.codigo,u);
	printf ("\nIngrese nueva fecha: ");
	gets (y.fecha);
	printf ("Ingrese nueva placa: ");
	gets (y.placa);
    printf ("Ingrese nueva tarea: ");
	gets (y.tarea);
	printf ("Ingrese nuevas notas: ");
	gets (y.nota);
	printf ("Ingrese otros: ");
	gets (y.otros);
	fflush (stdin);
	return y;
}

void listar (FILE *fps, char*n)
{
struct reparacion h;
FILE *fp;
  if ((fp=fopen(n,"rb"))==NULL)
    {
	fprintf (fps, "ERROR AL ABRIR EL ARCHIVO!!");
    return;
	}	
fread (&h,sizeof(struct reparacion),1,fp);
while (!feof(fp))
	             {
					if (h.baja==0)
	             	{
	                fprintf (fps,"%s;%s;%s;%s;%s;%s",h.fecha,h.placa,h.tarea,h.codigo,h.nota,h.otros); 
					}
			        fread (&h,sizeof(struct reparacion),1,fp);	 	
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



