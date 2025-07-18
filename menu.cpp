#include <iostream>
#include "menu.h"
using namespace std;

    void Menu(){

        bool bandera=true;
        do{
        system("cls");
        TextoMenuPrincipal();
        rlutil::hidecursor();
            switch(SeleccionMenus(54,10,5)){
            case(0):{//////////////////////COMPRAR/////////////////////////////
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

            case(4):{//////////////////////CARGA UN REGISTO////////////////////
            CargarRegistros();
            system("cls");
            }
            break;

            case(5):///////////////////////SALIDA//////////////////////////////
            bandera=false;
            break;
            }
        }while(bandera==true);
    }

///----------------------------------------------------------------------------------------///

    void comprar(){

        bool ban=true;
        do{
        system("cls");
        TextoMenuCompra();
        switch(SeleccionMenus(57,11,2)){

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
            ban=false;
            }
            break;
            }
        }while(ban);
    }

///----------------------------------------------------------------------------------------///

    void Listado(){

        bool ban=true;
            do{
            system("cls");
            TextoMenuListado();
                switch(SeleccionMenus(49,10,4)){

                case(0):{///////////PRODUCTOS///////////
                    bool opcion;
                    cout << "Para listar por precio ingrese 1, para listar por stock ingrese 0: " << endl;
                    cin >>opcion;
                    ListadoDeProductos(opcion);
                    }
                    break;

                case(1):{///////////VENTAS//////////////
                    ListadoDeVentas();
                    }
                    break;

                case(2):{///////////CLIENTES////////////
                    ListadoDeClientes();
                    }
                    break;

                case(3):{///////////DETALLE DE VENTAS///
                    ListadoDetalleVentasPorNumeroDeVenta();
                        }
                    break;
                case(4):{
                    ban=false;
                        }
                    break;
                }
            }while(ban);
    }

///----------------------------------------------------------------------------------------///

    void Busqueda(){
        bool bandera1=true;
            do{
            system("cls");
            TextoMenuBusqueda();
                    switch(SeleccionMenus(49,10,3)){
                        case(0):{////////////////////////////PRODUCTO///////////////////////////
                            bool opcion;
                            cout << "Para buscar por Id de producto ingrese 1" << endl;
                            cout << "Para buscar rango de precio ingrese 0" << endl;
                            cout << "-->: ";
                            cin >> opcion;
                            BuscarProducto(opcion);
                        }
                        break;

                        case(1):{////////////////////////////CLIENTE////////////////////////////
                            BuscarCliente();
                        }
                        break;

                        case(2):{////////////////////////////VENTA//////////////////////////////
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
                        bandera1=false;
                        break;
                    }
            }while(bandera1);
    }

///----------------------------------------------------------------------------------------///

    void Informes(){
        bool bandera1=true;
            do{
            system("cls");
            TextoMenuInformes();
                switch(SeleccionMenus(43,10, 4)){
                    case(0):
                    break;
                    case(1):
                    break;
                    case(2):
                    break;
                    case(3):
                    break;
                    case(4):
                    bandera1=false;
                    break;
                }
        }while(bandera1);
    }

///----------------------------------------------------------------------------------------///

    void CargarRegistros(){
        bool bandera1=false;
        do{
            system("cls");
            TextoMenuCargarRegistro();
            switch(SeleccionMenus(45,10,4)){
                case(0):{/////////////guarda registro de cliente/////////////
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

                case(1):{/////////////guarda registro de venta///////////////
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

                case(2):{/////////////guarda registro de producto////////////
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

                case(3):{/////////////guarda registro detalle de venta///////
                DetalleVenta venDT;
                system("cls");
                rlutil::showcursor();
                CargarDetalleVenta(0, venDT);
                system("cls");
                rlutil::hidecursor();
                GuardarRegistroDetalleVenta(venDT, "DetalleVentas.dat");
                }
                break;

                case(4):///////////////Salida/////////////
                bandera1=true;
                break;
            }
        }while(bandera1==false);
}

///----------------------------------------------------------------------------------------///


void TextoMenuPrincipal(){
    Pilares();
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

void TextoMenuCompra(){
    Pilares();
///opciones de Compra///
rlutil::locate(58,11);
cout<<"Productos";
rlutil::locate(58,12);
cout<<"Carrito";
rlutil::locate(58,13);
cout<<"Volver";
}

void TextoMenuListado(){
    Pilares();
///opciones de listado///
rlutil::locate(50,10);
cout<<"Listado de Productos";
rlutil::locate(50,11);
cout<<"Listado de clientes";
rlutil::locate(50,12);
cout<<"Listado de ventas";
rlutil::locate(50,13);
cout<<"Listado detalle de venta";
rlutil::locate(50,14);
cout<<"Volver";
}

void TextoMenuBusqueda(){
    Pilares();
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

void TextoMenuInformes(){
    Pilares();
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

void TextoMenuCargarRegistro(){
    Pilares();
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

//void TextoMenulistadosMostrar(){
//    Pilares();
/////opciones de listado///
//rlutil::locate(46,10);
//cout<<"Mostrar Listado de producto";
//rlutil::locate(46,11);
//cout<<"Mostrar Listado de venta";
//rlutil::locate(46,12);
//cout<<"Mostrar Listado de cliente";
//rlutil::locate(46,13);
//cout<<"Mostrar Listado detalle de venta";
//rlutil::locate(46,14);
//cout<<"Volver";
//}

    void TextoTiposDeProducto(){

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

    void Pilares(){

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
    }

    int SeleccionMenus(int EjeX, int EjeY, int CantOpc){

        int y=0, tecla;
        bool ban=false;
        do{
            rlutil::locate(EjeX,EjeY+y);
            cout<<(char)175<<endl;
            tecla = rlutil::getkey();

            switch(tecla){

                case(14):///arriba///
                rlutil::locate(EjeX,EjeY+y);
                cout<<" "<<endl;
                y--;
                if(y<0){y=CantOpc;}
                break;

                case(15):///abajo///
                rlutil::locate(EjeX,EjeY+y);
                cout<<" "<<endl;
                y++;
                if(y>CantOpc){y=0;}
                break;

                case(1):///enter///
                    system("cls");
                    if(y==CantOpc){return CantOpc;}
                    return y;
                break;

                case(0):
                    system("cls");
                return CantOpc;
                break;
            }
        }while(!ban);
        system("cls");
        return 12;
    }


