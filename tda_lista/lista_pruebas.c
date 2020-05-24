#include <stdio.h>
#include "testing.c"
#include "lista.c"

/* ******************************************************************
 *                        PRUEBAS UNITARIAS
 * *****************************************************************/

/* Pruebas para un vector de tamaño 0. */
void pruebas_lista_crear() {
    printf("INICIO DE PRUEBAS LISTA CREAR\n");

    /* Declaro las variables a utilizar*/
    lista_t* lista = lista_crear();

    /* Inicio de pruebas */
    print_test("La lista se creo con exito", lista != NULL);
    print_test("La lista esta vacia", lista_vacia(lista));
    print_test("La lista tiene 0 elementos", lista_elementos(lista) == 0);
}

void pruebas_lista_insertar(){
    printf("INICIO DE PRUEBAS LISTA INSERTAR\n");

    /* Declaro las variables a utilizar*/
    lista_t* lista = lista_crear();
    int a = 1, b = 2, c = 3, d = 4;

    /* Inicio de pruebas */
    print_test("Se inserta un elemento a la lista", lista_insertar(lista, &a) == 0);
    print_test("La lista tiene un elemento mas", lista_elementos(lista) == 1);
    print_test("La lista no esta vacia", !lista_vacia(lista));

    print_test("Se inserta un elemento a la lista", lista_insertar(lista, &b) == 0);
    print_test("La lista tiene un elemento mas", lista_elementos(lista) == 2);
    print_test("La lista no esta vacia", !lista_vacia(lista));

    print_test("Se inserta un elemento a la lista", lista_insertar(lista, &c) == 0);
    print_test("La lista tiene un elemento mas", lista_elementos(lista) == 3);
    print_test("La lista no esta vacia", !lista_vacia(lista));

    print_test("Se inserta un elemento a la lista", lista_insertar(lista, &d) == 0);
    print_test("La lista tiene un elemento mas", lista_elementos(lista) == 4);
    print_test("La lista no esta vacia", !lista_vacia(lista));
}

void pruebas_lista_insertar_en_posisicion(){
    printf("INICIO DE PRUEBAS LISTA INSERTAR EN POSICION\n");

    /* Declaro las variables a utilizar*/
    lista_t* lista = lista_crear();
    int a = 1, b = 2, c = 3;

    /* Inicio de pruebas */
    print_test("Se inserta un elemento a la lista", lista_insertar_en_posicion(lista, &a, 0) == 0);
    print_test("La lista tiene un elemento mas", lista_elementos(lista) == 1);
    print_test("La lista no esta vacia", !lista_vacia(lista));

    print_test("Se inserta un elemento a la lista", lista_insertar_en_posicion(lista, &b, 1) == 0);
    print_test("La lista tiene un elemento mas", lista_elementos(lista) == 2);
    print_test("La lista no esta vacia", !lista_vacia(lista));

    print_test("Se inserta un elemento a la lista", lista_insertar_en_posicion(lista, &c, 1) == 0);
    print_test("La lista tiene un elemento mas", lista_elementos(lista) == 3);
    print_test("La lista no esta vacia", !lista_vacia(lista));
}

void pruebas_lista_vacia(){
    printf("INICIO DE PRUEBAS LISTA VACIA\n");

    /* Declaro las variables a utilizar*/
    lista_t* lista = lista_crear();

    /* Inicio de pruebas */
    print_test("La lista esta vacia", lista_vacia(lista));
    print_test("Envio una lista NULL", lista_vacia(NULL));

}

void pruebas_lista_elementos(){
    printf("INICIO DE PRUEBAS LISTA ELEMENTOS\n");

    /* Declaro las variables a utilizar*/
    lista_t* lista = lista_crear();

    /* Inicio de pruebas */
    print_test("La lista esta vacia", lista_elementos(lista) == 0);
    print_test("La lista es NULL", lista_elementos(NULL) == 0);

}

void pruebas_lista_apilar(){
    printf("INICIO DE PRUEBAS LISTA APILAR\n");

    /* Declaro las variables a utilizar*/
    lista_t* lista = lista_crear();
    int a = 1, b = 2, c = 3, d = 4;

    /* Inicio de pruebas */
    print_test("Se inserta un elemento a la lista", lista_apilar(lista, &a) == 0);
    print_test("La lista tiene un elemento mas", lista_elementos(lista) == 1);
    print_test("La lista no esta vacia", !lista_vacia(lista));

    print_test("Se inserta un elemento a la lista", lista_apilar(lista, &b) == 0);
    print_test("La lista tiene un elemento mas", lista_elementos(lista) == 2);
    print_test("La lista no esta vacia", !lista_vacia(lista));

    print_test("Se inserta un elemento a la lista", lista_apilar(lista, &c) == 0);
    print_test("La lista tiene un elemento mas", lista_elementos(lista) == 3);
    print_test("La lista no esta vacia", !lista_vacia(lista));

    print_test("Se inserta un elemento a la lista", lista_apilar(lista, &d) == 0);
    print_test("La lista tiene un elemento mas", lista_elementos(lista) == 4);
    print_test("La lista no esta vacia", !lista_vacia(lista));
}

int main(){
   pruebas_lista_crear();
   pruebas_lista_insertar();
   pruebas_lista_insertar_en_posisicion();
   pruebas_lista_vacia();
   pruebas_lista_elementos();
   pruebas_lista_apilar();
   return 0;
}