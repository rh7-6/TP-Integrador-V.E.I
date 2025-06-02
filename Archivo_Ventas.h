#ifndef ARCHIVO_VENTAS_H_INCLUDED
#define ARCHIVO_VENTAS_H_INCLUDED
#include "Venta.h"
#include "Detalle_Venta.h"

class ArchivoVentas {
public:
    ///ventas///
    void GuardarVenta();
    int CantidadRegistrosVentas();
    int BuscarVenta(int NumeroDeVenta);
    void MostrarVenta(int pos);
    Venta LeerVenta(int pos);
    void SetNombreVenta(const char *nombre);
    const char *GetNombreVenta();
    ///detalle de ventas///
    void GuardarDetalleVenta();
    int CantidadRegistrosDetalleDeVentas();
    int BuscarDetalleDeVenta(int NumeroDeVenta);
    void MostrarDetalleDeVenta(int pos);
    DetalleVenta LeerDetalleDeVenta(int pos);
    void SetNombreDetalleDeVenta(const char *nombre);
    const char *GetNombreDetalleDeVenta();
    /// pendiente declarar constructor para crear el archivo .dat


private:
    Cadena _NombreArchivo;
};
#endif // ARCHIVO_VENTAS_H_INCLUDED
