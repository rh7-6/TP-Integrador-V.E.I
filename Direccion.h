#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#include "cadena.h"



class Direccion {
private:

    Cadena _Calle;
    Cadena _Altura;
    int _Piso;
    Cadena _Localidad;

public:

    void SetCalle(const char *t);
    void SetAltura(const char *t);
    void SetPiso(int tc);
    void SetLocalidad(const char *t);

    const char *GetCalle();
    const char *GetAltura();
    int GetPiso();
    const char *GetLocalidad();

    Direccion();
    Direccion(const char *Calle, const char *Altura, int Piso, const char *Localidad);

    void CargarDireccion();
    void MostrarDireccion();



};

#endif // DIRECCION_H_INCLUDED
