#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <wchar.h>
#include <locale.h>

struct entrada ingresoentrada (void);
struct salida ingresosalida (void);
struct entrada modificacionent (void);
struct salida modificacionsal (void);
void listarent (FILE *fps, char*n);
void listarsal (FILE *fps, char*n);
void AltEnter();

struct entrada{
	char fecha [25];
	char descripcion [100];
	char origen [60];
	char cantidad [10];
};

struct salida{
	char fecha [25];
	char descripcion [100];
	char edificio [60];
	char ascensor [40];
	char cantidad [10];
};

int main (int argc, char *argv[])
{
	setlocale(LC_ALL, "Spanish");
	SetConsoleCP(1252); 
    SetConsoleOutputCP(1252);
	system ("color 8F");
	int i,j;
	int v=0;
	char u[10];
	char d[25];
	char nombre[100];
	char k=1;
	char t[60];
	char aux[60];
	char aux2[60];
	char aux3[60];
	char aux4[60];
	char extension[10]=".dat";
	char directorio[100];
	char copia[100]="C:\\Users\\nico_\\Desktop\\HWA\\Entrada-Salida\\DAT\\";
	FILE *fp;
	struct entrada e;
	struct salida s;
	AltEnter ();
	while (k!='S')
	{
	j=1;  
	printf ("SOFTWARE DE ENTRADA/SALIDA v1.0\n");
	printf ("\n***Menu***\n");
	printf ("\n1-  Abrir archivo de datos");
	printf ("\n2-  Nueva entrada");
	printf ("\n3-  Listar entrada");
	printf ("\n4-  Modificar entrada");
	printf ("\n5-  Exportar listado de entrada");
	printf ("\n6-  Nueva salida");
	printf ("\n7-  Listar salida");
	printf ("\n8-  Modificar salida");
	printf ("\n9-  Exportar listado de salida");
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
			    system ("cls");
			    break;        
		case 2:
	        	while (strstr(nombre,"Entrada")!=NULL)
	        	{
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
	            printf ("INGRESO DE ENTRADA\n\n");	
	            printf ("\n Fecha        Descripcion                                                                       Origen                                              Cantidad");
	            printf ("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
				rewind (fp);
	            fread (&e,sizeof(struct entrada),1,fp);
		        while (!feof(fp))
			    {
				printf ("\n %-10s   %-70s            %-40s            %-30s    ",e.fecha,e.descripcion,e.origen,e.cantidad); 
			    fread (&e,sizeof(struct entrada),1,fp);
			    }
	            printf ("\n\n");
	            e=ingresoentrada();
		        fwrite (&e,sizeof(struct entrada),1,fp);
		        system ("cls");
		        printf ("LISTADO DE ENTRADA\n");
	            printf ("\n Fecha        Descripcion                                                                       Origen                                              Cantidad");
	            printf ("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
				rewind (fp);
	            fread (&e,sizeof(struct entrada),1,fp);
		        while (!feof(fp))
			    {
				printf ("\n %-10s   %-70s            %-40s            %-30s    ",e.fecha,e.descripcion,e.origen,e.cantidad); 
			    fread (&e,sizeof(struct entrada),1,fp);
			    }
		        printf ("\n\n\nIngrese cualquier tecla para ingresar otra entrada o [0] para volver: ");
	            scanf ("%d",&j);
	            }
	            fclose (fp);
			    system ("cls");
			    break;
			    }
			    system ("cls");	
			    break;
		case 3:
			    while (strstr(nombre,"Entrada")!=NULL)
	        	{
				if ((fp=fopen(directorio,"rb"))==NULL)
			    {
				printf ("ERROR AL ABRIR EL ARCHIVO!!");
			    printf ("\n\nIngrese cualquier tecla para volver o 'S' para salir: ");
			    scanf ("%s",&k);
			    system ("cls");
			    break;
			    }
			    printf ("LISTADO DE ENTRADA\n");
	            printf ("\n Fecha        Descripcion                                                                       Origen                                              Cantidad");
	            printf ("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
			    fread (&e,sizeof(struct entrada),1,fp);
			    while (!feof(fp))
			    {
				printf ("\n %-10s   %-70s            %-40s            %-30s    ",e.fecha,e.descripcion,e.origen,e.cantidad); 
			    fread (&e,sizeof(struct entrada),1,fp);
			    }
			    fclose (fp);
			    printf ("\n\nIngrese cualquier tecla para volver: ");
		    	scanf ("%s",&t);
			    system ("cls");
			    break;
			    }
			    system ("cls");
			    break;
		case 4:
		 	    while (strstr(nombre,"Entrada")!=NULL)
	        	{
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
		   	    printf ("MODIFICADOR DE ENTRADA\n");
	            printf ("\n Fecha        Descripcion                                                                       Origen                                              Cantidad");
	            printf ("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
	            rewind (fp);
	            fread (&e,sizeof(struct entrada),1,fp);
		        while (!feof(fp))
			    {
			    printf ("\n %-10s   %-70s            %-40s            %-30s    ",e.fecha,e.descripcion,e.origen,e.cantidad);  
			    fread (&e,sizeof(struct entrada),1,fp);
			    }
				printf ("\n\nIngrese fecha de entrada a modificar: ");	      
                gets(aux);
				printf ("\nIngrese descripcion de entrada a modificar: ");	      
                gets(aux2);
                rewind (fp);
                fread (&e,sizeof(struct entrada),1,fp);	
                system ("cls");
                printf ("MODIFICADOR DE ENTRADA\n");
	            printf ("\n Fecha        Descripcion                                                                       Origen                                              Cantidad");
	            printf ("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
	             while (!feof(fp))
	             {
                    if (strstr(e.fecha,aux)!=NULL && strstr(e.descripcion,aux2)!=NULL)
                    {
                    printf ("\n %-10s   %-70s            %-40s            %-30s    ",e.fecha,e.descripcion,e.origen,e.cantidad);
					l++;
				    e=modificacionent();
		            fseek (fp,(-1L)*sizeof(struct entrada),1);
		            fwrite (&e,sizeof(struct entrada),1,fp); 
		            printf ("\nEntrada modificada!!");
		            break;
			        } 
			        fread (&e,sizeof(struct entrada),1,fp);	 	
			   	 }  
				if (l<1)	
				{
				printf ("\n\nEntrada no encontrada");
				}	
			    printf ("\n\n\nIngrese cualquier tecla para otra modificacion o [0] para volver: ");
	            scanf ("%d",&j);
			    }
		 	    fclose (fp);	
		        system ("cls");
		    	break;
		        }
		        system ("cls");
		    	break;
		case 5:
			    while (strstr(nombre,"Entrada")!=NULL)
	        	{
				fp=fopen ("C:\\Users\\nico_\\Desktop\\HWA\\Entrada-Salida\\Backup_Entrada.csv","wt");
			    listarent (fp,directorio);
			    fclose(fp); 
			  	system ("C:\\Users\\nico_\\Desktop\\HWA\\Entrada-Salida\\Backup_Entrada.csv");	
			    system ("cls");	
			    break;	 
			    }
			    system ("cls");	
			    break;
		case 6:
	        	while (strstr(nombre,"Salida")!=NULL)
	        	{
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
	            printf ("INGRESO DE SALIDA\n\n");	
	            printf ("\n Fecha        Descripcion                                                                       Edificio                                Ascensor               Cantidad");
	            printf ("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
				rewind (fp);
	            fread (&s,sizeof(struct salida),1,fp);
		        while (!feof(fp))
			    {
				printf ("\n %-10s   %-70s            %-28s            %-20s   %-10s",s.fecha,s.descripcion,s.edificio,s.ascensor,s.cantidad); 
			    fread (&s,sizeof(struct salida),1,fp);
			    }
	            printf ("\n\n");
	            s=ingresosalida();
		        fwrite (&s,sizeof(struct salida),1,fp);
		        system ("cls");
		        printf ("LISTADO DE SALIDA\n");
	            printf ("\n Fecha        Descripcion                                                                       Edificio                                Ascensor               Cantidad");
	            printf ("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
				rewind (fp);
	            fread (&s,sizeof(struct salida),1,fp);
		        while (!feof(fp))
			    {
				printf ("\n %-10s   %-70s            %-28s            %-20s   %-10s",s.fecha,s.descripcion,s.edificio,s.ascensor,s.cantidad); 
			    fread (&s,sizeof(struct salida),1,fp);
			    }
		        printf ("\n\n\nIngrese cualquier tecla para ingresar otra entrada o [0] para volver: ");
	            scanf ("%d",&j);
	            }
	            fclose (fp);
			    system ("cls");
			    break;
		     	}
		     	system ("cls");
			    break;
		case 7:
			    while (strstr(nombre,"Salida")!=NULL)
	        	{
				if ((fp=fopen(directorio,"rb"))==NULL)
			    {
				printf ("ERROR AL ABRIR EL ARCHIVO!!");
			    printf ("\n\nIngrese cualquier tecla para volver o 'S' para salir: ");
			    scanf ("%s",&k);
			    system ("cls");
			    break;
			    }
			    printf ("LISTADO DE SALIDA\n");
	            printf ("\n Fecha        Descripcion                                                                       Edificio                                Ascensor               Cantidad");
	            printf ("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
			    fread (&s,sizeof(struct salida),1,fp);
			    while (!feof(fp))
			    {
				printf ("\n %-10s   %-70s            %-28s            %-20s   %-10s",s.fecha,s.descripcion,s.edificio,s.ascensor,s.cantidad); 
			    fread (&s,sizeof(struct salida),1,fp);
			    }
			    fclose (fp);
			    printf ("\n\nIngrese cualquier tecla para volver: ");
		    	scanf ("%s",&t);
			    system ("cls");
			    break;
		     	}
		     	system ("cls");
		     	break;
		case 8:
		 	    while (strstr(nombre,"Salida")!=NULL)
	        	{
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
		   	    printf ("MODIFICADOR DE SALIDA\n");
	            printf ("\n Fecha        Descripcion                                                                       Edificio                                Ascensor               Cantidad");
	            printf ("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
	            rewind (fp);
	            fread (&s,sizeof(struct salida),1,fp);
		        while (!feof(fp))
			    {
			    printf ("\n %-10s   %-70s            %-28s            %-20s   %-10s",s.fecha,s.descripcion,s.edificio,s.ascensor,s.cantidad); 
			    fread (&s,sizeof(struct salida),1,fp);
			    }
				printf ("\n\nIngrese fecha de salida a modificar: ");	      
                gets(aux3);
				printf ("\nIngrese descripcion de salida a modificar: ");	      
                gets(aux4);
                rewind (fp);
                fread (&s,sizeof(struct salida),1,fp);	
                system ("cls");
                printf ("MODIFICADOR DE SALIDA\n");
	            printf ("\n Fecha        Descripcion                                                                       Edificio                                Ascensor               Cantidad");
	            printf ("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
	             while (!feof(fp))
	             {
                    if (strstr(s.fecha,aux3)!=NULL && strstr(s.descripcion,aux4)!=NULL)
                    {
                    printf ("\n %-10s   %-70s            %-28s            %-20s   %-10s",s.fecha,s.descripcion,s.edificio,s.ascensor,s.cantidad); 
					l++;
				    s=modificacionsal();
		            fseek (fp,(-1L)*sizeof(struct salida),1);
		            fwrite (&s,sizeof(struct salida),1,fp); 
		            printf ("\nSalida modificada!!");
		            break;
			        } 
			        fread (&s,sizeof(struct salida),1,fp);	 	
			   	 }  
				if (l<1)	
				{
				printf ("\n\nSalida no encontrada");
				}	
			    printf ("\n\n\nIngrese cualquier tecla para otra modificacion o [0] para volver: ");
	            scanf ("%d",&j);
			    }
		 	    fclose (fp);	
		        system ("cls");
		    	break;	
				}
				system ("cls");
				break;
		case 9:
			    while (strstr(nombre,"Salida")!=NULL)
	        	{
				fp=fopen ("C:\\Users\\nico_\\Desktop\\HWA\\Entrada-Salida\\Backup_Salida.csv","wt");
			    listarsal (fp,directorio);
			    fclose(fp); 
			  	system ("C:\\Users\\nico_\\Desktop\\HWA\\Entrada-Salida\\Backup_Salida.csv");	
			    system ("cls");	
			    break;
		    	}
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

struct entrada ingresoentrada (){	
	struct entrada x;
	fflush(stdin);
	printf("\nIngrese fecha: ");
	gets(x.fecha);
    printf ("Ingrese descripcion: ");
	gets (x.descripcion);
	printf ("Ingrese origen: ");
	gets (x.origen);
	printf ("Ingrese cantidad: ");
	gets (x.cantidad);
	fflush(stdin);
	return x;
	system ("cls");
}

struct entrada modificacionent (){
	struct entrada y;
	fflush (stdin);
	printf ("\nIngrese nueva fecha: ");
	gets (y.fecha);
	printf ("Ingrese nueva descripcion: ");
	gets (y.descripcion);
	printf ("Ingrese nuevo origen: ");
	gets (y.origen);
	printf ("Ingrese nueva cantidad: ");
	gets (y.cantidad);
	fflush (stdin);
	return y;
	system ("cls");
}

struct salida ingresosalida (){	
	struct salida x;
	fflush(stdin);
	printf("\nIngrese fecha: ");
	gets(x.fecha);
    printf ("Ingrese descripcion: ");
	gets (x.descripcion);
	printf ("Ingrese edificio: ");
	gets (x.edificio);
	printf ("Ingrese ascensor: ");
	gets (x.ascensor);
	printf ("Ingrese cantidad: ");
	gets (x.cantidad);
	fflush(stdin);
	return x;
	system ("cls");
}

struct salida modificacionsal (){
	struct salida y;
	fflush (stdin);
	printf ("\nIngrese nueva fecha: ");
	gets (y.fecha);
	printf ("Ingrese nueva descripcion: ");
	gets (y.descripcion);
	printf ("Ingrese nuevo edificio: ");
	gets (y.edificio);
	printf ("Ingrese nuevo ascensor: ");
	gets (y.ascensor);
	printf ("Ingrese nueva cantidad: ");
	gets (y.cantidad);
	fflush (stdin);
	return y;
	system ("cls");
}

void listarent (FILE *fps, char*n)
{
struct entrada h;
FILE *fp;
  if ((fp=fopen(n,"rb"))==NULL)
    {
	fprintf (fps, "ERROR AL ABRIR EL ARCHIVO!!");
    return;
	}	
fread (&h,sizeof(struct entrada),1,fp);
while (!feof(fp))
	             {
	             	fprintf (fps,"%s;%s;%s;%s",h.fecha,h.descripcion,h.origen,h.cantidad); 
			        fread (&h,sizeof(struct entrada),1,fp);	 	
			   	 }  				   	    
fclose(fp);
}

void listarsal (FILE *fps, char*n)
{
struct salida h;
FILE *fp;
  if ((fp=fopen(n,"rb"))==NULL)
    {
	fprintf (fps, "ERROR AL ABRIR EL ARCHIVO!!");
    return;
	}	
fread (&h,sizeof(struct salida),1,fp);
while (!feof(fp))
	             {
	             	fprintf (fps,"%s;%s;%s;%s;%s",h.fecha,h.descripcion,h.edificio,h.ascensor,h.cantidad); 
			        fread (&h,sizeof(struct salida),1,fp);	 	
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





