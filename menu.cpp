#include <iostream>
#include "menu.h"
using namespace std;

    void Menu(){

        bool bandera=true;
        do{
        system("cls");
        Cadena opciones[6];
        TextoMenuPrincipal(opciones);
            switch(SeleccionMenuAnim(opciones,54,12,5,1)){
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
        Cadena opciones[4];
        TextoMenuCompra(opciones);
        switch(SeleccionMenuAnim(opciones,54,12,3,1)){

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
            Cadena opciones[5];
            TextoMenuListado(opciones);
                switch(SeleccionMenuAnim(opciones,54,12,4,1)){

                case(0):{///////////PRODUCTOS///////////
                    bool opcion;
                    rlutil::locate(43,5);
                    cout<<"Selecione el tipo de listado" << endl;
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
            Cadena opciones[4];
            TextoMenuBusqueda(opciones);
                    switch(SeleccionMenuAnim(opciones,54,12,3,1)){
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
            Cadena opciones[5];
            TextoMenuInformes(opciones);
                switch(SeleccionMenuAnim(opciones,54,12,4,1)){
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
            Cadena opciones[5];
            TextoMenuCargarRegistro(opciones);
            switch(SeleccionMenuAnim(opciones,54,12,4,1)){
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


    void TextoMenuPrincipal(Cadena *opciones){
        ///opciones///
        opciones[0].setTexto("COMPRA");
        opciones[1].setTexto("LISTADOS");
        opciones[2].setTexto("BUSQUEDAS");
        opciones[3].setTexto("INFORMES");
        opciones[4].setTexto("REGISTROS");
        opciones[5].setTexto("SALIR");
    }

    void TextoMenuCompra(Cadena *opciones){
        ///opciones de Compra///
        opciones[0].setTexto("Productos");
        opciones[1].setTexto("Carrito");
        opciones[2].setTexto("Finalizar Compra");
        opciones[3].setTexto("Volver");
    }

    void TextoMenuListado(Cadena *opciones){
        ///opciones de listado///
        opciones[0].setTexto("Listado de Productos");
        opciones[1].setTexto("Listado de Clientes");
        opciones[2].setTexto("Listado de Ventas");
        opciones[3].setTexto("Listado Detalles de venta");
        opciones[4].setTexto("Volver");
    }

    void TextoMenuBusqueda(Cadena *opciones){
        ///opciones de listado///
        opciones[0].setTexto("Busqueda de Producto");
        opciones[1].setTexto("Busqueda de Cliente");
        opciones[2].setTexto("Busqueda de Venta");
        opciones[3].setTexto("Volver");
    }

    void TextoMenuInformes(Cadena *opciones){
        ///opciones de listado///
        opciones[0].setTexto("Recaudacion anual");
        opciones[1].setTexto("Recaudacion por cliente");
        opciones[2].setTexto("Recaudacion por tipo de equipo");
        opciones[3].setTexto("Equipos vendidos por tipo de cliente");
        opciones[4].setTexto("Volver");
    }

    void TextoMenuCargarRegistro(Cadena *opciones){
        ///opciones de listado///
        opciones[0].setTexto("Cliente");
        opciones[1].setTexto("Producto");
        opciones[2].setTexto("Venta");
        opciones[3].setTexto("Detalle de venta");
        opciones[4].setTexto("Volver");
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

    void DibujarCaja(int EjX, int EjY, int TamH, int TamV, int ClRelln, int ClExtr){

        for(int Y=1;Y<TamV;Y++){
            for(int H=1;H<TamH;H++){
                rlutil::setBackgroundColor(ClRelln);
                rlutil::locate(EjX+H,EjY+Y);
                cout<<" ";
            }
        }
        rlutil::setBackgroundColor(ClExtr);
        rlutil::setColor(rlutil::BLACK);
        ///Primera Linea Vertical///
        rlutil::locate(EjX,EjY);cout<<(char)218;
        for(int i=1;i<=TamV;i++){rlutil::locate(EjX,EjY+i);cout<<(char)179;
        if(i==TamV){rlutil::locate(EjX,EjY+i);cout<<(char)192;}}

        ///Primera Linea Horizontal///
        for(int a=1;a<=TamH;a++){rlutil::locate(EjX+a,EjY);cout<<(char)196;}

        ///Segunda Linea Vertical///
        rlutil::locate(EjX+TamH,EjY);cout<<(char)191;
        for(int b=1;b<=TamV;b++){rlutil::locate(EjX+TamH,EjY+b);cout<<(char)179;
        if(b==TamV){rlutil::locate(EjX+TamH,EjY+b);cout<<(char)217;}
        }
        ///Segunda Linea Horizontal///
        for(int c=1;c<TamH;c++){rlutil::locate(EjX+c,EjY+TamV);cout<<(char)196;}

        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::setColor(rlutil::WHITE);
    }

    void MostrYRsaltTxt(const char *txt, int EjeX, int EjeY,bool selec, int ClRslt, int ClLtr, int ClFnd){
        if(selec){
            rlutil::setBackgroundColor(ClRslt);
            rlutil::setColor(ClLtr);
        }else{rlutil::setBackgroundColor(ClFnd);rlutil::setColor(ClLtr);}
        rlutil::locate(EjeX,EjeY);
        cout<<txt<<endl;
        rlutil::setBackgroundColor(ClFnd);
    }

    void SeleccionYAnimFlecha(int EjeX1, int EjeY1, int &tecla, int EjeX2, int EjeY2){ //, int EjeX2, int EjeY2
        while(1){
                if(kbhit()){tecla=getch();break;};
                rlutil::locate(EjeX1,EjeY1);cout<<" "<<char(175);
                rlutil::locate(EjeX2,EjeY2);cout<<char(174)<<" ";
                if(kbhit()){tecla=getch();break;};rlutil::msleep(50);
                if(kbhit()){tecla=getch();break;};rlutil::msleep(50);
                if(kbhit()){tecla=getch();break;};rlutil::msleep(50);
                if(kbhit()){tecla=getch();break;};rlutil::msleep(50);
                if(kbhit()){tecla=getch();break;};rlutil::msleep(50);
                if(kbhit()){tecla=getch();break;};rlutil::msleep(50);
                if(kbhit()){tecla=getch();break;};
                rlutil::locate(EjeX1,EjeY1);cout<<char(175)<<" ";
                rlutil::locate(EjeX2,EjeY2);cout<<" "<<char(174);
                if(kbhit()){tecla=getch();break;};rlutil::msleep(50);
                if(kbhit()){tecla=getch();break;};rlutil::msleep(50);
                if(kbhit()){tecla=getch();break;};rlutil::msleep(50);
                if(kbhit()){tecla=getch();break;};rlutil::msleep(50);
                if(kbhit()){tecla=getch();break;};rlutil::msleep(50);
                if(kbhit()){tecla=getch();break;};rlutil::msleep(50);
                if(kbhit()){tecla=getch();break;};
            }
    }

    int SeleccionMenuAnim(Cadena *opciones,int EjeX, int EjeY, int CantOpc, int SaltosDeLinea){
        rlutil::hidecursor();
        int y=0, tecla, maxCarctrs;
        for(int i=0; i<=CantOpc; i++){
            if(i==0){maxCarctrs=strlen(opciones[0].getTexto());}else{
                if((strlen(opciones[i].getTexto()))>maxCarctrs){maxCarctrs=strlen(opciones[i].getTexto());}
            }
        }
        DibujarCaja(EjeX-8,EjeY-3,maxCarctrs+15,CantOpc*SaltosDeLinea+6,rlutil::DARKGREY,rlutil::WHITE);
        do{
            for(int i=0; i<=CantOpc; i++){
                MostrYRsaltTxt(opciones[i].getTexto(),EjeX,EjeY+(i*SaltosDeLinea),y/SaltosDeLinea==i,rlutil::GREY,rlutil::BLACK,rlutil::DARKGREY);
            }
            SeleccionYAnimFlecha(EjeX-2,EjeY+y,tecla,EjeX+strlen(opciones[y/SaltosDeLinea].getTexto()),EjeY+y);
            switch(tecla){

                case(72):///arriba///
                    rlutil::locate(EjeX-2,EjeY+y);
                    cout<<"  "<<endl;
                    rlutil::locate(EjeX+strlen(opciones[y/SaltosDeLinea].getTexto()),EjeY+y);
                    cout<<"  "<<endl;
                    y=y-SaltosDeLinea;
                    if(y<0){y=CantOpc*SaltosDeLinea;}
                break;

                case(80):///abajo///
                    rlutil::locate(EjeX-2,EjeY+y);
                    cout<<"  "<<endl;
                    rlutil::locate(EjeX+strlen(opciones[y/SaltosDeLinea].getTexto()),EjeY+y);
                    cout<<"  "<<endl;
                    y=y+SaltosDeLinea;
                    if(y>CantOpc*SaltosDeLinea){y=0;}
                break;

                case(13):///enter///
                    rlutil::setColor(rlutil::WHITE);
                    rlutil::setBackgroundColor(rlutil::BLACK);
                    system("cls");
                    if(y==CantOpc*SaltosDeLinea){return CantOpc;}
                    return y/SaltosDeLinea;
                break;

                case(27):
                    rlutil::setColor(rlutil::WHITE);
                    rlutil::setBackgroundColor(rlutil::BLACK);
                    system("cls");
                    return CantOpc*SaltosDeLinea;
                break;
            }
        }while(1);
        system("cls");
        rlutil::showcursor();
        return 0;
    }

    int SeleccionCantidad(int ejeX, int ejeY, int Max, int Min){
        rlutil::hidecursor();
        int cant=Min, tecla;
        bool ban=true;
        rlutil::locate(ejeX,ejeY);
        cout << char(24);
        rlutil::locate(ejeX,ejeY+1);
        cout << char(25);
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

