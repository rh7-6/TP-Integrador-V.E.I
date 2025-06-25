#ifndef CADENA_H_INCLUDED
#define CADENA_H_INCLUDED
using namespace std;

class Cadena{

public:
    Cadena();
    Cadena(const char *t);
    const char *getTexto();
    void setTexto(const char *t);

private:
    int tam=50;
    char _Texto[50];
};


#endif // CADENA_H_INCLUDED
