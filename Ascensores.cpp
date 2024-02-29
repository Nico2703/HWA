#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <wchar.h>
#include <locale.h>

struct ascensor ingresoascensor (void);
struct ascensor modificacion (char *u);
struct ascensor eliminacion (void);
void listar (FILE *fps, char*n);
void AltEnter();

struct ascensor{
	int baja;
	char codigo [10];
	char edificio [60];
	char uso [20];
	char paradas [10];
	char carga [10];
	char velocidad [10];
	char proyecto [20];
	char ar [20];
	char nombreproyecto [20];
	char numero [10];
	char direccion [60];
	char zona [40];
	char nombre [40];
	char marca [20];
	char tipo [20];
	char modelo [10];
	char maquina [10];
	char regulador [10];
	char largo [10];
	char traccion [10];
	char marcatraccion [10];
	char largotira [10];	
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
	struct ascensor r;
	AltEnter ();
	while (k!='S')
	{
	j=1;  
	printf ("SOFTWARE DE INFORMACION v1.0\n");
	if ((fp=fopen("C:\\Users\\nico_\\Desktop\\HWA\\Ascensores\\Ascensores.dat","rb+"))==NULL)
	            {
    	        printf ("\nARCHIVO NO ENCONTRADO!!");
    	        }else{
    	        printf ("\nASCENSORES.DAT ABIERTO!!");
				}
	printf ("\n\n***Menu***\n");
	printf ("\n1-  Ingresar ascensor");
	printf ("\n2-  Listar ascensores");
	printf ("\n3-  Exportar listado de ascensores");
	printf ("\n4-  Buscar ascensores por codigo o edificio");
	printf ("\n5-  Modificar informacion");
	printf ("\n6-  Eliminar ascensores");
	printf ("\n7-  Recuperar ascensores eliminados");
	printf ("\n8-  Invertir iluminacion");
	printf ("\n0-  Salir\n");
	printf ("\nOpcion: ");
	scanf ("%d",&i);
    system ("cls");
	switch (i)
	{    
		case 1:
	        	if ((fp=fopen("C:\\Users\\nico_\\Desktop\\HWA\\Ascensores\\Ascensores.dat","rb+"))==NULL)
	            {
    	        printf ("ERROR AL ABRIR EL ARCHIVO!!");
			    printf ("\n\nIngrese cualquier tecla para volver o 'S' para salir: ");
			    scanf ("%s",&k);
			    system ("cls");
			    break;
	            }
	            fread (&r,sizeof(struct ascensor),1,fp);
	            while (!feof(fp))	
	            {
	        	fread (&r,sizeof(struct ascensor),1,fp);
			    }
	            while(j)
	            {
	            system ("cls");
	            printf ("INGRESO DE ASCENSOR\n\n");	
	            printf ("ULTIMO INGRESO");
				rewind (fp);
	            fread (&r,sizeof(struct ascensor),1,fp);
		        while (!feof(fp))
			    {
			    fread (&r,sizeof(struct ascensor),1,fp);
		    	}
				if (r.baja==0)
				{	
				printf ("\nCodigo: %s",r.codigo);  
				printf ("\nEdificio: %s",r.edificio); 
				printf ("\nDireccion: %s",r.direccion);  
			    printf ("\n");
			    }else{
			    printf ("\nUltimo ascensor ingresado eliminado");
				printf ("\n");
				}
			    printf ("\nNUEVO INGRESO");
			    fflush(stdin);
			    r=ingresoascensor();
				fwrite (&r,sizeof(struct ascensor),1,fp);
		        printf ("\nINGRESO CORRECTO\n");
		        printf ("\n\nIngrese cualquier tecla para ingresar una nueva reparacion o [0] para volver: ");
	            scanf ("%d",&j);
	            }
	            fclose (fp);
			    system ("cls");
			    break;
		case 2:
			    if ((fp=fopen("C:\\Users\\nico_\\Desktop\\HWA\\Ascensores\\Ascensores.dat","rb"))==NULL)
			    {
				printf ("ERROR AL ABRIR EL ARCHIVO!!");
			    printf ("\n\nIngrese cualquier tecla para volver o 'S' para salir: ");
			    scanf ("%s",&k);
			    system ("cls");
			    break;
			    }
			    printf ("LISTADO DE ASCENSORES\n");
			    printf ("Codigo       Edificio                             Direccion");
	            printf ("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
				rewind (fp);
			    fread (&r,sizeof(struct ascensor),1,fp);
			    while (!feof(fp))
			    {
				if (r.baja==0)
				{
				printf ("\n%-10s   %-30s       %-10s",r.codigo,r.edificio,r.direccion); 
			    }
			    fread (&r,sizeof(struct ascensor),1,fp);
			    }
			    printf ("\n\nIngrese codigo de ascensor a detallar o [0] para volver: ");
				scanf ("%s",&t);
		    	rewind (fp);
			    fread (&r,sizeof(struct ascensor),1,fp);
			    o=0;
		    	if(strcmp(t,"0")){
			          while (!feof(fp))
			          {
			          if (r.baja==0 && strstr(r.codigo,t)!=NULL)
				      {
				      o++;
					  printf ("\nCodigo: %s",r.codigo); 
				      printf ("\nEdificio: %s",r.edificio); 
				      printf ("\nUso: %s",r.uso); 
			      	  printf ("\nParadas: %s",r.paradas); 	
			          printf ("\nCarga: %s",r.carga); 
			          printf ("\nVelocidad: %s",r.velocidad); 
			          printf ("\nProyecto: %s",r.proyecto); 
				      printf ("\nAR-XXXX: %s",r.ar); 
				      printf ("\nNombre del proyecto: %s",r.nombreproyecto); 
			      	  printf ("\nNumero de ascensor: %s",r.numero); 	
			          printf ("\nDireccion: %s",r.direccion); 
			          printf ("\nZona: %s",r.zona); 
			          printf ("\nNombre: %s",r.nombre); 
				      printf ("\nMarca: %s",r.marca); 
				      printf ("\nTipo: %s",r.tipo); 
			      	  printf ("\nModelo: %s",r.modelo); 	
			          printf ("\nMaquina: %s",r.maquina); 
			          printf ("\nRegulador: %s",r.regulador); 
			          printf ("\nLargo: %s",r.largo); 
				      printf ("\nCable de traccion: %s",r.traccion); 
				      printf ("\nMarca: %s",r.marcatraccion); 
			      	  printf ("\nLargo de tira: %s",r.largotira); 	
			          printf ("\n");
			    }
			    fread (&r,sizeof(struct ascensor),1,fp);
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
			    fp=fopen ("C:\\Users\\nico_\\Desktop\\HWA\\Ascensores\\Backup_Ascensores.csv","wt");
			    strcpy(nombre,"C:\\Users\\nico_\\Desktop\\HWA\\Ascensores\\Ascensores.dat");
			    listar (fp,nombre);
			    fclose(fp); 
			  	system ("C:\\Users\\nico_\\Desktop\\HWA\\Ascensores\\Backup_Ascensores.csv");	
			    system ("cls");	
			    break;	    
		case 4:
			    if ((fp=fopen("C:\\Users\\nico_\\Desktop\\HWA\\Ascensores\\Ascensores.dat","rb"))==NULL)
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
				printf ("BUSCADOR DE ASCENSORES\n");	
		        printf ("\nIngrese codigo, edificio o direccion a buscar: ");	      
                gets (aux);
                rewind (fp);
                fread (&r,sizeof(struct ascensor),1,fp);	
                system ("cls");
                printf ("BUSCADOR DE ASCENSORES\n");
	            while (!feof(fp))
	            {
                if (strstr(r.codigo,t)!=NULL || strstr(r.edificio,aux)!=NULL || strstr(r.direccion,aux)!=NULL)
                {
                if (r.baja==0)
                {
			    printf ("\nCodigo: %s",r.codigo); 
				printf ("\nEdificio: %s",r.edificio); 
				printf ("\nUso: %s",r.uso); 
			    printf ("\nParadas: %s",r.paradas); 	
			    printf ("\nCarga: %s",r.carga); 
			    printf ("\nVelocidad: %s",r.velocidad); 
			    printf ("\nProyecto: %s",r.proyecto); 
			    printf ("\nAR-XXXX: %s",r.ar); 
				printf ("\nNombre del proyecto: %s",r.nombreproyecto); 
			    printf ("\nNumero de ascensor: %s",r.numero); 	
			    printf ("\nDireccion: %s",r.direccion); 
			    printf ("\nZona: %s",r.zona); 
			    printf ("\nNombre: %s",r.nombre); 
				printf ("\nMarca: %s",r.marca); 
				printf ("\nTipo: %s",r.tipo); 
			    printf ("\nModelo: %s",r.modelo); 	
			    printf ("\nMaquina: %s",r.maquina); 
			    printf ("\nRegulador: %s",r.regulador); 
			    printf ("\nLargo: %s",r.largo); 
				printf ("\nCable de traccion: %s",r.traccion); 
				printf ("\nMarca: %s",r.marcatraccion); 
			    printf ("\nLargo de tira: %s",r.largotira); 	
			    printf ("\n");
			    l++;	
			    } 
			    }
			    fread (&r,sizeof(struct ascensor),1,fp);    
			   	}   
				if (l<1)	
				{
				printf ("\n\nAscensor no encontrado\n");
				}	
		        printf ("\n\nIngrese cualquier tecla para una nueva consulta o [0] para volver: ");
	            scanf ("%d",&j);
	            }
	            fclose (fp);	
			    system ("cls");
		case 5:
		 	    if ((fp=fopen("C:\\Users\\nico_\\Desktop\\HWA\\Ascensores\\Ascensores.dat","rb+"))==NULL)
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
		   	    printf ("MODIFICADOR DE ASCENSORES\n");
	            printf ("Codigo       Edificio                             Direccion");
	            printf ("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
	            rewind (fp);
	            fread (&r,sizeof(struct ascensor),1,fp);
		        while (!feof(fp))
			    {
				if (r.baja==0)
				{
			    printf ("\n%-10s   %-30s       %-10s",r.codigo,r.edificio,r.direccion); 
			    }
			    fread (&r,sizeof(struct ascensor),1,fp);
			    }
				printf ("\n\nIngrese codigo de ascensor a modificar: ");	      
                scanf ("%s",&aux3);
                rewind (fp);
                fread (&r,sizeof(struct ascensor),1,fp);	
                printf ("MODIFICADOR DE ASCENSORES\n");
	              while (!feof(fp))
	              {
                    if (r.baja==0 && !strcmp(r.codigo,aux3))
                    {
                      system ("cls");
					  printf ("\nCodigo: %s",r.codigo); 
			          printf ("\nEdificio: %s",r.edificio); 
				      printf ("\nUso: %s",r.uso); 
			          printf ("\nParadas: %s",r.paradas); 	
			          printf ("\nCarga: %s",r.carga); 
			          printf ("\nVelocidad: %s",r.velocidad); 
			          printf ("\nProyecto: %s",r.proyecto); 
			          printf ("\nAR-XXXX: %s",r.ar); 
				      printf ("\nNombre del proyecto: %s",r.nombreproyecto); 
			          printf ("\nNumero de ascensor: %s",r.numero); 	
			          printf ("\nDireccion: %s",r.direccion); 
			          printf ("\nZona: %s",r.zona); 
			          printf ("\nNombre: %s",r.nombre); 
				      printf ("\nMarca: %s",r.marca); 
				      printf ("\nTipo: %s",r.tipo); 
			          printf ("\nModelo: %s",r.modelo); 	
			          printf ("\nMaquina: %s",r.maquina); 
			          printf ("\nRegulador: %s",r.regulador); 
			          printf ("\nLargo: %s",r.largo); 
				      printf ("\nCable de traccion: %s",r.traccion); 
				      printf ("\nMarca: %s",r.marcatraccion); 
			          printf ("\nLargo de tira: %s",r.largotira); 	
			          printf ("\n");	
					  strcpy(u,r.codigo);
					  l++;
				      r=modificacion(u);
		              fseek (fp,(-1L)*sizeof(struct ascensor),1);
		              fwrite (&r,sizeof(struct ascensor),1,fp); 
		              printf ("\n\nAscensor modificado!!");
		              break;
			          } 
			          fread (&r,sizeof(struct ascensor),1,fp);	 	
			   	  }  
				  if (l<1)	
				  {
				  printf ("\n\nAscensor no encontrado");
				  }	
			      printf ("\n\n\nIngrese cualquier tecla para una nueva modificacion o [0] para volver: ");
	              scanf ("%d",&j);
			      }
		 	    fclose (fp);	
		        system ("cls");
		    	break;
		case 6:	
		        if ((fp=fopen("C:\\Users\\nico_\\Desktop\\HWA\\Ascensores\\Ascensores.dat","rb+"))==NULL)
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
		   	    printf ("ELIMINADOR DE ASCENSORES\n");
	            printf ("Codigo       Edificio                             Direccion");
	            printf ("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
	            rewind (fp);
	            fread (&r,sizeof(struct ascensor),1,fp);
		        while (!feof(fp))
			    {
				if (r.baja==0)
				{
		    	printf ("\n%-10s   %-30s       %-10s",r.codigo,r.edificio,r.direccion); 
			    }
			    fread (&r,sizeof(struct ascensor),1,fp);
			    }
				printf ("\n\nIngrese codigo de ascensor a eliminar: ");	      
                scanf ("%s",&aux4);
                rewind (fp);
                fread (&r,sizeof(struct ascensor),1,fp);	
                system ("cls");
                printf ("ELIMINADOR DE ASCENSORES\n");
	            printf ("Codigo       Edificio                             Direccion");
	            printf ("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
	             while (!feof(fp))
	             {
                   if (r.baja==0 && !strcmp(r.codigo,aux4))
                   {
                   printf ("\n%-10s   %-30s       %-10s",r.codigo,r.edificio,r.direccion);   
				   l++;
					printf ("\n\nIngrese cualquier tecla para eliminar o [0] para cancelar: ");
	                scanf ("%d",&q);
	                if (q)
	                {
				    r.baja=1;
				    fseek (fp,(-1L)*sizeof(struct ascensor),1);
		            fwrite (&r,sizeof(struct ascensor),1,fp);
		            printf ("\nAscensor eliminado!!");
		            break;
		            }else{
		            printf ("\nCANCELADO!!");
					}
			        } 
			        fread (&r,sizeof(struct ascensor),1,fp);	 	
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
		 	    if ((fp=fopen("C:\\Users\\nico_\\Desktop\\HWA\\Ascensores\\Ascensores.dat","rb+"))==NULL)
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
		   	    printf ("RECUPERADOR DE ASCENSORES");
		        printf ("\n\nASCENSORES ELIMINADOS");
	            printf ("\n\nCodigo       Edificio                             Direccion");
	            printf ("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
	            rewind (fp);
                fread (&r,sizeof(struct ascensor),1,fp);
				 while (!feof(fp))
	             {
                    if (r.baja==1)
                    {
                    printf ("\n%-10s   %-30s       %-10s",r.codigo,r.edificio,r.direccion);  
                    l++;
	                }
			        fread (&r,sizeof(struct ascensor),1,fp);	 	
			   	 }  
				 if (l<1)	
				 {
				 printf ("\n\nNo se encontraron ascensores eliminados");
				 } else
				 {
				 printf ("\n\nIngrese codigo de ascensor a recuperar: ");	      
                 scanf ("%s",&aux5);
                 rewind (fp);
                 fread (&r,sizeof(struct ascensor),1,fp);
				 while (!feof(fp))
	             {
                    if (r.baja==1 && !strcmp(r.codigo,aux5))
                    {
				    r.baja=0;
		            fseek (fp,(-1L)*sizeof(struct ascensor),1);
		            fwrite (&r,sizeof(struct ascensor),1,fp);
		            printf ("\nAscensor recuperado!!");
		            s++;
		            break;
		            }
			        fread (&r,sizeof(struct ascensor),1,fp);	 	
			   	 }  
		         if(s<1)
		         {
		         printf ("\n\nAscensor no encontrado/eliminado");
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
struct ascensor ingresoascensor (void){	
	struct ascensor x;
	x.baja=0;
	printf ("\nIngrese codigo: ");
	gets (x.codigo);
	printf("Ingrese edificio: ");
	gets (x.edificio);
    printf ("Ingrese uso: ");
	gets (x.uso);
	printf ("Ingrese paradas: ");
	gets (x.paradas);
	printf ("Ingrese carga: ");
	gets (x.carga);
	printf ("Ingrese velocidad: ");
	gets (x.velocidad);
	printf ("Ingrese proyecto: ");
	gets (x.proyecto);
	printf("Ingrese AR: ");
	gets (x.ar);
    printf ("Ingrese nombre del proyecto: ");
	gets (x.nombreproyecto);
	printf ("Ingrese numero de ascensor: ");
	gets (x.numero);
	printf ("Ingrese direccion: ");
	gets (x.direccion);
	printf ("Ingrese zona: ");
	gets (x.zona);
	printf ("Ingrese nombre: ");
	gets (x.nombre);
	printf("Ingrese marca: ");
	gets(x.marca);
    printf ("Ingrese tipo: ");
	gets (x.tipo);
	printf ("Ingrese modelo: ");
	gets (x.modelo);
	printf ("Ingrese maquina: ");
	gets (x.maquina);
	printf ("Ingrese regulador: ");
	gets (x.regulador);
	printf ("Ingrese largo: ");
	gets (x.largo);
	printf("Ingrese cable de traccion: ");
	gets(x.traccion);
    printf ("Ingrese marca del cable de traccion: ");
	gets (x.marcatraccion);
	printf ("Ingrese largo de la tira: ");
	gets (x.largotira);
	fflush(stdin);
	return x;
}

struct ascensor modificacion (char *u){
	struct ascensor y;
	fflush (stdin);
	y.baja=0;
	strcpy(y.codigo,u);
	printf("Actualice edificio: ");
	gets(y.edificio);
    printf ("Actualice uso: ");
	gets (y.uso);
	printf ("Actualice paradas: ");
	gets (y.paradas);
	printf ("Actualice carga: ");
	gets (y.carga);
	printf ("Actualice velocidad: ");
	gets (y.velocidad);
	printf ("Actualice proyecto: ");
	gets (y.proyecto);
	printf("Actualice AR: ");
	gets(y.ar);
    printf ("Actualice nombre del proyecto: ");
	gets (y.nombreproyecto);
	printf ("Actualice numero de ascensor: ");
	gets (y.numero);
	printf ("Actualice direccion: ");
	gets (y.direccion);
	printf ("Actualice zona: ");
	gets (y.zona);
	printf ("Actualice nombre: ");
	gets (y.nombre);
	printf("Actualice marca: ");
	gets(y.marca);
    printf ("Actualice tipo: ");
	gets (y.tipo);
	printf ("Actualice modelo: ");
	gets (y.modelo);
	printf ("Actualice maquina: ");
	gets (y.maquina);
	printf ("Actualice regulador: ");
	gets (y.regulador);
	printf ("Actualice largo: ");
	gets (y.largo);
	printf("Actualice cable de traccion: ");
	gets(y.traccion);
    printf ("Actualice marca del cable de traccion: ");
	gets (y.marcatraccion);
	printf ("Actualice largo de la tira: ");
	gets (y.largotira);
	fflush (stdin);
	return y;
}

void listar (FILE *fps, char*n)
{
struct ascensor h;
FILE *fp;
  if ((fp=fopen(n,"rb"))==NULL)
    {
	fprintf (fps, "ERROR AL ABRIR EL ARCHIVO!!");
    return;
	}	
fread (&h,sizeof(struct ascensor),1,fp);
while (!feof(fp))
	             {
					if (h.baja==0)
	             	{
	                fprintf (fps,"%s;",h.codigo);
				    fprintf (fps,"%s;",h.edificio); 
				    fprintf (fps,"%s;",h.uso); 
				    fprintf (fps,"%s;",h.paradas); 	
			        fprintf (fps,"%s;",h.carga); 
			        fprintf (fps,"%s;",h.velocidad); 
			        fprintf (fps,"%s;",h.proyecto);
				    fprintf (fps,"%s;",h.ar); 
				    fprintf (fps,"%s;",h.nombreproyecto); 
				    fprintf (fps,"%s;",h.numero); 	
			        fprintf (fps,"%s;",h.direccion); 
			        fprintf (fps,"%s;",h.zona);
			        fprintf (fps,"%s;",h.nombre);
				    fprintf (fps,"%s;",h.marca); 
				    fprintf (fps,"%s;",h.tipo); 
				    fprintf (fps,"%s;",h.modelo); 	
			        fprintf (fps,"%s;",h.maquina); 
			        fprintf (fps,"%s;",h.regulador);
			        fprintf (fps,"%s;",h.largo);
				    fprintf (fps,"%s;",h.traccion); 
				    fprintf (fps,"%s;",h.marcatraccion); 
				    fprintf (fps,"%s",h.largotira); 	
					}
			        fread (&h,sizeof(struct ascensor),1,fp);	 	
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



