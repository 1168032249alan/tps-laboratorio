#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[250];
    int puntaje;
    char linkImagen[250];
}EMovie;

#endif // FUNCIONES_H_INCLUDED

/** \brief Asigna 0 y/o " " a los campos de la estructura EMovie.
 *
 * \param pMovie EMovie* El puntero que apunta a la direccion de memoria de la variable movie perteneciente a la estructura EMovie.
 * \param int Cantidad de peliculas que se pueden cargar
 * \return void
 *
 */
void inicializarPeliculas(EMovie *pMovie, int);

/** \brief Abre archivo que contiene peliculas y si no existe lo crea
 *
 * \param pMovie EMovie* El puntero que apunta a la direccion de memoria de la variable movie perteneciente a la estructura EMovie.
 * \param int Cantidad de peliculas que se pueden cargar
 * \return int retorna 1 o -1 de acuerdo a si pudo agregar la pelicula o no
 *
 */
int cargarArchivo(EMovie *pMovie,int);

/**
 *  Agrega una pelicula al archivo binario
 *  \param pMovie EMovie* El puntero que apunta a la direccion de memoria de la variable movie perteneciente a la estructura EMovie.
 *  \param int Cantidad de peliculas que se pueden cargar
 *  \return retorna 1 o -1 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie *pMovie, int);

/**
 *  Borra una pelicula del archivo binario
 *  \param pMovie EMovie* El puntero que apunta a la direccion de memoria de la variable movie perteneciente a la estructura EMovie.
 *  \param int Cantidad de peliculas que se pueden cargar
 *  \return retorna 1 o -1 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie *pMovie,int);

/** \brief Modificar una pelicula del archivo binario.
 *
 * \param pMovie EMovie* El puntero que apunta a la direccion de memoria de la variable movie perteneciente a la estructura EMovie.
 * \param int Cantidad de peliculas que se pueden cargar
 * \return int retorna 1 o -1 de acuerdo a si pudo eliminar la pelicula o no
 *
 */
int modificarPelicula(EMovie *pMovie, int);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 * \param pMovie EMovie* El puntero que apunta a la direccion de memoria de la variable movie perteneciente a la estructura EMovie.
 * \param int Cantidad de peliculas que se pueden cargar
 * \param nombre el nombre para el archivo.
 */
void generarHTML(EMovie *pMovie, int, char nombre[]);


/** \brief Busca la ultima pelicula cargada y su indice para devolver el siguiente (el proximo que esta vacio)
 *
 * \param pMovie EMovie* El puntero que apunta a la direccion de memoria de la variable movie perteneciente a la estructura EMovie.
 * \param length int Cantidad de peliculas que se pueden cargar
 * \return int retorna el indice siguiente al ultimo cargado
 *
 */
int buscarVacio(EMovie *pMovie, int);

/** \brief Muestra las peliculas cargadas
 *
 * \param pMovie EMovie* El puntero que apunta a la direccion de memoria de la variable movie perteneciente a la estructura EMovie.
 * \param length int Cantidad de peliculas que se pueden cargar
 * \return int retorna la cantidad de peliculas que se mostraron
 *
 */
int mostrarPeliculas(EMovie *pMovie,int length);

/** \brief Guarda los cambios hechos en el archivo binario
 *
 * \param pMovie EMovie* El puntero que apunta a la direccion de memoria de la variable movie perteneciente a la estructura EMovie.
 * \param length int Cantidad de peliculas que se pueden cargar
 * \return int retorna -1 o 1 de acuerdo a si pudo agregar la pelicula o no
 *
 */
int guardarArchivo(EMovie *pMovie,int length);

/** \brief Me dice si no hay ninguna pelicula cargada.
 *
 * \param pMovie EMovie* El puntero que apunta a la direccion de memoria de la variable movie perteneciente a la estructura EMovie.
 * \param length int Cantidad de peliculas que se pueden cargar
 * \return int retorna -1 si no hay peliculas cargadas y 1 si hay al menos una.
 *
 */
int estaVacio(EMovie *pMovie,int length);
