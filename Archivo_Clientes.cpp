#include <iostream>
#include "Archivo_Clientes.h"
using namespace std;


    bool ArchivoClientes::GuardarCliente(Cliente &cl){

        //if(int pos=BuscarCliente(cl.GetCuil())>=0){
//            FILE *pfile;
//            pfile = fopen(GetNombreArchivo(),"ab");
//            if(pfile==NULL){
//                return false;
//            }
//            fseek(pfile, sizeof(Cliente) *pos, SEEK_SET);
//            fwrite(&cl, sizeof(Cliente), 1, pfile);
//            fclose(pfile);
//            return true;
//        }

        FILE *pfile;
        pfile = fopen(GetNombreArchivo(),"ab");

        if(pfile==NULL){
            return false;
        }
        fwrite(&cl, sizeof(Cliente), 1, pfile);
        fclose(pfile);
        return true;
    }

    int ArchivoClientes::BuscarCliente(const char *CUIT){

        FILE *pfile;
        pfile = fopen(GetNombreArchivo(),"rb");

        if(pfile==NULL){
            return -1;
        }

        Cliente cl;
        int posCliente=0, cantReg=CantidadRegistros(sizeof(cl));

        for(int i=0; i<cantReg; i++){
            fread(&cl, sizeof(Cliente), 1, pfile);
            if(cl.GetCuil()==CUIT){
                fclose(pfile);
                return posCliente;
            }
            posCliente++;
        }
        fclose(pfile);
        return -2;
    }

    Cliente ArchivoClientes::LeerCliente(int pos){
        FILE *pfile;
        pfile = fopen(GetNombreArchivo(),"rb");

        if(pfile==NULL){
            return Cliente();
        }

        Cliente cl;

        fseek(pfile, sizeof(Cliente) * pos, SEEK_SET);
        fread(&cl, sizeof(Cliente), 1, pfile);
        fclose(pfile);
        return cl;
    }

    ArchivoClientes::ArchivoClientes(const char *nombre){

        SetNombreArchivo(nombre);
    }

    ArchivoClientes::ArchivoClientes(){
    }
