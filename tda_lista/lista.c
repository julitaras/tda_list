#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

/*Defino la estructura de nodo*/
typedef struct nodo {
    void * dato;
    struct nodo* siguiente;
} nodo_t;

/*Defino la estructura de lista*/
typedef struct lista{
    nodo_t * inicio;
    nodo_t * fin;
    size_t cantidad;
} lista_t;

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

    if (lista_vacia(lista)){
        return NULL;
    }

   return  lista->fin->dato;
}

int lista_apilar(lista_t* lista, void* elemento){
    //LIFO Last In First Out
    //Se apila siempre al final por lo que seria como insertar normal ya que siempre insertamos al final
}

