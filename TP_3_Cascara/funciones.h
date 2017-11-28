#ifndef _FUNCIONES_H
#define _FUNCIONES_H

#define MAX_TEXT_TITULO 100
#define MENSAJE 100
#define MAX_TEXT_GENERO 50
#define MAX_TEXT_DESCRIPCION 1000
#define MAX_TEXT_LINK 1000
#define TEXTOMAX 500
#define MAX_MOVIE 50

#define primerHtml "<!DOCTYPE html><!-- Template by Quackit.com -->\n<html lang='en'>\n<head>\n    <meta charset='utf-8'>\n    <meta http-equiv='X-UA-Compatible' content='IE=edge'>\n    <meta name='viewport' content='width=device-width, initial-scale=1'>\n    <!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->\n    <title>Lista peliculas</title>\n    <!-- Bootstrap Core CSS -->\n    <link href='css/bootstrap.min.css' rel='stylesheet'>\n    <!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->\n    <link href='css/custom.css' rel='stylesheet'>\n    <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->\n    <!-- WARNING: Respond.js doesn't work if you view the page via file:&bsol;&bsol; -->\n    <!--[if lt IE 9]>\n        <script src='https:&bsol;&bsol;oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>\n        <script src='https:&bsol;&bsol;oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>\n    <![endif]-->\n</head>\n<body>\n    <div class='container'>\n        <div class='row'>\n"
#define segundoHtml "</div>\n        <!-- /.row -->\n    </div>\n    <!-- /.container -->\n    <!-- jQuery -->\n    <script src='js/jquery-1.11.3.min.js'></script>\n    <!-- Bootstrap Core JavaScript -->\n    <script src='js/bootstrap.min.js'></script>\n	<!-- IE10 viewport bug workaround -->\n	<script src='js/ie10-viewport-bug-workaround.js'></script>\n	<!-- Placeholder Images -->\n	<script src='js/holder.min.js'></script>\n</body>\n</html>\0"
#define article "            <article class='col-md-4 article-intro'>\n"
#define articleLink "                <a href='#'>\n                    <img class='img-responsive img-rounded' src='%s' alt=''>\n                </a>\n"
#define articleTitulo "                <h3>\n                    <a href='#'>%s</a>\n                </h3>\n"
#define articleLista "				<ul>\n					<li>Género:%s</li>\n					<li>Puntaje:%d</li>\n					<li>Duración:%d</li>\n				</ul>\n"
#define articleDescripcion "                <p>%s</p>\n"
#define articleCierre "            </article>"

typedef struct
{
    char titulo [MAX_TEXT_TITULO];
    char genero [MAX_TEXT_GENERO];
    int duracion;
    char descripcion[MAX_TEXT_DESCRIPCION];
    int puntaje;
    char link[MAX_TEXT_LINK];
    int estado;
    int id;
}sMovie;

/**
* \brief Verifica el largo del texto y que el usuario no ingrese numeros
* \param se le ingresera un mensaje, y los valores de necesarios para la validacion
* \return 0 si hay error, 1 si esta todo bien.
*
*/
int VerificacionTexto (char texto[TEXTOMAX],int desde, int hasta);
/**
* \brief Muestra menu principal
* \return retorna opcion elegida por el usuario
*
*/
int menu ();
/**
* \brief Verifica que el usuario no haya ingresado numeros
* \param se le ingresera un mensaje, y los valores de necesarios para la validacion
* \return devuelve el numero correcto.
*
*/
int VerificacionNumero (char mensaje [MENSAJE], int desde, int hasta);

//::::::::::::::::::::::::::::::::::::
/**
* \brief Ingresa titulo de la pelicula
* \param se le ingresera un mensaje, y el indice del array donde se guardara
* \return void
*
*/
void setMovieTitulo (char mensaje[MENSAJE],sMovie movie[],int indice);
/**
* \brief Ingresa genero de la pelicula
* \param se le ingresera un mensaje, y el indice del array donde se guardara
* \return void
*
*/
void setMovieGenero (char mensaje[MENSAJE],sMovie movie[],int indice);
/**
* \brief Ingresa descripcion de la pelicula
* \param se le ingresera un mensaje, y el indice del array donde se guardara
* \return void
*
*/
void setMovieDescripcion (char mensaje[MENSAJE],sMovie movie[],int indice);
/**
* \brief Ingresa link de imagen de la pelicula
* \param se le ingresera un mensaje, y el indice del array donde se guardara
* \return void
*
*/
void setMovieLink (char mensaje[MENSAJE],sMovie movie[], int indice);
/**
* \brief ingresa una nueva pelicula
* \param se le pide al usuario los datos necesarios para crear una nueva pelicula
* \return void
*
*/
void setMovie (sMovie movie[], int max);
/**
* \brief inicia el estado de las peliculas en 0
* \return void
*
*/
void IniciarValores (sMovie movie[], int max);
/**
* \brief busca entre todos los array de pelicula el estado en 0
* \return retorna el indice donde se encuentra un array sin cargar, o -1 si no hay ninguno
*
*/
int BuscarVacio (sMovie movie[], int max);
/**
* \brief muestra por pantalla ID y TITULO de las peliculas
* \return void
*
*/
void getMovie (sMovie movie[], int max);
/**
* \brief crea archivo HTML
* \param se le ingresa el codigo necesario para generar un nuevo html
* \return void
*
*/
void crearHtml (sMovie movie[], int max);
/**
* \brief buscar id
* \param le llega la id ingresa por el usuario, buscara por todo el array la misma id
* \return -1 si la id es incorrecta, o indice donde esta la id
*
*/
int buscarId (sMovie movie[],int max, int id);
/**
* \brief modifica una pelicula
* \param le da unas opciones de que quiere modificar.
* \return void
*
*/
void modificarMovie (sMovie movie[],int max);
/**
* \brief Da de baja una pelicula
* \param pone su estado en -1
* \return void
*
*/
void darDeBaja (sMovie movie[],int max);

#endif // _FUNCIONES_H
