#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"



int VerificacionTexto (char texto[TEXTOMAX],int desde, int hasta)
{
    int cantidad=strlen(texto);
    int retorno=0;
    int i;
    if (cantidad>=desde && cantidad<=hasta )
    {
        retorno=1;
            for (i=0;i<cantidad;i++)
            {
                   if(isdigit(texto[i]))
                    {
                        system("cls");
                        printf("No puede ingresar numero/s\n");
                        retorno=0;
                        break;
                    }
            }
    }
    else
    {
        system("cls");
        printf("Supero el limite de caracter permitido o no ingreso nada\n");
    }
    return retorno;
}

int menu ()
{
    int opcion;

        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        return opcion;
}

int VerificacionNumero (char mensaje [MENSAJE], int desde, int hasta)
{
    int retorno;
    int i;
    char numero[500];
    int numeroverdadero;

    do
    {
        printf("%s ",mensaje);
        scanf ("%s",numero);
        int cantidad=strlen(numero);
        for (i=0;i<cantidad;i++)
        {
            retorno=0;
            if(isalpha(numero[i]))
            {
                printf("No puede ingresar letras/s\n");
                retorno=1;
                break;
            }
        }
    }while(retorno);
    numeroverdadero=atoi(numero);
    return numeroverdadero;
}

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
void setMovieTitulo (char mensaje[MENSAJE],sMovie movie[],int indice)
{
    char titulo [MAX_TEXT_TITULO];

        do{
            printf("%s: ",mensaje);
            fflush(stdin);
            gets(titulo);
        }while(!VerificacionTexto(titulo,1,MAX_TEXT_TITULO-1));
        strcpy(movie[indice].titulo,titulo);
}

void setMovieGenero (char mensaje[MENSAJE],sMovie movie[],int indice)
{
    char genero [MAX_TEXT_GENERO];

        do{
            printf("%s: ",mensaje);
            fflush(stdin);
            gets(genero);
        }while(!VerificacionTexto(genero,1,MAX_TEXT_GENERO-1));
        strcpy(movie[indice].genero,genero);
}

void setMovieDescripcion (char mensaje[MENSAJE],sMovie movie[],int indice)
{
    char descripcion [MAX_TEXT_DESCRIPCION];

        do{
            printf("%s: ",mensaje);
            fflush(stdin);
            gets(descripcion);
        }while(!VerificacionTexto(descripcion,10,MAX_TEXT_DESCRIPCION-1));
        strcpy(movie[indice].descripcion,descripcion);
}

void setMovieLink (char mensaje[MENSAJE],sMovie movie[], int indice)
{
            printf("%s: ",mensaje);
            fflush(stdin);
            gets(movie[indice].link);
}

void setMovie (sMovie movie[], int max)
{
    int indice=BuscarVacio(movie,max);

    if(indice==-1)
    {
        printf("NO HAY MAS MEMORIA");
    }
    else
    {
        setMovieTitulo("Ingrese TITULO de la pelicula ", movie, indice);
        setMovieGenero("Ingrese GENERO de la pelicula: ", movie,indice);
        movie[indice].duracion= VerificacionNumero("Ingrese DURACION de la pelicula (en minutos)",1,5);
        setMovieDescripcion("Ingrese DESCRIPCION de la pelicula",movie,indice);
        movie[indice].puntaje=VerificacionNumero("Ingrese PUNTAJE de la pelicula",1,3);
        setMovieLink("Ingrese LINK de la imagen ",movie,indice);
        movie[indice].estado=1;
        movie[indice].id=indice+1;
    }
}

void IniciarValores (sMovie movie[], int max)
{
    int i;

    for(i=0;i<max;i++)
    {
        movie[i].estado=0;
    }
}

int BuscarVacio (sMovie movie[], int max)
{
    int i;
    int retorno=-1;

    for(i=0;i<max;i++)
    {
        if(movie[i].estado==0)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}

void getMovie (sMovie movie[], int max)
{
    int i;
    for(i=0;i<max;i++)
    {
        if (movie[i].estado==1)
        {
            printf("ID:%d - Titulo: %s\n",movie[i].id,movie[i].titulo);
        }
    }
}

void crearHtml (sMovie movie[], int max)
{
    FILE* index;
    int i;

    index = fopen("template/index.html","w");
    if (index == NULL)
    {
        printf("No se pudo crear el archivo");
        return 0;
    }
    fprintf(index,primerHtml);
    for (i=0;i<max;i++)
    {
        if(movie[i].estado==1)
        {
            fprintf(index,article);
            fprintf(index,articleLink,movie[i].link);
            fprintf(index,articleTitulo,movie[i].titulo);
            fprintf(index,articleLista,movie[i].genero,movie[i].puntaje,movie[i].duracion);
            fprintf(index,articleDescripcion,movie[i].descripcion);
            fprintf(index,articleCierre);
        }
    }
    fprintf(index,segundoHtml);
    printf("El HTML fue generado");
    fclose(index);
}

int buscarId (sMovie movie[],int max, int id)
{
    int i;
    int retorno=-1;

    for (i=0;i<max;i++)
    {
        if(movie[i].id==id && movie[i].estado==1)
        {
            retorno=i;
            break;
        }
    }

    return retorno;
}

void modificarMovie (sMovie movie[],int max)
{
    int id;
    int indice;
    int opcion;
    id=VerificacionNumero("Ingrese ID para modicar",1,2);
    indice=buscarId(movie,max,id);
    if(indice!=-1)
    {
        system("cls");
        printf("¿que desea modificar?\n");
        printf("1 - Titulo\n");
        printf("2 - Genero\n");
        printf("3 - Duracion\n");
        printf("4 - Puntaje\n");
        printf("5 - Descripcion\n");
        printf("6 - Link de imagen\n");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1: setMovieTitulo("Ingrese TITULO de la pelicula ", movie, indice);
                break;
        case 2: setMovieGenero("Ingrese GENERO de la pelicula: ", movie,indice);
                break;
        case 3: movie[indice].duracion= VerificacionNumero("Ingrese DURACION de la pelicula (en minutos)",1,5);
                break;
        case 4: movie[indice].puntaje=VerificacionNumero("Ingrese PUNTAJE de la pelicula",1,3);
                break;
        case 5: setMovieDescripcion("Ingrese DESCRIPCION de la pelicula",movie,indice);
                break;
        case 6: setMovieLink("Ingrese LINK de la imagen ",movie,indice);
                break;
        default: printf("Opcion incorrecta");
                break;
        }
        printf("Modificacion exitosa");
    }
    else
    {
        printf("ID incorrecto");
    }

}

void darDeBaja (sMovie movie[],int max)
{
    int id;
    int indice;
    id=VerificacionNumero("Ingrese ID del que desee eliminar",1,2);
    indice=buscarId(movie,max,id);
    if(indice!=-1)
    {
        movie[indice].estado=-1;
        printf("La pelicula fue eliminada");
    }
    else
    {
        printf("ID INCORRECTA\n");
    }

}
