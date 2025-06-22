#ifndef ARCHIVO_VENTAS_H_INCLUDED
#define ARCHIVO_VENTAS_H_INCLUDED
#include "Archivo_Template.h"
#include "Venta.h"

class ArchivoVentas: public ArchivoTemplate{
public:

    bool GuardarVenta(Venta v);
    //int CantidadRegistrosVentas();
    int BuscarVenta(int NumeroDeVenta);
    Venta LeerVenta(int pos);
    //void SetNombreArchVentas(const char *nombre);
    //const char *GetNombreArchVentas();

    ArchivoVentas(const char *nombre);
    ArchivoVentas();

private:
    ///Cadena _NombreArchivo;
};
#endif // ARCHIVO_VENTAS_H_INCLUDED
