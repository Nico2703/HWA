#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <wchar.h>
#include <locale.h>

void Color(int Background, int Text);          

enum Colors { 
 BLACK = 0,
 BLUE = 1,
 GREEN = 2,
 CYAN = 3,
 RED = 4,
 MAGENTA = 5,
 BROWN = 6,
 LGREY = 7,
 DGREY = 8,
 LBLUE = 9,
 LGREEN = 10,
 LCYAN = 11,
 LRED = 12,
 LMAGENTA = 13,
 YELLOW = 14,
 WHITE = 15
};

void AltEnter();

struct presupuesto{
	char tipo [20];
	char creador [40];
	char codigo [20];
	char cliente [60];
	char descripcion [100];
	char comprobante [200];
	char ascensor [60];
	char fecha [40];
	char estadotec [20];
	char estadopre [20];
	char estadoadm [20];
};

struct archivos {
	 char n1[20]= "2001_3000.dat";
	 char n2[20]= "3001_4000.dat";
	 char n3[20]= "180001_180100.dat";
     char n4[20]= "180101_180200.dat";
     char n5[20]= "190001_200013.dat";
     char n6[20]= "200014_200100.dat";
};

int main (int argc, char *argv[])
{
	setlocale(LC_CTYPE, "Spanish");
	SetConsoleCP(1252); 
    SetConsoleOutputCP(1252);
	system ("color 8F");
	int i,j;
	int s;
	int v=0;
	char aux[100], aux2[100];
	char nombre[100];
	char directorio[100];
	char copia[100]="C:\\Users\\nico_\\Desktop\\HWA\\Presupuestos\\DAT\\";
	char k=1;
	char t[60];
	FILE *fp;
	struct presupuesto r;
	struct archivos a;
	AltEnter ();
	while (k!='S')
	{
	j=1;  
	printf ("SOFTWARE DE PRESUPUESTOS v1.0\n");
	printf ("ARCHIVOS EN USO: <%s> <%s> <%s> <%s> <%s> <%s>",a.n1,a.n2,a.n3,a.n4,a.n5,a.n6);
	printf ("\n\n***Menu***\n");
	printf ("\n1-  Buscar presupuestos por edificio");
	printf ("\n2-  Invertir iluminacion");
	printf ("\n0-  Salir\n");
	printf ("\nOpcion: ");
	scanf ("%d",&i);
    system ("cls");
	switch (i)
	{    
		case 1:	
		        while (j)
		        {
				system ("CLS");
				s=1;
				printf ("BUSCADOR DE PRESUPUESTOS\n");
				while(s<7)
		        { 	
		        strcpy(directorio," ");
				strcpy(directorio,copia);
				if (s==1) strcpy (nombre,a.n1);
		        else if (s==2) strcpy (nombre,a.n2);
		        else if (s==3) strcpy (nombre,a.n3);
		        else if (s==4) strcpy (nombre,a.n4);
		        else if (s==5) strcpy (nombre,a.n5);
		        else if (s==6) strcpy (nombre,a.n6);
		        else s==0;
		        strcat(directorio,nombre);
		        if ((fp=fopen(directorio,"rb"))==NULL)
		        {
				printf ("ERROR AL ABRIR EL ARCHIVO!!");
			    printf ("\n\nIngrese cualquier tecla para volver o 'S' para salir: ");
			    scanf ("%s",&k);
			    system ("cls");
			    break;
		    	}else
		    	if (s==1){
		        fflush (stdin);	
				printf ("\nIngrese palabra clave uno: ");	      
                gets (aux);
				if (strlen(aux)<2) {
                	printf("\nERROR! Ingrese más datos\n\n");
                	system("PAUSE");
                	break;}
				printf ("Ingrese palabra clave dos: ");	
				gets (aux2);}
				if (strlen(aux2)<2) {
                	printf("\nERROR! Ingrese más datos\n\n");
                	system("PAUSE");
                	break;
				}
		    	printf ("\nArchivo abierto: %s",nombre);
		        int l=0;	
                rewind (fp);
                fread (&r,sizeof(struct presupuesto),1,fp);	
	            while (!feof(fp))
	            {
                if (strstr(r.cliente,aux)!=NULL || strstr(r.cliente,aux2)!=NULL)
                {
				Color(DGREY,BLACK); printf ("\n\nTipo: %s",r.tipo); 
				Color(DGREY,BLACK);printf ("\nCreador: %s",r.creador); 
				Color(DGREY,BLACK);printf ("\nCodigo: %s",r.codigo); 
			    Color(DGREY,BLACK);printf ("\nCLiente: %s",r.cliente); 	
			    Color(DGREY,BLACK);printf ("\nDescripcion: %s",r.descripcion); 
			    Color(DGREY,BLACK);printf ("\nComprobante: %s",r.comprobante); 
			    Color(DGREY,BLACK);printf ("\nAscensor: %s",r.ascensor); 
			    Color(DGREY,BLACK);printf ("\nFecha: %s",r.fecha); 
			    Color(DGREY,BLACK);printf ("\nEstado operativo: %s",r.estadotec); 
			    Color(DGREY,BLACK);printf ("\nEstado presupuesto: %s",r.estadopre); 
			    Color(DGREY,BLACK);printf ("\nEstado administrativo: %s",r.estadoadm); 
			    Color(DGREY,WHITE);printf ("\n");
			    l++;
			    }
			    fread (&r,sizeof(struct presupuesto),1,fp);    
			   	}   
				if (l<1)	
				{
				printf ("\n\nPresupuesto no encontrado\n");
				}	
		        s++;
	            }
	            printf ("\n\n\nIngrese cualquier tecla para una nueva consulta o [0] para volver: ");
	            scanf ("%d",&j);
	            }
	            fclose (fp);	
			    system ("cls");
			    break;
		case 2:
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

void Color(int Background, int Text){ 
 HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE); 
 int    New_Color= Text + (Background * 16);
 SetConsoleTextAttribute(Console, New_Color); }


