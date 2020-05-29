#include <stdio.h>
#include "testing.c"
#include "lista.h"

/* ******************************************************************
 *                        PRUEBAS UNITARIAS
 * *****************************************************************/

/* Pruebas para un vector de tamaño 0. */
void pruebas_lista_crear() {
    printf("INICIO DE PRUEBAS LISTA CREAR\n");

    /* Declaro las variables a utilizar*/
    lista_t* lista = lista_crear();

    /* Inicio de pruebas */
    prueba("La lista se creo con exito", lista != NULL);
    prueba("La lista esta vacia", lista_vacia(lista));
    prueba("La lista tiene 0 elementos", lista_elementos(lista) == 0);
    lista_destruir(lista);
}

void pruebas_lista_insertar(){
    printf("INICIO DE PRUEBAS LISTA INSERTAR\n");

    /* Declaro las variables a utilizar*/
    lista_t* lista = lista_crear();
    int a = 1, b = 2, c = 3, d = 4;

    /* Inicio de pruebas */
    prueba("Se inserta un elemento a la lista", lista_insertar(lista, &a) == 0);
    prueba("La lista tiene un elemento mas", lista_elementos(lista) == 1);
    prueba("La lista no esta vacia", !lista_vacia(lista));

    prueba("Se inserta un elemento a la lista", lista_insertar(lista, &b) == 0);
    prueba("La lista tiene un elemento mas", lista_elementos(lista) == 2);
    prueba("La lista no esta vacia", !lista_vacia(lista));

    prueba("Se inserta un elemento a la lista", lista_insertar(lista, &c) == 0);
    prueba("La lista tiene un elemento mas", lista_elementos(lista) == 3);
    prueba("La lista no esta vacia", !lista_vacia(lista));

    prueba("Se inserta un elemento a la lista", lista_insertar(lista, &d) == 0);
    prueba("La lista tiene un elemento mas", lista_elementos(lista) == 4);
    prueba("La lista no esta vacia", !lista_vacia(lista));
    lista_destruir(lista);
}

void pruebas_lista_insertar_en_posisicion(){
    printf("INICIO DE PRUEBAS LISTA INSERTAR EN POSICION\n");

    /* Declaro las variables a utilizar*/
    lista_t* lista = lista_crear();
    int a = 1, b = 2, c = 3;

    /* Inicio de pruebas */
    prueba("Se inserta un elemento a la lista", lista_insertar_en_posicion(lista, &a, 0) == 0);
    prueba("Elemento en posicion 0", lista_elemento_en_posicion(lista, 0) == &a);
    prueba("Elemento en posicion 0", lista_primero(lista) == &a);
    prueba("La lista tiene un elemento mas", lista_elementos(lista) == 1);
    prueba("La lista no esta vacia", !lista_vacia(lista));

    prueba("Se inserta un elemento a la lista", lista_insertar_en_posicion(lista, &b, 1) == 0);
    prueba("Elemento en posicion 1", lista_elemento_en_posicion(lista, 1) == &b);
    prueba("La lista tiene un elemento mas", lista_elementos(lista) == 2);
    prueba("La lista no esta vacia", !lista_vacia(lista));

    prueba("Se inserta un elemento a la lista", lista_insertar_en_posicion(lista, &c, 2) == 0);
    prueba("Elemento en posicion 2", lista_elemento_en_posicion(lista, 2) == &c);
    prueba("La lista tiene un elemento mas", lista_elementos(lista) == 3);
    prueba("La lista no esta vacia", !lista_vacia(lista));
    lista_destruir(lista);
}

void pruebas_lista_vacia(){
    printf("INICIO DE PRUEBAS LISTA VACIA\n");

    /* Declaro las variables a utilizar*/
    lista_t* lista = lista_crear();

    /* Inicio de pruebas */
    prueba("La lista esta vacia", lista_vacia(lista));
    prueba("Envio una lista NULL", lista_vacia(NULL));
    lista_destruir(lista);
}

void pruebas_lista_elementos(){
    printf("INICIO DE PRUEBAS LISTA ELEMENTOS\n");

    /* Declaro las variables a utilizar*/
    lista_t* lista = lista_crear();

    /* Inicio de pruebas */
    prueba("La lista esta vacia", lista_elementos(lista) == 0);
    prueba("La lista es NULL", lista_elementos(NULL) == 0);
    lista_destruir(lista);
}

