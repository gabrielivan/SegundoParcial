#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Venta.h"
#include "utn.h"
#include "Parser.h"
#include "informes.h"

int main()
{
    LinkedList* listaVenta = ll_newLinkedList();
//    int CantidadUnidadesVendidasTotales;
//    int CantidadDeVentasPorUnMontoMayorDiez;
//    int CantidadDeVentasPorUnMontoMayorVeinte;
//    int CantidadDeTvLcdVendidas;

    if(!controller_loadFromText("data.csv",listaVenta))
    {
        printf("\nSe cargo el archivo con existo!\n");
    }
    else
    {
        printf("No se pudo cargar el archivo\n");
    }
    //informe_cantidadTotal(listaVenta);
    informe_cantidadMontoMayor(listaVenta);
//    CantidadDeTvLcdVendidas = informe_cantidadLcdTV(listaVenta);
//    CantidadDeVentasPorUnMontoMayorDiez = informe_cantidadMontoMayor(listaVenta);
//    CantidadDeVentasPorUnMontoMayorVeinte = informe_cantidadMontoMayorMas(listaVenta);
//    CantidadUnidadesVendidasTotales = informe_cantidadTotal(listaVenta);
//
//    printf("\n CantidadDeTvLcdVendidas: %d\n ",CantidadDeTvLcdVendidas);
//    printf("CantidadDeVentasPorUnMontoMayorDiez %d\n ",CantidadDeVentasPorUnMontoMayorDiez);
//    printf("CantidadDeVentasPorUnMontoMayorVeinte %d\n ",CantidadDeVentasPorUnMontoMayorVeinte);
//    printf("CantidadUnidadesVendidasTotales %d\n ",CantidadUnidadesVendidasTotales);

//    if(!controller_saveAsText("informes.txt",listaVenta))
//    {
//        printf("\nArchivo generado.");
//    }
//    else
//    {
//        printf("\nNo se pudo generar el archivo\n");
//    }
    return 0;
}
