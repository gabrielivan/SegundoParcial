#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Venta.h"
#include "informes.h"
#include "utn.h"

int informe_cantidadTotal(LinkedList* listaVentas)
{
    int retorno = 0;
    int resultadoCount;

    if(listaVentas != NULL)
    {
        resultadoCount = ll_count(listaVentas,Venta_cantidadUnidadesTotal);
        retorno = resultadoCount;
    }

    return retorno;
}

int informe_cantidadMontoMayor(LinkedList* listaVentas)
{
    int retorno = 0;
    int resultadoCount;

    if(listaVentas != NULL)
    {
        resultadoCount = ll_count(listaVentas,Venta_Mayor);
        retorno = resultadoCount;
    }

    return retorno;
}


int informe_cantidadMontoMayorMas(LinkedList* listaVentas)
{
    int retorno = 0;
    int resultadoCount;

    if(listaVentas != NULL)
    {
        resultadoCount = ll_count(listaVentas,Venta_MayorMas);
        retorno = resultadoCount;
    }

    return retorno;
}

int informe_cantidadLcdTV(LinkedList* listaVentas)
{
    int retorno = 0;
    int resultadoCount;

    if(listaVentas != NULL)
    {
        resultadoCount = ll_count(listaVentas,Venta_cantidadTvLcd);
        retorno = resultadoCount;
    }

    return retorno;
}
