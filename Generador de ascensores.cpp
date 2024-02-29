#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void Generador();
char *getKey(char *key);

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
char directorio[100]="C:\\Users\\nico_\\Desktop\\HWA\\Ascensores\\CSV\\";
char directorio2[100]="C:\\Users\\nico_\\Desktop\\HWA\\Ascensores\\";
struct ascensor r;
FILE *conf;
FILE *fp;
char cadena[5000], *key, *val;
system("cls");
fflush(stdin);
printf ("GENERACION DE ASCENSORES\n");
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
		strcpy(r.codigo,key);					
	
		key = val;
		val = getKey(key); 	
		strcpy(r.edificio,key);				
		
		key = val;
		val = getKey(key);
		strcpy(r.uso,key); 				
		
		key = val;
		val = getKey(key);
		strcpy(r.paradas,key); 
		
		key = val;
		val = getKey(key);
		strcpy(r.carga,key); 
		
		key = val;
		val = getKey(key);
		strcpy(r.velocidad,key); 
		
		key = val;
		val = getKey(key);
		strcpy(r.proyecto,key); 
		
		key = val;
		val = getKey(key);
		strcpy(r.ar,key); 
		
		key = val;
		val = getKey(key);
		strcpy(r.nombreproyecto,key); 
		
		key = val;
		val = getKey(key);
		strcpy(r.numero,key); 
		
		key = val;
		val = getKey(key);
		strcpy(r.direccion,key); 
		
		key = val;
		val = getKey(key);
		strcpy(r.zona,key); 
		
		key = val;
		val = getKey(key);
		strcpy(r.nombre,key);
		 
		key = val;
		val = getKey(key);
		strcpy(r.marca,key); 
		
		key = val;
		val = getKey(key);
		strcpy(r.tipo,key); 
		
		key = val;
		val = getKey(key);
		strcpy(r.modelo,key); 
		
		key = val;
		val = getKey(key);
		strcpy(r.maquina,key); 
		
		key = val;
		val = getKey(key);
		strcpy(r.regulador,key); 
		
		key = val;
		val = getKey(key);
		strcpy(r.marca,key); 
		
		key = val;
		val = getKey(key);
		strcpy(r.largo,key); 
		
		key = val;
		val = getKey(key);
		strcpy(r.traccion,key); 
		
		key = val;
		val = getKey(key); 	
		strcpy(r.marcatraccion,key);	 
		strcpy(r.largotira,val);
		
    fwrite(&r,sizeof(struct ascensor),1,fp);
    fgets(cadena, 5000, conf);
    
}
	fclose(conf);
	rewind(fp);
	printf ("ARCHIVO CREADO!!");
	printf ("\n\nLISTADO DE ASCENSORES\n");
	printf ("Codigo       Edificio                             Direccion");
	fread (&r,sizeof(struct ascensor),1,fp);
	while (!feof(fp))
			    {
			    printf ("\n%-10s   %-30s       %-10s",r.codigo,r.edificio,r.direccion); 
			    fread (&r,sizeof(struct ascensor),1,fp);
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


