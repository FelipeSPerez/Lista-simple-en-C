#include "listaString.h"

typedef struct listaString {
    ptrNodoString inicio;
    ptrNodoString fin;
} ListaString;
typedef ListaString* ptrListaString;

ptrListaString newListaString() {
    ptrListaString nuevaLista = malloc(sizeof(*nuevaLista));
    if(nuevaLista == NULL) return NULL;

    nuevaLista->inicio = nuevaLista->fin = NULL;
    return nuevaLista;
}

int hayListaVaciaListaString(ptrListaString ptr) {
    if(ptr == NULL) return 0;
    if(ptr->inicio != NULL) return 0;
    return 1;
}

int hayUnSoloElementoListaString(ptrListaString ptr) {
    if(ptr == NULL) return 0;
    if((ptr->inicio) != (ptr->fin)) return 0;
    return 1;
}

int getNumeroNodosListaString(ptrListaString ptr) {
    if(ptr == NULL) return 0;
    if(hayListaVaciaListaString(ptr)) return 0;
    if(hayUnSoloElementoListaString(ptr)) return 1;
    
    ptrNodoString temporal = getSiguienteNodoString(ptr->inicio);
    int contador;
    for(temporal = getSiguienteNodoString(temporal), contador = 2; temporal != NULL; contador++) {
        temporal = getSiguienteNodoString(temporal);
    }
    return contador;
}

int killListaString(ptrListaString ptr) {
    if(ptr == NULL) return 0;

    if(hayListaVaciaListaString(ptr)) {
        free(ptr);
        ptr = NULL;
        return 1;
    }

    if(hayUnSoloElementoListaString(ptr)) {
        return eliminarListaString(ptr);
    }
   
    while(ptr->inicio != NULL) {
        eliminarListaString(ptr);
    }

    free(ptr);
    ptr = NULL;
    return 1;
}

int insertarListaString(ptrListaString ptr, const char* dato) {
    if(ptr == NULL) return 0;
    
    ptrNodoString nuevoNodo = newNodoString(dato);
    if(nuevoNodo == NULL) return 0;

    if(hayListaVaciaListaString(ptr)) {
        ptr->inicio = ptr->fin = nuevoNodo;
        return 1;
    }

    setSiguienteNodoString(ptr->fin, nuevoNodo);
    ptr->fin = nuevoNodo;
    return 1;
}

int eliminarListaString(ptrListaString ptr) {
    if(ptr == NULL) return 0;
    
    if(hayListaVaciaListaString(ptr)) return 0;

    if(hayUnSoloElementoListaString(ptr)) { 
        killNodoString(ptr->inicio);
        ptr->inicio = ptr->fin = NULL;
        return 1;
    }
    
    ptrNodoString temporal = ptr->inicio;
    ptr->inicio = getSiguienteNodoString(temporal);
    setSiguienteNodoString(temporal, NULL);
    killNodoString(temporal);
    temporal = NULL;
    return 1;
}

void imprimirListaString(ptrListaString ptr) {
    if(ptr == NULL) {
        printf("Error, el puntero a la lista es NULL.\n");
    } else {
        for(ptrNodoString temporal = ptr->inicio; temporal != NULL; temporal = getSiguienteNodoString(temporal)) {
            printf("[%s]->", getDatoNodoString(temporal));
        }
    }
    printf("\n");
}

char* getDatoNumeroNodoListaString(ptrListaString ptr, const int numeroNodo) {
    if(ptr == NULL) return NULL;
    if(hayListaVaciaListaString(ptr)) return NULL;
    if(numeroNodo == 0) return NULL;
    if(numeroNodo == 1) return getDatoNodoString(ptr->inicio);
    ptrNodoString temporal; int posicion; for(temporal = getSiguienteNodoString(ptr->inicio), posicion = 2; temporal != NULL && posicion != numeroNodo; posicion++)
        temporal = getSiguienteNodoString(temporal);
    if(temporal == NULL) return NULL;
    return getDatoNodoString(temporal);
}

