#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Venta.h"
#include "utn.h"
#include "Parser.h"

int main()
{
    LinkedList* listaVenta = ll_newLinkedList();

    if(!controller_loadFromText("data.csv",listaVenta))
    {
        printf("Se cargo el archivo con existo!\n");
    }
    else
    {
        printf("No se pudo cargar el archivo\n");
    }

    if(!controller_saveAsText("informes.txt",listaVenta))
    {
        printf("\nArchivo generado.");
    }
    else
    {
        printf("\nNo se pudo generar el archivo\n");
    }
    return 0;
}
