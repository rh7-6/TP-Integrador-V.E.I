#include <iostream>
#include "Archivo_Template.h"
using namespace std;

    int ArchivoTemplate::CantidadRegistros(int tamObj){

        FILE *pfile;
        pfile = fopen(_NombreArchivo.getTexto(),"rb");

        if(pfile==NULL){
            return 0;
        }

        fseek(pfile, 0, SEEK_END);
        int cantReg = ftell(pfile)/tamObj;
        fclose(pfile);
        return cantReg;
    }

    void ArchivoTemplate::SetNombreArchivo(const char *nombre){
        _NombreArchivo.setTexto(nombre);
    }

    const char *ArchivoTemplate::GetNombreArchivo(){
        return _NombreArchivo.getTexto();
    }
