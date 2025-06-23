#ifndef CADENA_H_INCLUDED
#define CADENA_H_INCLUDED
#include <string>
using namespace std;

class Cadena{

public:
    Cadena();
    Cadena(const char *t);
    const char *getTexto();
    void setTexto(const char *t);
    void Concatenar(const char *t);

private:
    string _Texto;
};


#endif // CADENA_H_INCLUDED
