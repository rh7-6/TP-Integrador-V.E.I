#ifndef CADENA_H_INCLUDED
#define CADENA_H_INCLUDED
using namespace std;

class Cadena{

public:
    Cadena();
    Cadena(const char *t);
    ~Cadena();
    const char *getTexto();
    void setTexto(const char *t);
    void Concatenar(const char *t);

private:
    int tam;
    char *texto;
};


#endif // CADENA_H_INCLUDED
