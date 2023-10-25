#include <stdio.h>
#include <stdlib.h>

// Establecemos una estructura que represente un nodo
typedef struct Nodo {
    int valor;
    struct Nodo* siguiente;
} Nodo;

// Creamos una estructura que describa una lista enlazada
typedef struct ListaEnlazada {
    Nodo* cabeza;
} ListaEnlazada;

// Implementosmos una funcion que genere una lista enlazada sin elementos
ListaEnlazada* crearListaEnlazada() {
    ListaEnlazada* lista = (ListaEnlazada*)malloc(sizeof(ListaEnlazada));
    lista->cabeza = NULL;
    return lista;
}

// Desarrollamos una funcion que inserte un nodo al inicio de la lista
void agregarNodoAlPrincipio(ListaEnlazada* lista, int valor) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->valor = valor;
    nuevoNodo->siguiente = lista->cabeza;
    lista->cabeza = nuevoNodo;
}

// Desarrollamos una funcion que inserte un nodo al final de la lista
void agregarNodoAlFinal(ListaEnlazada* lista, int valor) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->valor = valor;
    nuevoNodo->siguiente = NULL;

    if (lista->cabeza == NULL) {
        lista->cabeza = nuevoNodo;
    } else {
        Nodo* actual = lista->cabeza;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
    }
}

// Desarrollamos una función para quitar un nodo con un valor en particular
void eliminarNodo(ListaEnlazada* lista, int valor) {
    Nodo* actual = lista->cabeza;
    Nodo* previo = NULL;

    while (actual != NULL && actual->valor != valor) {
        previo = actual;
        actual = actual->siguiente;
    }

    if (actual != NULL) {
        if (previo == NULL) {
            lista->cabeza = actual->siguiente;
        } else {
            previo->siguiente = actual->siguiente;
        }
        free(actual);
    }
}

// Desarrollamos una función para buscar un valor dentro de la lista
void buscarNodo(ListaEnlazada* lista, int valor) {
    Nodo* actual = lista->cabeza;
    while (actual != NULL) {
        if (actual->valor == valor) {
            printf("El valor %d existe en la lista.\n", valor);
            return;
        }
        actual = actual->siguiente;
    }
    printf("El valor %d no existe en la lista.\n", valor);
}

// Desarrollamos una función para imprimir la lista
void imprimirLista(ListaEnlazada* lista) {
    Nodo* actual = lista->cabeza;
    printf("Lista: ");
    while (actual != NULL) {
        printf("%d -> ", actual->valor);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

// Función para obtener un elemento en un índice determinado
void obtenerElementoEn(ListaEnlazada* lista, int indice) {
    Nodo* actual = lista->cabeza;
    int indiceActual = 0;

    while (actual != NULL && indiceActual < indice) {
        actual = actual->siguiente;
        indiceActual++;
    }

    if (actual != NULL) {
        printf("Elemento en el índice %d: %d\n", indice, actual->valor);
    } else {
        printf("No existe un elemento en el índice %d.\n", indice);
    }
}

void liberarLista(ListaEnlazada* lista) {
    Nodo* actual = lista->cabeza;
    while (actual != NULL) {
        Nodo* siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
    free(lista);
}

int main() {
    ListaEnlazada* miLista = crearListaEnlazada();

    agregarNodoAlPrincipio(miLista, 15);
    agregarNodoAlFinal(miLista, 25);
    agregarNodoAlFinal(miLista, 35);
    agregarNodoAlFinal(miLista, 45);
    agregarNodoAlFinal(miLista, 55);

    printf("Lista inicial:\n");
    imprimirLista(miLista);

    eliminarNodo(miLista, 35);
    printf("Lista después de eliminar el nodo con valor 35:\n");
    imprimirLista(miLista);

    agregarNodoAlPrincipio(miLista, 5);
    printf("Lista después de agregar el nodo 5 al inicio:\n");
    imprimirLista(miLista);

    agregarNodoAlFinal(miLista, 65);
    printf("Lista después de agregar el nodo 65 al final:\n");
    imprimirLista(miLista);

    buscarNodo(miLista, 25);
    buscarNodo(miLista, 50);

    obtenerElementoEn(miLista, 2);
    obtenerElementoEn(miLista, 5);

    // Liberar la memoria de la lista al final del programa
    liberarLista(miLista);

    return 0;
}

