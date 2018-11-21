#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Empleado.h"
#include "utn.h"
#include "Parser.h"

/****************************************************
    Menu:
    01. Cargar archivo
    02. Guardar archivo
    03. Listar empleados
    04. Calcular aumento
    05. Salir

*****************************************************/

int main()
{
    int option;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do
    {
        utn_getNumero(&option, "\n 01-Cargar archivo\n 02-Guardar archivo\n 03-Listar Empleados\n 04-Calcular aumento\n 05-Salir\n","Ingrese un numero valido\n",1,5,1);
        switch(option)
        {
        case 1:
            if(!controller_loadFromText("datos.csv",listaEmpleados))
            {
                printf("\nDatos cargados correctamente\n");
            }
            else
            {
                printf("No se puedo cargar el archivo!\n");
            }
            break;
        case 2:
            if(!controller_saveAsText("sueldo.csv",listaEmpleados))
            {
                printf("\nArchivo guardado.");
            }
            else
            {
                printf("\nNo se pudo guardar los datos\n");
            }
            break;
        case 3:
            if(ll_isEmpty(listaEmpleados))
            {
                printf("No se puede listar el vacio!");
            }
            else if(ll_isEmpty(listaEmpleados)== 0)
            {
                controller_ListarEmpleados(listaEmpleados);
            }
            else
            {
                printf("Error al listar!");
            }
            break;
        case 4:
            if(!ll_map(listaEmpleados,Empleado_aumentarSueldo))
            {
                printf("Se calculo el aumento correctamente!\n");
            }
            else
            {
                printf("No se pudo calcular el aumento!");
            }
            break;
        }
        pause();
    }
    while(option != 5);
    return 0;
}
