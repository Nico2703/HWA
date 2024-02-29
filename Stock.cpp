#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <wchar.h>
#include <locale.h>


struct producto{
	int baja;
	char codigo[10];
	char descripcion[60];
	char cantidad[5];
	char marca[20];
	char detalles[60];
	char precio[10];
};


struct producto ingresar (void);
struct producto modificacion (void);
struct producto modifcant (char *m1, char *m2, char *m3, char *m4, char *m5, char *m6);
void listar (FILE *fps, char*n);
void AltEnter();


int main (int argc, char *argv[])
{
	setlocale(LC_CTYPE, "Spanish");
	SetConsoleCP(1252); 
    SetConsoleOutputCP(1252);
	system ("color 8F");
	int i,j;
	int s,q;
	int v=0;
	char m1[10], m2[60], m3[5], m4[20], m5[60], m6[10];
	char aux[10], aux2[10], aux4[10], aux5[10];
	char aux3[60];
	char nombre [100];
	char k=1;
	char t[60];
	FILE *fp;
	struct producto r;
	AltEnter ();
	while (k!='S')
	{
	j=1;  
	printf ("SOFTWARE DE STOCK v1.0\n");
	printf ("\nReferencias: <AW/Automac Wittur> <BR/ Barrera> <CT/ Contactora> <DC/ DC-CT> <EC/ Encoder> <ES/ Escaleras> <FT/ Fuente> <GR/ Guiador> <IG/ IGBT> <IN/ Inductor>");
	printf ("                       <MP/ Motor> <PL/ PCB LG> <PM/ PCB Mitsubishi> <RM/ Ruleman> <RY/ Relay> <SK/ Sakura> <TL/ Teléfono> <TM/ Térmica> <VL/ Varios LG> <VM/ Varios Mitsubishi>");
	printf ("               <VV/ Varios> <XX/ Otros>");
	printf ("\n\n***Menu***\n");
	printf ("\n1-  Ingresar productos");
	printf ("\n2-  Listar productos");
	printf ("\n3-  Exportar listado de productos");
	printf ("\n4-  Buscar productos por codigo o descripcion y modificar cantidad");
	printf ("\n5-  Modificar productos");
	printf ("\n6-  Eliminar productos");
	printf ("\n7-  Recuperar productos eliminados");
	printf ("\n8-  Invertir iluminacion");
	printf ("\n0-  Salir\n");
	printf ("\nOpcion: ");
	scanf ("%d",&i);
    system ("cls");
	switch (i)
	{    
		case 1:	
		        if ((fp=fopen("C:\\Users\\nico_\\Desktop\\HWA\\Stock\\Stock.dat","ab+"))==NULL)
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
	            rewind (fp);
	            printf ("INGRESO DE STOCK\n\n");	
	            printf ("\n Codigo     Descripcion                                                 Cantidad   Marca                      Detalles                                         Precio");
	            printf ("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
	            fread (&r,sizeof(struct producto),1,fp);
		        while (!feof(fp))
			    { 
			    if (r.baja==0){
				printf ("\n# %-8s  %-50s          %-8s   %-20s       %-40s         %s",r.codigo,r.descripcion,r.cantidad,r.marca,r.detalles,r.precio);
			    fread (&r,sizeof(struct producto),1,fp); }
			    }
	            printf ("\n\n");
	            r=ingresar();
		        fwrite (&r,sizeof(struct producto),1,fp);
		        system ("cls");
		        printf ("LISTADO DE STOCK\n");
	            printf ("\n Codigo     Descripcion                                                 Cantidad   Marca                      Detalles                                         Precio");
	            printf ("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
				rewind (fp);
	            fread (&r,sizeof(struct producto),1,fp);
		        while (!feof(fp))
			    {
			    if (r.baja==0){	
				printf ("\n# %-8s  %-50s          %-8s   %-20s       %-40s         %s",r.codigo,r.descripcion,r.cantidad,r.marca,r.detalles,r.precio);
			    fread (&r,sizeof(struct producto),1,fp);}
			    }
		        printf ("\n\n\nIngrese cualquier tecla para ingresar un nuevo producto o '0' para volver: ");
	            scanf ("%d",&j);
	            }
	            fclose (fp);
			    system ("cls");
			    break;
		case 2:
			    if ((fp=fopen("C:\\Users\\nico_\\Desktop\\HWA\\Stock\\Stock.dat","rb"))==NULL)
			    {
				printf ("ERROR AL ABRIR EL ARCHIVO!!");
			    printf ("\n\nIngrese cualquier tecla para volver o 'S' para salir: ");
			    scanf ("%s",&k);
			    system ("cls");
			    break;
			    }
			    printf ("LISTADO DE STOCK\n");
	            printf ("\n Codigo     Descripcion                                                 Cantidad   Marca                      Detalles                                         Precio");
	            printf ("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
			    fread (&r,sizeof(struct producto),1,fp);
			    while (!feof(fp))
			    {
			    if (r.baja==0){
				printf ("\n# %-8s  %-50s          %-8s   %-20s       %-40s         %s",r.codigo,r.descripcion,r.cantidad,r.marca,r.detalles,r.precio);
			    fread (&r,sizeof(struct producto),1,fp);}
			    }
			    fclose (fp);
			    printf ("\n\nIngrese cualquier tecla para volver: ");
		    	scanf ("%s",&t);
			    system ("cls");
			    break;
		case 3: 
		        fp=fopen ("C:\\Users\\nico_\\Desktop\\HWA\\Stock\\Backup_Stock.csv","wt");
			    strcpy(nombre,"C:\\Users\\nico_\\Desktop\\HWA\\Stock\\Stock.dat");
			    listar (fp,nombre);
			    fclose(fp); 
			  	system ("C:\\Users\\nico_\\Desktop\\HWA\\Stock\\Backup_Stock.csv");	
			    system ("cls");	
			    break;
		case 4:
			    if ((fp=fopen("C:\\Users\\nico_\\Desktop\\HWA\\Stock\\Stock.dat","rb+"))==NULL)
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
				printf ("BUSCADOR DE PRODUCTOS\n");	
		        printf ("\nIngrese codigo o descripcion a buscar: ");	      
                gets (aux);
                rewind (fp);
                fread (&r,sizeof(struct producto),1,fp);	
                system ("cls");
                printf ("BUSCADOR DE PRODUCTOS\n");
                printf ("\n Codigo     Descripcion                                                 Cantidad   Marca                      Detalles                                         Precio");
	            printf ("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
	            while (!feof(fp))
	            {
                if (strstr(r.codigo,aux)!=NULL || strstr(r.descripcion,aux)!=NULL)
                {
                if (r.baja==0)
                {
			    printf ("\n# %-8s  %-50s          %-8s   %-20s       %-40s         %s",r.codigo,r.descripcion,r.cantidad,r.marca,r.detalles,r.precio);
			    l++;	
			    } 
			    }
			    fread (&r,sizeof(struct producto),1,fp);    
			   	}   
				if (l<1)	
				{
				printf ("\n\nProducto no encontrado\n");
				}
				else{
				  l=0;
				  printf ("\n\n\nIngrese codigo de producto a modificar cantidad o [0] para cancelar: ");
				  scanf ("%s",&aux2);
				  rewind (fp);
                  fread (&r,sizeof(struct producto),1,fp);	
				      if(strcmp(aux2,"0")){
				      	//system ("CLS");
				      	printf ("\nMODIFICAR CANTIDAD");
						while (!feof(fp))
				      	{
						  if (r.baja==0 && !strcmp(aux2,r.codigo)){
						  strcpy (m1,r.codigo);
						  strcpy (m2,r.descripcion);
						  strcpy (m3,r.cantidad);
						  strcpy (m4,r.marca);
						  strcpy (m5,r.detalles);
						  strcpy (m6,r.precio);
						  l++;
						  r=modifcant(m1,m2,m3,m4,m5,m6);
						  fseek (fp,(-1L)*sizeof(struct producto),1);
		                  fwrite (&r,sizeof(struct producto),1,fp); 
		                  printf ("\nProducto modificado!!");
		                  break;
						  }	
						  fread (&r,sizeof(struct producto),1,fp);
						}
						if (l<1)
						{
				        printf ("\n\nERROR DE CODIGO!!");
						}	
					    }		   
				}	
		        printf ("\nIngrese cualquier tecla para una nueva consulta o [0] para volver: ");
	            scanf ("%d",&j);
	            }
	            fclose (fp);	
			    system ("cls");	   
		case 5:
		 	    if ((fp=fopen("C:\\Users\\nico_\\Desktop\\HWA\\Stock\\Stock.dat","rb+"))==NULL)
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
		   	    printf ("MODIFICADOR DE PRODUCTOS\n");
	            printf ("\n Codigo     Descripcion                                                 Cantidad   Marca                      Detalles                                         Precio");
	            printf ("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
	            rewind (fp);
	            fread (&r,sizeof(struct producto),1,fp);
		        while (!feof(fp))
			    {
				if (r.baja==0)
			    {
			    printf ("\n# %-8s  %-50s          %-8s   %-20s       %-40s         %s",r.codigo,r.descripcion,r.cantidad,r.marca,r.detalles,r.precio);
			    }
			    fread (&r,sizeof(struct producto),1,fp);
			    }
				printf ("\n\nIngrese codigo de producto a modificar: ");	      
                gets(aux3);
				//scanf ("%s",&aux3);
                rewind (fp);
                fread (&r,sizeof(struct producto),1,fp);
				//printf(aux3);
                //printf ("MODIFICADOR DE PRODUCTOS\n");
	              while (!feof(fp))
	              {
                    if (r.baja==0 && !strcmp(r.codigo,aux3))
                      {
                      system ("cls");
					  printf ("MODIFICADOR DE PRODUCTOS\n");
					  printf ("\n\nCodigo: %s",r.codigo); 
				      printf ("\nDescripcion: %s",r.descripcion); 
				      printf ("\nCantidad: %s",r.cantidad); 
			      	  printf ("\nMarca: %s",r.marca); 	
			          printf ("\nDetalles: %s",r.detalles); 
			          printf ("\nPrecio: %s",r.precio); 	
					  l++;
				      r=modificacion();
		              fseek (fp,(-1L)*sizeof(struct producto),1);
		              fwrite (&r,sizeof(struct producto),1,fp); 	
		              printf ("\n\nProducto modificado!!");
		              break;
			          }      	
			   	      fread (&r,sizeof(struct producto),1,fp);	
				  }  
				  if (l<1)	
				  {
				  printf ("\n\nProducto no encontrado");
				  }	
			      printf ("\n\n\nIngrese cualquier tecla para una nueva modificacion o [0] para volver: ");
	              scanf ("%d",&j);
			      }
		 	    fclose (fp);	
		        system ("cls");
		    	break;
		case 6:	
		        if ((fp=fopen("C:\\Users\\nico_\\Desktop\\HWA\\Stock\\Stock.dat","rb+"))==NULL)
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
		   	    printf ("ELIMINADOR DE PRODUCTOS\n");
	            printf ("\n Codigo     Descripcion                                                 Cantidad   Marca                      Detalles                                         Precio");
	            printf ("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
	            rewind (fp);
	            fread (&r,sizeof(struct producto),1,fp);
		        while (!feof(fp))
			    {
				if (r.baja==0)
				{
		    	printf ("\n# %-8s  %-50s          %-8s   %-20s       %-40s         %s",r.codigo,r.descripcion,r.cantidad,r.marca,r.detalles,r.precio);
			    }
			    fread (&r,sizeof(struct producto),1,fp);
			    }
				printf ("\n\nIngrese codigo de producto a eliminar: ");	      
                scanf ("%s",&aux4);
                rewind (fp);
                fread (&r,sizeof(struct producto),1,fp);	
                system ("cls");
                printf ("ELIMINADOR DE PRODUCTOS\n");
	            printf ("\n Codigo     Descripcion                                                 Cantidad   Marca                      Detalles                                         Precio");
	            printf ("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
	             while (!feof(fp))
	             {
                   if (r.baja==0 && !strcmp(r.codigo,aux4))
                   {
                   printf ("\n# %-8s  %-50s          %-8s   %-20s       %-40s         %s",r.codigo,r.descripcion,r.cantidad,r.marca,r.detalles,r.precio);
				   l++;
					printf ("\n\nIngrese cualquier tecla para eliminar o [0] para cancelar: ");
	                scanf ("%d",&q);
	                if (q)
	                {
				    r.baja=1;
				    fseek (fp,(-1L)*sizeof(struct producto),1);
		            fwrite (&r,sizeof(struct producto),1,fp);
		            printf ("\nProducto eliminado!!");
		            break;
		            }else{
		            printf ("\nCANCELADO!!");
					}
			        } 
			        fread (&r,sizeof(struct producto),1,fp);	 	
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
		 	    if ((fp=fopen("C:\\Users\\nico_\\Desktop\\HWA\\Stock\\Stock.dat","rb+"))==NULL)
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
		   	    printf ("RECUPERADOR DE PRODUCTOS");
		        printf ("\n\nPRODUCTOS ELIMINADOS");
	            printf ("\n Codigo     Descripcion                                                 Cantidad   Marca                      Detalles                                         Precio");
	            printf ("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
	            rewind (fp);
                fread (&r,sizeof(struct producto),1,fp);
				 while (!feof(fp))
	             {
                    if (r.baja==1)
                    {
                    printf ("\n# %-8s  %-50s          %-8s   %-20s       %-40s         %s",r.codigo,r.descripcion,r.cantidad,r.marca,r.detalles,r.precio);
                    l++;
	                }
			        fread (&r,sizeof(struct producto),1,fp);	 	
			   	 }  
				 if (l<1)	
				 {
				 printf ("\n\nNo se encontraron productos eliminados");
				 } else
				 {
				 printf ("\n\nIngrese codigo de producto a recuperar: ");	      
                 scanf ("%s",&aux5);
                 rewind (fp);
                 fread (&r,sizeof(struct producto),1,fp);
				 while (!feof(fp))
	             {
                    if (r.baja==1 && !strcmp(r.codigo,aux5))
                    {
				    r.baja=0;
		            fseek (fp,(-1L)*sizeof(struct producto),1);
		            fwrite (&r,sizeof(struct producto),1,fp);
		            printf ("\nProducto recuperado!!");
		            s++;
		            break;
		            }
			        fread (&r,sizeof(struct producto),1,fp);	 	
			   	 }  
		         if(s<1)
		         {
		         printf ("\n\nProducto no encontrado/eliminado");
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

struct producto ingresar (void)
{
	struct producto x;
	x.baja=0;
	fflush (stdin);
	printf ("\nIngrese codigo: ");
	gets (x.codigo);
	printf ("Ingrese descripcion: ");
	gets (x.descripcion);
	printf ("Ingrese cantidad: ");
	gets (x.cantidad);
	printf ("Ingrese marca: ");
	gets (x.marca);
	printf ("Ingrese detalles: ");
	gets (x.detalles);
	printf ("Ingrese precio: ");
	gets (x.precio);
	return x;
	system ("CLS");
}

struct producto modificacion (void){
	struct producto y;
	y.baja=0;
	fflush (stdin);
	printf ("\n\nIngrese nuevo codigo: ");
	gets (y.codigo);
	printf ("Ingrese nueva descripcion: ");
	gets (y.descripcion);
    printf ("Ingrese nueva cantidad: ");
	gets (y.cantidad);
	printf ("Ingrese nueva marca: ");
	gets (y.marca);
	printf ("Ingrese nuevos detalles: ");
	gets (y.detalles);
	printf ("Ingrese nuevo precio: ");
	gets (y.precio);
	fflush (stdin);
	return y;
}

struct producto modifcant (char *m1, char *m2, char *m3, char *m4, char *m5, char *m6){
	struct producto z;
	z.baja=0;
	fflush(stdin);
	printf ("\n\nCodigo: %s",m1);
	strcpy(z.codigo,m1);
	printf ("\nDescripcion: %s",m2);
	strcpy(z.descripcion,m2);
	printf ("\nMarca: %s",m4);
	strcpy (z.marca,m4);
	printf ("\nDetalles: %s",m5);
	strcpy(z.detalles,m5);
	printf ("\nPrecio: %s",m6);
	strcpy(z.precio,m6);
	printf ("\n\nCantidad actual: %s",m3);
	printf ("\nIngrese nueva cantidad: ");
	gets (z.cantidad);
	fflush (stdin);
	return z;
}

void listar (FILE *fps, char*n)
{
struct producto h;
FILE *fp;
  if ((fp=fopen(n,"rb"))==NULL)
    {
	fprintf (fps, "ERROR AL ABRIR EL ARCHIVO!!");
    return;
	}	
fread (&h,sizeof(struct producto),1,fp);
while (!feof(fp))
	             {
	                if (h.baja==0){
					fprintf (fps,"%s;%s;%s;%s;%s;%s",h.codigo,h.descripcion,h.cantidad,h.marca,h.detalles,h.precio); 
	                //fprintf (fps,"\n");}
	                }
			        fread (&h,sizeof(struct producto),1,fp);	 	
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


