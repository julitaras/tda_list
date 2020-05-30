# TDA Lista

## Introduccion

Se entrega el TDA de `lista` junto con sus respectivas pruebas.

Elijo implementar la lista teniendo un puntero que apunta al `inicio` y otro puntero que apunta al `final`. Y la misma, tambien se implementa utilizando `nodos simplemnete enlazados`.

Siguiendo este modelo:

````
| *dato* | → | *dato* | → | *dato* | → | *dato* |
    ↑                                      ↑
  Inicio                                  Fin
````

Dentro de este TDA se incluye la implementacion de algunas funciones de los TDA `pila` y `cola`.

---
## ¿Cómo compilar ?

Compilamos el TDA y las respectivas pruebas haciendo:

````c
gcc lista.c lista_pruebas.c -o lista -g -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -O0
````

Ejecutamos el mismo haciendo:

`````c
./lista
`````

----
## Explicacion de conceptos
1. ¿Qué es lo que entendés por una lista? ¿Cuáles son las diferencias entre ser simple o doblemente enlazada?

    Entiendo que una lista es un TDA, un tipo de dato abstracto.

    La diferencia entre ser simple o doble es que la simple se enlaza a traves de un puntero. Es decir que por ejemplo sea el caso de la implementacion con nodos, un nodo conoce a su siguiente por lo que contiene un puntero que apunta al siguiente nodo, y asi sucesivamente hasta que el ultimo apuntaria a NULL, lo que quier decir que ese es el ultimo elemento.

    Que este doblemente enlazada es que los nodos de la lista se conocen entre si. Es decir, un nodo conoce a su siguiente y a su anterior.

2. ¿Cuáles son las características fundamentales de las Pilas? ¿Y de las Colas?

    La `Pila` es otro tipo de dato abstracto que tiene un metodo de almacenamiento llamado **LIFO** (Last In, First Out). Es decir, que el ultimo elemento que iingresa a la pila es el primero que vamos a poder sacar.

    La `Cola` es otro tipo de dato abstracto que tiene un metodo de almacenamiento llamado **FIFO** (First In, First Out). Es decir, que el primer elemento que guardamos en la cola es el primer elemento que vamos a poder sacar. 

3. ¿Qué es un iterador? ¿Cuál es su función?

    Es un tipo de dato abstracto que como dice su nombre, se encarga de iterar.

4. ¿En qué se diferencia un iterador interno de uno externo?

    Ambos se encargan de iterar, solo que lo hacen de forma distinta. Siendo que el iterador interno delega la iteracion a la lista, mientras que el externo se encarga el.

    El iterador interno con cada elemento de la lista, llama a una funcion.

---

## Enunciado

Se pide implementar una Lista simplemente enlazada. Para ello se brindan las firmas de las funciones públicas a imple-
mentar y se deja a criterio del alumno la creación de las funciones privadas del TDA para el correcto funcionamiento de
la Lista cumpliendo con las buenas prácticas de programación.


Dentro de este TDA, se pide incluir también la implementación de las funciones básicas de los TDAs Pila y Cola, cumpliendo
asi que este satisfaga el comportamiento de las tres estructuras.


Adicionalmente se pide la creación de un iterador interno y uno externo para la lista.