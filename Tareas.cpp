#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <wchar.h>
#include <locale.h>


struct tarea modificacion (int q);


struct tarea{
	int id;
	char edificio[60];
	char tarea[100];
	char descripcion [100];
};

int main (int argc, char *argv[])
{
	system ("color 8F");
	setlocale(LC_CTYPE, "Spanish");
	SetConsoleCP(1252); 
    SetConsoleOutputCP(1252);
	int i;
	int j=1;
	int o,p,q;	
	char t[60];
	FILE *fp;
	struct tarea r;	
	while (j)
    {  
	    while (1){
	    system ("CLS");
	    o=0;
		printf ("SOFTWARE DE TAREAS v1.0\n");
		if ((fp=fopen("C:\\Users\\nico_\\Desktop\\HWA\\Tareas\\Tareas.dat","ab+"))==NULL)
	    {
    	printf ("ERROR AL ABRIR EL ARCHIVO!!");
		system ("PAUSE");  
		break;}
		fread (&r,sizeof(struct tarea),1,fp);
	    while (!feof(fp))	
	    {
	    o=r.id;
	    fread (&r,sizeof(struct tarea),1,fp);
		}
	    printf ("\n #    Edificio               Tarea                                               Descripcion    ");
	    printf ("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
		rewind (fp);
	    fread (&r,sizeof(struct tarea),1,fp);
		while (!feof(fp))
		{
		printf ("\n %-5d%-20s   %-50s  %-40s",r.id,r.edificio,r.tarea,r.descripcion);
		fread (&r,sizeof(struct tarea),1,fp);
		}
		o++;
		fclose(fp);
	printf ("\n\n1-  Generar campo");
	printf ("\n2-  Modificar campo");
	printf ("\n0-  Salir");
	printf ("\n\nOpcion: ");
	gets(t);
    if (!strcmp(t,"1")){
    if ((fp=fopen("C:\\Users\\nico_\\Desktop\\HWA\\Tareas\\Tareas.dat","ab+"))==NULL)
	{
    printf ("ERROR AL ABRIR EL ARCHIVO!!");
	system ("PAUSE");  
	break;}
	fflush(stdin);
	r.id=o;
	strcpy(r.edificio," ");
	strcpy(r.tarea," ");
	strcpy(r.descripcion," ");
    //printf ("\n\nIngresar edificio: ");
    ////gets (r.edificio);
    //printf ("Ingresar tarea: ");
    //gets(r.tarea);
    //printf ("Ingresar descripcion: ");
    //gets(r.descripcion);
    fwrite (&r,sizeof(struct tarea),1,fp);
    fclose(fp);
    break;
	}
	else if (!strcmp(t,"2")){
	if ((fp=fopen("C:\\Users\\nico_\\Desktop\\HWA\\Tareas\\Tareas.dat","rb+"))==NULL)
	{
    printf ("ERROR AL ABRIR EL ARCHIVO!!");
	system ("PAUSE");  
	break;}
	p=0;
	printf ("\n\nIngresar numero de tarea a modificar: ");
	scanf ("%d",&i);
	rewind (fp);
	fread (&r,sizeof(struct tarea),1,fp);
	while (!feof(fp))
	{
	if (r.id==i){
		p++;
		q=r.id;
		//printf ("\nEdificio actual: %s",r.edificio);
		//printf ("\nTarea actual: %s",r.tarea);
		//printf ("\nDescripcion actual: %s",r.descripcion);	
		r=modificacion(q);
		fseek (fp,(-1L)*sizeof(struct tarea),1);
		fwrite (&r,sizeof(struct tarea),1,fp); 
		fclose(fp);
		break;
	}
	fread (&r,sizeof(struct tarea),1,fp);
	}
	if(p<1){
		printf("Numero incorrecto\n");
		system("PAUSE");}
    }
    else if (!strcmp(t,"0")){
    	j=0;
    	fclose(fp);
    	break;
	}
 	else  {
 		fclose(fp);
 		break;}
    }   
    }
    return 0;
}

struct tarea modificacion (int q){
	    struct tarea x;
	    fflush(stdin);
	    x.id=q;
	    printf ("\n\nIngresar edificio: ");
		gets(x.edificio);
		printf ("Ingresar tarea: ");
		gets(x.tarea);
		printf ("Ingresar descripcion: ");
		gets(x.descripcion);
		fflush(stdin);	
		return x;
}
