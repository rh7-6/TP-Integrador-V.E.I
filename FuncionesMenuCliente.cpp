#include <iostream>
#include "menu.h"
using namespace std;

                                ///CLIENTE///
//------------------------------------------------------------------------//
    int CargarCliente(Cliente &cl, int switchEdit, bool opcionCarga){

        system("cls");
        ArchivoClientes archCl("Clientes.dat");

        bool bandera=true;
        Direccion dir;
        int tc,NumeroDeCliente=1, resultadoBusqueda=0, altura=0, piso=0;
        char cuil[31]{}, nombre[31]{}, apellido[31]{}, telefono[31]{}, mail[31]{}, Calle[31]{}, Localidad[31]{};

        if(opcionCarga)
            {
            rlutil::locate(40, 5);
            cout<<"Ingrese el cuit del cliente: ";
            cin>>cuil; LimpiarBuffer();



            int posCl =archCl.BuscarCliente(cuil);
            archCl.LeerCliente(posCl, cl);
            if(posCl>=0)
                {
                system("cls");
                rlutil::locate(34,5);
                cout << "Ya existe un cliente con el cuit:" << cuil << endl;
                system("pause");
                opcionCarga=false;switchEdit=-1;
                return 0;
                }
                else
                {
                cl.SetCuil(cuil);
                rlutil::showcursor();
                system("cls");
                }
        }
        do{
                switch(switchEdit){
                case(0):{
                    system("cls");
                    rlutil::locate(40, 5); cout<<"Ingrese el nombre del cliente: ";
                    cin.getline(nombre, 31);
                    cl.SetNombre(nombre);
                }break;

                case(1):{
                    system("cls");
                    rlutil::locate(40, 5); cout<<"Ingrese el apellido del cliente: ";
                    cin.getline(apellido, 31);
                    cl.SetApellido(apellido);
                }break;

                case(2):{
                    system("cls");
                    rlutil::locate(40, 5); cout<<"Ingrese el telefono del cliente: ";
                    cin.getline(telefono, 31);
                    cl.SetTelefono(telefono);

                }break;

                case(3):{
                    system("cls");
                    rlutil::locate(40, 5); cout<<"Ingrese el mail del cliente: ";
                    cin.getline(mail, 31);
                    cl.SetMail(mail);
                }break;

                case(4):{
                    system("cls");
                    rlutil::locate(40, 5); cout<<"Ingrese la calle del cliente: ";///crear if si quiere ingresar direccion
                    cin.getline(Calle, 31);
                    system("cls");
                    rlutil::locate(40, 5); cout<<"Ingrese la Altura del cliente: ";
                    cin>>altura;
                    system("cls");
                    rlutil::locate(40, 5); cout<<"Ingrese el piso del cliente: ";
                    cin>>piso;
                    system("cls");
                    LimpiarBuffer();
                    rlutil::locate(40, 5); cout<<"Ingrese el Localidad del cliente: ";
                    cin.getline(Localidad, 31);
                    cl.SetDireccion(Calle, altura, piso, Localidad);
                }break;

                case(5):{
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
                }break;

                case(6):{
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
////////////////////////////////////////////numero de cliente automatico/////////////////////
    do{
resultadoBusqueda = archCl.BuscarCliente(NumeroDeCliente);
    if(resultadoBusqueda == -5)
    {
        cl.SetNumeroDeCliente(NumeroDeCliente);
        bandera = false;
    }
    else if(resultadoBusqueda == -1)
    {
        cl.SetNumeroDeCliente(NumeroDeCliente);
        bandera = false;
    }
    else
    {
        NumeroDeCliente++;
    }
} while(bandera == true);
/////////////////////////////////////////////////////////////////////////////////////////////

                }break;
            }
            switchEdit++;
            if(switchEdit>6){opcionCarga=0;}
        }while(opcionCarga);
        return 1;
    }

    void MostrarCliente(Cliente &cl){

       cout<<"Cuil del cliente: "<<cl.GetCuit()<<endl;
       cout<<"Nombre del cliente: "<<cl.GetNombre()<<endl;
       cout<<"Apellido del cliente: "<<cl.GetApellido()<<endl;
       cout<<"Telefono del cliente: "<<cl.GetTelefono()<<endl;
       cout<<"Mail del cliente: "<<cl.GetMail()<<endl;
       Direccion dir=cl.GetDireccion();//verificacion de si se cargo o no un cliente
       cout<<"La calle del cliente es: "<<dir.GetCalle()<<endl;
       cout<<"La altura del cliente es: "<<dir.GetAltura()<<endl;
       cout<<"El piso del cliente es: "<<dir.GetPiso()<<endl;
       cout<<"La localidad del cliente es: "<<dir.GetLocalidad()<<endl;
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

        pos=archCl.BuscarCliente(Cuit.c_str());
        while(pos<0){
            system("cls");
            rlutil::locate(41,5); cout << "Cliente inexistente reingrese Cuit: ";
            cin >> Cuit; LimpiarBuffer();
            pos=archCl.BuscarCliente(Cuit.c_str());
        }
            cl=archCl.LeerCliente(pos);
            MostrarCliente(cl);
            system("pause");
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
            if(seguir){seguir=CargarCliente(cl,0,0);}
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
        ArchivoClientes archCl("Clientes.dat");
        Cadena txt;
        MVector vecOpc;
        txt.setTexto("Guardar/Editar registro");vecOpc.Agregar(txt);
        txt.setTexto("Eliminar/Restaurar Registro");vecOpc.Agregar(txt);
        int opcion=SeleccionMenuAnim(vecOpc.GetCd(),54,12,1,1,4,8);

        Cliente cl;
        if(opcion==0){
                Cadena txt1;
                MVector vecOp1;
                txt1.setTexto("Ingresar nuevo");vecOp1.Agregar(txt1);
                txt1.setTexto("Editar existente");vecOp1.Agregar(txt1);

                if(SeleccionMenuAnim(vecOp1.GetCd(),54,12,1,1,4,8)==0){
                    CargarCliente(cl,0,1);
                    }else{
                        MVector VecCl;
                        CopiarYOrdenarClientes(VecCl);

                        int tamVecCl=VecCl.GetTam();
                        Cliente *ArrCl=VecCl.GetCl();
                        MVector OpcClTxt;
                        for(int i=0;i<tamVecCl;i++){
                            string TipoCliente;
                            if(ArrCl[i].GetTipoCliente()==1){TipoCliente="Particular";}else{TipoCliente="Empresa";}
                            string s=string("Cuit:")+ArrCl[i].GetCuit()+"|"+ArrCl[i].GetNombre()+" "+ArrCl[i].GetApellido()+"|"+TipoCliente;
                            OpcClTxt.Agregar(s.c_str());
                        }
                        int ClSelec=SeleccionMenuAnim(OpcClTxt.GetCd(),54,12,tamVecCl-1,2,4,8);
                        cl=ArrCl[ClSelec];
                        MVector vecEdt;
                        TxtEditCliente(vecEdt);
                        int SwitchEdit=SeleccionMenuAnim(vecEdt.GetCd(),54,12,6,2,4,8);
                        CargarCliente(cl,SwitchEdit,0);
                    }
                archCl.GuardarCliente(cl);
                system("cls");
                rlutil::hidecursor();
        }else{
            char Cuit[31];
            ArchivoClientes archP("Clientes.dat");
            rlutil::locate(40, 5);
            cout<<"Ingrese el Cuit del Cliente: ";
            cin.getline(Cuit,31);

            int posCl=archCl.BuscarCliente(Cuit);
            while(posCl<0){
                rlutil::locate(40, 5);
                cout<<"Cliente inexistente reingrese Cuit del cliente: ";
                cin.getline(Cuit,31);
                posCl =archCl.BuscarCliente(Cuit);
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
        }
    }

    void CopiarYOrdenarClientes(MVector &vecCl){

        system("cls");
        int TipoCliente;
        rlutil::locate(40,5); cout << "Selecione tipo de cliente" << endl;
        rlutil::locate(50,8); cout<<"Particular";
        rlutil::locate(50,9); cout<<"Empresa";
        TipoCliente=SeleccionMenus(48,8,1,1)+1;

        ArchivoClientes archCl("Clientes.dat");
        int cantReg=archCl.CantidadRegistros(sizeof(Cliente));

        MVector ClOrdenados;

        Cliente cl;
        for(int i; i<cantReg; i++){
        archCl.LeerCliente(i, cl);
            if(cl.GetTipoCliente()==TipoCliente){ClOrdenados.Agregar(cl);}
            }

        char abc[54]{'A', 'a', 'B', 'b', 'C', 'c', 'D', 'd', 'E', 'e', 'F', 'f', 'G', 'g', 'H', 'h', 'I', 'i', 'J', 'j', 'K', 'k', 'L', 'l', 'M', 'm', 'N', 'n', 'Ñ', 'ñ', 'O', 'o', 'P', 'p', 'Q', 'q', 'R', 'r', 'S', 's', 'T', 't', 'U', 'u', 'V', 'v', 'W', 'w', 'X', 'x', 'Y', 'y', 'Z', 'z'};


        int tamVecCl= ClOrdenados.GetTam();
        Cliente *ClOr= ClOrdenados.GetCl();
            for(int i=0; i<54; i++){
                for(int a=0; a<tamVecCl; a++){
                    string Apellido= ClOr[a].GetApellido();
                    if(Apellido[0]==abc[i]){vecCl.Agregar(ClOr[a]);}
                }
            }
        system("cls");
    }

    void TxtEditCliente(MVector &vec){

        vec.Agregar("Nombre");
        vec.Agregar("Apellido");
        vec.Agregar("Telefono");
        vec.Agregar("Mail");
        vec.Agregar("Direccion");
        vec.Agregar("Tipo de cliente");
        vec.Agregar("Estado");
    }
