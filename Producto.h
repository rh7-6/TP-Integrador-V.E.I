#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED
#include "cadena.h"

class Producto {
public:
void SetIdProducto(int num);
void SetPrecio(float num);
///arreglar problema con espacio en los char///////
void SetDescripcion(char *palabra);             ///
void SetMarca(char *palabra);                   ///
///////////////////////////////////////////////////
void SetTipoEquipo(int num);
void SetStock(int num);
void CargarProducto();
void MostrarProducto();

int GetIdProducto();
float GetPrecio();
const char *GetDescripcion();
const char *GetMarca();
int GetTipoEquipo();
int GetStock();

private:

    int _IdProducto;
    float _Precio;
    Cadena _Descripcion;
    Cadena _Marca;
    int _TipoEquipo;
    int _Stock;

};
#endif // PRODUCTO_H_INCLUDED
