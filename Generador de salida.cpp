#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void Generador();
char *getKey(char *key);

struct salida{
	char fecha [25];
	char descripcion [100];
	char edificio [60];
	char ascensor [40];
	char cantidad [10];
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
char directorio[100]="C:\\Users\\nico_\\Desktop\\HWA\\Entrada-Salida\\CSV\\";
char directorio2[100]="C:\\Users\\nico_\\Desktop\\HWA\\Entrada-Salida\\DAT\\";
struct salida r;
FILE *conf;
FILE *fp;
char cadena[5000], *key, *val;
system("cls");
fflush(stdin);
printf ("GENERACION DE SALIDA\n");
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
		
		key = cadena;
		val = getKey(key); 	
		strcpy(r.fecha,key);					
	
		key = val;
		val = getKey(key); 	
		strcpy(r.descripcion,key);				
		
		key = val;
		val = getKey(key);
		strcpy(r.edificio,key); 				
		
		key = val;
		val = getKey(key); 	
		strcpy(r.ascensor,key);	 
		strcpy(r.cantidad,val);
		
    fwrite(&r,sizeof(struct salida),1,fp);
    fgets(cadena, 5000, conf);
    
}
	fclose(conf);
	rewind(fp);
	printf ("ARCHIVO CREADO!!");
	printf ("\n\nLISTADO DE PRESUPUESTOS\n"); 
	printf ("\n Fecha        Descripcion                                                                       Edificio                                Ascensor               Cantidad");
	printf ("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
	fread (&r,sizeof(struct salida),1,fp);
	while (!feof(fp))
			    {
			    printf ("\n %-10s   %-70s            %-28s            %-20s   %-10s",r.fecha,r.descripcion,r.edificio,r.ascensor,r.cantidad); 
			    fread (&r,sizeof(struct salida),1,fp);
			    }
fclose(fp);
printf ("\n\n");
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

