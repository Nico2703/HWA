#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
	
void appreclamos(void);
void AltEnter();

int main (int argc, char *argv[])
{
SetConsoleCP (1252);
SetConsoleOutputCP(1252);
system ("color 8F");
int opcion;
char bucle[60];
while (strcmp(bucle,"0"))
{
	printf ("SOFTWARE INTEGRAL");
    printf ("\n\n***Menu***\n");
	printf ("\n1-  SOFTWARE DE RECLAMOS");
	printf ("\n2-  SOFTWARE DE REPARACIONES");
	printf ("\n3-  SOFTWARE DE INFORMACION");
	printf ("\n4-  SOFTWARE DE PRESUPUESTOS");
	printf ("\n5-  SOFTWARE DE STOCK");
	printf ("\n6-  SOFTWARE DE ENTRADA/SALIDA");
	printf ("\n7-  SOFTWARE DE TAREAS");
	printf ("\n0-  SALIR\n");
	printf ("\nOpcion: ");
	scanf ("%d",&opcion);
    system ("cls");
	  switch (opcion)
      {
    	case 1: system("C:\\Users\\nico_\\Desktop\\HWA\\Reclamos\\Reclamos.exe");
		        //system ("Reclamos.exe");
    	        system ("CLS");
    	        AltEnter ();
    	        break;
        case 2: system("C:\\Users\\nico_\\Desktop\\HWA\\Reparaciones\\Reparaciones.exe");
		        //system ("Reparaciones.exe");
                system ("CLS");
                AltEnter ();
                break;
        case 3: system("C:\\Users\\nico_\\Desktop\\HWA\\Ascensores\\Ascensores.exe");
		        //system ("Ascensores.exe");
                system ("CLS");
                AltEnter ();
                break;
        case 4: system("C:\\Users\\nico_\\Desktop\\HWA\\Presupuestos\\Presupuestos.exe");
		        //system ("Presupuestos.exe");
                system ("CLS");
                AltEnter ();
                break;
        case 5: system("C:\\Users\\nico_\\Desktop\\HWA\\Stock\\Stock.exe");
		        //system ("Stock.exe");
                system ("CLS");
                AltEnter ();
                break;
        case 6: system("C:\\Users\\nico_\\Desktop\\HWA\\Entrada-Salida\\Entrada-Salida.exe");
		        //system ("Entrada-Salida.exe");
                system ("CLS");
                AltEnter ();
                break;
        case 7: system("C:\\Users\\nico_\\Desktop\\HWA\\Tareas\\Tareas.exe");
		        //system ("Tareas.exe");
                system ("CLS");
                //AltEnter ();
                break;
        case 0: strcpy (bucle,"0");
                break;
        default:
		    	printf ("OPCION INCORRECTA!!");
		    	printf ("\nReinicie el programa\n\n");
		    	system ("PAUSE");
		    	strcpy (bucle,"0");
		        break;
	  }
    }
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

