#include <iostream>
#include "menu.h"
#include "Archivo_Clientes.h"
#include "Archivo_Productos.h"
#include "Archivo_Ventas.h"
#include "Archivo_Detalle_Ventas.h"
using namespace std;

                                ///PRODUCTO///
//------------------------------------------------------------------------//
    int CargarProducto(Producto &p, int switchEdit, bool opcCarga){

        ArchivoProductos archP("Productos.dat");
        int id,tipo=0,stock;
        float precio;
        char nombre[50]{},descripcion[500]{}, marca[20]{};

        if(opcCarga==1){
            rlutil::locate(30,5);
            cout<<"Ingrese id del producto: ";
            cin>>id; LimpiarBuffer();

            while(p.SetIdProducto(id)==0){
                rlutil::locate(20,5);
                cout<<"Ingrese un numero mayor a 0: ";
                cin>>id; LimpiarBuffer();
                system("cls");
            }
        }
        do{
            switch(switchEdit){
                case(0):{
                    rlutil::locate(35,5);
                    cout << "Ingrese nombre del producto: ";
                    cin.getline(nombre, 50);
                    p.SetNombreProducto(nombre);
                    system("cls");
                }break;

                case(1):{
                    rlutil::locate(20,5);
                    cout<<"Ingrese el precio del producto tienen que ser igual o mayor a 100: $";
                    cin>>precio;
                    while(p.SetPrecio(precio)==0){
                        system("cls");
                        rlutil::locate(20,5);
                        cout<<"el precio debe ser mayor a 100 por favor vuelva a ingresar el precio: $";
                        cin>>precio; LimpiarBuffer();
                    }
                    system("cls");
                }break;

                case(2):{
                    rlutil::locate(2,5);
                    cout<<"Ingrese la descripcion del producto(terminada en el caracter #): "<<endl;
                    cin.getline(descripcion,500, '#'); LimpiarBuffer();
                    p.SetDescripcion(descripcion);
                    system("cls");
                }break;

                case(3):{
                    rlutil::locate(20,5);
                    cout<<"Ingrese la marca a la que pertenece el producto: ";
                    cin.getline(marca,20);
                    p.SetMarca(marca);
                    system("cls");
                }break;

                case(4):{
                    rlutil::locate(50,7);
                    cout<<"Selecione el tipo de producto";
                    TextoTiposDeProducto();
                    tipo=SeleccionMenus(56,8,9,1);
                    tipo++;
                    p.SetTipoEquipo(tipo);
                    system("cls");
                }break;

                case(5):{
                    rlutil::locate(35,5);
                    cout<<"Ingrese el stock del producto: ";
                    cin>>stock; LimpiarBuffer();
                    while(p.SetStock(stock)==0){
                        rlutil::locate(20,5);
                        cout<<"El stock no puede ser menor a 0 por favor vuelva a ingresar el stock: ";
                        cin>>stock; LimpiarBuffer();
                    }
                    system("cls");
                }break;

                case(6):{
                    rlutil::locate(45,5);
                    cout<<"Selecione el estado del producto";
                    rlutil::locate(56,7);
                    cout<<"inactivo";
                    rlutil::locate(56,8);
                    cout<<"activo";
                    switch(SeleccionMenus(54,7,1,1)){
                    case(0):{p.SetEstado(0);}break;

                    case(1):{p.SetEstado(1);}break;
                    }
                    cout<<endl;
                    }break;
            }
            switchEdit++;
        }while(opcCarga);
        return 1;
    }

    void MostrarProducto(Producto &p){
    cout<<"Id: "<<p.GetIdProducto()<<endl<< endl;
    cout<<"Nombre y Marca: "<<p.GetMarca()<<endl<< endl;
    cout<<"Precio: $"<<fixed << setprecision(0)<<p.GetPrecio()<<endl<< endl;
    cout<< p.GetDescripcion();
    cout<< endl << endl;

 switch(p.GetTipoEquipo()){
case 1:
    cout << "Tipo de producto: Equipo" << endl;
    break;
case 2:
    cout << "Tipo de producto: Notebook" << endl;
    break;
case 3:
    cout << "Tipo de producto: Procesador" << endl;
    break;
case 4:
    cout << "Tipo de producto: Mother" << endl;
    break;
case 5:
    cout << "Tipo de producto: Placa de video" << endl;
    break;
case 6:
    cout << "Tipo de producto: Memoria Ram" << endl;
    break;
case 7:
    cout << "Tipo de producto: Gabinete" << endl;
    break;
case 8:
    cout << "Tipo de producto: Fuente" << endl;
    break;
case 9:
    cout << "Tipo de producto: Monitor" << endl;
    break;
case 10:
    cout << "Tipo de producto: Periferico" << endl;
    break;
default:{}
    }
    cout << endl;
    cout << "Stock: " << p.GetStock() << endl;

    cout<<"//////////////////////////////////////////////"<<endl;

    }

    void BuscarProducto(bool opcion){

        ArchivoProductos archP("Productos.dat");
        Producto p;

        if(opcion){

            int pos, id;
            rlutil::locate(40,5);
            cout << "Ingrese el Id del producto a buscar: ";
            cin >> id; LimpiarBuffer();
            cout << endl;

            if((pos=archP.BuscarProducto(id))<0){

                system("cls");
                rlutil::locate(40,5);
                cout << "Producto inexistente reingrese id: ";
                cin >> id;
            }else{
                p=archP.LeerProducto(pos);
                MostrarProducto(p);
                system("pause");
            }
        }else{

            float precioMax, precioMin;

            system("cls");
            rlutil::locate(35,5);
            cout << "Ingrese valor maximo en rango de precio a buscar: ";
            cin >> precioMax; LimpiarBuffer();
            cout << endl;

            rlutil::locate(35,8);
            cout << "Ingrese valor minimo en rango de precio a buscar: ";
            cin >> precioMin; LimpiarBuffer();
            cout << endl;
            system("cls");

            vector<Producto> PrEnRango;
            for(int i=0; i<archP.CantidadRegistros(sizeof(Producto)); i++){

                p= archP.LeerProducto(i);
                if(p.GetPrecio()<=precioMax&&p.GetPrecio()>=precioMin){

                    PrEnRango.push_back(p);
                }
            }
            int tamVecProd=PrEnRango.size();
            for(int i=0; i<tamVecProd; i++){
                MostrarProducto(PrEnRango[i]);
            cout<<"///////////////////////////////////////////////"<<endl;
            }
            system("pause");
            system("cls");
        }
    }

    void GuardarRegistroProducto(Producto &p){

        ArchivoProductos archP("Productos.dat");

        archP.GuardarProducto(p);
    }

    void ListadoDeProductos(bool opcion){

        system("cls");
        int TipoDeProducto;
        bool estado;

        rlutil::locate(50,7);
        cout<<"Selecione el tipo de producto";
        TextoTiposDeProducto();
        TipoDeProducto=SeleccionMenus(56,8,9,1);
        TipoDeProducto++;
        system("cls");

        while(TipoDeProducto>10||TipoDeProducto<0){
            system("cls");
            cout<<"como saliste del menu? ingrese por favor un numero entre el 1 y 10 ";
            cin>>TipoDeProducto; LimpiarBuffer();
        }
        system("cls");
        rlutil::locate(45,5);
        cout << "Ingrese estado en inventario" << endl;
        rlutil::locate(55,8);
        cout<<"Inactivo";
        rlutil::locate(55,9);
        cout<<"Activo";
        estado=SeleccionMenus(53,8,1,1);

        ArchivoProductos archPr("Productos.dat");
        int cantReg=archPr.CantidadRegistros(sizeof(Producto));

        vector<Producto> PrOrdenados;

        system("cls");

        Producto pr;
        for(int i=0; i<cantReg; i++){
            archPr.LeerProducto(i, pr);
            if(pr.GetTipoEquipo()==TipoDeProducto&&pr.GetEstado()==estado){
                //MostrarProducto(pr);
                PrOrdenados.push_back(pr);
                }
            }

        if(opcion){

                bool ban=true;
                int tamVecProd=PrOrdenados.size();
                while(ban){

                        int contPrOrdenados=0;
                    for(int i=0; i<tamVecProd; i++){

                        if(i!=tamVecProd-1){
                            if(PrOrdenados[i].GetPrecio()<PrOrdenados[i+1].GetPrecio()){
                                Producto p;
                                p= PrOrdenados[i+1];
                                PrOrdenados[i+1]=PrOrdenados[i];
                                PrOrdenados[i]=p;
                                contPrOrdenados++;
                            }
                        }
                    }
                        if(contPrOrdenados==0){
                            ban=false;
                        }
                }
            }else{
                bool ban=true;
                int tamVecProd=PrOrdenados.size();
                while(ban){

                        int contPrOrdenados=0;
                    for(int i=0; i<tamVecProd; i++){

                        if(i!=tamVecProd-1){
                            if(PrOrdenados[i].GetStock()<PrOrdenados[i+1].GetStock()){
                                Producto p;
                                p= PrOrdenados[i+1];
                                PrOrdenados[i+1]=PrOrdenados[i];
                                PrOrdenados[i]=p;
                                contPrOrdenados++;
                            }
                        }
                    }
                        if(contPrOrdenados==0){
                            ban=false;
                        }
                }
            }
            int tamVecProd=PrOrdenados.size();
            for(int i=0; i<tamVecProd; i++){
                MostrarProducto(PrOrdenados[i]);
            }
            system("pause");
            system("cls");
    }

    void MenuRegistroProducto(){

        system("cls");
        ArchivoProductos archP("Productos.dat");
        Cadena txt;
        MVector vecOp;
        txt.setTexto("Guardar/Editar registro");vecOp.Agregar(txt);
        txt.setTexto("Eliminar/Restaurar Registro");vecOp.Agregar(txt);
        int opcion=SeleccionMenuAnim(vecOp.GetCd(),54,12,1,1,4,8);

        Producto p;
        if(opcion==0){
                Cadena txt1;
                MVector vecOp1;
                txt1.setTexto("Ingresar nuevo");vecOp1.Agregar(txt1);
                txt1.setTexto("Editar existente");vecOp1.Agregar(txt1);

                if(SeleccionMenuAnim(vecOp1.GetCd(),54,12,1,1,4,8)==0){
                    CargarProducto(p,0,1);
                    }else{
                        MVector VecPr;
                        MVector vecTxTpPr;
                        TextoTiposDeProducto2(vecTxTpPr);
                        int TpPr=SeleccionMenuAnim(vecTxTpPr.GetCd(),54,12,9,1,4,8)+1;
                        CopiarYOrdenarProductos(VecPr,TpPr,1);
                        CopiarYOrdenarProductos(VecPr,TpPr,0);

                        int tamVecPr=VecPr.GetTam(sizeof(Producto));
                        Producto *ArrPr=VecPr.GetPr();
                        MVector OpcPrTxt;
                        for(int i=0;i<tamVecPr;i++){
                            string estado;
                            if(ArrPr[i].GetEstado()==0){estado="Borrado";}else{estado="listado";}
                            string s="ID:"+to_string(ArrPr[i].GetIdProducto())+"|"+ArrPr[i].GetMarca()+" "+ArrPr[i].GetNombreProducto()+"|"+estado;
                            OpcPrTxt.Agregar(s.c_str());
                        }
                        int PrSelec=SeleccionMenuAnim(OpcPrTxt.GetCd(),54,12,tamVecPr-1,2,4,8);
                        p=ArrPr[PrSelec];
                        MVector vecEdt;
                        TxtEditProducto(vecEdt);
                        int SwitchEdit=SeleccionMenuAnim(vecEdt.GetCd(),54,12,6,2,4,8);
                        CargarProducto(p,SwitchEdit,0);
                    }
                archP.GuardarProducto(p);
                system("cls");
                rlutil::hidecursor();
        }else{
            int idPr;
            ArchivoProductos archP("Productos.dat");
            rlutil::locate(40, 5);
            cout<<"Ingrese el id del producto: ";
            cin>>idPr; LimpiarBuffer();

            int posP=archP.BuscarProducto(idPr);
            while(posP<0){
                rlutil::locate(40, 5);
                cout<<"Producto inexistente reingrese id de producto: ";
                cin>>idPr; LimpiarBuffer();
                posP =archP.BuscarProducto(idPr);
                system("cls");
            }

            p=archP.LeerProducto(posP);
            if(p.GetEstado()==false){
                system("cls");
                rlutil::locate(40,5); cout<<"El registro ya se elimino desea restauralo?";
                rlutil::locate(55,7); cout<<"Si";
                rlutil::locate(55,8); cout<<"No";
                if(SeleccionMenus(53,7,1,1)==0){
                p.SetEstado(true);
                archP.GuardarProducto(p);
                }
            }else{p.SetEstado(false);archP.GuardarProducto(p);}
        }
    }

    void CargaDirecta(){
     ArchivoProductos archP("Productos.dat");
     Producto p;

      p.CargarProducto();
      if(archP.GuardarProducto(p))
        {
         cout<<"producto guardado correctamente";
        }
      else
        {
         cout<<"fallo al guradardar el producto";
        }

}

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

        vector<Cliente> ClOrdenados;

        Cliente cl;
        for(int i; i<cantReg; i++){
        archCl.LeerCliente(i, cl);
            if(cl.GetEstado()==estado){ClOrdenados.push_back(cl);}
            }

        char abc[54]{'A', 'a', 'B', 'b', 'C', 'c', 'D', 'd', 'E', 'e', 'F', 'f', 'G', 'g', 'H', 'h', 'I', 'i', 'J', 'j', 'K', 'k', 'L', 'l', 'M', 'm', 'N', 'n', 'Ñ', 'ñ', 'O', 'o', 'P', 'p', 'Q', 'q', 'R', 'r', 'S', 's', 'T', 't', 'U', 'u', 'V', 'v', 'W', 'w', 'X', 'x', 'Y', 'y', 'Z', 'z'};

        int tamVecCl= ClOrdenados.size();
            for(int i=0; i<54; i++){
                for(int a=0; a<tamVecCl; a++){
                    string Apellido= ClOrdenados[a].GetApellido();
                    if(Apellido[0]==abc[i]){MostrarCliente(ClOrdenados[a]);}
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

                                ///VENTA///
//------------------------------------------------------------------------//
    void CargarVenta(Venta &v, const char *cuit, double IMPORTE, bool opcionCarga){

        system("cls");
        ArchivoVentas archV("Ventas.dat");

        int numeroV,dia,mes,siglo;
        Fecha fech;
        bool estado;
        int cantReg= archV.CantidadRegistros(sizeof(Venta));

        if(opcionCarga){                                    //
                                                            // Carrito
            numeroV=cantReg+1;                              //
            v.SetNumeroVenta(numeroV);
        }else{
            bool opcion;
            rlutil::locate(35,5); cout << "Desea ingresar una venta nueva o editar una existente?" << endl;
            rlutil::locate(57,8); cout << "Nueva Venta";
            rlutil::locate(57,9); cout << "Editar Existente";
                    switch(SeleccionMenus(55, 8, 1, 1)){
                    case(0):{opcion=1;}
                    break;

                    case(1):{opcion=0;}
                    break;
                    }
            if(opcion){

                numeroV=cantReg+1;
                v.SetNumeroVenta(numeroV);
                v.SetImporteVenta(0);
            }else{
                rlutil::locate(35,5); cout << "Ingrese numero de venta a editar: ";
                cin >> numeroV; LimpiarBuffer();

                while(archV.BuscarVenta(numeroV-1)<0){

                    system("cls");
                    rlutil::locate(43,5); cout << "Numero de venta inexistente" << endl;
                    rlutil::locate(43,6); cout << "Reingrese numero de venta: ";
                    cin >> numeroV; LimpiarBuffer();
                }
                v.SetNumeroVenta(numeroV);
            }
        }

        system("cls");
        v.SetCuit(cuit);
        cout << endl;

        rlutil::locate(40,5); cout<<"Seleccione la fecha de la venta: "<<endl;
        rlutil::locate(40,6); cout<<"Dia: ";
        dia=SeleccionCantidad(45,6,31,1);

        rlutil::locate(40,6); cout<<"Mes: ";
        mes=SeleccionCantidad(45,6,12,1);

        rlutil::locate(40,6); cout<<"Anio: ";
        siglo=SeleccionCantidad(45,6,2025,2022);

        v.SetFechaVenta(dia,mes,siglo);
        cout << endl;

        if(opcionCarga){
            v.SetImporteVenta(IMPORTE);
        }

        system("cls");
            rlutil::locate(47,5); cout << "Seleccione el estado de venta";
            rlutil::locate(57,8); cout << "Activo";
            rlutil::locate(57,9); cout << "Inactivo";
                    switch(SeleccionMenus(55,8,1,1)){
                    case(0):{estado=1;v.SetEstado(estado);}
                    break;
                    case(1):{estado=0;v.SetEstado(estado);}
                    break;
                    }
        cout << endl;
        rlutil::hidecursor();
        system("cls");
    }

    void MostrarVenta(Venta &Venta){
    cout<<"El numero de venta es: "<<Venta.GetNumeroVenta()<<endl;
    cout<<"El cuil de la venta es: "<<Venta.GetCuit()<<endl;
    Venta.MostrarVentafecha();
    cout << std::fixed << std::setprecision(0);
    cout<<"El importe de la venta es: "<<Venta.GetImporteVenta()<<endl;
    cout<<"//////////////////////////////////////////////"<<endl;
    }

    void BuscarVenta(int opcion){

        ArchivoVentas archV("Ventas.dat");
        int cantReg= archV.CantidadRegistros(sizeof(Venta));
        Venta v;

        switch(opcion){
    case 0:{
        int numVenta;
        system("cls");
        rlutil::locate(35,5);
        cout << "Ingrese numero de venta(entre 1 y " << cantReg << ") :";
        cin >> numVenta; LimpiarBuffer(); cout << endl;
        while(numVenta<1||numVenta>cantReg){
            system("cls");
            rlutil::locate(35,5);
            cout << "Ingrese un numero de venta valido(entre 1 y " << cantReg << ") :";
            cin >> numVenta; LimpiarBuffer();
        }
        for(int i=0; i<cantReg; i++){
            v= archV.LeerVenta(i);
            if(v.GetNumeroVenta()==numVenta){MostrarVenta(v);}
        }
    }
    system("pause");
    system("cls");
    break;

    case 1:{
        ArchivoClientes archCl("Clientes.dat");
        char CUIT[30]{};

        system("cls");
        rlutil::locate(50,5); cout << "Ingrese CUIT: ";
        cin >> CUIT; LimpiarBuffer();
        cout << endl;

        int pos;
        while((pos=archCl.BuscarCliente(CUIT))<0){
            system("cls");
            rlutil::locate(40,5); cout << "Cliente inexistente reingrese CUIT: ";
            cin >> CUIT; LimpiarBuffer();
        }

        for(int i=0; i<cantReg; i++){
            v=archV.LeerVenta(i);
            if(strcmp(v.GetCuit(),CUIT)==0){MostrarVenta(v);}
        }
        system("pause");
        system("cls");
    }
    break;

    case 2:{
        system("cls");
        vector<Venta> vecVtOrdenadas;
        int Dia1, Mes1, Anio1, Dia2, Mes2, Anio2;

        rlutil::locate(40,5); cout<<"Seleccione la fecha inicial del rango: "<<endl;
        rlutil::locate(40,6); cout<<"Dia: ";
        Dia1=SeleccionCantidad(45,6,31,1);

        rlutil::locate(40,6); cout<<"Mes: ";
        Mes1=SeleccionCantidad(45,6,12,1);

        rlutil::locate(40,6); cout<<"Anio: ";
        Anio1=SeleccionCantidad(45,6,2025,2022);

        cout << endl;
        Fecha fMin(Dia1,Mes1,Anio1);
        system("cls");
        //----------------------------------------------------//

        rlutil::locate(40,5); cout<<"Seleccione la fecha final del rango: "<<endl;
        rlutil::locate(40,6); cout<<"Dia: ";
        Dia2=SeleccionCantidad(45,6,31,1);

        rlutil::locate(40,6); cout<<"Mes: ";
        Mes2=SeleccionCantidad(45,6,12,1);

        rlutil::locate(40,6); cout<<"Anio: ";
        Anio2=SeleccionCantidad(45,6,2025,2022);
        cout << endl;

        Fecha fMax(Dia2,Mes2,Anio2);

        Fecha fAct;
        int dia, mes, anio;
        for(int i=0; i<cantReg; i++){

            v= archV.LeerVenta(i);
            fAct= v.GetFecha();
            dia=fAct.getDia(); mes=fAct.getMes(); anio=fAct.getAnio();
            if((dia>=fMin.getDia()&&mes>=fMin.getMes()&&anio>=fMin.getAnio())&&(dia<=fMax.getDia()&&mes<=fMax.getMes()&&anio<=fMax.getAnio())){

                MostrarVenta(v);
            }
        }
        system("pause");
    }
        }



    }

    void GuardarRegistroVenta(Venta &v){

        ArchivoVentas archV("Ventas.dat");
        archV.GuardarVenta(v);
    }

    void ListadoDeVentas(){

        system("cls");
        bool estado;
        rlutil::locate(35,5);
        cout << "Selecione el estado de ventas que desea listar" << endl;

        rlutil::locate(50,8);
        cout<<"Borradas";
        rlutil::locate(50,9);
        cout<<"Listadas";

        estado=SeleccionMenus(48,8,1,1);

        ArchivoVentas archV("Ventas.dat");
        int cantReg=archV.CantidadRegistros(sizeof(Venta));

        vector<Venta> VtOrdenadas;

        Venta v;
        for(int i=0; i<cantReg; i++){
            archV.LeerVenta(i, v);
            if(v.GetEstado()==estado){
                //MostrarVenta(v);
                VtOrdenadas.push_back(v);
                }
            }

        bool ban=true;
        int tamVecV=VtOrdenadas.size();
        while(ban){

            int contVtOrdenadas=0;
            for(int i=0; i<tamVecV; i++){

                if(i!=tamVecV-1){

                    if(VtOrdenadas[i].GetImporteVenta()<VtOrdenadas[i+1].GetImporteVenta()){

                        Venta v;
                        v= VtOrdenadas[i+1];
                        VtOrdenadas[i+1]=VtOrdenadas[i];
                        VtOrdenadas[i]=v;
                        contVtOrdenadas++;
                    }
                }
            }
                if(contVtOrdenadas==0){
                    ban=false;
                }
        }

            for(int i=0; i<tamVecV; i++){
                MostrarVenta(VtOrdenadas[i]);
            }

        system("pause");
        system("cls");
    }

    void MenuRegistroVentas(){

        system("cls");
        rlutil::locate(50,6);cout<<"<Guardar/Editar registro>"<<endl;
        rlutil::locate(50,7);cout<<"<Eliminar Registro>"<<endl;
        int opcion=SeleccionMenus(49,6,1,1);

        Venta v;
        Cliente cl;
        if(opcion==0){
                if(CargarCliente(cl,1)==1){GuardarRegistroCliente(cl, 0);}
                CargarVenta(v, cl.GetCuit(), 0, 0);
                GuardarRegistroVenta(v);
        }else{
            int numVent;
            ArchivoVentas archV("Ventas.dat");
            rlutil::locate(40, 5);
            cout<<"Ingrese el numero de venta: ";
            cin>>numVent; LimpiarBuffer();

            int posV=archV.BuscarVenta(numVent);
            while(posV<0){
                cout<<"Venta inexistente reingrese numero de venta: ";
                cin>>numVent; LimpiarBuffer();
                posV =archV.BuscarVenta(numVent);
                system("cls");
            }

            v=archV.LeerVenta(posV);
            v.SetEstado(false);
            archV.GuardarVenta(v);
        }
    }

                                ///DETALLE VENTA///
//------------------------------------------------------------------------//
    bool CargarDetalleVenta(DetalleVenta &dv, int NUMVENTA, int IDPRODUCTO, int CANTIDAD, bool opcionCarga){

        rlutil::showcursor(); system("cls");
        ArchivoDetalleVentas archDV("DetalleVentas.dat");
        ArchivoVentas archV("Ventas.dat");
        ArchivoProductos archP("Productos.dat");

        int cantRegV= archV.CantidadRegistros(sizeof(Venta));
        int numeroventa, idproducto, cantidad;
        Producto p;
        int posP;

        if(opcionCarga){
            posP=archP.BuscarProducto(IDPRODUCTO);
            p=archP.LeerProducto(posP);
            dv.SetNumeroVentaDT(NUMVENTA);  //  Carrito
            dv.SetIdProductoDT(IDPRODUCTO); //
            dv.SetCantidad(CANTIDAD);
            dv.SetPrecioProductoDT(p.GetPrecio());
        }else{
            do{
                rlutil::locate(30, 5);
                cout<<"Ingrese un numero de venta existente (entre 1 y " << cantRegV << "): ";
                cin>>numeroventa; LimpiarBuffer(); cout<<endl;
                system("cls");
            }while(numeroventa<0||numeroventa>cantRegV);
            dv.SetNumeroVentaDT(numeroventa);

            rlutil::locate(30,5);
            cout<<"Ingrese el numero de id del producto: ";
            cin>>idproducto; LimpiarBuffer();
            do{
                posP=archP.BuscarProducto(idproducto);
                while(posP<0){
                    system("cls");
                    rlutil::locate(35,5); cout<<"Producto inexistente reingrese id: ";
                    cin>>idproducto; LimpiarBuffer();
                }
                p=archP.LeerProducto(posP);
                if(p.GetEstado()==false){
                    system("cls");
                    rlutil::locate(35,5); cout<<"Producto inactivo reingrese id o 0 para salir: ";
                    cin>>idproducto; LimpiarBuffer();
                    if(idproducto==0){return false;}
                }
                if(p.GetStock()==0){
                    system("cls");
                    rlutil::locate(35,5); cout<<"Producto sin stock, reingrese id o 0 para salir: ";
                    cin>>idproducto; LimpiarBuffer();
                    if(idproducto==0){return false;}
                }
            }while(p.GetEstado()==false||p.GetStock()==0);
            dv.SetIdProductoDT(idproducto);
            cout << endl;

            int stock= p.GetStock();
            system("cls");
            rlutil::locate(30,5);
            cout << "Ingrese la cantidad requerida(minimo 1, maximo " << stock << "): ";
            cin >> cantidad; LimpiarBuffer();
            while(dv.SetCantidad(cantidad)==0||cantidad>stock)
                {
                system("cls");
                rlutil::locate(30,5);
                cout << "Reingrese la cantidad (minimo 1, maximo " << stock << "): ";
                cin >> cantidad; LimpiarBuffer();
                }
            cout << endl;
            dv.SetPrecioProductoDT(p.GetPrecio());
        }
        p.SetStock(p.GetStock()-dv.GetCantidad());
        archP.GuardarProducto(p);
        if(!opcionCarga){
            Venta v;
            for(int i=0; i<cantRegV; i++){
                v=archV.LeerVenta(i);
                if(v.GetNumeroVenta()==dv.GetNumeroVentaDT()){
                    double importeActulizado;
                    importeActulizado=v.GetImporteVenta()+dv.GetPrecioProducto()*dv.GetCantidad();
                    v.SetImporteVenta(importeActulizado);
                    archV.GuardarVenta(v);
                    return true;
                }
            }
        }
        rlutil::hidecursor(); system("cls");
        return true;
    }

    void MostrarDetalleVenta(DetalleVenta &dv){
       cout<<"El numero de venta es: "<<dv.GetNumeroVentaDT()<<endl;
       cout << std::fixed << std::setprecision(0);
       cout<<"El precio del producto: $"<<dv.GetPrecioProducto()<<endl;
       cout<<"El numero de id del producto es: "<<dv.GetIdProductoDT()<<endl;
       cout<<"La cantidad de productos comprados: "<<dv.GetCantidad()<<endl;
       cout<<"//////////////////////////////////////////////"<<endl;
       }

    void GuardarRegistroDetalleVenta(DetalleVenta &dv, bool opcionSeguir){

        ArchivoDetalleVentas archDV("DetalleVentas.dat");
        bool seguir=true;
        system("cls");
        while(seguir){
            archDV.GuardarDetalleVenta(dv);
            if(!opcionSeguir){return;}
            rlutil::locate(40,5);
            cout << "Desea ingresar otro detalle de venta?";
            rlutil::locate(56,7);
            cout<<"si";
            rlutil::locate(56,8);
            cout<<"no";
                    switch(SeleccionMenus(55, 7, 1, 1))
                    {
                    case(0):{
                    seguir=1;
                    }
                    break;
                    case(1):{
                    seguir=0;
                    }
                    break;
                    }
            system("cls");
            if(seguir){
            CargarDetalleVenta(dv,0,0,0,false);
            system("cls");
            rlutil::locate(53,5);
            cout << "Que desea hacer";
            rlutil::locate(56,7);
            cout<<"Guardar";
            rlutil::locate(56,8);
            cout<<"Descartar";
                    switch(SeleccionMenus(53, 7, 1, 1))
                    {
                    case(0):{
                    seguir=1;
                    }
                    break;
                    case(1):{
                    seguir=0;
                    }
                    break;
                    }

                system("cls");
                if(!seguir){
                    return;
                }
            }
        }
    }

    void ListadoDetalleVentasPorNumeroDeVenta(){

        rlutil::showcursor();
        system("cls");
        int numeroventa;

        ArchivoVentas archV("Ventas.dat");
        int cantRegV= archV.CantidadRegistros(sizeof(Venta));

        ArchivoDetalleVentas archDV("DetalleVentas.dat");
        int cantRegDv=archDV.CantidadRegistros(sizeof(DetalleVenta));

        rlutil::locate(35,5);
        cout << "Ingrese un numero de venta existente (entre 1 y " << cantRegV << "): ";
        cin >> numeroventa; LimpiarBuffer();

        system("cls");
        while(numeroventa<0||numeroventa>cantRegV){
            rlutil::locate(35,6);
            cout << "Reingrese un numero de venta entre 1 y " << cantRegV << ": ";
            cin >> numeroventa; LimpiarBuffer();
            int pos=archV.BuscarVenta(numeroventa);
            Venta v=archV.LeerVenta(pos);
            if(v.GetEstado()==false){rlutil::locate(35,7); cout<<"Venta inactiva"; rlutil::getkey(); system("cls");}
        }

        DetalleVenta dv;
        for(int i=0; i<cantRegDv; i++){
            archDV.LeerDetalleDeVenta(i, dv);
            if(dv.GetNumeroVentaDT()==numeroventa){
                MostrarDetalleVenta(dv);
                }
        }
        system("pause");
        system("cls");
        rlutil::hidecursor();
    }


                                ///COMPRA///
//------------------------------------------------------------------------//
    void CopiarYOrdenarProductos(MVector &vecPrMod, int tipoPr, bool estado){

        ArchivoProductos archPr("Productos.dat");
        int cantReg=archPr.CantidadRegistros(sizeof(Producto));

        int tamVecProd=vecPrMod.GetTam(sizeof(Producto));
        Producto pr;
        for(int i=0; i<cantReg; i++){
            archPr.LeerProducto(i, pr);
            if(pr.GetTipoEquipo()==tipoPr&&pr.GetEstado()==estado&&pr.GetStock()>0){
                //MostrarProducto(pr);
                vecPrMod.Agregar(pr);
                }
            }

        bool ban=true;
        tamVecProd=vecPrMod.GetTam(sizeof(Producto));
        Producto *arrPrMod=vecPrMod.GetPr();
        while(ban){

                int contPrOrdenados=0;
            for(int i=0; i<tamVecProd; i++){

                if(i!=tamVecProd-1){
                    if(arrPrMod[i].GetStock()<arrPrMod[i+1].GetStock()){
                        Producto p;
                        p= arrPrMod[i+1];
                        arrPrMod[i+1]=arrPrMod[i];
                        arrPrMod[i]=p;
                        contPrOrdenados++;
                    }
                }
            }
            if(contPrOrdenados==0){
                            ban=false;
            }
        }

    }

    void ListadoDeProductosCompra(MVector &vecPr){

        int tamVecPr=vecPr.GetTam(sizeof(Producto));
        int SaltDeLin=0;

        rlutil::locate(42,9);
        cout << "|------------------------------------------------|" << endl;

        if(tamVecPr==0){
            rlutil::locate(48,10);
            cout << "  Sin Productos que mostrar <SALIR>" << endl;
            return;
        }

        Producto *ArrPrs=vecPr.GetPr();
        for(int i=0; i<tamVecPr; i++){

            if(i!=0){SaltDeLin+=4;}
            rlutil::locate(48,10+SaltDeLin);
            cout << ArrPrs[i].GetMarca()<< " " <<ArrPrs[i].GetNombreProducto() << endl;
            rlutil::locate(48,11+SaltDeLin);
            cout << std::fixed << std::setprecision(0);
            cout << "Precio: " << ArrPrs[i].GetPrecio() << endl;
            rlutil::locate(48,12+SaltDeLin);
            cout << "Stock: " << ArrPrs[i].GetStock() << endl;
            rlutil::locate(42,13+SaltDeLin);
            cout << "|------------------------------------------------|" << endl;
        }
        SaltDeLin+=4;
        rlutil::locate(48,10+SaltDeLin);
        cout << "<SALIR>" << endl;
    }

    int MenuProductosCompra(MVector &vecPrMod, MVector &vecPrSelec){

        ListadoDeProductosCompra(vecPrMod);
        int TotalPr=vecPrMod.GetTam(sizeof(Producto));
        int IndicePrSelec= SeleccionMenus(47,10,TotalPr,4);
        if(IndicePrSelec==TotalPr){return-1;}
        system("cls");

        Producto *prM=vecPrMod.GetPr();
        Producto *prS=vecPrSelec.GetPr();

        int maximo=prM[IndicePrSelec].GetStock();
        rlutil::locate(48,10); cout << "Seleccione Cantidad:";
        int CantPrSelec= SeleccionCantidad(48,11,maximo,0);
        if(CantPrSelec==0){return-1;};

        prM[IndicePrSelec].SetStock(prM[IndicePrSelec].GetStock()-CantPrSelec);

        bool ban=true;
        int tamVecPrSelec=vecPrSelec.GetTam(sizeof(Producto));
        for(int i=0; i<tamVecPrSelec; i++){
            if(prM[IndicePrSelec].GetIdProducto()==prS[i].GetIdProducto()){
                prS[i]=prM[IndicePrSelec];
                ban=false;
            }
        }
        if(ban){vecPrSelec.Agregar(prM[IndicePrSelec]);}
        return 0;
    }

    void ListadoDeProductosCarrito(MVector &vecPrSelec, MVector &vecPrOrg){

        int tamVecPrSelec=vecPrSelec.GetTam(sizeof(Producto));
        int SaltDeLin=0, cont=0;
        double ImporteTotal=0;

        rlutil::locate(42,9);
        cout << "|------------------------------------------------|" << endl;
        if(tamVecPrSelec==0){
            rlutil::locate(48,10);
            cout << "  |Carrito Vacio| <SALIR>" << endl;
            return;
        }

        int cantPrSelec;
        Producto *arrPrS=vecPrSelec.GetPr();
        for(int i=0; i<tamVecPrSelec; i++){

            cantPrSelec=CalculoCantidadProductosSeleccionados(vecPrSelec,vecPrOrg,i);

            if(arrPrS[i].GetEstado()==true){

                cont++;
                if(i!=0&&cont>1){SaltDeLin+=4;}
                ImporteTotal+=arrPrS[i].GetPrecio()*cantPrSelec;
                rlutil::locate(48,10+SaltDeLin);
                cout << arrPrS[i].GetMarca()<< " " <<arrPrS[i].GetNombreProducto() << endl;
                rlutil::locate(48,11+SaltDeLin);
                cout << std::fixed << std::setprecision(0);
                cout << "Precio: " << arrPrS[i].GetPrecio() << endl;
                rlutil::locate(48,12+SaltDeLin);
                cout << "Cantidad: " << cantPrSelec << endl;
                rlutil::locate(42,13+SaltDeLin);
                cout << "|------------------------------------------------|" << endl;
            }
        }
        if(cont==0){
            rlutil::locate(48,10);
            cout << "|Carrito Vacio| " << "<SALIR>" << endl;
            return;
        }
        SaltDeLin+=1;
        rlutil::locate(48,13+SaltDeLin);
        cout << std::fixed << std::setprecision(0);
        cout << "<SALIR>          |IMPORTE TOTAL: $" << ImporteTotal << "|" << endl;
    }

    void MenuCarrito(MVector &vecPrSelec, MVector &vecPrOrg, MVector &vecPrMod){

        bool ban=true;
        Producto *arrPrSelec=vecPrSelec.GetPr(),*arrPrOrg=vecPrOrg.GetPr(),*arrPrMod=vecPrMod.GetPr();

        do{
            int TamVecPrSelec=vecPrSelec.GetTam(sizeof(Producto)), TotalPr=0;
            for(int i=0; i<TamVecPrSelec; i++){if(arrPrSelec[i].GetEstado()==true){TotalPr++;}}
            ListadoDeProductosCarrito(vecPrSelec,vecPrOrg);
            int IndicePrSelec= SeleccionMenus(47,10,TotalPr,4);
            if(IndicePrSelec==TotalPr){return;}

            system("cls");
            rlutil::locate(48,10); cout << "Eliminar producto?" << endl;
            rlutil::locate(48,11); cout << "No" << endl;
            rlutil::locate(48,12); cout << "Si" << endl;
            int opcion=SeleccionMenus(47,11,1,1);
            switch(opcion){
            case(1):
                arrPrSelec[IndicePrSelec].SetEstado(false);
                int tamVecPrMod=vecPrMod.GetTam(sizeof(Producto));
                for(int i=0; i<tamVecPrMod; i++){
                    if(arrPrMod[i].GetIdProducto()==arrPrSelec[IndicePrSelec].GetIdProducto()){
                        arrPrMod[i]=arrPrOrg[i];
                    }
                }
            break;
            }
        }while(ban);
    }

    void GuardarVentaCarrito(MVector &vecPrSelec, MVector &vecPrOrg, MVector &vecPrMod, bool &salida){

        int tamVecPrselec=vecPrSelec.GetTam(sizeof(Producto)), tamVecPrMod=vecPrMod.GetTam(sizeof(Producto)), contadorParaSalida=0;
        Producto *arrPrSelec=vecPrSelec.GetPr(), *arrPrMod=vecPrMod.GetPr();
        for(int i=0;i<tamVecPrselec;i++){if(arrPrSelec[i].GetEstado()==true){contadorParaSalida++;}}
        if(tamVecPrselec==0||contadorParaSalida==0){ rlutil::locate(48,10); cout << "|CARRITO VACIO|";rlutil::locate(48,11);system("pause");return;}
        rlutil::locate(48,10); cout << "Guardar y finalizar compra? " << endl;
        rlutil::locate(48,11); cout << "No" << endl;
        rlutil::locate(48,12); cout << "Si" << endl;
        int opcion=SeleccionMenus(47,11,1,1);

        Cliente cl;
        Venta v;
        //DetalleVenta dv;
        MVector vecDv;

        if(opcion==0){return;}else{
            double ImporteTotal= CalculoImporteTotal(vecPrSelec,vecPrOrg);

            CargarCliente(cl,true);

            CargarVenta(v,cl.GetCuit(),ImporteTotal,true);

            for(int i=0; i<tamVecPrselec; i++){
                if(arrPrSelec[i].GetEstado()==true){
                int cantPrSelec= CalculoCantidadProductosSeleccionados(vecPrSelec,vecPrOrg,i);
                DetalleVenta dv(v.GetNumeroVenta(),arrPrSelec[i].GetPrecio()*cantPrSelec,arrPrSelec[i].GetIdProducto(),cantPrSelec);
                vecDv.Agregar(dv);
                }
            }
        }

        rlutil::locate(40,10); cout << "Guardar y finalizar compra? " << endl;
        rlutil::locate(48,11); cout << "No" << endl;
        rlutil::locate(48,12); cout << "Si" << endl;
        int opcion1=SeleccionMenus(47,11,1,1);

        int tamVecDv=vecDv.GetTam(sizeof(DetalleVenta));
        DetalleVenta *arrDv=vecDv.GetDtV();
        if(opcion1==0){return;}else{
            GuardarRegistroCliente(cl,false);
            GuardarRegistroVenta(v);
            for(int i=0;i<tamVecDv; i++){GuardarRegistroDetalleVenta(arrDv[i],false);}
            for(int i=0;i<tamVecPrMod; i++){if(arrPrMod[i].GetStock()==0){arrPrMod[i].SetEstado(0);}GuardarRegistroProducto(arrPrMod[i]);}
        }
        salida=false;
    }

    double CalculoImporteTotal(MVector &vecPrSelec, MVector &vecPrOrg){

        int tamVecSelec=vecPrSelec.GetTam(sizeof(Producto));
        Producto *arrPrSelec=vecPrSelec.GetPr();
        double ImporteTotal; int cantPrSelec;

        for(int i=0; i<tamVecSelec; i++){
            cantPrSelec=CalculoCantidadProductosSeleccionados(vecPrSelec,vecPrOrg,i);
            if(arrPrSelec[i].GetEstado()==true){ImporteTotal+=arrPrSelec[i].GetPrecio()*cantPrSelec;}
        }
        return ImporteTotal;
    }

    int CalculoCantidadProductosSeleccionados(MVector &vecPrSelec, MVector &vecPrOrg, int indice){

        int tamVecPrOrg=vecPrOrg.GetTam(sizeof(Producto));
        Producto *arrPrs=vecPrSelec.GetPr(), *arrPrOg=vecPrOrg.GetPr();

            int cantPrSelec;
            for(int a=0; a<tamVecPrOrg; a++){
                if(arrPrOg[a].GetIdProducto()==arrPrs[indice].GetIdProducto()){
                    cantPrSelec=arrPrOg[a].GetStock()-arrPrs[indice].GetStock();
                    return cantPrSelec;
                }
            }
    }














































                                ///INFORMES///
//------------------------------------------------------------------------//

    void RecaudacionAnual(){
     int anio=0,i=0;
     float importe=0,meses[12]={0};
     Fecha fech;
     Venta ven;
     ArchivoVentas archV("Ventas.dat");
    int cantReg= archV.CantidadRegistros(sizeof(Venta));
        rlutil::locate(45,5);
        cout<<"Ingrese el anio que desea consultar: ";
        cin>>anio; LimpiarBuffer();
        for(i=0;i<cantReg;i++)
        {
        archV.LeerVenta(i,ven);
        fech=ven.GetFecha();
        if(fech.getAnio()==anio&&ven.GetEstado()==true)
        {
        switch(fech.getMes())
        {
    case(1):
        {
        meses[0]=meses[0]+ven.GetImporteVenta();
        }
    break;
    case(2):
        {
        meses[1]=meses[1]+ven.GetImporteVenta();
        }
    break;
    case(3):
        {
        meses[2]=meses[2]+ven.GetImporteVenta();
        }
    break;
    case(4):
        {
        meses[3]=meses[3]+ven.GetImporteVenta();
        }
    break;
    case(5):
        {
        meses[4]=meses[4]+ven.GetImporteVenta();
        }
    break;
    case(6):
        {
        meses[5]=meses[5]+ven.GetImporteVenta();
        }
    break;
    case(7):
        {
        meses[6]=meses[6]+ven.GetImporteVenta();
        }
    break;
    case(8):
        {
        meses[7]=meses[7]+ven.GetImporteVenta();
        }
    break;
    case(9):
        {
        meses[8]=meses[8]+ven.GetImporteVenta();
        }
    break;
    case(10):
        {
        meses[9]=meses[9]+ven.GetImporteVenta();
        }
    break;
    case(11):
        {
        meses[10]=meses[10]+ven.GetImporteVenta();
        }
    break;
    case(12):
        {
        meses[11]=meses[11]+ven.GetImporteVenta();
        }
    break;
        }
        importe=importe+ven.GetImporteVenta();
        }
        }
        if(importe==0)
        {
        system("cls");
        rlutil::locate(47,5);
        cout<<"No se recaudo nada el anio "<<anio;
        rlutil::getkey();
        }
        else
        {
        system("cls");
        cout << std::fixed << std::setprecision(0);
        rlutil::locate(52,5);
        cout<<"Enero= $"<<meses[0];
        rlutil::locate(52,6);
        cout<<"Febrero= $"<<meses[1];
        rlutil::locate(52,7);
        cout<<"Marzo= $"<<meses[2];
        rlutil::locate(52,8);
        cout<<"Abril= $"<<meses[3];
        rlutil::locate(52,9);
        cout<<"Mayo= $"<<meses[4];
        rlutil::locate(52,10);
        cout<<"Junio= $"<<meses[5];
        rlutil::locate(52,11);
        cout<<"Julio= $"<<meses[6];
        rlutil::locate(52,12);
        cout<<"Agosto= $"<<meses[7];
        rlutil::locate(52,13);
        cout<<"Septiembre= $"<<meses[8];
        rlutil::locate(52,14);
        cout<<"Octubre= $"<<meses[9];
        rlutil::locate(52,15);
        cout<<"Noviembre= $"<<meses[10];
        rlutil::locate(52,16);
        cout<<"Diciembre= $"<<meses[11];
        rlutil::locate(35,18);
        cout<<"Lo que se recaudo en total del "<<anio<<" es de: $"<<importe;
        rlutil::getkey();
        }
    }

    void RecaudacionCliente(){
    int i=0,anio=0;
    char cuit[50];
     float total=0, importe=0;
     Cliente clie;
     Venta ven;
     Fecha fech;
     ArchivoClientes archCl("Clientes.dat");
     ArchivoVentas archV("Ventas.dat");
    int cantReg= archV.CantidadRegistros(sizeof(Venta));
        rlutil::locate(45,5);
        cout<<"Ingrese el cuil del cliente: ";
        cin>>cuit; LimpiarBuffer();
        rlutil::locate(35,5);
        cout<<"Ingrese el anio que desea ver de la recaudacion del cliente: ";
        cin>>anio; LimpiarBuffer();
        archCl.LeerCliente(archCl.BuscarCliente(cuit),clie);
        if(clie.GetEstado()==false||archCl.BuscarCliente(cuit)<0)
        {
        system("cls");
        rlutil::locate(45,5);
        cout<<"cliente borrado o inexistente";
        rlutil::getkey();
        return;
        }

        for(i=0;i<cantReg;i++)
        {
        ven=archV.LeerVenta(i);
        fech=ven.GetFecha();
        if(clie.GetEstado()==true&&fech.getAnio()==anio){
        if(strcmp(ven.GetCuit(),cuit)==0)
        {
        importe=ven.GetImporteVenta();
        total=total+importe;
        }
        }
        }
        if(total==0)
        {
        system("cls");
        rlutil::locate(47,5);
        cout<<"No se recaudo nada con el cliente "<<cuit;
        rlutil::getkey();
        }
        else
        {
        system("cls");
        rlutil::locate(35,5);
        cout << std::fixed << std::setprecision(0);
        cout<<"Lo que se recaudo en total del cliente "<<cuit<<" es de: $"<<total<<endl;
        rlutil::getkey();
        }

    }

    void RecaudacionEquipo(){

    int i=0,f=0,equipo=0;
    float total=0, importe=0;
    DetalleVenta deven;
    Producto prod;

    ArchivoDetalleVentas archD("DetalleVentas.dat");
    ArchivoProductos archprod("Productos.dat");
    int cantRegDv= archD.CantidadRegistros(sizeof(DetalleVenta));
    int cantRegPr= archprod.CantidadRegistros(sizeof(Producto));


        rlutil::locate(45,5);
        cout<<"seleccione el tipo de producto";
        TextoTiposDeProducto();
        equipo=SeleccionMenus(55,8,9,1);
        for(i=0;i<cantRegDv;i++)
        {
        for(f=0;f<cantRegPr;f++){
        deven=archD.LeerDetalleDeVenta(i);
        prod=archprod.LeerProducto(f);
        if(deven.GetIdProductoDT()==prod.GetIdProducto()){
        if(prod.GetTipoEquipo()==equipo+1&&prod.GetEstado()==true)
        {
        importe=deven.GetPrecioProducto()*deven.GetCantidad();
        total=total+importe;
        }
        }
        }
        }
        if(total==0)
        {
        system("cls");
        rlutil::locate(47,5);
        cout<<"No se recaudo nada con el producto";
        rlutil::getkey();
        }
        else
        {
        system("cls");
        rlutil::locate(35,5);
        cout << std::fixed << std::setprecision(0);
        cout<<"Lo que se recaudo en total del producto es de: $"<<total<<endl;
        rlutil::getkey();
        }

    }

    void informetipocliente(){
    int tipocliente=0,acumulador=0,contador=0;
    DetalleVenta deven;
    Cliente cli;
    Venta ven;
    ArchivoVentas arch1("Ventas.dat");
    ArchivoClientes arch2("Clientes.dat");
    ArchivoDetalleVentas arch3("DetalleVentas.dat");
    int cantReg1= arch3.CantidadRegistros(sizeof(DetalleVenta));
    int cantReg2= arch2.CantidadRegistros(sizeof(Cliente));
    int cantReg3= arch1.CantidadRegistros(sizeof(Venta));
    rlutil::locate(45,5);
    cout<<"selecione el tipo de cliente";
    rlutil::locate(40,7);
    cout<<"Particular";
    rlutil::locate(40,8);
    cout<<"Empresa";
    tipocliente=SeleccionMenus(38,7,1,1);
    tipocliente++;

    for(int i=0;i<cantReg2;i++)
    {
    cli=arch2.LeerCliente(i);
    if(cli.GetTipoCliente()==tipocliente)
    {
    for(int f=0;f<cantReg3;f++)
        {
            ven=arch1.LeerVenta(f);
            if(strcmp(ven.GetCuit(),cli.GetCuit())==0)
            {
                for(int a=0;a<cantReg1;a++)
                    {
                    deven=arch3.LeerDetalleDeVenta(a);
                        if(ven.GetNumeroVenta()==deven.GetNumeroVentaDT())
                        {
                        contador=deven.GetCantidad();
                        acumulador=acumulador+contador;
                        }
                    }
            }
        }

    }

    }
    cout << std::fixed << std::setprecision(0);
   cout<<"La cantidad de equipos vendidos por tipo de cliente es de: "<<acumulador;
   rlutil::getkey();

    }





    void LimpiarBuffer(){
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
