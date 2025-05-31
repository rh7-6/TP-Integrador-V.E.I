#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

class Producto {
public:
void set_numero_de_producto(int num);
void set_precio(float num);
void set_descripcion(const char palabra);
void set_marca(const char palabra);
void set_tipo_de_equipo(int num);
void set_stock(int num);

private:

    int numero_de_producto;
    float precio;
    const char descripcion[50];
    const char marca[20];
    int tipo_de_equipo;
    int stock;

};
#endif // PRODUCTO_H_INCLUDED
