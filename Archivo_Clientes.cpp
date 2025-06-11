#include <iostream>
#include "Archivo_Clientes.h"
using namespace std;


    bool ArchivoClientes::GuardarCliente(Cliente &cl){

        FILE *pfile;
        pfile = fopen(_NombreArchivo.getTexto(),"ab");

        if(pfile==NULL){
            return false;
        }

        ArchivoClientes a;
        if(int pos=a.BuscarCliente(cl.GetCuit())>=0){

            fwrite(&cl, sizeof(Cliente), 1, pfile);
            fclose(pfile);
            return true;
        }

        fwrite(&cl, sizeof(Cliente), 1, pfile);
        fclose(pfile);
        return true;
    }

    int ArchivoClientes::CantidadRegistros(){

        FILE *pfile;
        pfile = fopen(_NombreArchivo.getTexto(),"rb");

        if(pfile==NULL){
            return 0;
        }

        int contReg=0;
        Cliente b;
        while(fread(&b, sizeof(Cliente), 1, pfile)==1){
            contReg++;
        }
        fclose(pfile);
        return contReg;
    }

    int ArchivoClientes::BuscarCliente(const char *CUIT){

        FILE *pfile;
        pfile = fopen(_NombreArchivo.getTexto(),"rb");

        if(pfile==NULL){
            return 0;
        }

        Cliente cl;
        ArchivoClientes a;
        int posCliente=0, cantReg=a.CantidadRegistros();

        for(int i=0; i<cantReg; i++){
            fread(&cl, sizeof(Cliente), 1, pfile);
            if(cl.GetCuit()==CUIT){
                fclose(pfile);
                return posCliente;
            }
            posCliente++;
        }
        fclose(pfile);
        return -1;
    }

    Cliente ArchivoClientes::LeerCliente(int pos){

        FILE *pfile;
        pfile = fopen(_NombreArchivo.getTexto(),"rb");

        if(pfile==NULL){
            return Cliente();
        }

        Cliente cl;

        fseek(pfile, sizeof(Cliente) * pos, SEEK_SET);
        fread(&cl, sizeof(Cliente), 1, pfile);
        fclose(pfile);
        return cl;
    }

    void ArchivoClientes::SetNombre(const char *nombre){

        _NombreArchivo.setTexto(nombre);
    }

    const char *ArchivoClientes::GetNombre(){

        return _NombreArchivo.getTexto();
    }


    /// pendiente desarrollar el constructor para crear el archivo .dat

