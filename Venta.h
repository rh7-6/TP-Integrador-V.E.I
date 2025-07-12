#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED
#include "cadena.h"
#include "Fecha.h"
#include "cstring"

class Venta {
public:

    void SetNumeroVenta(int id);
    void SetCuit(const char *t);
    void SetFechaVenta(int dia,int mes,int siglo);
    int SetImporteVenta(float v);
    void SetEstado(bool estado);

    int GetNumeroVenta();
    const char *GetCuit();
    Fecha GetFecha();
    float GetImporteVenta();
    bool GetEstado();

    Venta();
    Venta(int numeroVenta, char *cuit, int dia, int mes, int anio, double importeTotal, bool estado);

    void CargarVenta();
    void MostrarVentafecha();


private:

    int _NumeroVenta;
    Cadena _Cuit;
    Fecha _FechaVenta;
    double _ImporteVenta;
    bool _Estado;
};
#endif // VENTA_H_INCLUDED
