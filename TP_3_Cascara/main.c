#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    sMovie movie[MAX_MOVIE];

    IniciarValores(movie,MAX_MOVIE);
    while(seguir=='s')
    {
        system("cls");
        switch(menu())
        {
        case 1:
            setMovie(movie,MAX_MOVIE);
            system("pause");
            break;
        case 2:
            system("cls");
            getMovie(movie,MAX_MOVIE);
            darDeBaja(movie,MAX_MOVIE);
            system("pause");
            break;
        case 3:
            system("cls");
            getMovie(movie,MAX_MOVIE);
            modificarMovie(movie,MAX_MOVIE);
            system("pause");
            break;
        case 4:
            crearHtml(movie,MAX_MOVIE);
            system("pause");
            break;
        case 5:
            seguir = 'n';
            break;
        default:
            printf("Opcion incorrecta");
            break;
        }
    }
    return 0;
}



