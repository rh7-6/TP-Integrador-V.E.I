#include <iostream>
#include "menu.h"
using namespace std;

void Menu(){

int y=0, icono;
bool bandera=true;


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
    if(y<0){y=5;}
    break;
    case(15):///abajo///
    rlutil::locate(54,10+y);
    cout<<" "<<endl;
    y++;
    if(y>5){y=0;}
    break;
    ///rlutil::showcursor(); hace aparecer el cursor///
    case(1):///enter///
       switch(y)
        {
            case(0):{///////////////////////COMPRAR/////////////////////////////
              comprar();
            }
            break;

            case(1):{//////////////////////LISTADOS////////////////////////////
            Listado();
            system("cls");
            }
            break;

            case(2):{//////////////////////BUSQUEDA////////////////////////////
            Busqueda();
            system("cls");
            }
            break;

            case(3):{//////////////////////INFORMES////////////////////////////
            Informes();
            system("cls");
            }
            break;

            case(4):{//////////////////////////CARGA UN REGISTO////////////////////
            CargarRegistros();
            system("cls");
            }
            break;

            case(5)://////////////////////////SALIDA//////////////////////////////
            bandera=false;
            break;

        }
        break;

    }


}while(bandera==true);

    }

    void comprar(){
int a=0, icono;
bool bandera1=false;
system("cls");
            do{
            MenuCompra();
            rlutil::locate(56,11+a);
            cout<<(char)175<<endl;
            icono = rlutil::getkey();
            switch (icono){
                case(14):///arriba///
                rlutil::locate(56,11+a);
                cout<<" "<<endl;
                a--;
                if(a<0){a=2;}
                break;
                case(15):///abajo///
                rlutil::locate(56,11+a);
                cout<<" "<<endl;
                a++;
                if(a>2){a=0;}
                break;
                case(1):///enter///
                    switch(a)
                    {
                        case(0):{
                             cout<<"PRODUCTOS";
                             system("pause");
                             system("cls");
                         }
                        break;

                        case(1):{
                            cout<<"Carrito";
                            system("pause");
                            system("cls");
                        }
                        break;

                        case(2):{
                        bandera1=true;
                        }
                        break;
                    break;
        }
        }
    }while(bandera1==false);
    system("cls");
}

void Listado(){
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
////////////////////////////////////////////PRODUCTOS/////////////////////////////////////////////////////////
                        case(0):{
                            bool opcion;
                            cout << "Para listar por precio ingrese 1, para listar por stock ingrese 0: " << endl;
                            cin >>opcion;
                            ListadoDeProductos(opcion);
                         }
                        break;
////////////////////////////////////////////VENTAS/////////////////////////////////////////////////////////
                        case(1):{
                            ListadoDeVentas();
                        }
                        break;
////////////////////////////////////////////CLIENTES/////////////////////////////////////////////////////////
                        case(2):{
                            ListadoDeClientes();
                        }
                        break;
////////////////////////////////////////////DETALLE DE VENTAS/////////////////////////////////////////////////////////
                        case(3):{
                            ListadoDetalleVentasPorNumeroDeVenta();
                        }
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

void Busqueda(){
system("cls");
int a=0, icono;
bool bandera1=false;
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
////////////////////////////////////////////PRODUCTO/////////////////////////////////////////////////////////
                        case(0):{
                            bool opcion;
                            cout << "Para buscar por Id de producto ingrese 1" << endl;
                            cout << "Para buscar rango de precio ingrese 0" << endl;
                            cout << "-->: ";
                            cin >> opcion;
                            BuscarProducto(opcion);
                        }
                        break;
////////////////////////////////////////////CLIENTE/////////////////////////////////////////////////////////
                        case(1):{
                            BuscarCliente();
                        }
                        break;
////////////////////////////////////////////VENTA////////////////////////////////////////////////////////
                        case(2):{
                            int opcion;
                            cout << "Para buscar por numero de venta ingrese 0" << endl;
                            cout << "Para buscar por rango CUIT ingrese 1" << endl;
                            cout << "Para buscar por rango de fechas ingrese 2" << endl;
                            cout << "-->: ";
                            cin >> opcion;
                            BuscarVenta(opcion);
                        }
                        break;
                        case(3):
                        bandera1=true;
                        break;
        break;

        }
        }
        }while(bandera1==false);
}

void Informes(){
system("cls");
int a=0, icono;
bool bandera1=false;
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
}

void CargarRegistros(){
system("cls");
int a=0, icono;
bool bandera1=false;
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

////////////////////////////////////////////guarda registro de cliente/////////////////////////////////////////////////////////

                        case(0):{

                            Cliente cl;
                            system("cls");

                            rlutil::showcursor();
                            if(CargarCliente(cl)==1){
                            GuardarRegistroCliente(cl, 1);
                            }
                            system("cls");
                            rlutil::hidecursor();
                            //cin.ignore(numeric_limits<streamsize>::max(), '\n');//por que?

                        }
                        break;

////////////////////////////////////////////guarda registro de venta/////////////////////////////////////////////////////////

                        case(1):{
                            Venta v;
                            Cliente cl;
                            system("cls");
                            rlutil::showcursor();

                            if(CargarCliente(cl)==1){
                            GuardarRegistroCliente(cl, 0);
                            }

                            CargarVenta(v, cl.GetCuit(), 0);
                            GuardarRegistroVenta(v, "Ventas.dat");

                            system("cls");
                            rlutil::hidecursor();
                        }
                        break;

////////////////////////////////////////////guarda registro de producto/////////////////////////////////////////////////////////

                        case(2):{
                            Producto p;
                            system("cls");

                            rlutil::showcursor();
                            if(CargarProducto(p)==1){
                            GuardarRegistroProducto(p);
                            }

                            system("cls");
                            rlutil::hidecursor();
                        }
                        break;

////////////////////////////////////////////guarda registro detalle de venta/////////////////////////////////////////////////////////

                        case(3):{
                            DetalleVenta venDT;
                            system("cls");
                            rlutil::showcursor();
                            CargarDetalleVenta(0, venDT);
                            system("cls");
                            rlutil::hidecursor();
                            GuardarRegistroDetalleVenta(venDT, "DetalleVentas.dat");
                        }
                        break;

/////////////////////////////////////////////////Salida//////////////////////////////////////////////////////////////////////

                        case(4):
                        bandera1=true;
                        break;

        break;
        }
        }
        }while(bandera1==false);
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
cout<<"COMPRA";
rlutil::locate(55,11);
cout<<"LISTADOS";
rlutil::locate(55,12);
cout<<"BUSQUEDAS";
rlutil::locate(55,13);
cout<<"INFORMES";
rlutil::locate(55,14);
cout<<"CARGAR UN REGISTO";
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
cout<<"Busqueda de producto";
rlutil::locate(50,11);
cout<<"Busqueda de cliente";
rlutil::locate(50,12);
cout<<"Busqueda de venta";
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

void MenuCompra(){
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
///opciones de Compra///
rlutil::locate(58,11);
cout<<"Productos";
rlutil::locate(58,12);
cout<<"Carrito";
rlutil::locate(58,13);
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




