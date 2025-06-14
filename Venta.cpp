#include <iostream>
#include "Venta.h"
#include "cadena.h"
#include "Fecha.h"

using namespace std;


    void Venta::SetNumeroVenta(int id){
        while(id>0)
        {
            if(id>0)
            {
                _NumeroVenta=id;
            }
            else
            {
            cout<<"el numero de venta tiene que ser igual a 0 o mayor: ";
            cin>>id;
            cout<<endl;
            }
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

///--------------------------------------------------------------------------------------------------


void Venta::CargarVenta(){

int venta;
char cuit[20];

cout<<"ingrese numero de venta tiene que ser igual a 0 o mayor: ";
cin>>venta;
SetNumeroVenta(venta);
cout<<endl;
cout<<"ingrese el cuil de venta: ";
cin>>cuit;
SetCuit(cuit);
cout<<endl;


}


