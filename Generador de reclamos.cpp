#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <wchar.h>
#include <locale.h>

void Generador();
char *getKey(char *key);

struct reclamo{
	//int baja;
	char codigo[10];
	char equipo[10];
	char fecharec[25];
	char horarec[25];
	char titulo[100];
	char descripcion[];
	char fechavis[25];
	char tareavis[60];
	char fechares[25];
	char horaini[25];
	char horafin[25];
	char tareares[60];
	char tecnico[40];
};

int main (int argc, char *argv[])
{
setlocale(LC_CTYPE, "Spanish");
SetConsoleCP(1252); 
SetConsoleOutputCP(1252);
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
char directorio[100]="C:\\Users\\nico_\\Desktop\\HWA\\Reclamos\\CSV\\";
char directorio2[100]="C:\\Users\\nico_\\Desktop\\HWA\\Reclamos\\DAT\\";
struct reclamo r;
FILE *conf;
FILE *fp;
char cadena[20000], *key, *val;
system("cls");
fflush(stdin);
printf ("GENERACION DE ARCHIVOS\n");
printf ("INSTRUCTIVO PARA GENERAR");
printf ("\n1- Exportar archivo de registros desde la web de Indicom");
printf ("\n2- Abrir con Excel e importar con las siguientes opciones:");
printf ("\n   Tipo de archivo: Delimitados");
printf ("\n   Separadores - Otro - '|'");
printf ("\n   Formato general");
printf ("\n3- Dejar solo las siguientes columnas (eliminar el resto):");
printf ("\n   Idllamada");
printf ("\n   Fechahora");
printf ("\n   Form1dat");
printf ("\n   Form2dat");
printf ("\n   Form10dat");
printf ("\n4- Eliminar la primer fila con los campos");
printf ("\n5- Guardar el archivo en la carpeta del programa de reclamos con el nombre deseado y el tipo '.CSV (delimitado por comas)'");
printf ("\n   Para lograr mayor prolijidad, se recomienda eliminar (antes de guardar) reclamos fallidos y caracteres no deseados");
printf ("\n\n\nIngrese nombre del archivo de Excel a abrir: ");
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
fgets(cadena, 20000, conf);	            
while(!feof(conf))
{
	    //r.baja=0;

		key = cadena;
		val = getKey(key); 	
		strcpy(r.codigo,key);					
	    
		key = val;
		val = getKey(key); 	
		strcpy(r.equipo,key);				
	
		key = val;
		val = getKey(key);
		strcpy(r.fecharec,key); 					
		
		key = val;
		val = getKey(key);
		strcpy(r.horarec,key); 					
		
		key = val;
		val = getKey(key);
		strcpy(r.titulo,key); 					
	
		key = val;
		val = getKey(key);
		strcpy(r.descripcion,key); 	
		
		key = val;
		val = getKey(key);
		strcpy(r.fechavis,key); 	
		
		key = val;
		val = getKey(key);
		strcpy(r.tareavis,key); 	
		
		key = val;
		val = getKey(key);
		strcpy(r.fechares,key); 
		
		key = val;
		val = getKey(key);
		strcpy(r.horaini,key); 
		
		key = val;
		val = getKey(key);
		strcpy(r.horafin,key); 					
		
		key = val;
		val = getKey(key); 	
		strcpy(r.tareares,key);	 
		strcpy(r.tecnico,val);
		
    fwrite(&r,sizeof(struct reclamo),1,fp);
    fgets(cadena, 20000, conf);
    
}
	fclose(conf);
	rewind(fp);
	printf ("ARCHIVO CREADO!!");
	printf ("\n\nLISTADO DE RECLAMOS\n");
	printf ("\n Codigo     Fecha             Hora                       Título                                Resolución");
	printf ("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
	fread (&r,sizeof(struct reclamo),1,fp);
	while (!feof(fp))
			    {
				printf ("\n# %-5s%-10s %-10s   %-35s   %-10s\n",r.codigo,r.fecharec,r.horarec,r.titulo,r.tareares); 
			    fread (&r,sizeof(struct reclamo),1,fp);
			    }
                fclose(fp);
                printf ("\n\n");
			    return;
} 

char *getKey(char *key){
long int i = 0;
while(*(key+i) != ';'){
	i++;
}
*(key+i) = 0;
return key+i+1;
}

