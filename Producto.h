#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED
#include "cadena.h"

class Producto {
public:
void SetIdProducto(int num);
void SetPrecio(float num);
void SetDescripcion(char *palabra);
void SetMarca(char *palabra);
void SetTipoEquipo(int num);
void SetStock(int num);

int GetIdProducto();
float GetPrecio();
const char *GetDescripcion();
const char *GetMarca();
int GetTipoEquipo();
int GetStock();

void CargarProducto();
void MostrarProducto();

private:

    int _IdProducto;
    float _Precio;
    Cadena _Descripcion;
    Cadena _Marca;
    int _TipoEquipo;
    int _Stock;

};
#endif // PRODUCTO_H_INCLUDED
