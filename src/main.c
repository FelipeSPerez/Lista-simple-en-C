#include "menu.h"
#include "listaSimple.h"

void opcionInsertar(ptrListaSimple lista);
void opcionEliminar(ptrListaSimple lista);

int main(void) {
    ptrMenu menuListaSimple = newMenu(4, "Insertar dato.", "Eliminar dato.", "Imprimir Lista", "Salir.");
    ptrListaSimple lista = newListaSimple();

    int opcion;
    do {
        opcion = leerOpcion(menuListaSimple);
        switch(opcion) {
            case 1:
                opcionInsertar(lista);
                break;
            case 2:
                opcionEliminar(lista);
                break;
            case 3:
                system("clear");
                imprimirListaSimple(lista);
                break;
            case 4:
                break;
            default:
                /*Opcion no valida*/
                opcion = 0;
                printf("La opcion no es valida.\n");
                break;
        }
    } while(opcion != 4);

    printf("Cerrando el programa, adiós");

    /* Es necesario limpiar la memoria dinámica */
    if(killListaSimple(lista)) printf("La memoria de la lista se libero correctamente.\n");
    if(killMenu(menuListaSimple)) printf("La memoria del menu se libero correctamente.\n");


    return 0;
}

void opcionInsertar(ptrListaSimple lista) {
    system("clear");
    char dato = '\0';
    imprimirListaSimple(lista);
    printf("Introduce el dato a insertar: ");
    scanf("\n%c", &dato);
    if(insertarListaSimple(lista, dato))
        printf("El dato se insertó correctamente.\n");
    else
        printf("Error, el programa no pudo asignar memoria, memoria RAM llena.\n");
    imprimirListaSimple(lista);
}

void opcionEliminar(ptrListaSimple lista) {
    system("clear");
    imprimirListaSimple(lista);
    if(eliminarListaSimple(lista))
        printf("El dato se eliminó correctamente.\n");
    else
        printf("No se pudo eliminar el dato, hay lista vacia.\n");
    imprimirListaSimple(lista);
}

