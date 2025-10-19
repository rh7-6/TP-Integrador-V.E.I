#include <iostream>
#include "menu.h"
using namespace std;

                                ///CLIENTE///
//------------------------------------------------------------------------//
    int CargarCliente(Cliente &cl, bool opcionCarga){

        system("cls");
        ArchivoClientes archCl("Clientes.dat");

        int tc;
        char cuil[31]{}, nombre[31]{}, apellido[31]{}, telefono[31]{}, mail[31]{}, direccion[31]{};

        rlutil::locate(40, 5);
        cout<<"Ingrese el cuit del cliente: ";
        cin>>cuil; LimpiarBuffer();

        int posCl =archCl.BuscarCliente(cuil);
        if(posCl>=0){

            if(opcionCarga){archCl.LeerCliente(posCl, cl);return 0;}
            system("cls");
            rlutil::locate(34,5);
            cout << "Ya existe un cliente con el cuit:" << cuil << " Desea editarlo?" << endl;
            rlutil::locate(57,8);
            cout<<"NO";
            rlutil::locate(57,9);
            cout<<"SI";
                switch(SeleccionMenus(55,8,1,1)){
                    case(0):{archCl.LeerCliente(posCl, cl);return 0;}
                    break;

                    case(1):{cl.SetCuil(cuil);}
                    break;
                    }
        }
        cl.SetCuil(cuil);
        rlutil::showcursor();
        system("cls");


        system("cls");
        rlutil::locate(40, 5); cout<<"Ingrese el nombre del cliente: ";
        cin.getline(nombre, 31);
        cl.SetNombre(nombre);

        system("cls");
        rlutil::locate(40, 5); cout<<"Ingrese el apellido del cliente: ";
        cin.getline(apellido, 31);
        cl.SetApellido(apellido);

        system("cls");
        rlutil::locate(40, 5); cout<<"Ingrese el telefono del cliente: ";
        cin.getline(telefono, 31);
        cl.SetTelefono(telefono);

        system("cls");
        rlutil::locate(40, 5); cout<<"Ingrese el mail del cliente: ";
        cin.getline(mail, 31);
        cl.SetMail(mail);

        system("cls");
        rlutil::locate(40, 5); cout<<"Ingrese la direccion del cliente: ";
        cin.getline(direccion, 31);
        cl.SetDireccion(direccion);


        system("cls");
        rlutil::locate(45, 5); cout<<"Selecione el tipo de cliente";
            rlutil::locate(57,8); cout<<"Particular";
            rlutil::locate(57,9); cout<<"Empresa";
            switch(SeleccionMenus(55,8,1,1)){
                    case(0):{tc=1;cl.SetTipoCliente(tc);}
                    break;

                    case(1):{tc=2;cl.SetTipoCliente(tc);}
                    break;
                    }

        system("cls");
        rlutil::locate(43, 5); cout <<"Seleccione estado del cliente ";
            rlutil::locate(54,8); cout<<"Activo";
            rlutil::locate(54,9); cout<<"Inactivo";
            switch(SeleccionMenus(53,8,1,1)){
                    case(0):{cl.SetEstado(1);}
                    break;

                    case(1):{cl.SetEstado(0);}
                    break;
                    }
        rlutil::hidecursor();
        system("cls");
        return 1;
    }

    void MostrarCliente(Cliente &cl){

       cout<<"Cuil del cliente: "<<cl.GetCuit()<<endl;
       cout<<"Nombre del cliente: "<<cl.GetNombre()<<endl;
       cout<<"Apellido del cliente: "<<cl.GetApellido()<<endl;
       cout<<"Telefono del cliente: "<<cl.GetTelefono()<<endl;
       cout<<"Mail del cliente: "<<cl.GetMail()<<endl;
       cout<<"Direccion del cliente: "<<cl.GetDireccion()<<endl;

       if(cl.GetTipoCliente()==1)
       {
       cout<<"tipo de cliente Particular"<<endl;
       }
       else
       {
       cout<<"tipo de cliente Empresa"<<endl;
       }
       cout<<"//////////////////////////////////////////////"<<endl;
    }

    void BuscarCliente(){

        ArchivoClientes archCl("Clientes.dat");
        Cliente cl;
        string Cuit;
        int pos;

        rlutil::locate(41,5); cout << "Ingrese el CUIT del cliente a buscar: ";
        cin >> Cuit; LimpiarBuffer();
        cout << endl;

        if((pos=archCl.BuscarCliente(Cuit.c_str()))<0){
            system("cls");
            rlutil::locate(41,5); cout << "Cliente inexistente reingrese Cuit: ";
            cin >> Cuit; LimpiarBuffer();
        }else{

            cl=archCl.LeerCliente(pos);
            MostrarCliente(cl);
            system("pause");
        }
    }

    void GuardarRegistroCliente(Cliente &cl, bool opcionSeg){

        ArchivoClientes archCl("Clientes.dat");
        bool seguir=false;
        do{
            archCl.GuardarCliente(cl);
            if(opcionSeg){
            system("cls");
            rlutil::locate(45,5); cout << "Desea ingresar otro cliente?";
            rlutil::locate(56,7); cout<< "si";
            rlutil::locate(56,8); cout<< "no";
                    switch(SeleccionMenus(54,7,1,1)){
                    case(0):{seguir=1;}
                    break;
                    case(1):{seguir=0;}
                    break;
                    }
            if(seguir){seguir=CargarCliente(cl,0);}
            }
        }while(seguir);
        system("cls");
    }

    void ListadoDeClientes(){

        system("cls");
        bool estado;
        rlutil::locate(40,5); cout << "Selecione el estado del cliente" << endl;
        rlutil::locate(50,8); cout<<"Inactivos";
        rlutil::locate(50,9); cout<<"Activos";
        estado=SeleccionMenus(48,8,1,1);

        ArchivoClientes archCl("Clientes.dat");
        int cantReg=archCl.CantidadRegistros(sizeof(Cliente));

        MVector ClOrdenados;

        Cliente cl;
        for(int i; i<cantReg; i++){
        archCl.LeerCliente(i, cl);
            if(cl.GetEstado()==estado){ClOrdenados.Agregar(cl);}
            }

        char abc[54]{'A', 'a', 'B', 'b', 'C', 'c', 'D', 'd', 'E', 'e', 'F', 'f', 'G', 'g', 'H', 'h', 'I', 'i', 'J', 'j', 'K', 'k', 'L', 'l', 'M', 'm', 'N', 'n', 'Ñ', 'ñ', 'O', 'o', 'P', 'p', 'Q', 'q', 'R', 'r', 'S', 's', 'T', 't', 'U', 'u', 'V', 'v', 'W', 'w', 'X', 'x', 'Y', 'y', 'Z', 'z'};

        int tamVecCl= ClOrdenados.GetTam();
        Cliente *ClOr= ClOrdenados.GetCl();
            for(int i=0; i<54; i++){
                for(int a=0; a<tamVecCl; a++){
                    string Apellido= ClOr[a].GetApellido();
                    if(Apellido[0]==abc[i]){MostrarCliente(ClOr[a]);}
                }
            }

        system("pause");
        system("cls");
    }

    void MenuRegistroCliente(){

        system("cls");
        rlutil::locate(50,6);cout<<"<Guardar/Editar registro>"<<endl;
        rlutil::locate(50,7);cout<<"<Eliminar Registro/Restaurar>"<<endl;
        int opcion=SeleccionMenus(49,6,1,1);

        Cliente cl;
        if(opcion==0){
            if(CargarCliente(cl,0)==1){GuardarRegistroCliente(cl,true);}
        }else{
            char cuil[31]{};
            ArchivoClientes archCl("Clientes.dat");
            rlutil::locate(40, 5);
            cout<<"Ingrese el cuit del cliente: ";
            cin>>cuil; LimpiarBuffer();

            int posCl=archCl.BuscarCliente(cuil);
            while(posCl<0){
                posCl =archCl.BuscarCliente(cuil);
                rlutil::locate(40, 5);
                cout<<"Cliente inexistente reingrese cuit: ";
                cin>>cuil; LimpiarBuffer();
                system("cls");
            }
            cl=archCl.LeerCliente(posCl);
            if(cl.GetEstado()==false){
                system("cls");
                rlutil::locate(40,5); cout<<"El registro ya se elimino desea restauralo?";
                rlutil::locate(55,7); cout<<"Si";
                rlutil::locate(55,8); cout<<"No";
                if(SeleccionMenus(53,7,1,1)==0){
                cl.SetEstado(true);
                archCl.GuardarCliente(cl);
                }
            }else{cl.SetEstado(false);archCl.GuardarCliente(cl);}
            system("cls");
        }
    }
