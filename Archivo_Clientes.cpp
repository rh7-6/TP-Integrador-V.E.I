#include <iostream>
#include <cstring>
#include "Archivo_Clientes.h"
using namespace std;


    bool ArchivoClientes::GuardarCliente(Cliente &cl){

        int pos=BuscarCliente(cl.GetCuit());
        if(pos>=0){

            FILE *pfile;
            pfile = fopen(GetNombreArchivo(),"rb+");
            if(pfile==NULL){
                return false;
            }

            fseek(pfile, sizeof(Cliente) *pos, SEEK_SET);
            fwrite(&cl, sizeof(Cliente), 1, pfile);
            fclose(pfile);
            return true;
        }

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
            if(strcmp(cl.GetCuit(),CUIT)==0){
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

    int ArchivoClientes::LeerCliente(int pos, Cliente &cl){

        FILE *pfile;
        pfile = fopen(GetNombreArchivo(),"rb");

        if(pfile==NULL){
            return -1;
        }


        fseek(pfile, sizeof(Cliente) * pos, SEEK_SET);
        int lectura= fread(&cl, sizeof(Cliente), 1, pfile);
        fclose(pfile);
        return lectura;
    }

    ArchivoClientes::ArchivoClientes(const char *nombre){

        SetNombreArchivo(nombre);
//        FILE *pfile;
//        pfile = fopen(GetNombreArchivo(),"ab");
//        fclose(pfile);
    }

    ArchivoClientes::ArchivoClientes(){
    }

    int ArchivoClientes::BuscarCliente(int num){

        FILE *pfile;
        pfile = fopen(GetNombreArchivo(),"rb");

        if(pfile==NULL){
            return -1;
        }

        Cliente cl;
        int posCliente=0, cantReg=CantidadRegistros(sizeof(cl));

        for(int i=0; i<cantReg; i++)
        {
            fread(&cl, sizeof(Cliente), 1, pfile);
            if(cl.GetNumeroDeCliente()==num)
            {
                fclose(pfile);
                return posCliente;
            }
            posCliente++;
        }
        fclose(pfile);
        return -5;
    }
