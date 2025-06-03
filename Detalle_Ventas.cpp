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

    bool DetalleVenta::SetCantidad(int n){

        if(n>0){
            _Cantidad=n;
            return true;
        }else{
            return false;
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

