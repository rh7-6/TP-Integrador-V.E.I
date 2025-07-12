#ifndef DETALLE_VENTA_H_INCLUDED
#define DETALLE_VENTA_H_INCLUDED

class DetalleVenta{

public:

    void SetNumeroVentaDT(int n);
    int SetPrecioProductoDT(float p);
    void SetIdProductoDT(int n);
    int SetCantidad(int n);

    int GetNumeroVentaDT();
    float GetPrecioProducto();
    int GetIdProductoDT();
    int GetCantidad();

    DetalleVenta();
    DetalleVenta(int numeroVenta, float precioProducto, int idProducto, int cantidad);

    void CargarDetalleVenta();
    void MotrarDetalleVenta();

private:

    int _NumeroVenta;
    float _PrecioProducto;
    int _IdProducto;
    int _Cantidad;


};

#endif // DETALLE_VENTA_H_INCLUDED
