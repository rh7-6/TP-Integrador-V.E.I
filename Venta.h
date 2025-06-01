#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED
#include "cadena.h"
#include "Fecha.h"


class Venta {
public:

    void SetIdVenta(int id);
    void SetCuit(const char *t);
    void SetFechaVenta(Fecha f);
    void SetImporteVenta(float v);

    int GetIdVenta();
    const char *GetCuit();
    Fecha GetFecha();
    float GetImporteVenta();


private:

    int _IdVenta;
    Cadena _Cuit;
    Fecha _Fecha;
    float _ImporteVenta;


};
#endif // VENTA_H_INCLUDED
