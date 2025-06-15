#include <iostream>
#include <limits>
#include "cstring"
#include "Venta.h"
#include "cadena.h"
#include "Fecha.h"

using namespace std;


    void Venta::SetNumeroVenta(int id){
    bool a=false;
        while(a==false)
        {
            if(id>0)
            {
                _NumeroVenta=id;
                a=true;
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

    void Venta::SetImporteVenta(float v){

    bool a=false;
    while(a==false)
        {
            if(v>0)
            {
                _ImporteVenta=v;
                a=true;
            }
            else
            {
                cout<<"ingrtese un importe de venta mayor a 0: ";
                cin>>v;
                cout<<endl;
            }
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

        int venta,dia,mes,siglo;
        float importe;
        Fecha fech;
        char cuit[20];

        cout<<"ingrese numero de venta tiene que ser igual a 0 o mayor: ";
        cin>>venta;
        SetNumeroVenta(venta);
        cout<<endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout<<"ingrese el cuil de venta: ";
        cin.getline(cuit,20);
        SetCuit(cuit);
        cout<<endl;
        cout<<"ingrese dia de la venta: ";
        cin>>dia;
        cout<<endl;
        cout<<"ingrese mes de la venta:  ";
        cout<<endl;
        cin>>mes;
        cout<<"ingrese anio de la venta: ";
        cin>>siglo;
        cout<<endl;
        fech.setDia(dia);
        fech.setMes(mes);
        fech.setAnio(siglo);
        SetFechaVenta(fech);
        cout<<"ingrese import de venta: ";
        cin>>importe;
        SetImporteVenta(importe);
        cout<<endl;
}

    void Venta::MostrarVenta(){
    cout<<"El numero de venta es: "<<GetNumeroVenta()<<endl;
    cout<<"El cuil de la venta es: "<<GetCuit()<<endl;
    cout<<"La fecha de venta es: ";
    GetFechaVenta();
    cout<<endl;
    cout<<"El importe de la venta es: "<<GetImporteVenta()<<endl;
    }
