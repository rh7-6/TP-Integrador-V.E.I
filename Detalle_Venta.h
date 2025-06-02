#ifndef DETALLE_VENTA_H_INCLUDED
#define DETALLE_VENTA_H_INCLUDED

class DetalleVenta{

public:

    void SetNumeroVenta(int n);
    void SetPrecioProducto(float p);
    void SetIdProducto(int n);
    void SetCantidad(int n);

    int GetNumeroVentaDT();
    float GetPrecioProducto();
    int GetIdProductoDT();
    int GetCantidad();

private:

    int _NumeroVenta;
    float _PrecioProducto;
    int _IdProducto;
    int _Cantidad;


};

#endif // DETALLE_VENTA_H_INCLUDED
