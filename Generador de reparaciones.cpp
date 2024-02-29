#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void Generador();
char *getKey(char *key);

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
system ("color 8F");
Generador();
system ("PAUSE");
return 0;
}


void Generador(){	
char t[60];
char nombre[100];
char nombre2[100];
char extension[10]=".dat";
char extension2[10]=".csv";
char directorio[100]="C:\\Users\\nico_\\Desktop\\HWA\\Reparaciones\\CSV\\";
char directorio2[100]="C:\\Users\\nico_\\Desktop\\HWA\\Reparaciones\\";
struct reparacion r;
FILE *conf;
FILE *fp;
char cadena[5000], *key, *val;
system("cls");
fflush(stdin);
printf ("GENERACION DE REPARACIONES\n");
printf ("\nIngrese nombre del archivo de Excel a abrir: ");
gets(nombre);
strcat(nombre,extension2);
strcat(directorio,nombre);
if((conf = fopen(directorio,"rb")) == NULL ){
	printf ("ERROR AL ABRIR EL ARCHIVO!!");
	printf ("\n\nIngrese cualquier tecla para volver: ");
		    	scanf ("%s",&t);
			    system ("cls");
			    return;
} 
	printf ("ARCHIVO ABIERTO!!");
	fflush(stdin);
	printf ("\nIngrese nombre del archivo a crear: ");
    gets(nombre2); 
	strcat(nombre2,extension);	
	strcat(directorio2,nombre2);
if ((fp=fopen(directorio2,"wb+"))==NULL) {
    	        printf ("ERROR AL CREAR EL ARCHIVO !!");
			    printf ("\n\nIngrese cualquier tecla para volver: ");
		    	scanf ("%s",&t);
			    system ("cls");
			    return;
	            }
fgets(cadena, 5000, conf);	            
while(!feof(conf))
{
		r.baja=0;
		
		key = cadena;
		val = getKey(key); 	
		strcpy(r.fecha,key);					
	
		key = val;
		val = getKey(key); 	
		strcpy(r.placa,key);				
		
		key = val;
		val = getKey(key);
		strcpy(r.tarea,key); 				
		
		key = val;
		val = getKey(key);
		strcpy(r.codigo,key); 
		
		key = val;
		val = getKey(key); 	
		strcpy(r.nota,key);	 
		strcpy(r.otros,val);
		
    fwrite(&r,sizeof(struct reparacion),1,fp);
    fgets(cadena, 5000, conf);
    
}
	fclose(conf);
	rewind(fp);
	printf ("ARCHIVO CREADO!!");
	printf ("\n\nLISTADO DE REPARACIONES\n");
	fread (&r,sizeof(struct reparacion),1,fp);
	while (!feof(fp))
			    {
			    printf ("\nCodigo: %s",r.codigo); 
				printf ("\nFecha: %s",r.fecha); 
				printf ("\nPlaca: %s",r.placa); 
				printf ("\nTarea: %s",r.tarea); 	
			    printf ("\nNota: %s",r.nota); 
			    printf ("\nOtros: %s",r.otros); 
			    printf ("\n");
			    fread (&r,sizeof(struct reparacion),1,fp);
			    }
printf ("\n\n");
fclose(fp);
return;
} 

char *getKey(char *key){
char i = 0;
while(*(key+i) != ';'){
	i++;
}
*(key+i) = 0;
return key+i+1;
}

