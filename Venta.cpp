#include <iostream>
#include <limits>
#include "cstring"
#include "Venta.h"

using namespace std;


    int Venta::SetNumeroVenta(int id){
    if(id>0)
            {
                _NumeroVenta=id;
                return 1;
            }
            else
            {
            return 0;
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

    int Venta::SetImporteVenta(double v){
            if(v>0)
            {
                _ImporteVenta=v;
                return 1;
            }
            else
            {
                return 0;
            }
}

    void Venta::SetEstado(bool estado){

        _Estado=estado;
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

    bool Venta::GetEstado(){

        return _Estado;
    }

    Venta::Venta(){}

    Venta::Venta(int numeroVenta, char *cuit, int dia, int mes, int anio, double importeTotal, bool estado){

        _NumeroVenta=numeroVenta;
        _Cuit.setTexto(cuit);
        _FechaVenta.setDia(dia);
        _FechaVenta.setMes(mes);
        _FechaVenta.setAnio(anio);
        _ImporteVenta=importeTotal;
        _Estado=estado;
    }

///--------------------------------------------------------------------------------------------------

    void Venta::CargarVenta(){

        int venta,dia,mes,siglo;
        double importe;
        Fecha fech;
        char cuit[20];

        cout<<"ingrese numero de venta tiene que ser igual a 0 o mayor: ";
        cin>>venta;
        SetNumeroVenta(venta);
        cout<<endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
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

    void Venta::MostrarVentafecha(){
    cout<<"La fecha de venta es: "<<_FechaVenta.getDia()<<" / "<<_FechaVenta.getMes()<<" / "<<_FechaVenta.getAnio()<<endl;
    }
