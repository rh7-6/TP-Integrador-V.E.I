#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#include "Direcciones.h"
#include "cadena.h"

class Cliente {
public:

    void SetNumeroDeCliente(int tc);
    void SetCuil(const char *t);
    void SetNombre(const char *t);
    void SetApellido(const char *t);
    void SetTelefono(const char *t);
    void SetMail(const char *t);
///-------------------------------- incluir set calle, altura, piso y localidad o uno solo que pida los 3
    void SetTipoCliente(int tc);
    void SetEstado(bool estado);

    int GetNumeroDeCliente();
    const char *GetCuit();
    const char *GetNombre();
    const char *GetApellido();
    const char *GetTelefono();
    const char *GetMail();
//-----------------------------lo mismo para el get
    int GetTipoCliente();
    bool GetEstado();

    Cliente();
    Cliente(int NumeroDeCliente, const char *CUIT, const char *nombre, const char *apellido, const char *telefono, const char *mail, const char *direccion, int tipoCliente, bool estado);

    void CargarCliente();
    void MostrarCliente();

private:
    int _NumeroDeCliente;
    Cadena _Cuit;
    Cadena _Nombre;
    Cadena _Apellido;
    Cadena _Telefono;
    Cadena _Mail;
    Direccion _Direccion;
    int _TipoCliente;
    bool _Estado;


};
#endif // CLIENTES_H_INCLUDED
