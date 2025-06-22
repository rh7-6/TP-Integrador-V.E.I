#ifndef ARCHIVO_PRODUCTOS_H_INCLUDED
#define ARCHIVO_PRODUCTOS_H_INCLUDED
#include "Archivo_Template.h"
#include "Producto.h"

class ArchivoProductos: public ArchivoTemplate{

public:

    bool GuardarProducto(Producto pr);
    int BuscarProducto(int IdProducto);
    Producto LeerProducto(int pos);

    ArchivoProductos(const char *t);
    ArchivoProductos();

};

#endif // ARCHIVO_PRODUCTOS_H_INCLUDED
