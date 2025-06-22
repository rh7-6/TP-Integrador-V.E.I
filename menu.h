#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
///libreria grafica///
#include "rlutil.h"
using namespace std;

void menu(){
///columna superior///
rlutil::locate(40,8);
cout<<"///////////////////////////////////////////";
///pilar izquierdo///
rlutil::locate(40,9);
cout<<"//";
rlutil::locate(40,10);
cout<<"//";
rlutil::locate(40,11);
cout<<"//";
rlutil::locate(40,12);
cout<<"//";
rlutil::locate(40,13);
cout<<"//";
rlutil::locate(40,14);
cout<<"//";
rlutil::locate(40,15);
cout<<"//";
rlutil::locate(40,16);
cout<<"//";
rlutil::locate(40,17);
cout<<"//";
///pilar derecho///
rlutil::locate(81,9);
cout<<"//";
rlutil::locate(81,10);
cout<<"//";
rlutil::locate(81,11);
cout<<"//";
rlutil::locate(81,12);
cout<<"//";
rlutil::locate(81,13);
cout<<"//";
rlutil::locate(81,14);
cout<<"//";
rlutil::locate(81,15);
cout<<"//";
rlutil::locate(81,16);
cout<<"//";
rlutil::locate(81,17);
cout<<"//";
///columna inferior///
rlutil::locate(40,18);
cout<<"///////////////////////////////////////////";
///opciones///
rlutil::locate(55,10);
cout<<"LISTADOS";
rlutil::locate(55,11);
cout<<"BUSQUEDAS";
rlutil::locate(55,12);
cout<<"INFORMES";
rlutil::locate(55,13);
cout<<"CARGAR UN REGISTO";
rlutil::locate(55,14);
cout<<"MOSTRAR REGISTROS";
rlutil::locate(55,15);
cout<<"SALIR";
}

void MenuListado(){
///columna superior///
rlutil::locate(40,8);
cout<<"///////////////////////////////////////////";
///pilar izquierdo///
rlutil::locate(40,9);
cout<<"//";
rlutil::locate(40,10);
cout<<"//";
rlutil::locate(40,11);
cout<<"//";
rlutil::locate(40,12);
cout<<"//";
rlutil::locate(40,13);
cout<<"//";
rlutil::locate(40,14);
cout<<"//";
rlutil::locate(40,15);
cout<<"//";
rlutil::locate(40,16);
cout<<"//";
rlutil::locate(40,17);
cout<<"//";
///pilar derecho///
rlutil::locate(81,9);
cout<<"//";
rlutil::locate(81,10);
cout<<"//";
rlutil::locate(81,11);
cout<<"//";
rlutil::locate(81,12);
cout<<"//";
rlutil::locate(81,13);
cout<<"//";
rlutil::locate(81,14);
cout<<"//";
rlutil::locate(81,15);
cout<<"//";
rlutil::locate(81,16);
cout<<"//";
rlutil::locate(81,17);
cout<<"//";
///columna inferior///
rlutil::locate(40,18);
cout<<"///////////////////////////////////////////";
///opciones de listado///
rlutil::locate(50,10);
cout<<"Listado de equipos";
rlutil::locate(50,11);
cout<<"Listado de clientes";
rlutil::locate(50,12);
cout<<"Listado de ventas";
rlutil::locate(50,13);
cout<<"Volver";
}

void MenuBusquedad(){
///columna superior///
rlutil::locate(40,8);
cout<<"///////////////////////////////////////////";
///pilar izquierdo///
rlutil::locate(40,9);
cout<<"//";
rlutil::locate(40,10);
cout<<"//";
rlutil::locate(40,11);
cout<<"//";
rlutil::locate(40,12);
cout<<"//";
rlutil::locate(40,13);
cout<<"//";
rlutil::locate(40,14);
cout<<"//";
rlutil::locate(40,15);
cout<<"//";
rlutil::locate(40,16);
cout<<"//";
rlutil::locate(40,17);
cout<<"//";
///pilar derecho///
rlutil::locate(81,9);
cout<<"//";
rlutil::locate(81,10);
cout<<"//";
rlutil::locate(81,11);
cout<<"//";
rlutil::locate(81,12);
cout<<"//";
rlutil::locate(81,13);
cout<<"//";
rlutil::locate(81,14);
cout<<"//";
rlutil::locate(81,15);
cout<<"//";
rlutil::locate(81,16);
cout<<"//";
rlutil::locate(81,17);
cout<<"//";
///columna inferior///
rlutil::locate(40,18);
cout<<"///////////////////////////////////////////";
///opciones de listado///
rlutil::locate(50,10);
cout<<"Busqueda de equipos";
rlutil::locate(50,11);
cout<<"Busqueda de clientes";
rlutil::locate(50,12);
cout<<"Busqueda de ventas";
rlutil::locate(50,13);
cout<<"Volver";
}

