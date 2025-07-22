#include <iostream>
#include "menu.h"
#include "Archivo_Clientes.h"
#include "Archivo_Productos.h"
#include "Archivo_Ventas.h"
#include "Archivo_Detalle_Ventas.h"
using namespace std;

                                ///PRODUCTO///
//------------------------------------------------------------------------//
    int CargarProducto(Producto &p){

        ArchivoProductos archP("Productos.dat");
        int id,tipo=0,stock;
        float precio;
        char nombre[50]{},descripcion[500]{}, marca[20]{};
        rlutil::locate(30,5);
        cout<<"Ingrese el id del producto o equipo igual o mayor a 0: ";
        cin>>id; LimpiarBuffer();

        while(p.SetIdProducto(id)==0){
            rlutil::locate(20,5);
            cout<<"el numero tiene que ser mayor o igual a 0 por favor vuelva a cargar el numero: ";
            cin>>id; LimpiarBuffer();
        }
        cout<<endl;
        system("cls");

        if(archP.BuscarProducto(id)>=0){

            system("cls");
            rlutil::locate(30,5);
            cout << "Ya existe un producto con el Id: " << id << " Desea reingresarlo?" << endl;

            bool ban=true;
            do{
                rlutil::hidecursor();
                rlutil::locate(57,8);
                cout<<"NO";
                rlutil::locate(57,9);
                cout<<"SI";
                    switch(SeleccionMenus(56,8,1,1)){

                    case(0):{return 0;}
                    break;

                    case(1):{ban=false;}
                    break;
                    }
                }while(ban);
        }
        rlutil::showcursor();
        system("cls");


        rlutil::locate(35,5);
        cout << "Ingrese nombre del producto: ";
        cin.getline(nombre, 50);
        p.SetNombreProducto(nombre);
        cout<<endl;
        system("cls");

        rlutil::locate(20,5);
        cout<<"Ingrese el precio del producto tienen que ser igual o mayor a 100: $";
        cin>>precio;
        while(p.SetPrecio(precio)==0){
            system("cls");
            rlutil::locate(20,5);
            cout<<"el precio tiene que ser minimo 100 por favor vuelva a cargar el precio: $";
            cin>>precio; LimpiarBuffer();
        }
        cout<<endl;
        system("cls");

        rlutil::locate(20,5);
        cout<<"Ingrese la descripcion del producto(terminada en el caracter #): "<<endl;
        cin.getline(descripcion,500, '#'); LimpiarBuffer();
        p.SetDescripcion(descripcion);
        cout<<endl;
        system("cls");

        rlutil::locate(20,5);
        cout<<"Ingrese la marca a la que pertenece el producto: ";
        cin.getline(marca,20);
        p.SetMarca(marca);
        cout<<endl;
        system("cls");

        rlutil::locate(50,7);
        cout<<"Selecione el tipo de producto";
        TextoTiposDeProducto();
        tipo=SeleccionMenus(56,8,9,1);
        tipo++;
        p.SetTipoEquipo(tipo);
        system("cls");

        rlutil::locate(35,5);
        cout<<"Ingrese el stock del producto: ";
        cin>>stock; LimpiarBuffer();
        while(p.SetStock(stock)==0){
            rlutil::locate(20,5);
            cout<<"el stock no puede ser menor a 0 por favor vuelva a ingresar el stock: ";
            cin>>stock; LimpiarBuffer();
        }
        cout<<endl;
        system("cls");

        rlutil::locate(45,5);
        cout<<"Selecione el estado del producto";
            rlutil::locate(56,7);
            cout<<"inactivo";
            rlutil::locate(56,8);
            cout<<"activo";
            switch(SeleccionMenus(54,7,1,1))
                    {
                    case(0):{
                    p.SetEstado(0);
                    }
                    break;
                    case(1):{
                    p.SetEstado(1);
                    }
                    break;
                    }
        cout<<endl;
        return 1;
            }

    void MostrarProducto(Producto &p){
    cout<<"Id del producto: "<<p.GetIdProducto()<<endl<< endl;
    cout<<"Precio del producto: $"<<fixed << setprecision(0)<<p.GetPrecio()<<endl<< endl;
    cout<<"Descripcion del producto: "<< endl << p.GetDescripcion();
    cout<< endl << endl;
    cout<<"Marca del producto: "<<p.GetMarca()<<endl<< endl;

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
        bool seguir=true;

        while(seguir){
                system("cls");
            archP.GuardarProducto(p);
            rlutil::locate(45,5);
            cout << "¿Desea ingresar otro producto?";
            rlutil::locate(56,7);
            cout<<"si";
            rlutil::locate(56,8);
            cout<<"no";
                    switch(SeleccionMenus(55,7,1,1))
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

            if(seguir){
            CargarProducto(p);
            }
        }
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
                switch(SeleccionMenus(55,8,1,1))
                    {
                    case(0):{
                    archCl.LeerCliente(posCl, cl);
                    return 0;
                    }
                    break;
                    case(1):{
                    cl.SetCuil(cuil);
                    }
                    break;
                    }
        }
        cl.SetCuil(cuil);
        system("cls");
        rlutil::showcursor();


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
            switch(SeleccionMenus(55,8,1,1))
                    {
                    case(0):{
                    tc=1;
                    cl.SetTipoCliente(tc);
                    }
                    break;
                    case(1):{
                    tc=2;
                    cl.SetTipoCliente(tc);
                    }
                    break;
                    }

        system("cls");
        rlutil::locate(43, 5); cout <<"Seleccione estado del cliente ";
            rlutil::locate(54,8); cout<<"Activo";
            rlutil::locate(54,9); cout<<"Inactivo";
            switch(SeleccionMenus(53,8,1,1))
                    {
                    case(0):{
                    cl.SetEstado(1);
                    }
                    break;
                    case(1):{
                    cl.SetEstado(0);
                    }
                    break;
                    }



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
            rlutil::locate(45,5);
            cout << "Desea ingresar otro cliente?";
            rlutil::locate(56,7);
            cout<<"si";
            rlutil::locate(56,8);
            cout<<"no";
                    switch(SeleccionMenus(54,7,1,1))
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
            if(seguir){
            seguir=CargarCliente(cl,0);
                }
            }
            }while(seguir);
        }

    void ListadoDeClientes(){

        system("cls");
        bool estado;
        rlutil::locate(40,5);
        cout << "Selecione el estado del cliente" << endl;
        rlutil::locate(50,8);
        cout<<"Inactivos";
        rlutil::locate(50,9);
        cout<<"Activos";
        estado=SeleccionMenus(48,8,1,1);

        ArchivoClientes archCl("Clientes.dat");
        int cantReg=archCl.CantidadRegistros(sizeof(Cliente));

        vector<Cliente> ClOrdenados;

        Cliente cl;
        for(int i; i<cantReg; i++){
        archCl.LeerCliente(i, cl);
            if(cl.GetEstado()==estado){
                //MostrarCliente(cl);
                ClOrdenados.push_back(cl);
                }
            }

        char abc[54]{'A', 'a', 'B', 'b', 'C', 'c', 'D', 'd', 'E', 'e', 'F', 'f', 'G', 'g', 'H', 'h', 'I', 'i', 'J', 'j', 'K', 'k', 'L', 'l', 'M', 'm', 'N', 'n', 'Ñ', 'ñ', 'O', 'o', 'P', 'p', 'Q', 'q', 'R', 'r', 'S', 's', 'T', 't', 'U', 'u', 'V', 'v', 'W', 'w', 'X', 'x', 'Y', 'y', 'Z', 'z'};

        int tamVecCl= ClOrdenados.size();

            for(int i=0; i<54; i++){
                for(int a=0; a<tamVecCl; a++){

                    string Apellido= ClOrdenados[a].GetApellido();
                    if(Apellido[0]==abc[i]){
                            MostrarCliente(ClOrdenados[a]);
                    }
                }
            }

        system("pause");
        system("cls");
    }

                                ///VENTA///
