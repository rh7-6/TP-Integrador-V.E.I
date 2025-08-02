#ifndef M_VECTOR_H_INCLUDED
#define M_VECTOR_H_INCLUDED
#include "cadena.h"
#include "Producto.h"
#include "Clientes.h"
#include "Venta.h"
#include "Detalle_Venta.h"

class MVector{

public:

    void Agregar(Cadena &cd);
    Cadena *GetCd();

    void Agregar(Producto &pr);
    Producto *GetPr();

    void Agregar(Cliente &cl);
    Cliente *GetCl();

    void Agregar(Venta &vt);
    Venta *GetVt();

    void Agregar(DetalleVenta &dtv);
    DetalleVenta *GetDtV();

    int GetTam(int sizeOfObj);

    ~MVector();

private:

    Cadena *_Cad= nullptr;
    int _TamCad=0;

    Producto *_Prod= nullptr;
    int _TamProd=0;

    Cliente *_Cl= nullptr;
    int _TamCl=0;

    Venta *_Vt= nullptr;
    int _TamVt=0;

    DetalleVenta *_DtV= nullptr;
    int _TamDtV=0;
};


#endif // M_VECTOR_H_INCLUDED