void pruebas_lista_apilar(){
    printf("INICIO DE PRUEBAS LISTA APILAR\n");

    /* Declaro las variables a utilizar*/
    lista_t* lista = lista_crear();
    int a = 1, b = 2, c = 3, d = 4;

    /* Inicio de pruebas */
    prueba("Se inserta un elemento a la lista", lista_apilar(lista, &a) == 0);
    prueba("La lista tiene un elemento mas", lista_elementos(lista) == 1);
    prueba("La lista no esta vacia", !lista_vacia(lista));

    prueba("Se inserta un elemento a la lista", lista_apilar(lista, &b) == 0);
    prueba("La lista tiene un elemento mas", lista_elementos(lista) == 2);
    prueba("La lista no esta vacia", !lista_vacia(lista));

    prueba("Se inserta un elemento a la lista", lista_apilar(lista, &c) == 0);
    prueba("La lista tiene un elemento mas", lista_elementos(lista) == 3);
    prueba("La lista no esta vacia", !lista_vacia(lista));

    prueba("Se inserta un elemento a la lista", lista_apilar(lista, &d) == 0);
    prueba("La lista tiene un elemento mas", lista_elementos(lista) == 4);
    prueba("La lista no esta vacia", !lista_vacia(lista));
    lista_destruir(lista);
}

void pruebas_lista_desapilar(){
    printf("INICIO DE PRUEBAS LISTA DESAPILAR\n");

    /* Declaro las variables a utilizar*/
    lista_t* lista = lista_crear();
    int a = 1, b = 2, c = 3;

    /* Inicio de pruebas */
    prueba("Se inserta un elemento a la lista", lista_apilar(lista, &a) == 0);
    prueba("La lista tiene un elemento mas", lista_elementos(lista) == 1);
    prueba("La lista no esta vacia", !lista_vacia(lista));

    prueba("Se apila un elemento a la lista", lista_apilar(lista, &b) == 0);
    prueba("La lista tiene un elemento mas", lista_elementos(lista) == 2);
    prueba("La lista no esta vacia", !lista_vacia(lista));

    prueba("Se apila un elemento a la lista", lista_apilar(lista, &c) == 0);
    prueba("La lista tiene un elemento mas", lista_elementos(lista) == 3);
    prueba("La lista no esta vacia", !lista_vacia(lista));

    prueba("Se desapila un elemento a la lista", lista_desapilar(lista) == 0);
    prueba("La lista tiene un elemento menos", lista_elementos(lista) == 2);
    prueba("La lista no esta vacia", !lista_vacia(lista));

    prueba("Se desapila un elemento a la lista", lista_desapilar(lista) == 0);
    prueba("La lista tiene un elemento menos", lista_elementos(lista) == 1);
    prueba("La lista no esta vacia", !lista_vacia(lista));

    prueba("Se desapila un elemento a la lista", lista_desapilar(lista) == 0);
    prueba("La lista esta vacia", lista_vacia(lista));
    lista_destruir(lista);
}

void pruebas_lista_borrar(){
    printf("INICIO DE PRUEBAS LISTA BORRAR\n");

    /* Declaro las variables a utilizar*/
    lista_t* lista = lista_crear();
    int a = 1, b = 2, c = 3;

    /* Inicio de pruebas */
    prueba("Se inserta un elemento a la lista", lista_insertar(lista, &a) == 0);
    prueba("La lista tiene un elemento mas", lista_elementos(lista) == 1);
    prueba("La lista no esta vacia", !lista_vacia(lista));

    prueba("Se inserta un elemento a la lista", lista_insertar(lista, &b) == 0);
    prueba("La lista tiene un elemento mas", lista_elementos(lista) == 2);
    prueba("La lista no esta vacia", !lista_vacia(lista));

    prueba("Se inserta un elemento a la lista", lista_insertar(lista, &c) == 0);
    prueba("La lista tiene un elemento mas", lista_elementos(lista) == 3);
    prueba("La lista no esta vacia", !lista_vacia(lista));

    prueba("Se borra un elemento a la lista", lista_borrar(lista) == 0);
    prueba("La lista tiene un elemento menos", lista_elementos(lista) == 2);
    prueba("La lista no esta vacia", !lista_vacia(lista));

    prueba("Se borra un elemento a la lista", lista_borrar(lista) == 0);
    prueba("La lista tiene un elemento menos", lista_elementos(lista) == 1);
    prueba("La lista no esta vacia", !lista_vacia(lista));

    prueba("Se borra un elemento a la lista", lista_borrar(lista) == 0);
    prueba("La lista esta vacia", lista_vacia(lista));
    lista_destruir(lista);
}

