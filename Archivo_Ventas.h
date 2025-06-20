#ifndef ARCHIVO_VENTAS_H_INCLUDED
#define ARCHIVO_VENTAS_H_INCLUDED
#include "Venta.h"
#include "Detalle_Venta.h"

class ArchivoVentas {
public:
    ///ventas///
    bool GuardarVenta(Venta v);
    int CantidadRegistrosVentas();
    int BuscarVenta(int NumeroDeVenta);
    Venta LeerVenta(int pos);
    void SetNombreArchVentas(const char *nombre);
    const char *GetNombreArchVentas();
    ///detalle de ventas///
    bool GuardarDetalleVenta(DetalleVenta dv);
    int CantidadRegistrosDetalleDeVentas();
    int BuscarDetalleDeVenta(int NumeroDeVenta);
    DetalleVenta LeerDetalleDeVenta(int pos);
    void SetNombreAchDetalleVentas(const char *nombre);
    const char *GetNombreArchDetalleVentas();

    ArchivoVentas(const char *nombre, int ventaOdetalle); // venta=1 detalle=2
    ArchivoVentas();

private:
    Cadena _NombreArchivoVentas;
    Cadena _NombreArchivoDetalleVentas;
};
#endif // ARCHIVO_VENTAS_H_INCLUDED
