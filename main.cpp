#include <iostream>
#include "menu.h"
#include "Fecha.h"
#include "cadena.h"
#include "Producto.h"
#include "Clientes.h"
#include "Venta.h"
#include "Detalle_Venta.h"
#include "Archivo_Clientes.h"
#include "Archivo_Productos.h"
#include "Archivo_Ventas.h"
#include "rlutil.h"

using namespace std;

int main(){

int y=0, icono;
bool bandera=true;
///movimiento///
do{
menu();
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
       bool bandera1=false;
            int a=0;
        switch(y)
        {
            case(0)://////////////////////LISTADOS////////////////////////////
            system("cls");
            do{
            MenuListado();
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

            case(1)://////////////////////BUSQUEDA////////////////////////////
            system("cls");
            do{
            MenuBusquedad();
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
            MenuRegistro();
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
                    Cliente cl;
                    Venta ven;
                    Producto prod;
                    DetalleVenta vendet;
                    switch(a)
                    {
                        case(0):
                            system("cls");
                            rlutil::showcursor();
                            cl.CargarCliente();
                            system("cls");
////////////////////////////////////////////guarda registro de cliente/////////////////////////////////////////////////////////
                        break;
                        case(1):
                            system("cls");
                            rlutil::showcursor();
                            ven.CargarVenta();
                            system("cls");
////////////////////////////////////////////guarda registro de venta/////////////////////////////////////////////////////////
                        break;
                        case(2):
                            system("cls");
                            rlutil::showcursor();
                            prod.CargarProducto();
                            system("cls");
////////////////////////////////////////////guarda registro de producto/////////////////////////////////////////////////////////
                        break;
                        case(3):

                            system("cls");
                            rlutil::showcursor();
                            vendet.CargarDetalleVenta();
                            system("cls");
////////////////////////////////////////////guarda registro detalle de venta/////////////////////////////////////////////////////////
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

        case(4)://////////////////////////MOSTRAR REGISTROS///////////////////

            system("cls");
            do{
            MenuRegistroMostrar();
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

        case(5)://////////////////////////SALIDA//////////////////////////////
        bandera=false;
        break;

        }
        break;

    }


}while(bandera==true);




return 0;
}
