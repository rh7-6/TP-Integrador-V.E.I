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

void MenuRegistro();

void MenuRegistroMostrar();

void MuestraTextoTiposDeProducto();

/// funcionalidad ///

void GuardarRegistroProducto(Producto &p);

int CargarProducto(Producto &p); // necesita el archivo producto para verificar si ya existe el producto

void ListadoDeProductosPorTipo();

#endif // MENU_H_INCLUDED