void pruebas_lista_elemento_en_posicion(){
    printf("INICIO DE PRUEBAS LISTA ELEMENTO EN POSICION\n");

    /* Declaro las variables a utilizar*/
    lista_t* lista = lista_crear();
    int a = 1, b = 2, c = 3;

    /* Inicio de pruebas */
    prueba("Se inserta un elemento a la lista", lista_insertar(lista, &a) == 0);
    prueba("La lista tiene un elemento mas", lista_elementos(lista) == 1);
    prueba("Elemento en posicion 0", lista_elemento_en_posicion(lista, 0) == &a);
    prueba("La lista no esta vacia", !lista_vacia(lista));

    prueba("Se inserta un elemento a la lista", lista_insertar(lista, &b) == 0);
    prueba("La lista tiene un elemento mas", lista_elementos(lista) == 2);
    prueba("Elemento en posicion 1", lista_elemento_en_posicion(lista, 1) == &b);
    prueba("La lista no esta vacia", !lista_vacia(lista));

    prueba("Se inserta un elemento a la lista", lista_insertar(lista, &c) == 0);
    prueba("La lista tiene un elemento mas", lista_elementos(lista) == 3);
    prueba("Elemento en posicion 2", lista_elemento_en_posicion(lista, 2) == &c);
    prueba("La lista no esta vacia", !lista_vacia(lista));

    prueba("Se borra un elemento a la lista", lista_borrar(lista) == 0);
    prueba("La lista tiene un elemento menos", lista_elementos(lista) == 2);
    prueba("No hay elemento en posicion 2", lista_elemento_en_posicion(lista, 2) == NULL);
    prueba("Elemento en posicion 1", lista_elemento_en_posicion(lista, 1) == &b);
    prueba("La lista no esta vacia", !lista_vacia(lista));
    lista_destruir(lista);
}

void pruebas_lista_borrar_de_posicion(){
    printf("INICIO DE PRUEBAS LISTA BORRAR ELEMENTO EN POSICION\n");

    /* Declaro las variables a utilizar*/
    lista_t* lista = lista_crear();
    int a = 1, b = 2, c = 3, d = 4;

    /* Inicio de pruebas */
    prueba("Se inserta un elemento a la lista", lista_insertar(lista, &a) == 0);
    prueba("La lista tiene un elemento mas", lista_elementos(lista) == 1);
    prueba("Elemento en posicion 0", lista_elemento_en_posicion(lista, 0) == &a);
    prueba("La lista no esta vacia", !lista_vacia(lista));

    prueba("Se inserta un elemento a la lista", lista_insertar(lista, &b) == 0);
    prueba("La lista tiene un elemento mas", lista_elementos(lista) == 2);
    prueba("Elemento en posicion 1", lista_elemento_en_posicion(lista, 1) == &b);
    prueba("La lista no esta vacia", !lista_vacia(lista));

    prueba("Se inserta un elemento a la lista", lista_insertar(lista, &c) == 0);
    prueba("La lista tiene un elemento mas", lista_elementos(lista) == 3);
    prueba("Elemento en posicion 2", lista_elemento_en_posicion(lista, 2) == &c);
    prueba("La lista no esta vacia", !lista_vacia(lista));

    prueba("Se inserta un elemento a la lista", lista_insertar(lista, &d) == 0);
    prueba("La lista tiene un elemento mas", lista_elementos(lista) == 4);
    prueba("Elemento en posicion 3", lista_elemento_en_posicion(lista, 3) == &d);
    prueba("La lista no esta vacia", !lista_vacia(lista));

    prueba("Se borra un elemento en la posicion 0 de la lista", lista_borrar_de_posicion(lista, 0) == 0);
    prueba("Elemento en posicion 0", lista_elemento_en_posicion(lista, 0) == &b);
    prueba("La lista no esta vacia", !lista_vacia(lista));

    prueba("Se borra un elemento en la posicion 1 de la lista", lista_borrar_de_posicion(lista, 1) == 0);
    prueba("Elemento en posicion 1", lista_elemento_en_posicion(lista, 1) == &d);
    prueba("La lista no esta vacia", !lista_vacia(lista));

    prueba("Se borra un elemento en la posicion 1 de la lista", lista_borrar_de_posicion(lista, 1) == 0);
    prueba("La lista le queda solo un elemento", lista_elementos(lista) == 1);
    prueba("Elemento en posicion 0", lista_elemento_en_posicion(lista, 0) == &b);
    prueba("La lista no esta vacia", !lista_vacia(lista));

    prueba("Se borra un elemento en la posicion 1 de la lista", lista_borrar_de_posicion(lista, 0) == 0);
    prueba("La lista quedo vacia", lista_vacia(lista));
    lista_destruir(lista);
}


