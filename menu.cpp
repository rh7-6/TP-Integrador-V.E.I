#include <iostream>
#include "menu.h"
using namespace std;

    void Menu(){

        bool bandera=true;
        do{
        system("cls");
        TextoMenuPrincipal();
            switch(SeleccionMenus(54,10,5,1)){
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
        vector<Producto> vecPrOrig;
        vector<Producto> vecPrMod;
        vector<Producto> vecPrSelec;
        do{
        system("cls");
        TextoMenuCompra();
        switch(SeleccionMenus(57,11,3,1)){

            case(0):{///////////PRODUCTOS/////////////
                bool banP=true;
                do{
                int tamVecPrMod=vecPrMod.size();
                if(tamVecPrMod==0){CopiarYOrdenarProductos(vecPrMod); vecPrOrig=vecPrMod;}

                if(MenuProductosCompra(vecPrMod,vecPrSelec)==-1){banP=false;}
                system("cls");
                }while(banP);
            }
            break;

            case(1):{///////////CARRITO//////////////
                MenuCarrito(vecPrSelec,vecPrOrig,vecPrMod);
                system("cls");
            }
            break;

            case(2):{///////////FINALIZAR/COMPRA///////////////
                GuardarVentaCarrito(vecPrSelec,vecPrOrig,ban);
            }
            break;
            case(3):{///////////SALIDA///////////////
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
                switch(SeleccionMenus(49,10,4,1)){

                case(0):{///////////PRODUCTOS///////////
                    bool opcion;
                    rlutil::locate(43,5);
                    cout << "Selecione el tipo de listado" << endl;
                    rlutil::locate(50,8);
                    cout<<"Listar por stock";
                    rlutil::locate(50,9);
                    cout<<"Listar por rango de precio";
                    opcion=SeleccionMenus(48,8,1,1);
                    ListadoDeProductos(opcion);
                    }
                    break;

                case(1):{///////////CLIENTES////////////
                    ListadoDeClientes();
                    }
                    break;

                case(2):{///////////VENTAS//////////////
                    ListadoDeVentas();
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
                    switch(SeleccionMenus(49,10,3,1)){
                        case(0):{////////////////////////////PRODUCTO///////////////////////////
                            bool opcion;
                            rlutil::locate(43,5);
                            cout<<"Para buscar rango de precio" << endl;
                            rlutil::locate(43,6);
                            cout<<"Para buscar por Id de producto" << endl;
                            opcion=SeleccionMenus(41,5,1,1);
                            BuscarProducto(opcion);
                        }
                        break;

                        case(1):{////////////////////////////CLIENTE////////////////////////////
                            BuscarCliente();
                        }
                        break;

                        case(2):{////////////////////////////VENTA//////////////////////////////
                            int opcion;
                            rlutil::locate(43,5);
                            cout << "Para buscar por numero de venta" << endl;
                            rlutil::locate(43,6);
                            cout << "Para buscar por CUIT" << endl;
                            rlutil::locate(43,7);
                            cout << "Para buscar por rango de fechas" << endl;
                            opcion=SeleccionMenus(41,5,2,1);
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
                switch(SeleccionMenus(43,10,4,1)){
                    case(0):
                        RecaudacionAnual();
                    break;
                    case(1):
                        RecaudacionCliente();
                    break;
                    case(2):
                        RecaudacionEquipo();
                    break;
                    case(3):
                        informetipocliente();
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
            switch(SeleccionMenus(52,10,4,1)){
                case(0):{/////////////Clientes/////////////
                    MenuRegistroCliente();
                }
                break;

                case(1):{/////////////Productos///////////////
                    MenuRegistroProducto();
                }
                break;

                case(2):{/////////////Ventas////////////
                    MenuRegistroVentas();
                }
                break;

                case(3):{/////////////Detalles de venta///////
                DetalleVenta DT;
                if(CargarDetalleVenta(DT,0,0,0,false)){GuardarRegistroDetalleVenta(DT,true);};
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
    Pilares2();
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
cout<<"REGISTROS";
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
cout<<"Finalizar Compra";
rlutil::locate(58,14);
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
rlutil::locate(54,10);
cout<<"Cliente";
rlutil::locate(54,11);
cout<<"Producto";
rlutil::locate(54,12);
cout<<"Venta";
rlutil::locate(54,13);
cout<<"Detalle de venta";
rlutil::locate(54,14);
cout<<"Volver";
}

    void TextoTiposDeProducto(){

        rlutil::locate(57,8);
        cout << "Equipos" << endl;
        rlutil::locate(57,9);
        cout << "Notebooks" << endl;
        rlutil::locate(57,10);
        cout << "Procesadores" << endl;
        rlutil::locate(57,11);
        cout << "Mothers" << endl;
        rlutil::locate(57,12);
        cout << "Placas de video" << endl;
        rlutil::locate(57,13);
        cout << "Memorias RAM" << endl;
        rlutil::locate(57,14);
        cout << "Gabinetes" << endl;
        rlutil::locate(57,15);
        cout << "Fuentes" << endl;
        rlutil::locate(57,16);
        cout << "Almacenamiento" << endl;
        rlutil::locate(57,17);
        cout << "Perifericos" << endl;
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

    void Pilares2(){
        ///columna superior///
        for(int i=0;i<40;i++){rlutil::locate(41+i,8);cout<<(char)196;}

        ///pilar izquierdo///
        rlutil::locate(40,8);cout<<(char)218;
        for(int i=0;i<9;i++){rlutil::locate(40,9+i);cout<<(char)179;}
        rlutil::locate(40,18);cout<<(char)192;

        ///pilar derecho///
        rlutil::locate(81,8);cout<<(char)191;
        for(int i=0;i<9;i++){rlutil::locate(81,9+i);cout<<(char)179;}
        rlutil::locate(81,18);cout<<(char)217;

        ///columna inferior///
        for(int i=0;i<40;i++){rlutil::locate(41+i,18);cout<<(char)196;}
    }

    int SeleccionMenus(int EjeX, int EjeY, int CantOpc, int SaltosDeLinea){

        rlutil::hidecursor();
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
                    y=y-SaltosDeLinea;
                    if(y<0){y=CantOpc*SaltosDeLinea;}
                break;

                case(15):///abajo///
                    rlutil::locate(EjeX,EjeY+y);
                    cout<<" "<<endl;
                    y=y+SaltosDeLinea;
                    if(y>CantOpc*SaltosDeLinea){y=0;}
                break;

                case(1):///enter///
                    system("cls");
                    if(y==CantOpc*SaltosDeLinea){return CantOpc;}
                    return y/SaltosDeLinea;
                break;

                case(0):///caracter nulo///(deberia ser 27 para el escape pero me lo toma como 0)
                    system("cls");
                    return CantOpc;
                break;
            }
        }while(!ban);
        system("cls");
        rlutil::showcursor();
        return -1;
    }

    int SeleccionCantidad(int ejeX, int ejeY, int Max, int Min){

        rlutil::hidecursor();
        int cant=Min, tecla;
        bool ban=true;
        rlutil::locate(ejeX,ejeY);
        cout << "^";
        rlutil::locate(ejeX,ejeY+1);
        cout << "v";
        do{

            if(cant<10){rlutil::locate(ejeX+2,ejeY);cout<<" ";}
            rlutil::locate(ejeX+1,ejeY);
            cout << cant;
            tecla = rlutil::getkey();

            switch(tecla){

            case(14):///mas///
               cant++;
               if(cant>Max){cant=Max;}
               break;
            case(15):///menos///
               cant--;
               if(cant<Min){cant=Min;cant=Min;}
               break;
            case(1):///enter///
                system("cls");
                return cant;
            case(0):
                system("cls");
                return 0;
            }
        }while(ban);
        rlutil::showcursor();
        return -1;
    }

