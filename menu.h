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

void MenuListado();

void MenuBusqueda();

void MenuInformes();

void MenuCargarRegistro();

void MenulistadosMostrar();

void MuestraTextoTiposDeProducto();

void Listado();

void Busqueda();

void Informes();

void CargarRegistros();

/// funcionalidad ///

/*---------
  Productos
  ---------*/

void GuardarRegistroProducto(Producto &p); // guarda y pregunta si se quiere continuar guardando productos

int CargarProducto(Producto &p); // verifica si ya existe el producto y pregunta si se quiere reingresar el mismo(en el caso de que se quiera actualizar o corregir un error)

void ListadoDeProductosPorTipo();

/*---------
  Clientes
  ---------*/

void GuardarRegistroCliente(Cliente &cl);

int CargarClientes(Cliente &cl);

void ListadoDeClientesPorEstado();

#endif // MENU_H_INCLUDED
