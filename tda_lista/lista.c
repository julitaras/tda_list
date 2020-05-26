#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

/*Defino la estructura de nodo*/
typedef struct nodo {
    void * dato;
    struct nodo* siguiente;
} nodo_t;

/*Defino la estructura de lista*/
struct lista{
    nodo_t * inicio;
    nodo_t * fin;
    size_t cantidad;
};

/*Crea la estructura de nodo_t, reservando memoria para la misma*/
nodo_t * nodo_crear(){

    nodo_t* nodo = calloc(1, sizeof(nodo_t));
    
    return nodo;
}

lista_t* lista_crear(){

    lista_t * lista =  malloc(sizeof(lista_t));

    if (!lista){
        return NULL;
    }

    lista->inicio = NULL;
    lista->fin = NULL;
    lista->cantidad = 0;

    return lista;
}

int lista_insertar(lista_t* lista, void* elemento){
    
    if (!lista){
        return -1;
    }

    nodo_t * nodo_nuevo = nodo_crear();

    if (!nodo_nuevo){
        return -1;
    }

    nodo_nuevo->dato = elemento;
    
    if (lista_vacia(lista)){
        lista->inicio = nodo_nuevo;
        lista->fin = nodo_nuevo;
    }

    lista->fin->siguiente = nodo_nuevo;
    lista->fin = nodo_nuevo;

    nodo_nuevo->siguiente = NULL;
    lista->cantidad++;

    return 0;
}

int lista_insertar_en_posicion(lista_t* lista, void* elemento, size_t posicion){

    if(!lista){
        return -1;
    }

    if(posicion > lista_elementos(lista)){
        return lista_insertar(lista, elemento);
    }

    nodo_t * nodo_nuevo = nodo_crear();

    if (!nodo_nuevo){
        return -1;
    }

    nodo_nuevo->dato = elemento;

    nodo_t **siguiente_posicion_nodo_nuevo = &lista->inicio;

    for (int i = 0; i < posicion && *siguiente_posicion_nodo_nuevo != NULL; i++) {
        siguiente_posicion_nodo_nuevo = &(*siguiente_posicion_nodo_nuevo)->siguiente;
    }

    nodo_nuevo->siguiente = *siguiente_posicion_nodo_nuevo;

    *siguiente_posicion_nodo_nuevo = nodo_nuevo;

    lista->cantidad++;

    return 0;
}

int lista_borrar(lista_t* lista){

    if (!lista || lista_vacia(lista)){
        return -1;
    }

    nodo_t * nodo_eliminar = lista->fin;

    nodo_t **nuevo_fin = &lista->inicio;

    for (int i = 1; i < lista->cantidad - 1 && *nuevo_fin != NULL; i++) {
        nuevo_fin = &(*nuevo_fin)->siguiente;
    }    

    lista->fin = *nuevo_fin;
    lista->cantidad --;

    free(nodo_eliminar);

    return 0;
}

int lista_borrar_de_posicion(lista_t* lista, size_t posicion){

    if (!lista || lista_vacia(lista)){
        return -1;
    }

    if(posicion > lista->cantidad){
        return lista_borrar(lista);
    }

    nodo_t * nodo_eliminar = lista->fin;

    nodo_t **nuevo_fin = &lista->inicio;

    for (int i = 1; i < posicion && *nuevo_fin != NULL; i++) {
        nuevo_fin = &(*nuevo_fin)->siguiente;
    }    


    //Que pasa en el caso de que la poscion sea 0 ? Debo cambiar el inicio. Chequear esta func
    lista->fin = *nuevo_fin;
    lista->cantidad --;

    free(nodo_eliminar);

    return 0;
}

void* lista_elemento_en_posicion(lista_t* lista, size_t posicion){

    if (!lista || lista_vacia(lista) || posicion > lista->cantidad){
        return NULL;
    }

    nodo_t * nodo_buscado = lista->inicio;

    for (int i = 0; i < posicion && nodo_buscado != NULL; i++) {
        nodo_buscado = nodo_buscado->siguiente;
    }

    return nodo_buscado->dato;
}

bool lista_vacia(lista_t* lista){
    if (lista_elementos(lista) == 0){
        return true;
    }

    return false;
}

size_t lista_elementos(lista_t* lista){

    if(lista == NULL){
        return 0;
    }

    return lista->cantidad;
}

void* lista_ultimo(lista_t* lista){

    if (!lista || lista_vacia(lista)){
        return NULL;
    }

   return  lista->fin->dato;
}

int lista_apilar(lista_t* lista, void* elemento){
    return lista_insertar(lista, elemento);
}

int lista_desapilar(lista_t* lista){
    return lista_borrar(lista);
}

void* lista_tope(lista_t* lista){
    return lista_ultimo(lista);
}

void* lista_primero(lista_t* lista){

    if (!lista || lista_vacia(lista)){
        return NULL;
    }

    return lista->inicio->dato;
}

int lista_encolar(lista_t* lista, void* elemento){

    if (!lista || lista_vacia(lista)){
        return -1;
    }
}

int lista_desencolar(lista_t* lista){

    if (!lista || lista_vacia(lista)){
        return -1;
    }
}

/*Revisar func que faltan, + iteradores*/