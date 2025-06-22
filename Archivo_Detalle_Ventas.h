#ifndef ARCHIVO_DETALLE_VENTAS_H_INCLUDED
#define ARCHIVO_DETALLE_VENTAS_H_INCLUDED
#include "Archivo_Template.h"
#include "Detalle_Venta.h"


class ArchivoDetalleVentas: public ArchivoTemplate{

public:
    bool GuardarDetalleVenta(DetalleVenta dv);
    ///int CantidadRegistrosDetalleDeVentas();
    int BuscarDetalleDeVenta(int NumeroDeVenta);
    DetalleVenta LeerDetalleDeVenta(int pos);
    ///void SetNombreAchDetalleVentas(const char *nombre);
    ///const char *GetNombreArchDetalleVentas();

    ArchivoDetalleVentas(const char *nombre);
    ArchivoDetalleVentas();


};

#endif // ARCHIVO_DETALLE_VENTAS_H_INCLUDED
