#include <iostream>
#include "menu.h"
using namespace std;

void Menu(){

int y=0, icono;
bool bandera=true;


Cliente cl;
Venta ven;
Producto prod;
DetalleVenta venDT;
ArchivoClientes arch_cl("clientes.dat");
ArchivoProductos arch_p("Productos.dat");



///movimiento///
do{
menuPrincipal();
rlutil::hidecursor();
rlutil::locate(54,10+y);
cout<<(char)175<<endl;
icono = rlutil::getkey();
switch (icono){
    case(14):///arriba///
    rlutil::locate(54,10+y);
    cout<<" "<<endl;
    y--;
    if(y<0){y=4;}
    break;
    case(15):///abajo///
    rlutil::locate(54,10+y);
    cout<<" "<<endl;
    y++;
    if(y>4){y=0;}
    break;
    ///rlutil::showcursor(); hace aparecer el cursor///
    case(1):///enter///
       bool bandera1=false;
            int a=0;
        switch(y)
        {
            case(0):{//////////////////////LISTADOS////////////////////////////
            MostrarListado();
            system("cls");
            }
            break;

            case(1)://////////////////////BUSQUEDA////////////////////////////
            system("cls");
            do{
            MenuBusqueda();
            rlutil::locate(49,10+a);
            cout<<(char)175<<endl;
            icono = rlutil::getkey();
            switch (icono){
                case(14):///arriba///
                rlutil::locate(49,10+a);
                cout<<" "<<endl;
                a--;
                if(a<0){a=3;}
                break;
                case(15):///abajo///
                rlutil::locate(49,10+a);
                cout<<" "<<endl;
                a++;
                if(a>3){a=0;}
                break;
                case(1):///enter///
                    switch(a)
                    {
                        case(0):
                        break;
                        case(1):
                        break;
                        case(2):
                        break;
                        case(3):
                        bandera1=true;
                        break;
        break;

        }
        }
        }while(bandera1==false);
            system("cls");
            break;

            case(2)://////////////////////INFORMES////////////////////////////

            system("cls");
            do{
            MenuInformes();
            rlutil::locate(43,10+a);
            cout<<(char)175<<endl;
            icono = rlutil::getkey();
            switch (icono){
                case(14):///arriba///
                rlutil::locate(43,10+a);
                cout<<" "<<endl;
                a--;
                if(a<0){a=4;}
                break;
                case(15):///abajo///
                rlutil::locate(43,10+a);
                cout<<" "<<endl;
                a++;
                if(a>4){a=0;}
                break;
                case(1):///enter///
                    switch(a)
                    {
                        case(0):
                        break;
                        case(1):
                        break;
                        case(2):
                        break;
                        case(3):
                        break;
                        case(4):
                        bandera1=true;
                        break;
        break;

        }
        }
        }while(bandera1==false);
            system("cls");

        break;
        case(3)://////////////////////////CARGA UN REGISTO////////////////////

            system("cls");
            do{
            MenuCargarRegistro();
            rlutil::locate(43,10+a);
            cout<<(char)175<<endl;
            icono = rlutil::getkey();
            switch (icono){
                case(14):///arriba///
                rlutil::locate(43,10+a);
                cout<<" "<<endl;
                a--;
                if(a<0){a=4;}
                break;
                case(15):///abajo///
                rlutil::locate(43,10+a);
                cout<<" "<<endl;
                a++;
                if(a>4){a=0;}
                break;
                case(1):///enter///

                    switch(a)
                    {
                        case(0):

////////////////////////////////////////////guarda registro de cliente/////////////////////////////////////////////////////////
                            system("cls");
                            rlutil::showcursor();
                            cl.CargarCliente();
                            system("cls");
                            rlutil::hidecursor();
                            arch_cl.GuardarCliente(cl);
                        break;
                        case(1):

////////////////////////////////////////////guarda registro de venta/////////////////////////////////////////////////////////
                            system("cls");
                            rlutil::showcursor();
                            ven.CargarVenta();
                            system("cls");
                            rlutil::hidecursor();
                        break;
                        case(2):{
////////////////////////////////////////////guarda registro de producto/////////////////////////////////////////////////////////
                            system("cls");
                            rlutil::showcursor();
                            Producto p;
                            CargarProducto(p);
                            system("cls");
                            rlutil::hidecursor();
                            GuardarRegistroProducto(p);
                        }
                        break;
                        case(3):

////////////////////////////////////////////guarda registro detalle de venta/////////////////////////////////////////////////////////
                            system("cls");
                            rlutil::showcursor();
                            venDT.CargarDetalleVenta();
                            system("cls");
                            rlutil::hidecursor();
                        break;
                        case(4):
                        bandera1=true;
                        break;
        break;
        }
        }
        }while(bandera1==false);
            system("cls");

        break;
        case(4)://////////////////////////SALIDA//////////////////////////////
        bandera=false;
        break;

        }
        break;

    }


}while(bandera==true);

    }

void menuPrincipal(){
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
cout<<"Mostrar listados";
rlutil::locate(50,12);
cout<<"Listado de clientes";
rlutil::locate(50,13);
cout<<"Listado de ventas";
rlutil::locate(50,14);
cout<<"Volver";
}

void MenuBusqueda(){
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

void MenuCargarRegistro(){
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

void MenulistadosMostrar(){
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
cout<<"Mostrar Listado de producto";
rlutil::locate(46,11);
cout<<"Mostrar Listado de venta";
rlutil::locate(46,12);
cout<<"Mostrar Listado de cliente";
rlutil::locate(46,13);
cout<<"Mostrar Listado detalle de venta";
rlutil::locate(46,14);
cout<<"Volver";
}

void MuestraTextoTiposDeProducto(){

    cout << "Equipos=1" << endl;
    cout << "Notebooks=2" << endl;
    cout << "Procesadores=3" << endl;
    cout << "Mothers=4" << endl;
    cout << "Placas de video=5" << endl;
    cout << "Memorias RAM=6" << endl;
    cout << "Gabinetes=7" << endl;
    cout << "Fuentes=8" << endl;
    cout << "Monitores=9" << endl;
    cout << "Perifericos=10" << endl;
}

void MostrarListado(){
Cliente cl;
ArchivoClientes arch_cl("clientes.dat");
int a=0, icono;
bool bandera1=false;
system("cls");
            do{
            MenulistadosMostrar();
            rlutil::locate(43,10+a);
            cout<<(char)175<<endl;
            icono = rlutil::getkey();
            switch (icono){
                case(14):///arriba///
                rlutil::locate(43,10+a);
                cout<<" "<<endl;
                a--;
                if(a<0){a=4;}
                break;
                case(15):///abajo///
                rlutil::locate(43,10+a);
                cout<<" "<<endl;
                a++;
                if(a>4){a=0;}
                break;
                case(1):///enter///
                    switch(a)
                    {
                        case(0):{
                         system("cls");
                         ListadoDeProductosPorTipo();
                         }
                        break;
                        case(1):
                        break;
                        case(2):
                        break;
                        case(3):
                        break;
                        case(4):{
                        bandera1=true;
                        }
                        break;
                    break;
        }
        }
        }while(bandera1==false);
}

