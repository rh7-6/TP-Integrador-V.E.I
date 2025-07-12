#include <iostream>
#include "Detalle_Venta.h"
using namespace std;

    void DetalleVenta::SetNumeroVentaDT(int n){

        _NumeroVenta=n;

    }

    int DetalleVenta::SetPrecioProductoDT(float p){

                if(p>99)
                {
                _PrecioProducto=p;
                return 1;
                }
                else
                {
                return 0;
                }
                }

    void DetalleVenta::SetIdProductoDT(int n){

        _IdProducto=n;

    }

    int DetalleVenta::SetCantidad(int n){
   if(n>0)
                {
                _Cantidad=n;
                return 1;
                }
                else
                {
                return 0;
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
