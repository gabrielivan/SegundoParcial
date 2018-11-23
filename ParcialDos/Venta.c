#include "Venta.h"
#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

/**
*\brief Reservar espacio en memoria para un elemento
*\param void
*\return Retorna el elemento si reserva memoria sino NULL
*/
Venta* Venta_new()
{
    Venta* this;
    this=malloc(sizeof(Venta));
    if(this!=NULL)
    {
        return this;
    }
    else
    {
        return NULL;
    }

}

/**
*\brief Libera espacio en memoria ocupado por elemento
*\param tihs Es el elemento
*\return Retorna 0 si logra liberar sino retorna -1
*/

int Venta_delete(Venta* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

/**
*\brief Se realiza el alta de un elemento desde consola
*\param pArrayListEmpleado Es el array para ingresar elemento
*\return Retorna 0 si logra agregar elemento sino retorna -1
*/

Venta* Venta_newConParametros(char* idVenta,char* fecha,char* codigoProducto,char* cantidad,char* precioUnitario,char* cuitCliente)//lee desde el archivo
{
    Venta* this;
    this = Venta_new();
    int idVentaInt;
    int cantidadInt;
    int precioUnitarioInt;
    char codigoProductoAux[1024];
    char cuitClienteAux[14];
    char fechaAux[1024];

    if(EsEntero(idVenta,1024)&& EsEntero(cantidad,1024)&& EsFloatPositivo(precioUnitario,1024)&& EsCuit(cuitCliente,14))
    {
        idVentaInt = atoi(idVenta);
        cantidadInt = atoi(cantidad);
        precioUnitarioInt = atoi(precioUnitario);
        strcpy(codigoProductoAux,codigoProducto);
        strcpy(cuitClienteAux,cuitCliente);
        strcpy(fechaAux,fecha);

        if(
        !Venta_setId(this,idVentaInt)&&
        !Venta_setCodigoProducto(this,codigoProductoAux)&&
        !Venta_setCantidad(this,cantidadInt)&&
        !Venta_setPrecioUnitario(this,precioUnitarioInt))
            return this;
    }

    Venta_delete(this);
    return NULL;
}

/**
*\brief Se setea el ID del elemento
*\param this Es el elemento
*\param id Es el ID para setear
*\return Retorna 0 si setea sino -1
*/

int Venta_setId(Venta* this,int id)
{
    int retorno=-1;
    static int proximoId=-1;

    if(this!=NULL && id==-1)
    {
        proximoId++;
        this->idVenta=proximoId;
        retorno=0;
    }
    else if(id>proximoId)
    {
        proximoId=id;
        this->idVenta=proximoId;
        retorno=0;
    }
    return retorno;
}

/**
*\brief Se obtiene el ID del elemento
*\param this Es el elemento
*\param id Es el ID que se obtiene
*\return Retorna 0 si obtiene sino retorna -1
*/

int Venta_getId(Venta* this,int* idVenta)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *idVenta=this->idVenta;
        retorno=0;
    }
    return retorno;
}

/**
*\brief Se setea el nombre del elemento
*\param this Es el elemento
*\param nombre Es el nombre para setear
*\return Retorna 0 si setea elemento sino retorna -1
*/

int Venta_setCodigoProducto(Venta* this,char* codigoProducto)
{
    int retorno=-1;
    if(this!=NULL && codigoProducto!=NULL)
    {
        strcpy(this->codigoProducto,codigoProducto);
        retorno=0;
    }
    return retorno;
}

/**
*\brief Se obtiene el nombre del elemento
*\param this Es el elemento
*\param nombre Es el nombre que se obtiene
*\return Retorna 0 si obtiene elemento sino retorna -1
*/

int Venta_getCodigoProducto(Venta* this,char* codigoProducto)
{
    int retorno=-1;
    if(this!=NULL && codigoProducto!=NULL)
    {
        strcpy(codigoProducto,this->codigoProducto);
        retorno=0;
    }
    return retorno;
}

/**
*\brief Se setea las horas trabajadas del elemento
*\param this Es el elemento
*\param horasTrabajadas Es la cantidad de horas para setear
*\return Retorna 0 si setea elemento sino retorna -1
*/

int Venta_setCantidad(Venta* this,int cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->cantidad=cantidad;
        retorno=0;
    }
    return retorno;
}

/**
*\brief Se obtienen las horas trabajadas del elemento
*\param this Es el elemento
*\param horasTrabajadas Es la cantidad de horas que se obtiene
*\return Retorna 0 si setea elemento sino retorna -1
*/

int Venta_getCantidad(Venta* this,int* cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *cantidad=this->cantidad;
        retorno=0;
    }
    return retorno;
}

/**
*\brief Se setea el sueldo del elemento
*\param this Es el elemento
*\param sueldo Es el sueldo para setear
*\return Retorna 0 si setea elemento sino retorna -1
*/

float Venta_setPrecioUnitario(Venta* this,float precioUnitario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->precioUnitario=precioUnitario;
        retorno=0;
    }
    return retorno;
}

