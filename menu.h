#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
///libreria grafica///
#include "rlutil.h"
#include "Fecha.h"
#include "cadena.h"
#include "Producto.h"
#include "Clientes.h"
#include "Venta.h"
#include "Detalle_Venta.h"
#include "Archivo_Clientes.h"
#include "Archivo_Productos.h"
#include "Archivo_Ventas.h"
#include "Archivo_Detalle_Ventas.h"
using namespace std;

/// selección y graficos ///
    void Menu();

    void menuPrincipal();

    void MenuCompra();

    void MenuListado();

    void MenuBusqueda();

    void MenuInformes();

    void MenuCargarRegistro();

    void MenulistadosMostrar();

    void MuestraTextoTiposDeProducto();

    void comprar();

    void Listado();

    void Busqueda();

    void Informes();

    void CargarRegistros();


/// funcionalidad ///

/*---------
  Productos
  ---------*/

    int CargarProducto(Producto &p); // verifica si ya existe el producto y pregunta si se quiere reingresar el mismo(en el caso de que se quiera actualizar o corregir un error)

    void MostrarProducto(Producto &p);

    void GuardarRegistroProducto(Producto &p); // guarda y pregunta si se quiere continuar guardando productos

    void ListadoDeProductosPorTipo();

/*---------
  Clientes
  ---------*/

    int CargarCliente(Cliente &cl);//  verifica si ya existe el cliente y pregunta si se quiere reingresar el mismo(en el caso de que se quiera actualizar o corregir un error)

    void MostrarCliente(Cliente &cl);

    void GuardarRegistroCliente(Cliente &cl, bool opcionSeg);//Guarda y pregunta si quiere continuar guardando ||opcionSeg 1: para tener la opcion de ingresar mas clientes, opcionSeg: 0 para no tener la opcion

    void ListadoDeClientesPorEstado();

/*---------
  Ventas
  ---------*/

    int CargarVenta(Venta &v, bool opcionFuncion);//(carrito=1 , carga simple o editar= 0) en caso de ingresar 0 podes ingresar una venta de forma manual o reingresar una existente.
                                                  // En caso de ingresar 1 se establece automaticamente el numero de venta y podes ingresar los datos restantes de la nueva venta
    void MostrarVenta(Venta &v);

    void GuardarRegistroVenta(Venta &v);//   guarda y pregunta si se quiere continuar guardando productos

    void ListadoDeVentasPorEstado();

/*---------
  Detalle Ventas
  ---------*/

    int CargarDetalleVenta(int numVenta, DetalleVenta &dv);// si el numero de venta que se de como parametro es igual a 0 se ingresa luego de forma manual dentro de la funcion

    void MostrarDetalleVenta(DetalleVenta &dv);

    void GuardarRegistroDetalleVenta(DetalleVenta &dv);//                 ||

    void ListadoDetalleVentasPorNumeroDeVenta();

#endif // MENU_H_INCLUDED
