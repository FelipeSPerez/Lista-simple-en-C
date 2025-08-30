#include "menu.h"

typedef struct menu {
    ptrListaString opciones;
    int cantidadOpciones;
} Menu;
typedef Menu* ptrMenu;

ptrMenu newMenu(const int cantidadOpciones, ...) {
    if(cantidadOpciones <= 0) return NULL;

    ptrListaString opciones = newListaString();
    if(opciones == NULL) return NULL;

    va_list ap;
    va_start(ap, cantidadOpciones);
        for(int i = 1; i <= cantidadOpciones; i++)
            insertarListaString(opciones, va_arg(ap, char*));
    va_end(ap);

    ptrMenu nuevoMenu = malloc(sizeof(Menu));
    if(nuevoMenu == NULL) {
        killListaString(opciones);
        opciones = NULL;
        return NULL;
    }

    nuevoMenu->opciones = opciones;
    nuevoMenu->cantidadOpciones = cantidadOpciones;
    return nuevoMenu;
}

int killMenu(ptrMenu ptr) {
    killListaString(ptr->opciones);
    ptr->opciones = NULL;
    free(ptr);
    ptr = NULL;
    return 1;
}

int leerOpcion(ptrMenu ptr) {
    int error;
    char opcion = '\0';
    do {
        error = 0;
        imprimirMenu(ptr);
        printf("¿Opción?: ");
        scanf("\n%c", &opcion);
        if(atoi(&opcion) < 1 || atoi(&opcion) > ptr->cantidadOpciones) {
            system("clear");
            error = 1;
        }
    } while(error);
    return atoi(&opcion);
}

void imprimirMenu(ptrMenu ptr) {
    if(ptr == NULL) return;
    if(ptr->cantidadOpciones == 0) return;
    printf("--------------------------------------------\n");
    for(int posicion = 1; posicion <= ptr->cantidadOpciones; posicion++) {
        printf("%d) %s\n", posicion, getDatoNumeroNodoListaString(ptr->opciones, posicion));
    }
    printf("\n");
}

