#include <iostream>
#include "menu.h"
using namespace std;

    void Menu(){

        bool bandera=true;
        do{
        system("cls");
        Cadena opciones[6];
        TextoMenuPrincipal(opciones);
            switch(SeleccionMenuAnim(opciones,54,12,5,2,6,rlutil::GREY,rlutil::WHITE,rlutil::WHITE,rlutil::BLACK,rlutil::WHITE)){
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
        switch(SeleccionMenuAnim(opciones,54,12,3,2,6,rlutil::GREY,rlutil::WHITE,rlutil::WHITE,rlutil::BLACK,rlutil::WHITE)){

            case(0):{///////////PRODUCTOS/////////////
                bool banP=true;
                do{
                int tamVecPrMod=vecPrMod.size();
                if(tamVecPrMod==0){
                    Cadena Opc[10]; TextoTiposDeProducto2(Opc);
                    int TpPr=SeleccionMenuAnim(Opc,54,12,9,1,4,8,15,15,0,15)+1;
                    CopiarYOrdenarProductos(vecPrMod,TpPr,1); vecPrOrig=vecPrMod;}

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
                GuardarVentaCarrito(vecPrSelec,vecPrOrig,vecPrMod,ban);
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
                switch(SeleccionMenuAnim(opciones,54,12,4,2,6,rlutil::GREY,rlutil::WHITE,rlutil::WHITE,rlutil::BLACK,rlutil::WHITE)){

                case(0):{///////////PRODUCTOS///////////
                    bool opcion;
                    rlutil::locate(43,5);
                    cout<<"Selecione el tipo de listado" << endl;
                    rlutil::locate(50,8);
                    cout<<"Listar por stock";
                    rlutil::locate(50,9);
                    cout<<"Listar por precio";
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
                    switch(SeleccionMenuAnim(opciones,54,12,3,2,6,rlutil::GREY,rlutil::WHITE,rlutil::WHITE,rlutil::BLACK,rlutil::WHITE)){
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
                switch(SeleccionMenuAnim(opciones,54,12,4,2,6,rlutil::GREY,rlutil::WHITE,rlutil::WHITE,rlutil::BLACK,rlutil::WHITE)){
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
            switch(SeleccionMenuAnim(opciones,54,12,4,2,6,rlutil::GREY,rlutil::WHITE,rlutil::WHITE,rlutil::BLACK,rlutil::WHITE)){
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
        opciones[0].setTexto("C O M P R A");
        opciones[1].setTexto("L I S T A D O S");
        opciones[2].setTexto("B U S Q U E D A S");
        opciones[3].setTexto("I N F O R M E S");
        opciones[4].setTexto("R E G I S T R O S");
        opciones[5].setTexto("S A L I R");
    }

    void TextoMenuCompra(Cadena *opciones){
        ///opciones de Compra///
        opciones[0].setTexto("P r o d u c t o s");
        opciones[1].setTexto("C a r r i t o");
        opciones[2].setTexto("F i n a l i z a r | C o m p r a");
        opciones[3].setTexto("V o l v e r");
    }

    void TextoMenuListado(Cadena *opciones){
        ///opciones de listado///
        opciones[0].setTexto("L i s t a d o | P r o d u c t o s");
        opciones[1].setTexto("L i s t a d o | C l i e n t e s");
        opciones[2].setTexto("L i s t a d o | V e n t a s");
        opciones[3].setTexto("L i s t a d o | D e t a l l e s | V e n t a");
        opciones[4].setTexto("V o l v e r");
    }

    void TextoMenuBusqueda(Cadena *opciones){
        ///opciones de listado///
        opciones[0].setTexto("B u s q u e d a | P r o d u c t o");
        opciones[1].setTexto("B u s q u e d a | C l i e n t e");
        opciones[2].setTexto("B u s q u e d a | V e n t a");
        opciones[3].setTexto("V o l v e r");
    }

    void TextoMenuInformes(Cadena *opciones){
        ///opciones de listado///
        opciones[0].setTexto("R e c a u d o | A n u a l");
        opciones[1].setTexto("R e c a u d o | C l i e n t e");
        opciones[2].setTexto("R e c a u d o | T i p o | E q u i p o");
        opciones[3].setTexto("U n i d a d e s | T i p o | C l i e n t e");
        opciones[4].setTexto("V o l v e r");
    }

    void TextoMenuCargarRegistro(Cadena *opciones){
        ///opciones de listado///
        opciones[0].setTexto("C l i e n t e");
        opciones[1].setTexto("P r o d u c t o");
        opciones[2].setTexto("V e n t a");
        opciones[3].setTexto("D e t a l l  e | V e n t a ");
        opciones[4].setTexto("V o l v e r");
    }

    void TextoTiposDeProducto(){
        rlutil::locate(57,8); cout << "Equipos" << endl;
        rlutil::locate(57,9); cout << "Notebooks" << endl;
        rlutil::locate(57,10); cout << "Procesadores" << endl;
        rlutil::locate(57,11); cout << "Mothers" << endl;
        rlutil::locate(57,12); cout << "Placas de video" << endl;
        rlutil::locate(57,13); cout << "Memorias RAM" << endl;
        rlutil::locate(57,14); cout << "Gabinetes" << endl;
        rlutil::locate(57,15); cout << "Fuentes" << endl;
        rlutil::locate(57,16); cout << "Almacenamiento" << endl;
        rlutil::locate(57,17); cout << "Perifericos" << endl;
    }

    void TextoTiposDeProducto2(Cadena *opciones){

        opciones[0].setTexto("Equipos");
        opciones[1].setTexto("Notebooks");
        opciones[2].setTexto("Procesadores");
        opciones[3].setTexto("Mothers");
        opciones[4].setTexto("Placas de Video");
        opciones[5].setTexto("Memorias RAM");
        opciones[6].setTexto("Gabinetes");
        opciones[7].setTexto("Fuentes");
        opciones[8].setTexto("Almacenamiento");
        opciones[9].setTexto("Perifericos");
    }

    void TxtEditProducto(Cadena *opciones){

        opciones[0].setTexto("Nombre");
        opciones[1].setTexto("Precio");
        opciones[2].setTexto("Descripcion");
        opciones[3].setTexto("Marca");
        opciones[4].setTexto("Tipo de Producto");
        opciones[5].setTexto("Stock");
        opciones[6].setTexto("Estado");
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

    void SeleccionYAnimFlecha(int EjeX1, int EjeY1, int &tecla, int EjeX2, int EjeY2, int ClFlch){
        rlutil::setColor(ClFlch);
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
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(EjeX1,EjeY2);
        cout<<"  "<<endl;
        rlutil::locate(EjeX2,EjeY2);
        cout<<"  "<<endl;
    }

    int SeleccionMenuAnim(Cadena *opciones,int EjeX, int EjeY, int CantOpc, int SaltosDeLinea, int TamCj, int ClRell, int ClExtr, int ClRslt, int ClLtr, int ClFlch){
        rlutil::hidecursor();
        int y=0, tecla, maxCarctrs;

        for(int i=0; i<=CantOpc; i++){
            if(i==0){maxCarctrs=strlen(opciones[0].getTexto());}else{
                    int TamTxtActual=strlen(opciones[i].getTexto());
                if(TamTxtActual>maxCarctrs){maxCarctrs=TamTxtActual;}
            }
        }
        DibujarCaja(EjeX-(TamCj*2),EjeY-(TamCj-1),maxCarctrs+((TamCj*4)-1),CantOpc*SaltosDeLinea+((TamCj-1)*2),ClRell,ClExtr);
        int mtdCj=(maxCarctrs)/2;

        do{
            for(int i=0; i<=CantOpc; i++){
                    int CantTxt=strlen(opciones[i].getTexto())/2;
                MostrYRsaltTxt(opciones[i].getTexto(),(EjeX+mtdCj)-CantTxt,EjeY+(i*SaltosDeLinea),y/SaltosDeLinea==i,ClRslt,ClLtr,ClRell);
            }

            int tamTxtAct=strlen(opciones[y/SaltosDeLinea].getTexto());
                int ClcPosX=(EjeX+mtdCj)-tamTxtAct/2;
                SeleccionYAnimFlecha(ClcPosX-2,EjeY+y,tecla,ClcPosX+tamTxtAct,EjeY+y,ClFlch);

            switch(tecla){

                case(72):///arriba///
                    y=y-SaltosDeLinea;
                    if(y<0){y=CantOpc*SaltosDeLinea;}
                break;

                case(80):///abajo///
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
                    return CantOpc;
                break;
            }
        }while(1);
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

