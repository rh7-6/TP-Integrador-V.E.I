#include <iostream>
#include <string>
#include "Producto.h"
#include "Clientes.h"
#include "Venta.h"
#include "Detalle_Venta.h"
///libreria grafica///
#include "rlutil.h"

using namespace std;

int main()
{
int y=0, icono;
bool bandera=true;

///columna superior///borrar corchetes {}
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

///test///
rlutil::locate(53,10);
cout<<"Cargar registro";
rlutil::locate(53,11);
cout<<"Mostrar registro";
rlutil::locate(53,12);
cout<<"Editar registro";
rlutil::locate(53,13);
cout<<"Salir";

///opciones///
do{
rlutil::hidecursor();
rlutil::locate(51,10+y);
cout<<(char)175<<endl;
icono = rlutil::getkey();
switch (icono){
    case(14):///arriba///
    rlutil::locate(51,10+y);
    cout<<" "<<endl;
    y--;
    if(y<0){y=3;}
    break;
    case(15):///abajo///
    rlutil::locate(51,10+y);
    cout<<" "<<endl;
    y++;
    if(y>3){y=0;}
    break;
    ///rlutil::showcursor(); hace aparecer el cursor///
    case(1):///enter///

        switch(y)
        {
        case(0):
        break;
        case(1):
        break;
        case(2):
        break;
        case(3):
            bandera=false;
        break;
        }

    break;

    }


}while(bandera==true);


    return 0;
}
