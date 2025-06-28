#include <iostream>
#include <limits>
#include "Producto.h"
#include "Archivo_Productos.h"
#include "menu.h"


using namespace std;

int main(){

    //Menu();

    ArchivoProductos archp("Productos.dat");
    Producto p;
    bool seguir=true;

    while(seguir){

        p.CargarProducto();
        archp.GuardarProducto(p);
        cout << "continuar?(1=si,0=no): ";
        cin >> seguir;
    }

    cout << "cantidad de registros: " << archp.CantidadRegistros(sizeof(Producto))<< endl;
    system("pause");
    cout << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;


        Producto p1;
        int pos=0;
    while(archp.LeerProducto(pos,p1)){

        p1.MostrarProducto();
        pos++;
    }


return 0;
}
