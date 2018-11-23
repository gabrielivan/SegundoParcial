#include "Parser.h"
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Venta.h"
#include "informes.h"

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 * \param FILE* pFile Puntero del tipo file al archivo para parsear
 * \param listaVenta LinkedList* lista donde se van a a guardar los empleados
 * \return en caso de exito retorna 0 y en caso de error retorna -1
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* listaVenta)
{
    char bufferidVenta[1024];
    char bufferCodigoProducto[1024];
    char bufferCuitCliente[1024];
    char bufferCantidad[1024];
    char bufferPrecioUnitario[1024];
    char bufferFecha[1024];
    int retorno = -1;
    int flagOnce = 1;
    Venta* pVenta;


    if(pFile!= NULL)
    {
        while(!feof(pFile))
        {
            if(flagOnce)
            {
               flagOnce = 0;
               fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
                                                bufferidVenta,
                                                bufferFecha,
                                                bufferCodigoProducto,
                                                bufferCantidad,
                                                bufferPrecioUnitario,
                                                bufferCuitCliente);
            }
             fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
                                                bufferidVenta,
                                                bufferFecha,
                                                bufferCodigoProducto,
                                                bufferCantidad,
                                                bufferPrecioUnitario,
                                                bufferCuitCliente);

            printf("Idventa: %s\n",bufferidVenta);
              printf("fecha: %s\n",bufferFecha);
               printf("codigoP %s\n",bufferCodigoProducto);
                printf("cantidad %s\n",bufferCantidad);
                 printf("precioUn %s\n",bufferPrecioUnitario);
                  printf("cuit %s\n",bufferCuitCliente);


            pVenta = Venta_newConParametros(        bufferidVenta,
                                                    bufferFecha,
                                                    bufferCodigoProducto,
                                                    bufferCantidad,
                                                    bufferPrecioUnitario,
                                                    bufferCuitCliente);


            if(pVenta != NULL)
            {
                retorno = 0;
                ll_add(listaVenta,pVenta);
            }

        }
    }
    return retorno;
}

int parser_SaveToText(FILE* pFile,LinkedList* listaVentas)
{
    int retorno = -1;
    int cantidadTotal;
    int cantidadMontoMayor;
    int cantidadMontoMayorMas;
    int cantidadLcdTV;

    cantidadTotal = informe_cantidadTotal(listaVentas);
    cantidadMontoMayor = informe_cantidadMontoMayor(listaVentas);
    cantidadMontoMayorMas = informe_cantidadMontoMayorMas(listaVentas);
    cantidadLcdTV = informe_cantidadLcdTV(listaVentas);

    if(pFile != NULL)
    {
        fprintf(pFile,"%d,%d,%d,%d \n",cantidadTotal,cantidadMontoMayor,cantidadMontoMayorMas,cantidadLcdTV);
        retorno = 0;
    }

    return retorno;
}