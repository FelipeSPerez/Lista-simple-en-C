#include "listaSimple.h"

typedef struct listaSimple {
    ptrNodoSimple inicio;
    ptrNodoSimple fin;
} ListaSimple;
typedef ListaSimple* ptrListaSimple;

ptrListaSimple newListaSimple() {
    ptrListaSimple nuevaLista = malloc(sizeof(ListaSimple));
    if(nuevaLista == NULL) return NULL;
    nuevaLista->inicio = nuevaLista->fin = NULL;
    return nuevaLista;
}

int hayListaVaciaListaSimple(ptrListaSimple lista) {
    if(lista == NULL) return -1;
    if(lista->inicio == NULL) return 1;
    return 0;
}

int hayUnSoloElementoListaSimple(ptrListaSimple lista) {
    if(lista == NULL) return -1;
    if(lista->inicio == lista->fin) return 1;
    return 0;
}

int killListaSimple(ptrListaSimple lista) {
    if(lista == NULL) return -1;
    while(!hayListaVaciaListaSimple(lista))
        eliminarListaSimple(lista);
    free(lista);
    lista = NULL;
    return 1;
}

int insertarListaSimple(ptrListaSimple lista, const char dato) {
    if(lista == NULL) return -1;
    
    ptrNodoSimple nuevoNodo = newNodoSimple(dato);
    if(nuevoNodo == NULL) return 0;

    if(hayListaVaciaListaSimple(lista)) {
        lista->inicio = lista->fin = nuevoNodo;
        nuevoNodo = NULL;
        return 1;
    }
    setSiguienteNodoSimple(lista->fin, nuevoNodo);
    lista->fin = nuevoNodo;
    nuevoNodo = NULL;
    return 1;
}

int eliminarListaSimple(ptrListaSimple lista) {
    if(lista == NULL) return -1;
    if(hayListaVaciaListaSimple(lista)) return 0;
    if(hayUnSoloElementoListaSimple(lista)) {
        killNodoSimple(lista->inicio);
        lista->inicio = lista->fin = NULL;
        return 1;
    }
    ptrNodoSimple temporal = lista->inicio;
    lista->inicio = getSiguienteNodoSimple(temporal);
    setSiguienteNodoSimple(temporal, NULL);
    killNodoSimple(temporal);
    temporal = NULL;
    return 1;
}

int getNumeroNodosListaSimple(ptrListaSimple lista) {
    if(lista == NULL) return -1;
    if(hayListaVaciaListaSimple(lista)) return 0;
    if(hayUnSoloElementoListaSimple(lista)) return 1;
    int contador = 2;
    ptrNodoSimple temporal;
    for(temporal = getSiguienteNodoSimple(lista->inicio); temporal != NULL; temporal = getSiguienteNodoSimple(temporal), contador++);
    return contador;
}

void imprimirListaSimple(ptrListaSimple lista) {
    ptrNodoSimple temporal = lista->inicio;
    while(temporal !=NULL){
        printf("[%c]->", getDatoNodoSimple(temporal));
        temporal = getSiguienteNodoSimple(temporal);
    }
    printf("\n");
}

