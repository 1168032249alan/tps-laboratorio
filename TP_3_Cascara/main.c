#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define LENGTH 100

int main()
{
    char seguir='s', nombreArchivo[20];
    int opcion=0;
    int i;

    EMovie *pMovie;
    EMovie movie[LENGTH];

    pMovie=&movie;

    inicializarPeliculas(pMovie,LENGTH);

    if(cargarArchivo(pMovie, LENGTH)!=-1)
	{
	    printf("Archivo cargado.\n");
	}
	else
	{
		printf("No se pudo abrir el archivo.");
	}


    while(seguir=='s')
    {
        printf("1- Agregar  pelicula\n");
        printf("2- Modificar  pelicula\n");
        printf("3- Borrar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        system("cls");

        switch(opcion)
        {
            case 1:
                {
                if(agregarPelicula(pMovie,LENGTH)==-1)
                printf("No se pudo agregar pelicula.");
                }
                break;
            case 2:
                {
                if(modificarPelicula(pMovie,LENGTH)==-1)
                printf("No se puede modificar.\n");
                }
                break;
            case 3:
                {
                if(borrarPelicula(pMovie,LENGTH)==-1)
                printf("No se puede borrar.\n");
                }
               break;
            case 4:
                {
                printf("Ingrese nombre de archivo a guardar: ");
                scanf("%s",&nombreArchivo);
                generarHTML(pMovie,LENGTH,nombreArchivo);
                }
                break;
            case 5:
                printf("\nGuardar cambios s/n ?: ");

				do{
                    opcion = tolower(getche());


                    if(opcion == 's')
                    {
                        if(guardarArchivo(pMovie, LENGTH)==-1)
                        {
                            printf("\nNo se pudo abrir el archivo\n");
                        }
                        else
                            {
                            printf("\nSe guardo la informacion con exito\n");
                            }
                    }

                    if(opcion == 'n')
                    {
                        break;
                    }
				}while(opcion!='s' && opcion!='n');

				seguir='n';

                break;
        }
    }

    return 0;
}
