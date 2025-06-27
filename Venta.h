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
    void SetImporteVenta(float v);

    int GetNumeroVenta();
    const char *GetCuit();
    Fecha GetFecha();
    float GetImporteVenta();

    Venta();
    Venta(int numeroVenta, char *cuit, int dia, int mes, int anio, double importeTotal);

    void CargarVenta();
    void MostrarVenta();


private:

    int _NumeroVenta;
    Cadena _Cuit;
    Fecha _FechaVenta;
    double _ImporteVenta;
};
#endif // VENTA_H_INCLUDED
