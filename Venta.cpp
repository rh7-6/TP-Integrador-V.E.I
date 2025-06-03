#include <iostream>
#include "Venta.h"
#include "cadena.h"
#include "Fecha.h"

using namespace std;


    bool Venta::SetNumeroVenta(int id){

        if(id > 0 ){
            _NumeroVenta=id;
        }

    }

    void Venta::SetCuit(const char *t){

        _Cuit.setTexto(t);

    }

    void Venta::SetFechaVenta(Fecha f){

        _FechaVenta=f;

    }

    bool Venta::SetImporteVenta(float v){

        if(v>0){
            _ImporteVenta=v;
            return true;
        }else{
            return false;
        }

    }

///--------------------------------------------------------------------------------------------------

    int Venta::GetNumeroVenta(){

        return _NumeroVenta;

    }

    const char *Venta::GetCuit(){

        return _Cuit.getTexto();

    }

    Fecha Venta::GetFechaVenta(){

        return _FechaVenta;

    }

    float Venta::GetImporteVenta(){

        return _ImporteVenta;

    }
