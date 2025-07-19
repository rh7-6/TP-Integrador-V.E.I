#include <iostream>
#include "menu.h"
#include "Archivo_Clientes.h"
#include "Archivo_Productos.h"
#include "Archivo_Ventas.h"
#include "Archivo_Detalle_Ventas.h"
using namespace std;

                                ///PRODUCTO///
//------------------------------------------------------------------------//
    int CargarProducto(Producto &p){                                                          ///DISEÑO MEJORADO///

        ArchivoProductos archP("Productos.dat");
        int id,tipo=0,stock;
        float precio;
        char nombre[50]{},descripcion[500]{}, marca[20]{};
        rlutil::locate(30,5);
        cout<<"Ingrese el id del producto o equipo igual o mayor a 0: ";
        cin>>id;

        while(p.SetIdProducto(id)==0){
            rlutil::locate(20,5);
            cout<<"el numero tiene que ser mayor o igual a 0 por favor vuelva a cargar el numero: ";
            cin>>id;
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


        cin.ignore(numeric_limits<streamsize>::max(), '\n');///limpiador del buffer///
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
            cin>>precio;
        }
        cout<<endl;
        system("cls");

        cin.ignore(numeric_limits<streamsize>::max(), '\n');///limpiador del buffer///
        rlutil::locate(20,5);
        cout<<"Ingrese la descripcion del producto(terminada en el caracter #): "<<endl;
        cin.getline(descripcion,500, '#');
        p.SetDescripcion(descripcion);
        cout<<endl;
        system("cls");

        cin.ignore(numeric_limits<streamsize>::max(), '\n');///limpiador del buffer///
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
        cin>>stock;
        while(p.SetStock(stock)==0){
            rlutil::locate(20,5);
            cout<<"el stock no puede ser menor a 0 por favor vuelva a ingresar el stock: ";
            cin>>stock;
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
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
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

            cout << "Ingrese el Id del producto a buscar: ";
            cin >> id;
            cout << endl;

            if((pos=archP.BuscarProducto(id))<0){

                cout << "Producto inexistente reingrese id: ";
                cin >> id;
                system("cls");
            }else{

                p=archP.LeerProducto(pos);
                MostrarProducto(p);
                system("pause");
            }
        }else{

            float precioMax, precioMin;

            cout << "Ingrese valor maximo en rango de precio a buscar: ";
            cin >> precioMax;
            cout << endl;

            cout << "Ingrese valor minimo en rango de precio a buscar: ";
            cin >> precioMin;
            cout << endl;

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

        cout << "Ingrese un tipo de producto(1 a 10)" << endl;
        TextoTiposDeProducto();
        cout << "==> :";
        cin >> TipoDeProducto;
        while(TipoDeProducto>10||TipoDeProducto<0){
            cout<<"Ingrese porfavor un tipo valido(1 a 10): ";
            cin>>TipoDeProducto;
            system("cls");
        }

        cout << "Ingrese estado en inventario(1: Activo, 0: inactivo): " << endl;
        cin >> estado;

        ArchivoProductos archPr("Productos.dat");
        int cantReg=archPr.CantidadRegistros(sizeof(Producto));

        vector<Producto> PrOrdenados;

        system("cls");

        Producto pr;
        for(int i=0; i<cantReg; i++){
            archPr.LeerProducto(i, pr);
            if(pr.GetTipoEquipo()==TipoDeProducto&& pr.GetEstado()==estado){
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

                                ///CLIENTE///
//------------------------------------------------------------------------//
    int CargarCliente(Cliente &cl){                                                           ///mejorar diseño pendiente///

        ArchivoClientes archCl("Clientes.dat");

        int tc;
        char cuil[31]{}, nombre[31]{}, apellido[31]{}, telefono[31]{}, mail[31]{}, direccion[31]{};


        rlutil::locate(40, 5);
        cout<<"Ingrese el cuit del cliente: ";
        cin>>cuil;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if(int posCl =archCl.BuscarCliente(cuil)>=0){
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
        rlutil::locate(40, 5);
        cout<<"Ingrese el nombre del cliente: ";
        cin.getline(nombre, 31);
        cl.SetNombre(nombre);
        cout<<endl;

        system("cls");
        rlutil::locate(40, 5);
        cout<<"Ingrese el apellido del cliente: ";
        cin.getline(apellido, 31);
        cl.SetApellido(apellido);
        cout<<endl;

        system("cls");
        rlutil::locate(40, 5);
        cout<<"Ingrese el telefono del cliente: ";
        cin.getline(telefono, 31);
        cl.SetTelefono(telefono);
        cout<<endl;

        system("cls");
        rlutil::locate(40, 5);
        cout<<"Ingrese el mail del cliente: ";
        cin.getline(mail, 31);
        cl.SetMail(mail);
        cout<<endl;

        system("cls");
        rlutil::locate(40, 5);
        cout<<"Ingrese la direccion del cliente: ";
        cin.getline(direccion, 31);
        cl.SetDireccion(direccion);
        cout<<endl;


        system("cls");
        rlutil::locate(45, 5);
        cout<<"Selecione el tipo de cliente";
            rlutil::locate(57,8);
            cout<<"particular";
            rlutil::locate(57,9);
            cout<<"empresa";
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
                    cout<<endl;
        system("cls");
        rlutil::locate(43, 5);
        cout <<"Ingrese estado del cliente ";
            rlutil::locate(54,8);
            cout<<"activo";
            rlutil::locate(54,9);
            cout<<"inactivo";
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
    }

    void BuscarCliente(){

        ArchivoClientes archCl("Clientes.dat");
        Cliente cl;
        string Cuit;
        int pos;

        cout << "Ingrese el CUIT del cliente a buscar: ";
        cin >> Cuit;
        cout << endl;

        if((pos=archCl.BuscarCliente(Cuit.c_str()))<0){

            cout << "Cliente inexistente reingrese Cuit: ";
            cin >> Cuit;
            system("cls");
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
            seguir=CargarCliente(cl);
                }
            }
            }while(seguir);
        }

    void ListadoDeClientes(){

        system("cls");
        bool estado;
        cout << "Ingrese estado de clientes (1: activos, 0: inactivos): " << endl;
        cin >> estado;

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
    void CargarVenta(Venta &v, const char *cuit, bool opcionCarga){                          ///mejorar diseño pendiente///

        ArchivoVentas archV("Ventas.dat");

        int numeroV,dia,mes,siglo;
        double importe;
        Fecha fech;
        bool estado;

        int cantReg= archV.CantidadRegistros(sizeof(Venta));

        if(opcionCarga){                                    //
                                                            // Carrito
            numeroV=cantReg+1;                              //
        }else{

            bool opcion;
            system("cls");
            rlutil::locate(35,5);                                                                       //
            cout << "Desea igresar una venta nueva o editar una existente?" << endl;           //
            rlutil::locate(57,8);
            cout<<"Nueva Venta";
            rlutil::locate(57,9);
            cout<<"Editar Existente";
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
                                                                                               //
            if(opcion){                                                                        //
                                                                                               //
                numeroV=cantReg+1;                                                             //
            }else{
                system("cls");                                                                             // Carga simple o edicion de una venta
                rlutil::locate(35,5);                                                                               //
                cout << "Ingrese numero de venta a editar: ";                                  //
                cin >> numeroV;                                                                //
                                                                                               //
                while(archV.BuscarVenta(numeroV-1)<0){                                         //

                    system("cls");                                                                             // Carga simple o edicion de una venta
                    rlutil::locate(43,5);                                                                      //
                    cout << "Numero de venta inexistente" << endl;                             //
                    rlutil::locate(43,6);
                    cout << "Reingrese numero de venta: ";                             //
                    cin >> numeroV;                                                            //
                }
            }
        }
            system("cls");
        v.SetCuit(cuit);
        cout << endl;

        system("cls");
        rlutil::locate(40,5);
        cout << "Ingrese dia de la venta: ";
        cin >> dia;
        cout << endl;

        system("cls");
        rlutil::locate(40,5);
        cout << "Ingrese mes de la venta:  ";
        cin >> mes;
        cout << endl;

        system("cls");
        rlutil::locate(40,5);
        cout << "Ingrese anio de la venta: ";
        cin >> siglo;
        v.SetFechaVenta(dia,mes,siglo);
        cout << endl;

        system("cls");
        rlutil::locate(40,5);
        cout << "Ingrese importe de la venta: $";
        cin >> importe;
        while(v.SetImporteVenta(importe)==0)
            {
                system("cls");
                rlutil::locate(40,5);
                cout<<"el inporte de venta no puede ser 0 o menor a 0: ";
                cin>>importe;
            }
        cout << endl;

        system("cls");
        rlutil::locate(47,5);
        cout << "Seleccione el estado de venta";
            rlutil::locate(57,8);
            cout<<"Activo";
            rlutil::locate(57,9);
            cout<<"Inactivo";
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
    }

    void BuscarVenta(int opcion){

        ArchivoVentas archV("Ventas.dat");
        int cantReg= archV.CantidadRegistros(sizeof(Venta));
        Venta v;

        switch(opcion){
    case 0:{

        int numVenta;
        cout << "Ingrese numero de venta(entre 1 y " << cantReg << ") :";
        cin >> numVenta;
        cout << endl;
        while(numVenta<1||numVenta>cantReg){
            cout << "Ingrese un numero de venta valido(entre 1 y " << cantReg << ") :";
            cin >> numVenta;
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
        Cliente cl;
        char CUIT[30]{};

        cout << "Ingrese CUIT: ";
        cin >> CUIT;
        cout << endl;

        int pos;
        while((pos=archCl.BuscarCliente(CUIT))<0){

            cout << "Cliente inexistente reingrese CUIT: ";
            cin >> CUIT;
        }

        cl=archCl.LeerCliente(pos);
        MostrarCliente(cl);
        system("pause");
        system("cls");
    }
    break;
    case 2:{

        vector<Venta> vecVtOrdenadas;
        int Dia1, Mes1, Anio1, Dia2, Mes2, Anio2;

        cout << "Ingrese la fecha inicial del rango: " << endl;
        cout << "Dia: ";
        cin >> Dia1;
        while(Dia1<1||Dia1>31){
            cout << "Ingrese un dia valido(1 a 31): ";
            cin >> Dia1;
            system("cls");
        }
        cout << endl;
        cout << "Mes: ";
        cin >> Mes1;
        while(Mes1<1||Mes1>12){
            cout << "Ingrese un mes valido(1 a 12): ";
            cin >> Mes1;
            system("cls");
        }
        cout << endl;
        cout << "Anio: ";
        cin >> Anio1;
        while(Anio1<2020||Anio1>2028){
            cout << "Ingrese anio valido(2020 a 2028): ";
            cin >> Anio1;
            system("cls");
        }
        cout << endl;
        Fecha fMin(Dia1,Mes1,Anio1);
        //----------------------------------------------------//
        cout << "Ingrese la fecha final del rango: " << endl;
        cout << "Dia: ";
        cin >> Dia2;
        while(Dia2<1||Dia2>31){
            cout << "Ingrese un dia valido(1 a 31): ";
            cin >> Dia2;
            system("cls");
        }
        cout << endl;
        cout << "Mes: ";
        cin >> Mes2;
        while(Mes2<1||Mes2>12){
            cout << "Ingrese un mes valido(1 a 12): ";
            cin >> Mes2;
            system("cls");
        }
        cout << endl;
        cout << "Anio: ";
        cin >> Anio2;
        while(Anio2<2020||Anio2>2028){
            cout << "Ingrese anio valido(2020 a 2028): ";
            cin >> Anio2;
            system("cls");
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

    void GuardarRegistroVenta(Venta &v, const char *nombreArchivo){

        ArchivoVentas archV(nombreArchivo);
        archV.GuardarVenta(v);
    }

    void ListadoDeVentas(){

        system("cls");
        bool estado;
        cout << "Ingrese estado de ventas (1: Listadas, 0: Borradas): " << endl;
        cin >> estado;

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
            }

        system("pause");
        system("cls");
    }

                                ///DETALLE VENTA///
//------------------------------------------------------------------------//
    void CargarDetalleVenta(int numVenta, DetalleVenta &dv){                                    ///mejorar diseño pendiente///

        ArchivoDetalleVentas archDV("DetalleVentas.dat");

        ArchivoVentas archV("Ventas.dat");
        int cantRegV= archV.CantidadRegistros(sizeof(Venta));

        int numeroventa, idproducto, cantidad;

        if(numVenta==0){                                                                        //
                                                                                                //
            do{
            rlutil::locate(30, 5);                                                                                //
            cout << "Ingrese un numero de venta existente (entre 1 y " << cantRegV << "): ";    //  Carga simple o edicion de un detalle de venta
            cin >> numeroventa;                                                                 //
            cout << endl;
            system("cls");                                                                       //
            }while(numeroventa<0||numeroventa>cantRegV);                                        //
            dv.SetNumeroVentaDT(numeroventa);                                                   //
        }else{
                                                                          //
            dv.SetNumeroVentaDT(numVenta);                               //  Carrito
        }                                                                //


        ArchivoProductos archP("Productos.dat");
        Producto p;

            int pos;
        rlutil::locate(30,5);
        cout << "Ingrese el numero de id del producto: ";
        cin >> idproducto;
            if((pos=archP.BuscarProducto(idproducto))<0){
                system("cls");
                rlutil::locate(35,5);
                cout << "Producto inexistente reingrese id: ";
                cin >> idproducto;
            }
        dv.SetIdProductoDT(idproducto);
        cout << endl;

        p=archP.LeerProducto(pos);
        dv.SetPrecioProductoDT(p.GetPrecio());


        int stock= p.GetStock();
        system("cls");
        rlutil::locate(30,5);
        cout << "Ingrese la cantidad requerida(minimo 1, maximo " << stock << "): ";
        cin >> cantidad;
        while(dv.SetCantidad(cantidad)==0||cantidad>stock)
            {
            system("cls");
            rlutil::locate(30,5);
            cout << "Reingrese la cantidad (minimo 1, maximo " << stock << "): ";
            cin >> cantidad;
            }
        cout << endl;
    }

    void MostrarDetalleVenta(DetalleVenta &dv){
       cout<<"El numero de venta es: "<<dv.GetNumeroVentaDT()<<endl;
       cout<<"El precio de la venta fue de: $"<<dv.GetPrecioProducto()<<endl;
       cout<<"El numero de id del producto es: "<<dv.GetIdProductoDT()<<endl;
       cout<<"La cantidad de productos comprados: "<<dv.GetCantidad()<<endl;
       }

    void GuardarRegistroDetalleVenta(DetalleVenta &dv, const char *nombreArchivo){

        ArchivoDetalleVentas archDV(nombreArchivo);
        bool seguir=true;
        system("cls");
        while(seguir){
            archDV.GuardarDetalleVenta(dv);
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
            CargarDetalleVenta(0, dv);
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

        system("cls");
        int numeroventa;

        ArchivoVentas archV("Ventas.dat");
        int cantRegV= archV.CantidadRegistros(sizeof(Venta));

        ArchivoDetalleVentas archDV("DetalleVentas.dat");
        int cantReg=archDV.CantidadRegistros(sizeof(DetalleVenta));

        do{

        cout << "Ingrese un numero de venta existente (entre 1 y " << cantRegV << "): ";
        cin >> numeroventa;
        }while(numeroventa>0&&numeroventa<=cantRegV);

        DetalleVenta dv;
        for(int i; i<=cantReg; i++){
        if(archDV.LeerDetalleDeVenta(i, dv)){
            if(dv.GetNumeroVentaDT()==numeroventa){
                MostrarDetalleVenta(dv);
                }
            }
        }
        system("pause");
        system("cls");
    }

                                ///COMPRA///
//------------------------------------------------------------------------//
    void ListadoDeProductosCompra(int TipoProducto){

        ArchivoProductos archPr("Productos.dat");
        int cantReg=archPr.CantidadRegistros(sizeof(Producto));

        vector<Producto> PrOrdenados;

        system("cls");

        Producto pr;
        for(int i=0; i<cantReg; i++){
            archPr.LeerProducto(i, pr);
            if(pr.GetTipoEquipo()==TipoProducto&&pr.GetEstado()==1){
                //MostrarProducto(pr);
                PrOrdenados.push_back(pr);
                }
            }

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

