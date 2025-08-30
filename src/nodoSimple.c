#include "nodoSimple.h"

typedef struct nodoSimple {
    char dato;
    struct nodoSimple* siguiente;
} NodoSimple;
typedef NodoSimple* ptrNodoSimple;

ptrNodoSimple newNodoSimple(const char dato) {
    ptrNodoSimple nuevoNodo = malloc(sizeof(NodoSimple));
    if(nuevoNodo == NULL) return NULL;
    
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

int killNodoSimple(ptrNodoSimple ptrNodo) {
    if(ptrNodo == NULL) return -1;
    free(ptrNodo);
    ptrNodo = NULL;
    return 1;
}

char getDatoNodoSimple(ptrNodoSimple ptrNodo) {
    return ptrNodo->dato;
}

void setSiguienteNodoSimple(ptrNodoSimple ptrNodo, ptrNodoSimple siguiente) {
    if(ptrNodo == NULL) return;
    ptrNodo->siguiente = siguiente;
}

ptrNodoSimple getSiguienteNodoSimple(ptrNodoSimple ptrNodo) {
    if(ptrNodo == NULL) return NULL;
    return ptrNodo->siguiente;
}

