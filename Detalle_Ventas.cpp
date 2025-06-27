#include <iostream>
#include "Detalle_Venta.h"
using namespace std;

    void DetalleVenta::SetNumeroVentaDT(int n){

        _NumeroVenta=n;

    }

    void DetalleVenta::SetPrecioProductoDT(float p){

                _PrecioProducto=p;
    }

    void DetalleVenta::SetIdProductoDT(int n){

        _IdProducto=n;

    }

    void DetalleVenta::SetCantidad(int n){
    bool a=false;
        while(a==false)
        {
            if(n>=0)
            {
                _Cantidad=n;
                a=true;
            }
            else
            {
                cout<<"ingerese una cantidad mayo a o igual a 0: ";
                cin>>n;
                cout<<endl;
                a=false;
            }
        }
    }

///--------------------------------------------------------------------------------------------------

    int DetalleVenta::GetNumeroVentaDT(){

        return _NumeroVenta;

    }

    float DetalleVenta::GetPrecioProducto(){

        return _PrecioProducto;

    }

    int DetalleVenta::GetIdProductoDT(){

        return _IdProducto;

    }

    int DetalleVenta::GetCantidad(){

        return _Cantidad;

    }

    DetalleVenta::DetalleVenta(){}
    DetalleVenta::DetalleVenta(int numeroVenta, float precioProducto, int idProducto, int cantidad){

        _NumeroVenta=numeroVenta;
        _PrecioProducto=precioProducto;
        _IdProducto=idProducto;
        _Cantidad=cantidad;
    }

///--------------------------------------------------------------------------------------------------

void DetalleVenta::CargarDetalleVenta(){

int numeroventa, idproducto, cantidad;
float precio;

cout<<"ingrese un numero de venta: ";
cin>>numeroventa;
cout<<endl;
SetNumeroVentaDT(numeroventa);
cout<<"ingrese un precio mayor o igual a 1 : $";
cin>>precio;
cout<<endl;
SetPrecioProductoDT(precio);
cout<<"ingrese el nuemro de id del producto: ";
cin>>idproducto;
cout<<endl;
SetIdProductoDT(idproducto);
cout<<"ingrese la cantidad de productos vendidos: ";
cin>>cantidad;
cout<<endl;
SetCantidad(cantidad);
}


void DetalleVenta::MotrarDetalleVenta(){
cout<<"El numero de venta es: "<<GetNumeroVentaDT()<<endl;
cout<<"El precio de la venta fue de: $"<<GetPrecioProducto()<<endl;
cout<<"El numero de id del producto es: "<<GetIdProductoDT()<<endl;
cout<<"La cantidad de productos comprados: "<<GetCantidad()<<endl;

}
