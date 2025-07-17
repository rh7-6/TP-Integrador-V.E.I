#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "vector"
//#include "Fecha.h"
//#include "cadena.h"
#include "Producto.h"
#include "Clientes.h"
#include "Venta.h"
#include "Detalle_Venta.h"
///libreria grafica///
#include "rlutil.h"
using namespace std;

/// selección y graficos ///
    void Menu();

    void Pilares();

    void comprar();

    void Listado();

    void Busqueda();

    void Informes();

    void CargarRegistros();

    void TextoMenuPrincipal();

    void TextoMenuCompra();

    void TextoMenuListado();

    void TextoMenuBusqueda();

    void TextoMenuInformes();

    void TextoMenuCargarRegistro();

    void TextoTiposDeProducto();



/// funcionalidad ///

/*---------
  PRODUCTOS
  ---------*/

    int CargarProducto(Producto &p); // verifica si ya existe el producto y pregunta si se quiere reingresar el mismo(en el caso de que se quiera actualizar o corregir un error)

    void MostrarProducto(Producto &p);

    void BuscarProducto(bool opcion); // opcion1= buscar por numero de equipo| opcion0=buscar por rango de precio

    void GuardarRegistroProducto(Producto &p); // guarda y pregunta si se quiere continuar guardando productos

    void ListadoDeProductos(bool opcion); // opcion1= ordenados por precio, opcion0= ordenados por stock

/*---------
  CLIENTES
  ---------*/

    int CargarCliente(Cliente &cl);//  verifica si ya existe el cliente y pregunta si se quiere reingresar el mismo(en el caso de que se quiera actualizar o corregir un error)

    void MostrarCliente(Cliente &cl);

    void BuscarCliente();

    void GuardarRegistroCliente(Cliente &cl, bool opcionSeg);//Guarda y pregunta si quiere continuar guardando ||opcionSeg 1: para tener la opcion de ingresar mas clientes, opcionSeg: 0 para no tener la opcion

    void ListadoDeClientes();

/*---------
  VENTAS
  ---------*/

    void CargarVenta(Venta &v, const char *cuit, bool opcionFuncion);//(carrito=1 | carga simple o editar= 0) en caso de ingresar 0 podes ingresar una venta de forma manual o reingresar una existente.
                                                                     // En caso de ingresar 1 se establece automaticamente el numero de venta y podes ingresar los datos restantes de la nueva venta
    void MostrarVenta(Venta &v);

    void BuscarVenta(int opcion);//

    void GuardarRegistroVenta(Venta &v, const char *nombreArchivo);//   guarda y pregunta si se quiere continuar guardando productos

    void ListadoDeVentas();

/*---------
  DETALLE VENTAS
  ---------*/

    void CargarDetalleVenta(int numVenta, DetalleVenta &dv);// si el numero de venta que se de como parametro es igual a 0 se ingresa luego de forma manual dentro de la funcion

    void MostrarDetalleVenta(DetalleVenta &dv);

    void BuscarDetalleVenta();

    void GuardarRegistroDetalleVenta(DetalleVenta &dv, const char *nombreArchivo);//                 ||

    void ListadoDetalleVentasPorNumeroDeVenta();

/*---------
    COMPRA
  ---------*/

#endif // MENU_H_INCLUDED