/**
*\brief Se obtiene el sueldo del elemento
*\param this Es el elemento
*\param sueldo Es el sueldo que se obtiene
*\return Retorna 0 si setea elemento sino retorna -1
*/

float Venta_getPrecioUnitario(Venta* this,float* precioUnitario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *precioUnitario=this->precioUnitario;
        retorno=0;
    }
    return retorno;
}

/**
*\brief Se muestran los datos de todos los campos del elemento
*\param this Es el puntero al elemento
*\return Retorna 0 si el elemento es diferente a NULL sino retorna -1
*/

int Venta_mostrar(void* pVenta)
{
    int retorno = -1;
    int auxId;
    char auxCodigoProducto[128];
    char auxCuit[128];
    char auxFecha[128];
    int auxIdVenta;
    int auxCantidad;
    float auxPrecioUnitario;

    if(pVenta != NULL)
    {
        Venta_getId(pVenta,&auxId);
        if(auxId != -1)
        {
            Venta_getCodigoProducto(pVenta,auxCodigoProducto);
            Venta_getCantidad(pVenta,&auxCantidad);
            Venta_getPrecioUnitario(pVenta,&auxPrecioUnitario);
            Venta_getId(pVenta,&auxIdVenta);
            Venta_getFecha(pVenta,auxFecha);
            Venta_getCuitCliente(pVenta,auxCuit);

            printf("\nID: %d",auxIdVenta);
            printf("\nCodigo Producto: %s",auxCodigoProducto);
            printf("\nCantidad: %d",auxCantidad);
            printf("\nPrecio Unitario: %f\n",auxPrecioUnitario);
            printf("\nCUIT : %s\n",auxCuit);
            printf("\nFECHA: %s\n",auxFecha);
            retorno = 0;
        }
    }
    return retorno;
}


int Venta_getAll(Venta* this,char* codigoProducto,char* cuitCliente,int* cantidad,float* precioUnitario,int* idVenta)
{
    int retorno = -1;

    if(this != NULL)
    {
        Venta_getCodigoProducto(this,codigoProducto);
        Venta_getCuitCliente(this,cuitCliente);
        Venta_getCantidad(this,cantidad);
        Venta_getPrecioUnitario(this,precioUnitario);
        Venta_getId(this,idVenta);
        retorno = 0;
    }
    return retorno;
}

int Venta_setCuitCliente(Venta* this,char* cuitCliente)
{
    int retorno=-1;
    if(this!=NULL && cuitCliente!=NULL)
    {
        strcpy(this->cuitCliente,cuitCliente);
        retorno=0;
    }
    return retorno;
}

int Venta_getCuitCliente(Venta* this,char* cuitCliente)
{
    int retorno=-1;
    if(this!=NULL && cuitCliente!=NULL)
    {
        strcpy(cuitCliente,this->cuitCliente);
        retorno=0;
    }
    return retorno;
}

int Venta_setFecha(Venta* this,char* fecha)
{
    int retorno=-1;
    if(this!=NULL && fecha!=NULL)
    {
        strcpy(this->fecha,fecha);
        retorno=0;
    }
    return retorno;
}

int Venta_getFecha(Venta* this,char* fecha)
{
    int retorno=-1;
    if(this!=NULL && fecha!=NULL)
    {
        strcpy(fecha,this->fecha);
        retorno=0;
    }
    return retorno;
}
int Venta_Mayor(void* this)
{
    int retorno = 0;
    float auxPrecio;
    int contadorCantidad = 0;

    Venta_getPrecioUnitario(this,&auxPrecio);

    if(this != NULL)
    {

        if(auxPrecio > 10000)
        {
            contadorCantidad++;
            retorno = contadorCantidad;
        }

    }

    return retorno;
}

int Venta_MayorMas(void* this)
{
    int retorno = 0;
    float auxPrecio;
    int contadorCantidad = 0;

    Venta_getPrecioUnitario(this,&auxPrecio);

    if(this != NULL)
    {

        if(auxPrecio > 20000)
        {
            contadorCantidad++;
            retorno = contadorCantidad;
        }

    }

    return retorno;
}

int Venta_cantidadUnidadesTotal(void* this)
{
    int retorno = 0;
    int auxCantidad;
    int contadorCantidad = 0;

    Venta_getCantidad(this,&auxCantidad);

    if(this != NULL)
    {
        contadorCantidad = contadorCantidad + auxCantidad;
        retorno = contadorCantidad;

    }

    return retorno;
}

int Venta_cantidadTvLcd(void* this)
{
    int retorno = 0;
    char auxTvLcd[1024];
    int contadorTvLcd = 0;

    Venta_getCodigoProducto(this,auxTvLcd);

    if(this != NULL)
    {
        if(strcmp(auxTvLcd,"LCD_TV")== 0)
        {
            contadorTvLcd++;
            retorno = contadorTvLcd;
        }
    }

    return retorno;
}