void MenuInformes(){
///columna superior///
rlutil::locate(40,8);
cout<<"///////////////////////////////////////////";
///pilar izquierdo///
rlutil::locate(40,9);
cout<<"//";
rlutil::locate(40,10);
cout<<"//";
rlutil::locate(40,11);
cout<<"//";
rlutil::locate(40,12);
cout<<"//";
rlutil::locate(40,13);
cout<<"//";
rlutil::locate(40,14);
cout<<"//";
rlutil::locate(40,15);
cout<<"//";
rlutil::locate(40,16);
cout<<"//";
rlutil::locate(40,17);
cout<<"//";
///pilar derecho///
rlutil::locate(81,9);
cout<<"//";
rlutil::locate(81,10);
cout<<"//";
rlutil::locate(81,11);
cout<<"//";
rlutil::locate(81,12);
cout<<"//";
rlutil::locate(81,13);
cout<<"//";
rlutil::locate(81,14);
cout<<"//";
rlutil::locate(81,15);
cout<<"//";
rlutil::locate(81,16);
cout<<"//";
rlutil::locate(81,17);
cout<<"//";
///columna inferior///
rlutil::locate(40,18);
cout<<"///////////////////////////////////////////";
///opciones de listado///
rlutil::locate(44,10);
cout<<"Recaudacion anual";
rlutil::locate(44,11);
cout<<"Recaudacion por cliente";
rlutil::locate(44,12);
cout<<"Recaudacion por tipo de equipo";
rlutil::locate(44,13);
cout<<"Equipos vendidos por tipo de cliente";
rlutil::locate(44,14);
cout<<"Volver";
}

void MenuRegistro(){
///columna superior///
rlutil::locate(40,8);
cout<<"///////////////////////////////////////////";
///pilar izquierdo///
rlutil::locate(40,9);
cout<<"//";
rlutil::locate(40,10);
cout<<"//";
rlutil::locate(40,11);
cout<<"//";
rlutil::locate(40,12);
cout<<"//";
rlutil::locate(40,13);
cout<<"//";
rlutil::locate(40,14);
cout<<"//";
rlutil::locate(40,15);
cout<<"//";
rlutil::locate(40,16);
cout<<"//";
rlutil::locate(40,17);
cout<<"//";
///pilar derecho///
rlutil::locate(81,9);
cout<<"//";
rlutil::locate(81,10);
cout<<"//";
rlutil::locate(81,11);
cout<<"//";
rlutil::locate(81,12);
cout<<"//";
rlutil::locate(81,13);
cout<<"//";
rlutil::locate(81,14);
cout<<"//";
rlutil::locate(81,15);
cout<<"//";
rlutil::locate(81,16);
cout<<"//";
rlutil::locate(81,17);
cout<<"//";
///columna inferior///
rlutil::locate(40,18);
cout<<"///////////////////////////////////////////";
///opciones de listado///
rlutil::locate(46,10);
cout<<"Cargar registro de cliente";
rlutil::locate(46,11);
cout<<"Cargar registro de venta";
rlutil::locate(46,12);
cout<<"Cargar registro de producto";
rlutil::locate(46,13);
cout<<"Cargar registro detalle de venta";
rlutil::locate(46,14);
cout<<"Volver";
}

void MenuRegistroMostrar(){
///columna superior///
rlutil::locate(40,8);
cout<<"///////////////////////////////////////////";
///pilar izquierdo///
rlutil::locate(40,9);
cout<<"//";
rlutil::locate(40,10);
cout<<"//";
rlutil::locate(40,11);
cout<<"//";
rlutil::locate(40,12);
cout<<"//";
rlutil::locate(40,13);
cout<<"//";
rlutil::locate(40,14);
cout<<"//";
rlutil::locate(40,15);
cout<<"//";
rlutil::locate(40,16);
cout<<"//";
rlutil::locate(40,17);
cout<<"//";
///pilar derecho///
rlutil::locate(81,9);
cout<<"//";
rlutil::locate(81,10);
cout<<"//";
rlutil::locate(81,11);
cout<<"//";
rlutil::locate(81,12);
cout<<"//";
rlutil::locate(81,13);
cout<<"//";
rlutil::locate(81,14);
cout<<"//";
rlutil::locate(81,15);
cout<<"//";
rlutil::locate(81,16);
cout<<"//";
rlutil::locate(81,17);
cout<<"//";
///columna inferior///
rlutil::locate(40,18);
cout<<"///////////////////////////////////////////";
///opciones de listado///
rlutil::locate(46,10);
cout<<"Mostrar registros de cliente";
rlutil::locate(46,11);
cout<<"Mostrar registros de venta";
rlutil::locate(46,12);
cout<<"Mostrar registros de producto";
rlutil::locate(46,13);
cout<<"Mostrar registros detalle de venta";
rlutil::locate(46,14);
cout<<"Volver";

}

#endif // MENU_H_INCLUDED
