#include <iostream>
#include "Clientes.h"
#include "Archivo_Clientes.h"
#include "menu.h"


using namespace std;

int main(){

    //Menu();
    Cliente jose;
    jose.CargarCliente();

    FILE *pfile;
    pfile=fopen("test.dat","wb");

    fwrite(&jose,sizeof(Cliente),1,pfile);

    fclose(pfile);

//    Cliente jose1;
//
//    ArchivoClientes archc("test.dat");
//
//    jose1= archc.LeerCliente(0);
//
//    jose1.MostrarCliente();


return 0;
}
