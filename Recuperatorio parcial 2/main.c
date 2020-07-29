#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "utn.h"
#include "funciones.h"

int menu();

int main()
{
    LinkedList* lista = ll_newLinkedList();
    int opcion;
    srand (time(NULL));

    if(lista==NULL)
    {
        printf("No se pudo asignar memoria");
        exit(EXIT_FAILURE);
    }
    do
    {
        system("cls");
        opcion=menu();

        switch(opcion)
        {
        case 1:
            system("cls");
            if(cargarArchivo(lista))
            {
                printf("Archivo cargado con exito\n");
            }
            else
            {
                printf("Error al cargar archivo\n");
            }
            system("pause");
            break;
        case 2:
            system("cls");
            imprimirLista(lista);
            system("pause");
            break;
        case 3:
            system("cls");
            if(asignarTiempo(lista))
            {
                printf("Tiempos asignados\n");
            }
            else
            {
                printf("Error al asignar tiempos\n");
            }
            system("pause");
            break;
        case 4:
            system("cls");
            if(filtrarTipo(lista))
            {
                printf("Archivo filtrado guardado\n");
            }
            else
            {
                printf("Error al filtrar archivo\n");
            }
            system("pause");
            break;
        case 5:
            system("cls");
            if(mostrarPocisiones(lista))
            {
            }
            else
            {
                printf("Error al intentar mostrar la lista\n");
            }
            system("pause");
            break;
        case 6:
            system("cls");
            if(guardarPocisiones(lista))
            {
                printf("Archivo guardado\n");
            }
            else
            {
                printf("Error al intentar guardar la lista\n");
            }
            system("pause");
            break;
        default:
            break;
        }

    }while(opcion!=7);

    ll_deleteLinkedList(lista);

    return 0;
}

int menu()
{
    int opcion;

    printf("1. Cargar archivo\n");
    printf("2. Imprimir lista\n");
    printf("3. Asignar tiempo\n");
    printf("4. Filtrar por tipo\n");
    printf("5. Mostrar posiciones\n");
    printf("6. Guardar posiciones\n");
    printf("7. Salir\n\n");

    utn_getEntero(&opcion,20,"Elija una opcion: ","Error. Vuelva a intentar: ",1,7);

    return opcion;
}
