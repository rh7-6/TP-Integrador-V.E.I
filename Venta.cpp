#include <iostream>
#include <limits>
#include "cstring"
#include "Venta.h"

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

    void Venta::SetFechaVenta(int dia,int mes,int siglo){

    _FechaVenta.setDia(dia);
    _FechaVenta.setMes(mes);
    _FechaVenta.setAnio(siglo);

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

    Fecha Venta::GetFecha(){

        return _FechaVenta;
    }

    float Venta::GetImporteVenta(){

        return _ImporteVenta;

    }

    Venta::Venta(){}

    Venta::Venta(int numeroVenta, char *cuit, int dia, int mes, int anio, float importeTotal){

        _NumeroVenta=numeroVenta;
        _Cuit.setTexto(cuit);
        _FechaVenta.setDia(dia);
        _FechaVenta.setMes(mes);
        _FechaVenta.setAnio(anio);
        _ImporteVenta=importeTotal;
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
        cout<<"ingrese el cuit del comprador: ";
        cin.getline(cuit,20);
        SetCuit(cuit);
        cout<<endl;
        cout<<"ingrese dia de la venta: ";
        cin>>dia;
        cout<<endl;
        cout<<"ingrese mes de la venta:  ";
        cin>>mes;
        cout<<endl;
        cout<<"ingrese anio de la venta: ";
        cin>>siglo;
        cout<<endl;
        SetFechaVenta(dia,mes,siglo);
        cout<<"ingrese import de venta: ";
        cin>>importe;
        SetImporteVenta(importe);
        cout<<endl;
}

    void Venta::MostrarVenta(){
    cout<<"El numero de venta es: "<<GetNumeroVenta()<<endl;
    cout<<"El cuil de la venta es: "<<GetCuit()<<endl;
    cout<<"La fecha de venta es: "<<_FechaVenta.getDia()<<" / "<<_FechaVenta.getMes()<<" / "<<_FechaVenta.getAnio()<<endl;
    cout<<"El importe de la venta es: "<<GetImporteVenta()<<endl;
    }
