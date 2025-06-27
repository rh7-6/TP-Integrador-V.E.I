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
//    bool seguir=true;

//    while(seguir){

    p.CargarProducto();
    archp.GuardarProducto(p);
//    cout << "continuar?(1=si,0=no): ";
//    cin >> seguir;
//    }

    system("pause");
    cout << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;

//    for(int i=0; i<=archp.CantidadRegistros(sizeof(Producto)); i++){

    Producto p1;
    p1=archp.LeerProducto(0);

    p1.MostrarProducto();
//    }


return 0;
}
