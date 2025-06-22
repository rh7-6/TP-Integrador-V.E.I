#ifndef ARCHIVO_VENTAS_H_INCLUDED
#define ARCHIVO_VENTAS_H_INCLUDED
#include "Archivo_Template.h"
#include "Venta.h"

class ArchivoVentas: public ArchivoTemplate{

public:

    bool GuardarVenta(Venta v);
    int BuscarVenta(int NumeroDeVenta);
    Venta LeerVenta(int pos);

    ArchivoVentas(const char *nombre);
    ArchivoVentas();
};
#endif // ARCHIVO_VENTAS_H_INCLUDED
