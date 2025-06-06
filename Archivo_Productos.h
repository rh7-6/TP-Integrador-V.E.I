#ifndef ARCHIVO_PRODUCTOS_H_INCLUDED
#define ARCHIVO_PRODUCTOS_H_INCLUDED
#include "Producto.h"

class ArchivoProductos {
public:

    void GuardarProducto(Producto *pr, int pos);
    int CantidadRegistros();
    int BuscarProducto(int IdProducto);
    void MostrarProducto(int pos);
    Producto LeerProducto(int pos);
    void SetNombreProducto(const char *nombre);
    const char *GetNombreProducto();

    /// pendiente declarar constructor para crear el archivo .dat
private:

    Cadena _NombreArchivo;

};

#endif // ARCHIVO_PRODUCTOS_H_INCLUDED
