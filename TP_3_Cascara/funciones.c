#include "funciones.h"
#include <stdio.h>
#include <string.h>

void inicializarPeliculas(EMovie *pMovie, int length)
{
    int i;

    for(i=0;i<length;i++)
    {
        strcpy((pMovie+i)->titulo," ");
        strcpy((pMovie+i)->genero," ");
        (pMovie+i)->duracion=0;
        strcpy((pMovie+i)->descripcion," ");
        (pMovie+i)->puntaje=0;
        strcpy((pMovie+i)->linkImagen," ");
    }
}

int cargarArchivo(EMovie *pMovie,int length)
{
    int flag=0;
	FILE *A;

	A=fopen("archivo.bin", "rb");

	if(A==NULL)
	{
		A = fopen("archivo.bin", "wb");

		if(A==NULL)
		{
			return 1;
		}

		flag=1;

	}

	if(flag==0)
	{
	    fread(pMovie,sizeof(EMovie),length,A);
    }

	fclose(A);

	return 0;
}

int agregarPelicula(EMovie *pMovie, int length)
{
    int indiceVacio;

    indiceVacio=buscarVacio(pMovie, length);

    if(indiceVacio>=0)
    {
        printf("Ingrese titulo de la pelicula: ");
        fflush(stdin);
        gets((pMovie+indiceVacio)->titulo);

        printf("Ingrese genero de la pelicula: ");
        fflush(stdin);
        gets((pMovie+indiceVacio)->genero);

        do{
            printf("Ingrese duracion de la pelicula: ");
            fflush(stdin);
            scanf("%d", &(pMovie+indiceVacio)->duracion);
            if((pMovie+indiceVacio)->duracion<=0)
            {
                printf("Error! ");
            }
        }while((pMovie+indiceVacio)->duracion<=0 && !isdigit((pMovie+indiceVacio)->duracion));


        printf("Ingrese la descripcion de la pelicula: ");
        fflush(stdin);
        gets((pMovie+indiceVacio)->descripcion);


        do{
            printf("Ingrese puntaje de la pelicula (del 0 al 10): ");
            fflush(stdin);
            scanf("%d", &(pMovie+indiceVacio)->puntaje);
            if((pMovie+indiceVacio)->puntaje<0 || (pMovie+indiceVacio)->puntaje>10)
            {
                printf("Error! ");
            }
        }while(((pMovie+indiceVacio)->puntaje<0 || (pMovie+indiceVacio)->puntaje>10) && !isdigit((pMovie+indiceVacio)->puntaje));

        printf("Ingrese link de imagen de la pelicula: ");
        fflush(stdin);
        gets((pMovie+indiceVacio)->linkImagen);
    }
    else
        printf("sin espacio .");

    return indiceVacio;
}

int borrarPelicula(EMovie *pMovie, int length)
{
    int opcion, retorno=-1;
    char opcion2;

    if(estaVacio(pMovie,length)==1)
    {
    printf("Seleccione la  pelicula que desea eliminar: \n");

    mostrarPeliculas(pMovie,length);

    scanf("%d",&opcion);

    printf("Esta seguro que desea eliminar s/n: %s\n",(pMovie+(opcion-1))->titulo);

    fflush(stdin);
    opcion2=getchar();

    if(opcion>=1 && opcion<=length && opcion2=='s')
    {
        strcpy((pMovie+(opcion-1))->titulo,"");
        strcpy((pMovie+(opcion-1))->genero,"");
        (pMovie+(opcion-1))->duracion=0;
        strcpy((pMovie+(opcion-1))->descripcion,"");
        (pMovie+(opcion-1))->puntaje=0;
        strcpy((pMovie+(opcion-1))->linkImagen,"");
    }
    retorno=1;
    }

    return retorno;
}