//------------------------------------------------------------------------//
    void CargarVenta(Venta &v, const char *cuit, double IMPORTE, bool opcionCarga){

        ArchivoVentas archV("Ventas.dat");

        int numeroV,dia,mes,siglo;
        double importe;
        Fecha fech;
        bool estado;

        int cantReg= archV.CantidadRegistros(sizeof(Venta));

        if(opcionCarga){                                    //
                                                            // Carrito
            numeroV=cantReg+1;                              //
            v.SetNumeroVenta(numeroV);
        }else{

            bool opcion;
            system("cls");
            rlutil::locate(35,5); cout << "Desea igresar una venta nueva o editar una existente?" << endl;
            rlutil::locate(57,8); cout << "Nueva Venta";
            rlutil::locate(57,9); cout << "Editar Existente";
                    switch(SeleccionMenus(55, 8, 1, 1))
                    {
                    case(0):{
                    opcion=1;
                    }
                    break;
                    case(1):{
                    opcion=0;
                    }
                    break;
                    }

            if(opcion){

                numeroV=cantReg+1;
                v.SetNumeroVenta(numeroV);
            }else{
                system("cls");
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

        system("cls");
        rlutil::locate(40,5);cout << "Ingrese dia de la venta: ";
        cin >> dia; LimpiarBuffer();

        system("cls");
        rlutil::locate(40,5); cout << "Ingrese mes de la venta:  ";
        cin >> mes; LimpiarBuffer();

        system("cls");
        rlutil::locate(40,5); cout << "Ingrese anio de la venta: ";
        cin >> siglo; LimpiarBuffer();
        v.SetFechaVenta(dia,mes,siglo);
        cout << endl;

        if(opcionCarga){
            v.SetImporteVenta(IMPORTE);
        }else{
        system("cls");
        rlutil::locate(40,5); cout << "Ingrese importe de la venta: $";
        cin >> importe; LimpiarBuffer();
        while(v.SetImporteVenta(importe)==0){
                system("cls");
                rlutil::locate(40,5); cout << "el importe de venta no puede ser 0 o menor a 0: ";
                cin>>importe; LimpiarBuffer();
            }
        cout << endl;
        }

        system("cls");
        rlutil::locate(47,5); cout << "Seleccione el estado de venta";
            rlutil::locate(57,8); cout << "Activo";
            rlutil::locate(57,9); cout << "Inactivo";
                    switch(SeleccionMenus(55,8,1,1))
                    {
                    case(0):{
                    estado=1;
                    v.SetEstado(estado);
                    }
                    break;
                    case(1):{
                    estado=0;
                    v.SetEstado(estado);
                    }
                    break;
                    }
        cout << endl;
    }

    void MostrarVenta(Venta &Venta){
    cout<<"El numero de venta es: "<<Venta.GetNumeroVenta()<<endl;
    cout<<"El cuil de la venta es: "<<Venta.GetCuit()<<endl;
    Venta.MostrarVentafecha();
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
        cin >> numVenta; LimpiarBuffer();
        cout << endl;
        while(numVenta<1||numVenta>cantReg){
            system("cls");
            rlutil::locate(35,5);
            cout << "Ingrese un numero de venta valido(entre 1 y " << cantReg << ") :";
            cin >> numVenta; LimpiarBuffer();
        }
        for(int i=0; i<cantReg; i++){
            v= archV.LeerVenta(i);
            if(v.GetNumeroVenta()==numVenta){
                MostrarVenta(v);
            }
        }
    }
    system("pause");
    system("cls");
    break;
    case 1:{

        ArchivoClientes archCl("Clientes.dat");
        char CUIT[30]{};

        system("cls");
        rlutil::locate(50,5);
        cout << "Ingrese CUIT: ";
        cin >> CUIT; LimpiarBuffer();
        cout << endl;

        int pos;
        while((pos=archCl.BuscarCliente(CUIT))<0){
            system("cls");
            rlutil::locate(40,5);
            cout << "Cliente inexistente reingrese CUIT: ";
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

        rlutil::locate(40,5);
        cout << "Ingrese la fecha inicial del rango: " << endl;
        rlutil::locate(50,6);
        cout << "Dia: ";
        cin >> Dia1; LimpiarBuffer();
        while(Dia1<1||Dia1>31){
            rlutil::locate(70,6);
            cout<<"        ";
            rlutil::locate(40,6);
            cout << "Ingrese un dia valido(1 a 31):";
            cin >> Dia1; LimpiarBuffer();
        }
        rlutil::locate(50,7);
        cout << "Mes: ";
        cin >> Mes1; LimpiarBuffer();
        while(Mes1<1||Mes1>12){
            rlutil::locate(70,7);
            cout<<"        ";
            rlutil::locate(40,7);
            cout << "Ingrese un mes valido(1 a 12): ";
            cin >> Mes1; LimpiarBuffer();
        }
        rlutil::locate(50,8);
        cout << "Anio: ";
        cin >> Anio1; LimpiarBuffer();
        while(Anio1<2020||Anio1>2028){
             rlutil::locate(70,8);
            cout<<"           ";
            rlutil::locate(40,8);
            cout << "Ingrese anio valido(2020 a 2028): ";
            cin >> Anio1; LimpiarBuffer();
        }
        cout << endl;
        Fecha fMin(Dia1,Mes1,Anio1);
        //----------------------------------------------------//
        rlutil::locate(40,9);
        cout << "Ingrese la fecha final del rango: " << endl;
        rlutil::locate(50,10);
        cout << "Dia: ";
        cin >> Dia2; LimpiarBuffer();
        while(Dia2<1||Dia2>31){
            rlutil::locate(70,10);
            cout<<"        ";
            rlutil::locate(40,10);
            cout << "Ingrese un dia valido(1 a 31): ";
            cin >> Dia2; LimpiarBuffer();
        }
        rlutil::locate(50,11);
        cout << "Mes: ";
        cin >> Mes2; LimpiarBuffer();
        while(Mes2<1||Mes2>12){
            rlutil::locate(70,11);
            cout<<"        ";
            rlutil::locate(40,11);
            cout << "Ingrese un mes valido(1 a 12): ";
            cin >> Mes2; LimpiarBuffer();
        }
        rlutil::locate(50,12);
        cout << "Anio: ";
        cin >> Anio2; LimpiarBuffer();
        while(Anio2<2020||Anio2>2028){
            rlutil::locate(70,12);
            cout<<"        ";
            rlutil::locate(40,12);
            cout << "Ingrese anio valido(2020 a 2028): ";
            cin >> Anio2; LimpiarBuffer();
        }
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
        for(int i; i<cantReg; i++){
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
                cout<<"///////////////////////////////////////////"<<endl;
            }

        system("pause");
        system("cls");
    }

                                ///DETALLE VENTA///
//------------------------------------------------------------------------//
    void CargarDetalleVenta(DetalleVenta &dv, int NUMVENTA, int IDPRODUCTO, int CANTIDAD, bool opcionCarga){

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
            rlutil::locate(30, 5);                                                              //
            cout << "Ingrese un numero de venta existente (entre 1 y " << cantRegV << "): ";    //
            cin >> numeroventa; LimpiarBuffer();                                                //
            cout << endl;                                                                       //
            system("cls");                                                                      //
            }while(numeroventa<0||numeroventa>cantRegV);                                        //
            dv.SetNumeroVentaDT(numeroventa);                                                   //
                                                                                                //  Carga simple o edicion de un detalle venta
            rlutil::locate(30,5);                                                               //
            cout << "Ingrese el numero de id del producto: ";                                   //
            cin >> idproducto; LimpiarBuffer();                                                 //
                if((posP=archP.BuscarProducto(idproducto))<0){                                  //
                    system("cls");                                                              //
                    rlutil::locate(35,5);                                                       //
                    cout << "Producto inexistente reingrese id: ";                              //
                    cin >> idproducto; LimpiarBuffer();                                         //
                }                                                                               //
            dv.SetIdProductoDT(idproducto);                                                     //
            cout << endl;                                                                       //

            p=archP.LeerProducto(posP);
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
    }

    void MostrarDetalleVenta(DetalleVenta &dv){
       cout<<"El numero de venta es: "<<dv.GetNumeroVentaDT()<<endl;
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
        cout << "Ingrese un numero de venta entre 1 y " << cantRegV << ": ";
        cin >> numeroventa; LimpiarBuffer();
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
    void CopiarYOrdenarProductos(vector<Producto> &vecPrMod){

        ArchivoProductos archPr("Productos.dat");
        int cantReg=archPr.CantidadRegistros(sizeof(Producto));

        TextoTiposDeProducto();
        int tipo=SeleccionMenus(56,8,9,1);tipo++;
        system("cls");

        int tamVecProd=vecPrMod.size();
        Producto pr;
        for(int i=0; i<cantReg; i++){
            archPr.LeerProducto(i, pr);
            if(pr.GetTipoEquipo()==tipo&&pr.GetEstado()==1&&pr.GetStock()>0){
                //MostrarProducto(pr);
                vecPrMod.push_back(pr);
                }
            }

        bool ban=true;
        tamVecProd=vecPrMod.size();
        while(ban){

                int contPrOrdenados=0;
            for(int i=0; i<tamVecProd; i++){

                if(i!=tamVecProd-1){
                    if(vecPrMod[i].GetStock()<vecPrMod[i+1].GetStock()){
                        Producto p;
                        p= vecPrMod[i+1];
                        vecPrMod[i+1]=vecPrMod[i];
                        vecPrMod[i]=p;
                        contPrOrdenados++;
                    }
                }
            }
            if(contPrOrdenados==0){
                            ban=false;
            }
        }

    }

    void ListadoDeProductosCompra(vector<Producto> &vecPr){

        int tamVecPr=vecPr.size();
        int SaltDeLin=0;

        rlutil::locate(42,9);
        cout << "|------------------------------------------------|" << endl;

        if(tamVecPr==0){
            rlutil::locate(48,10);
            cout << "  Sin Productos que mostrar <SALIR>" << endl;
            return;
        }

        for(int i=0; i<tamVecPr; i++){

            if(i!=0){SaltDeLin+=4;}
            rlutil::locate(48,10+SaltDeLin);
            cout << vecPr[i].GetMarca()<< " " <<vecPr[i].GetNombreProducto() << endl;
            rlutil::locate(48,11+SaltDeLin);
            cout << "Precio: " << vecPr[i].GetPrecio() << endl;
            rlutil::locate(48,12+SaltDeLin);
            cout << "Stock: " << vecPr[i].GetStock() << endl;
            rlutil::locate(42,13+SaltDeLin);
            cout << "|------------------------------------------------|" << endl;
        }
        SaltDeLin+=4;
        rlutil::locate(48,10+SaltDeLin);
        cout << "<SALIR>" << endl;
    }

    int MenuProductosCompra(vector<Producto> &vecPrMod, vector<Producto> &vecPrSelec){

        ListadoDeProductosCompra(vecPrMod);
        int TotalPr=vecPrMod.size();
        int IndicePrSelec= SeleccionMenus(47,10,TotalPr,4);
        if(IndicePrSelec==TotalPr){return-1;}
        system("cls");

        int maximo=vecPrMod[IndicePrSelec].GetStock();
        int CantPrSelec= SeleccionCantidad(maximo,1);
        if(CantPrSelec==0){return-1;};

        vecPrMod[IndicePrSelec].SetStock(vecPrMod[IndicePrSelec].GetStock()-CantPrSelec);

        bool ban=true;
        int tamVecPrSelec=vecPrSelec.size();
        for(int i=0; i<tamVecPrSelec; i++){
            if(vecPrMod[IndicePrSelec].GetIdProducto()==vecPrSelec[i].GetIdProducto()){
                vecPrSelec[i]=vecPrMod[IndicePrSelec];
                ban=false;
            }
        }
        if(ban){vecPrSelec.push_back(vecPrMod[IndicePrSelec]);}
    }

    void ListadoDeProductosCarrito(vector<Producto> &vecPrSelec, vector<Producto> &vecPrOrg){

        int tamVecPrSelec=vecPrSelec.size(), tamVecPrOrg=vecPrOrg.size();
        int SaltDeLin=0, cont=0;
        double ImporteTotal=0;

        rlutil::locate(42,9);
        cout << "|------------------------------------------------|" << endl;
        if(tamVecPrSelec==0){
            rlutil::locate(48,10);
            cout << "  |Carrito Vacio| <SALIR>" << endl;
            return;
        }

        for(int i=0; i<tamVecPrSelec; i++){

            int cantPrSelec;
            for(int a=0; a<tamVecPrOrg; a++){
                if(vecPrOrg[a].GetIdProducto()==vecPrSelec[i].GetIdProducto()){
                    cantPrSelec=vecPrOrg[a].GetStock()-vecPrSelec[i].GetStock();
                }
            }


            if(vecPrSelec[i].GetEstado()==true){

                cont++;
                if(i!=0&&cont>1){SaltDeLin+=4;}
                ImporteTotal+=vecPrSelec[i].GetPrecio()*cantPrSelec;
                rlutil::locate(48,10+SaltDeLin);
                cout << vecPrSelec[i].GetMarca()<< " " <<vecPrSelec[i].GetNombreProducto() << endl;
                rlutil::locate(48,11+SaltDeLin);
                cout << "Precio: " << vecPrSelec[i].GetPrecio() << endl;
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
        cout << "<SALIR>          |IMPORTE TOTAL:" << ImporteTotal << "|" << endl;
    }

    void MenuCarrito(vector<Producto> &vecPrSelec, vector<Producto> &vecPrOrg, vector<Producto> &vecPrMod){

        bool ban=true;

        do{
            int TamVecPrSelec=vecPrSelec.size(), TotalPr=0;
            for(int i=0; i<TamVecPrSelec; i++){if(vecPrSelec[i].GetEstado()==true){TotalPr++;}}
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
                vecPrSelec[IndicePrSelec].SetEstado(false);
                int tamVecPrMod=vecPrMod.size();
                for(int i=0; i<tamVecPrMod; i++){
                    if(vecPrMod[i].GetIdProducto()==vecPrSelec[IndicePrSelec].GetIdProducto()){
                        vecPrMod[i]=vecPrOrg[i];
                    }
                }
            break;
            }
        }while(ban);
    }

    void GuardarVentaCarrito(vector<Producto> &vecPrSelec, vector<Producto> &vecPrOrg){

        int tamVecPrselec=vecPrSelec.size(), cantPrSelec;
        rlutil::locate(48,10); cout << "Guardar y finalizar compra? " << endl;
        rlutil::locate(48,11); cout << "No" << endl;
        rlutil::locate(48,12); cout << "Si" << endl;
        int opcion=SeleccionMenus(47,11,1,1);

        Cliente cl;
        Venta v;
        vector<DetalleVenta> VecDv(tamVecPrselec);

        if(opcion==0){return;}else{
            double ImporteTotal= CalculoImporteTotal(vecPrSelec,vecPrOrg);

            CargarCliente(cl,true);

            CargarVenta(v,cl.GetCuit(),ImporteTotal,true);

            for(int i=0; i<tamVecPrselec; i++){
                if(vecPrSelec[i].GetEstado()==true){
                cantPrSelec= CalculoCantidadProductosSeleccionados(vecPrSelec,vecPrOrg,i);
                CargarDetalleVenta(VecDv[i],v.GetNumeroVenta(),vecPrSelec[i].GetIdProducto(),cantPrSelec,true);
                }
            }
        }

        rlutil::locate(40,10); cout << "Guardar y finalizar compra? " << endl;
        rlutil::locate(48,11); cout << "No" << endl;
        rlutil::locate(48,12); cout << "Si" << endl;
        int opcion1=SeleccionMenus(47,11,1,1);

        if(opcion1==0){return;}else{
            GuardarRegistroCliente(cl,false);
            GuardarRegistroVenta(v);
            for(int i=0;i<tamVecPrselec; i++){if(vecPrSelec[i].GetEstado()==true){GuardarRegistroDetalleVenta(VecDv[i],false);}}
        }
    }

    double CalculoImporteTotal(vector<Producto> &vecPrSelec, vector<Producto> &vecPrOrg){

        int tamVecSelec=vecPrSelec.size(), tamVecPrOrg=vecPrOrg.size();
        double ImporteTotal;

        for(int i=0; i<tamVecSelec; i++){
            int cantPrSelec;
            for(int a=0; a<tamVecPrOrg; a++){
                if(vecPrOrg[a].GetIdProducto()==vecPrSelec[i].GetIdProducto()){
                    cantPrSelec=vecPrOrg[a].GetStock()-vecPrSelec[i].GetStock();
                }
            }
            if(vecPrSelec[i].GetEstado()==true){ImporteTotal+=vecPrSelec[i].GetPrecio()*cantPrSelec;}
        }
        return ImporteTotal;
    }

    int CalculoCantidadProductosSeleccionados(vector<Producto> &vecPrSelec, vector<Producto> &vecPrOrg, int indice){

        int tamVecPrOrg=vecPrOrg.size();

            int cantPrSelec;
            for(int a=0; a<tamVecPrOrg; a++){
                if(vecPrOrg[a].GetIdProducto()==vecPrSelec[indice].GetIdProducto()){
                    cantPrSelec=vecPrOrg[a].GetStock()-vecPrSelec[indice].GetStock();
                    return cantPrSelec;
                }
            }
    }














































                                ///INFORMES///
//------------------------------------------------------------------------//

    void RecaudacionAnual(){
     int anio=0,i=0,totalanual=0;
     Fecha fech;
     Venta ven;
     ArchivoVentas archV("Ventas.dat");
    int cantReg= archV.CantidadRegistros(sizeof(Venta));
        cout<<"Ingrese el anio que desea consultar: "<<endl;
        cin>>anio; LimpiarBuffer();
        for(i=0;i<cantReg;i++)
        {
        ven=archV.LeerVenta(i);
        MostrarVenta(ven);
        system("pause"); ///probando///no borrar
        fech=ven.GetFecha();
        if(fech.getAnio()==anio)
        {
        MostrarVenta(ven);
        system("pause");
        }
        }


    }











    void LimpiarBuffer(){
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
