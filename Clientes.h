#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#include "cadena.h"

class Cliente {
public:

    void SetCuit(const char *t);
    void SetNombre(const char *t);
    void SetApellido(const char *t);
    void SetTelefono(const char *t);
    void SetMail(const char *t);
    void SetDireccion(const char *t);
    void SetTipoCliente(int tc);

    const char *GetCuit();
    const char *GetNombre();
    const char *GetApellido();
    const char *GetTelefono();
    const char *GetMail();
    const char *GetDireccion();
    int GetTipoCliente();


private:

    Cadena _Cuit;
    Cadena _Nombre;
    Cadena _Apellido;
    Cadena _Telefono;
    Cadena _Mail;
    Cadena _Direccion;
    int _TipoCliente;


};
#endif // CLIENTES_H_INCLUDED
