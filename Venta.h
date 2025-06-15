#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED
#include "cadena.h"
#include "Fecha.h"


class Venta {
public:

    void SetNumeroVenta(int id);
    void SetCuit(const char *t);
    void SetFechaVenta(Fecha f);
    void SetImporteVenta(float v);

    int GetNumeroVenta();
    const char *GetCuit();
    Fecha GetFechaVenta();
    float GetImporteVenta();

    void CargarVenta();
    void MostrarVenta();


private:

    int _NumeroVenta;
    Cadena _Cuit;
    Fecha _FechaVenta;
    float _ImporteVenta;


};
#endif // VENTA_H_INCLUDED
