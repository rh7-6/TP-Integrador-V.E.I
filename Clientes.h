#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#include "cadena.h"

class Cliente {
public:

    void SetCuil(const char *t);
    void SetNombre(const char *t);
    void SetApellido(const char *t);
    void SetTelefono(const char *t);
    void SetMail(const char *t);
    void SetDireccion(const char *t);
    void SetTipoCliente(int tc);

    const char *GetCuil();
    const char *GetNombre();
    const char *GetApellido();
    const char *GetTelefono();
    const char *GetMail();
    const char *GetDireccion();
    int GetTipoCliente();

    Cliente();
    Cliente(const char *CUIT, const char *nombre, const char *apellido, const char *telefono, const char *mail, const char *direccion, int tipoCliente, bool estado);

    void CargarCliente();
    void MostrarCliente();

private:

    Cadena _Cuit;
    Cadena _Nombre;
    Cadena _Apellido;
    Cadena _Telefono;
    Cadena _Mail;
    Cadena _Direccion;
    int _TipoCliente;
    bool _Estado;


};
#endif // CLIENTES_H_INCLUDED