int modificarPelicula(EMovie *pMovie, int length)
{
    int opcion=-1, opcion2, retorno=-1,cantidadMostradas;

    if(estaVacio(pMovie,length)==1)
    {

    printf("Seleccione la pelicula que desea modificar: \n");

    cantidadMostradas=mostrarPeliculas(pMovie,length);

    scanf("%d",&opcion);

    if(opcion<=cantidadMostradas && opcion>=1)
    {

    printf("1- Modificar Titulo\n");
    printf("2- Modificar Genero\n");
    printf("3- Modificar Duracion\n");
    printf("4- Modificar Descripcion (muestra la descripcion anterior)\n");
    printf("5- Modificar Puntaje\n");
    printf("6- Modificar Link de Imagen\n");
    printf("7- Volver al menu principal\n");

    fflush(stdin);
    scanf("%d",&opcion2);

    system("cls");


        switch(opcion2)
        {
            case 1:
                {
                    printf("Ingrese nuevo titulo: ");
                    fflush(stdin);
                    gets((pMovie+(opcion-1))->titulo);
                }
                break;
            case 2:
                {
                    printf("Ingrese nuevo genero: ");
                    fflush(stdin);
                    gets((pMovie+(opcion-1))->genero);
                }
                break;
            case 3:
                {
                    do{
                    printf("Ingrese nueva duracion: ");
                    fflush(stdin);
                    scanf("%d", &(pMovie+(opcion-1))->duracion);
                    if((pMovie+(opcion-1))->duracion<=0)
                    {
                        printf("Error! ");
                    }
                    }while((pMovie+(opcion-1))->duracion<=0 && !isdigit((pMovie+(opcion-1))->duracion));
                }
               break;
            case 4:
                {
                    printf("%s\n\n", (pMovie+(opcion-1))->descripcion);
                    printf("Desea editar descripcion? s/n\n");
                    fflush(stdin);
                    if(getchar()=='s')
                    {
                        printf("Ingrese nueva descripcion: ");
                        fflush(stdin);
                        gets((pMovie+(opcion-1))->descripcion);
                    }
                }
                break;
            case 5:
                {
                    do{
                    printf("Ingrese puntaje de la pelicula (del 0 al 10): ");
                    fflush(stdin);
                    scanf("%d", &(pMovie+(opcion-1))->puntaje);
                    if((pMovie+(opcion-1))->puntaje<0 || (pMovie+(opcion-1))->puntaje>10)
                    {
                        printf("Error! ");
                    }
                    }while(((pMovie+(opcion-1))->puntaje<0 || (pMovie+(opcion-1))->puntaje>10) && !isdigit((pMovie+(opcion-1))->puntaje));
                }
                break;
            case 6:
                {
                    printf("Ingrese nuevo link de la imagen: ");
                    fflush(stdin);
                    gets((pMovie+(opcion-1))->linkImagen);
                }
                break;
            case 7:
                break;
            default:
                printf("Opcion incorrecta.\n");
                break;
        }
        retorno=1;
    }
    else
        printf("Error ");
    }


    return retorno;
}

int buscarVacio(EMovie *pMovie, int length)
{
    int indiceVacio=-1;
	int i;
	for( i=0; i < length; i++)
    {
        if((pMovie+i)->duracion==0)
        {
            indiceVacio=i;
            break;
        }
    }

	return indiceVacio;
}

int mostrarPeliculas(EMovie *pMovie,int length)
{
    int i, retorno=0;

    printf("  Titulo \n\n\n Genero\n\n\n Duracion\tPuntaje\n");

    for(i=0;i<length;i++)
    {
        if((pMovie+i)->duracion>0)
        {
            printf("%d %s\n\n%s\n\n\n%d\n\n%d\n",i+1, (pMovie+i)->titulo, (pMovie+i)->genero,(pMovie+i)->duracion,(pMovie+i)->puntaje);
            retorno+=1;
        }
    }
    return retorno;
}

int guardarArchivo(EMovie *pMovie,int length)
{
	FILE *A;
	int flag=-1;

    A=fopen("archivo.bin","wb");

    if(A!=NULL)
    {
        fwrite(pMovie,sizeof(EMovie),length,A);
        fclose(A);
        flag=1;
    }

	return flag;
}

void generarHTML(EMovie *pMovie,int length, char nombre[])
{
     int i;
     FILE *A;
     strcat(nombre,".html");
     A=fopen(nombre, "w");

     if(A == NULL)
     {
          printf("No se pudo abrir el archivo\n");
     }
     else
     {
         for(i=0; i<length; i++)
         {
             fprintf(A,"<article class='col-md-4 article-intro'>\n<a href='#'>\n");
             fprintf(A,"<img class='img-responsive img-rounded' src='");
             if((pMovie+i)->duracion>0)
             {
                 fprintf(A,"%s'\n\nalt=''>\n </a>\n <h3>\n <a href='#'>", (pMovie+i)->linkImagen);
                 fprintf(A,"%s</a>\n </h3>\n<ul>\n<li>", (pMovie+i)->titulo);
                 fprintf(A,"Genero: %s</li>\n<li>", (pMovie+i)->genero);
                 fprintf(A,"Puntaje: %d</li>\n<li>", (pMovie+i)->puntaje);
                 fprintf(A,"Duracion: %d</li>\n</ul>\n <p>", (pMovie+i)->duracion);
                 fprintf(A,"%s</p>\n</article>\n", (pMovie+i)->descripcion);
             }

         }
      }

      fclose(A);

      printf(" EL Archivo HTML fue creado con exito.\n");
      system("pause");
}

int estaVacio(EMovie *pMovie,int length)
{
    int i, retorno=-1;

    for(i=0;i<length;i++)
    {
        if(((pMovie+i)->duracion)!=0)
        {
            retorno=1;
            break;
        }
    }

    return retorno;
}
