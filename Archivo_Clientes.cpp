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

            fseek(pfile, sizeof(Cliente) * pos, SEEK_SET);
        }

        fwrite(&cl, sizeof(Cliente), 1, pfile);

        fclose(pfile);
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

    void ArchivoClientes::MostrarCliente(int pos){


    }

    Cliente ArchivoClientes::LeerCliente(int pos){

    }

    void ArchivoClientes::SetNombre(const char *nombre){

    }

    const char *ArchivoClientes::GetNombre(){

    }


    /// pendiente desarrollar el constructor para crear el archivo .dat