void pruebas_lista_encolar(){
    printf("INICIO DE PRUEBAS LISTA ENCOLAR\n");

    /* Declaro las variables a utilizar*/
    lista_t* lista = lista_crear();
    int a = 1, b = 2, c = 3;

    /* Inicio de pruebas */
    prueba("Se encola un elemento a la lista", lista_encolar(lista, &a) == 0);
    prueba("La lista tiene un elemento mas", lista_elementos(lista) == 1);
    prueba("La lista no esta vacia", !lista_vacia(lista));

    prueba("Se encola un elemento a la lista", lista_encolar(lista, &b) == 0);
    prueba("La lista tiene un elemento mas", lista_elementos(lista) == 2);
    prueba("La lista no esta vacia", !lista_vacia(lista));

    prueba("Se encola un elemento a la lista", lista_encolar(lista, &c) == 0);
    prueba("La lista tiene un elemento mas", lista_elementos(lista) == 3);
    prueba("La lista no esta vacia", !lista_vacia(lista));


    prueba("El ultio elemento que se inserto es el primero", lista_elemento_en_posicion(lista, 0) == &c);
    prueba("El elemento que se inserto en el medio esta en el medio", lista_elemento_en_posicion(lista, 1) == &b);
    prueba("El primer elemento que se inserto es el ultimo", lista_elemento_en_posicion(lista, 2) == &a);
  
    lista_destruir(lista);
}

void pruebas_lista_desencolar(){
    printf("INICIO DE PRUEBAS LISTA DESENCOLAR\n");

    /* Declaro las variables a utilizar*/
    lista_t* lista = lista_crear();
    int a = 1, b = 2, c = 3, d = 4;

    /* Inicio de pruebas */
    prueba("Se encola un elemento a la lista", lista_encolar(lista, &a) == 0);
    prueba("La lista tiene un elemento mas", lista_elementos(lista) == 1);
    prueba("Elemento en posicion 0", lista_elemento_en_posicion(lista, 0) == &a);
    prueba("La lista no esta vacia", !lista_vacia(lista));

    prueba("Se encola un elemento a la lista", lista_encolar(lista, &b) == 0);
    prueba("La lista tiene un elemento mas", lista_elementos(lista) == 2);
    prueba("Elemento en posicion", lista_elemento_en_posicion(lista, 1) == &b);
    prueba("La lista no esta vacia", !lista_vacia(lista));

    prueba("Se encola un elemento a la lista", lista_encolar(lista, &c) == 0);
    prueba("La lista tiene un elemento mas", lista_elementos(lista) == 3);
    prueba("Elemento en posicion", lista_elemento_en_posicion(lista, 2) == &c);
    prueba("La lista no esta vacia", !lista_vacia(lista));

    prueba("Se encola un elemento a la lista", lista_encolar(lista, &d) == 0);
    prueba("La lista tiene un elemento mas", lista_elementos(lista) == 4);
    prueba("Elemento en posicion", lista_elemento_en_posicion(lista, 3) == &d);
    prueba("La lista no esta vacia", !lista_vacia(lista));

    prueba("Se desenencola un elemento a la lista", lista_desencolar(lista) == 0);
    prueba("La lista tiene un elemento mas", lista_elementos(lista) == 3);
    lista_destruir(lista);
}

/*Revisar que prubas faltan*/

int main(){
   pruebas_lista_crear();
   pruebas_lista_insertar();
   pruebas_lista_insertar_en_posisicion();
   pruebas_lista_vacia();
   pruebas_lista_elementos();
   pruebas_lista_apilar();
   pruebas_lista_desapilar();
   pruebas_lista_borrar();
   pruebas_lista_elemento_en_posicion();
   pruebas_lista_borrar_de_posicion();
   pruebas_lista_encolar();
//    pruebas_lista_desencolar();
   return 0;
}