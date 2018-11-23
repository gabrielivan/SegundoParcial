#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Venta.h"
#include "informes.h"
#include "utn.h"

int informe_cantidadTotal(LinkedList* listaVentas)
{
    int retorno = -1;

    if(listaVentas != NULL)
    {
        retorno = ll_count(listaVentas,Venta_cantidadUnidadesTotal);
    }

    return retorno;
}

int informe_cantidadMontoMayor(LinkedList* listaVentas)
{
    int retorno = -1;

    retorno = ll_count(listaVentas,Venta_Mayor);

    return retorno;
}

int informe_cantidadMontoMayorMas(LinkedList* listaVentas)
{
    int retorno = -1;

    retorno = ll_count(listaVentas,Venta_MayorMas);

    return retorno;
}

int informe_cantidadLcdTV(LinkedList* listaVentas)
{
    int retorno = -1;

    retorno = ll_count(listaVentas,Venta_cantidadTvLcd);

    return retorno;
}
