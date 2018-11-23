#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Venta.h"
#include "parser.h"
#include "utn.h"



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 * \param path char* ruta del archivo
 * \param pArrayListEmployee LinkedList* lista donde se va a guardar el archivo
 * \return [0] Exito y [-1] Error
 */

int controller_loadFromText(char* path , LinkedList* listaVenta)
{
    FILE* pArchivo;
    int retorno = -1;
    pArchivo = fopen(path,"r");
    if(!parser_EmployeeFromText(pArchivo,listaVenta))
    {
        retorno = 0;
    }
    fclose(pArchivo);
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char* ruta del archivo
 * \param pArrayListEmployee LinkedList* lista que se va a guardar
 * \return [0] Exito y [-1] Error
 */

//int controller_saveAsText(char* path , LinkedList* listaVenta)
//{
//    FILE* pArchivo = fopen(path,"w");
//    int retorno = -1;
//
//    if(pArchivo != NULL && !parser_SaveToText(pArchivo,listaVenta))
//    {
//        retorno = 0;
//    }
//    fclose(pArchivo);
//    return retorno;
//}
