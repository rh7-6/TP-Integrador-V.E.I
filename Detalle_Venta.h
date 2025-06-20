#ifndef DETALLE_VENTA_H_INCLUDED
#define DETALLE_VENTA_H_INCLUDED

class DetalleVenta{

public:

    void SetNumeroVentaDT(int n);
    void SetPrecioProductoDT(float p);
    void SetIdProductoDT(int n);
    void SetCantidad(int n);

    int GetNumeroVentaDT();
    float GetPrecioProducto();
    int GetIdProductoDT();
    int GetCantidad();

    void CargarDetalleVenta();
    void MotrarDetalleVenta();

private:

    int _NumeroVenta;
    float _PrecioProducto;
    int _IdProducto;
    int _Cantidad;


};

#endif // DETALLE_VENTA_H_INCLUDED
