#include "nodoString.h"

typedef struct nodoString {
    char* dato;
    struct nodoString* siguiente;
} NodoString;
typedef NodoString* ptrNodoString;

ptrNodoString newNodoString(const char* dato) {
    ptrNodoString nuevoNodo = malloc(sizeof(*nuevoNodo));
    if(nuevoNodo == NULL) return NULL;

    nuevoNodo->dato = malloc(strlen(dato)+1);
    if(nuevoNodo->dato == NULL) {
        free(nuevoNodo);
        return NULL;
    }
    strncpy(nuevoNodo->dato, dato, strlen(dato)+1);

    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

int killNodoString(ptrNodoString ptr) {
    free(ptr->dato);
    ptr->dato = NULL;
    free(ptr);
    ptr = NULL;
    return 1;
}

int setSiguienteNodoString(ptrNodoString ptr, ptrNodoString siguiente) {
    if(ptr == NULL) return 0;
    ptr->siguiente = siguiente;
    return 1;
}

ptrNodoString getSiguienteNodoString(ptrNodoString ptr) {
    return ptr->siguiente;
}

char* getDatoNodoString(ptrNodoString ptr) {
    return ptr->dato;
}

