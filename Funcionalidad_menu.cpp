#include <iostream>
#include "menu.h"
using namespace std;

    int CargarProducto(Producto &p){ ///DISEÑO MEJORADO///

        ArchivoProductos archP("Productos.dat");
        int id,tipo=0,stock;
        float precio;
        char nombre[50]{},descripcion[500]{}, marca[20]{};

        int k=0, icono=0;
        bool bandera1=false;
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
            int opcion;
            rlutil::locate(30,5);
            cout << "Ya existe un producto con el Id: " << id << " Desea reingresarlo?" << endl;
            ///
            k=0, icono=0;
            bandera1=false;
            do{
            rlutil::hidecursor();
            rlutil::locate(57,8);
            cout<<"NO";
            rlutil::locate(57,9);
            cout<<"SI";
            rlutil::locate(56,8+k);
            cout<<(char)175<<endl;
            icono = rlutil::getkey();
            switch (icono){
                case(14):///arriba///
                rlutil::locate(56,8+k);
                cout<<" "<<endl;
                k--;
                if(k<0){k=1;}
                break;
                case(15):///abajo///
                rlutil::locate(56,8+k);
                cout<<" "<<endl;
                k++;
                if(k>1){k=0;}
                break;
                case(1):///enter///
                    switch(k)
                    {
                    case(0):{
                    return opcion;///por que o para que?///
                    bandera1=true;
                    }
                    break;
                    case(1):{
                    bandera1=true;
                    }
                    break;
                    }
            }
                }while(bandera1==false);
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
        while(p.SetPrecio(precio)==0)
        {
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
    rlutil::locate(57,8);
    cout << "Equipos" << endl;
    rlutil::locate(57,9);
    cout << "Notebooks" << endl;
    rlutil::locate(57,10);
    cout << "Procesadores" << endl;
    rlutil::locate(57,11);
    cout << "Mothers" << endl;
    rlutil::locate(57,12);
    cout << "Placas de video" << endl;
    rlutil::locate(57,13);
    cout << "Memorias RAM" << endl;
    rlutil::locate(57,14);
    cout << "Gabinetes" << endl;
    rlutil::locate(57,15);
    cout << "Fuentes" << endl;
    rlutil::locate(57,16);
    cout << "Monitores" << endl;
    rlutil::locate(57,17);
    cout << "Perifericos" << endl;
            icono=0;
            bandera1=false;
            do{
            rlutil::hidecursor();
            rlutil::locate(56,8+tipo);
            cout<<(char)175<<endl;
            icono = rlutil::getkey();
            switch (icono){
                case(14):///arriba///
                rlutil::locate(56,8+tipo);
                cout<<" "<<endl;
                tipo--;
                if(tipo<0){tipo=9;}
                break;
                case(15):///abajo///
                rlutil::locate(56,8+tipo);
                cout<<" "<<endl;
                tipo++;
                if(tipo>9){tipo=0;}
                break;
                case(1):///enter///
                    switch(tipo)
                    {
                default:
                    {tipo++;
        while(p.SetTipoEquipo(tipo)==0)
            {
            cout<<"ERRORel tipo de equipo tiene que ser entre 1 y 10 porfavor seleccione: ";
            cin>>tipo;
            }
                    bandera1=true;
                    }
                    }
            }
                }while(bandera1==false);
                tipo=0;
                rlutil::showcursor();
                system("cls");

        rlutil::locate(35,5);
        cout<<"Ingrese el stock del producto: ";
        cin>>stock;
        while(p.SetStock(stock)==0)
        {
            rlutil::locate(20,5);
            cout<<"el stock no puede ser menor a 0 por favor vuelva a ingresar el stock: ";
            cin>>stock;
        }
        cout<<endl;
        system("cls");

        rlutil::locate(45,5);
        cout<<"Selecione el estado del producto";
        k=0, icono=0;
        bandera1=false;
            do{
            rlutil::hidecursor();
            rlutil::locate(56,7);
            cout<<"inactivo";
            rlutil::locate(56,8);
            cout<<"activo";
            rlutil::locate(53,7+k);
            cout<<(char)175<<endl;
            icono = rlutil::getkey();
            switch (icono){
                case(14):///arriba///
                rlutil::locate(53,7+k);
                cout<<" "<<endl;
                k--;
                if(k<0){k=1;}
                break;
                case(15):///abajo///
                rlutil::locate(53,7+k);
                cout<<" "<<endl;
                k++;
                if(k>1){k=0;}
                break;
                case(1):///enter///
                    switch(k)
                    {
                    case(0):{
                    p.SetEstado(0);
                    bandera1=true;
                    }
                    break;
                    case(1):{
                    p.SetEstado(1);
                    bandera1=true;
                    }
                    break;
                    }
            }
                }while(bandera1==false);

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
            archP.GuardarProducto(p);
            cout << "Para ingresar otro producto(1=si,0=no): ";
            cin >> seguir;
            if(seguir){
            CargarProducto(p);
            }
        }
    }

    void ListadoDeProductos(bool opcion){

        system("cls");
        int TipoDeProducto;
        bool ban=true;
        bool estado;
        cout << "Ingrese un tipo de producto(1 a 10)" << endl;
        MuestraTextoTiposDeProducto();
        cout << "==> :";
        cin >> TipoDeProducto;
        cout << "Ingrese estado en inventario(1: Activo, 0: inactivo)" << endl;
        cin >> estado;

        ArchivoProductos archPr("Productos.dat");
        int cantReg=archPr.CantidadRegistros(sizeof(Producto));

        vector<Producto> PrOrdenados;

        system("cls");
        while(ban==true){
            if(TipoDeProducto<=10&&TipoDeProducto>0){
                Producto pr;
                for(int i=0; i<=cantReg; i++){
                if(archPr.LeerProducto(i, pr)){
                    if(pr.GetTipoEquipo()==TipoDeProducto&& pr.GetEstado()==estado){
                        //MostrarProducto(pr);
                        PrOrdenados.push_back(pr);
                        }
                    }
                }
                ban=false;
            } else{
                cout<<"Ingrese porfavor un tipo valido(1 a 10): ";
                cin>>TipoDeProducto;
                system("cls");
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

//------------------------------------------------------------------------//
    int CargarCliente(Cliente &cl){ ///mejorar diseño pendiente///

        ArchivoClientes archCl("Clientes.dat");

        int tc;
        char *cuil= new char[31], *nombre= new char[31], *apellido= new char[31], *telefono= new char[31], *mail=new char[31], *direccion=new char[31];
        bool estado;

        cout<<"Ingrese el cuit del cliente: ";
        cin.getline(cuil, 31);
        if(archCl.BuscarCliente(cuil)>=0){


            cout << "Ya existe un cliente con el cuit:" << cuil << " Desea reingresarlo?" << endl;

            int k=0, icono;
            bool bandera1=false;
            do{
            rlutil::hidecursor();
            rlutil::locate(10,4);
            cout<<"NO";
            rlutil::locate(10,5);
            cout<<"SI";
            rlutil::locate(9,4+k);
            cout<<(char)175<<endl;
            icono = rlutil::getkey();
            switch (icono){
                case(14):///arriba///
                rlutil::locate(9,4+k);
                cout<<" "<<endl;
                k--;
                if(k<0){k=1;}
                break;
                case(15):///abajo///
                rlutil::locate(9,4+k);
                cout<<" "<<endl;
                k++;
                if(k>1){k=0;}
                break;
                case(1):///enter///
                    switch(k)
                    {
                    case(0):{
                    return k;
                    bandera1=true;
                    }
                    break;
                    case(1):{
                    cl.SetCuil(cuil);
                    bandera1=true;
                    }
                    break;
                    }
            }
                }while(bandera1==false);
        }
        cl.SetCuil(cuil);
        system("cls");
        rlutil::showcursor();



        cout<<"Ingrese el nombre del cliente: ";
        cin.getline(nombre, 31);
        cl.SetNombre(nombre);
        cout<<endl;

        cout<<"Ingrese el apellido del cliente: ";
        cin.getline(apellido, 31);
        cl.SetApellido(apellido);
        cout<<endl;

        cout<<"Ingrese el telefono del cliente: ";
        cin.getline(telefono, 31);
        cl.SetTelefono(telefono);
        cout<<endl;

        cout<<"Ingrese el mail del cliente: ";
        cin.getline(mail, 31);
        cl.SetMail(mail);
        cout<<endl;

        cout<<"Ingrese la direccion del cliente: ";
        cin.getline(direccion, 31);
        cl.SetDireccion(direccion);
        cout<<endl;

        cout<<"Ingrese el tipo de cliente(1-particular o 2-empresa): ";
        cin>>tc;
        cl.SetTipoCliente(tc);
        cout<<endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout <<"Ingrese estado del cliente(1-activo, 0-inactivo): ";
        cin>>estado;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        delete[] cuil; delete[] nombre; delete[] apellido; delete[] telefono; delete[] mail; delete[] direccion;

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
            cout << "Para ingresar otro cliente(1=si,0=no): ";
            cin >> seguir;
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
        for(int i; i<=cantReg; i++){
        if(archCl.LeerCliente(i, cl)){
            if(cl.GetEstado()==estado){
                //MostrarCliente(cl);
                ClOrdenados.push_back(cl);
                }
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

//------------------------------------------------------------------------//
    int CargarVenta(Venta &v, bool opcionFuncion){///mejorar diseño pendiente///

        ArchivoVentas archV("Ventas.dat");

        int numeroV,dia,mes,siglo;
        double importe;
        Fecha fech;
        char cuit[20];
        bool estado;

        int cantReg= archV.CantidadRegistros(sizeof(Venta));

        if(opcionFuncion){                                  //
                                                            // Carrito
            numeroV=cantReg+1;                              //
        }else{

            bool opcion;                                                                       //
            cout << "Desea igresar una venta nueva o editar una existente?" << endl;           //
            cout << "(1=nueva, 0=existente): ";                                                //
            cin >> opcion;                                                                     //
                                                                                               //
            if(opcion){                                                                        //
                                                                                               //
                numeroV=cantReg+1;                                                             //
            }else{                                                                             // Carga simple o edicion de una venta
                                                                                               //
                cout << "Ingrese numero de venta a editar: ";                                  //
                cin >> numeroV;                                                                //
                                                                                               //
                while(archV.BuscarVenta(numeroV-1)<0){                                         //
                                                                                               //
                    cout << "Numero de venta inexistente" << endl;                             //
                    cout << "Reingrese numero de venta: " << endl;                             //
                    cin >> numeroV;                                                            //
                }
            }
        }
        v.SetNumeroVenta(numeroV);
        cout<<endl;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ingrese el cuit del comprador: ";
        cin.getline(cuit,20);
        v.SetCuit(cuit);
        cout << endl;

        cout << "Ingrese dia de la venta: ";
        cin >> dia;
        cout << endl;

        cout << "Ingrese mes de la venta:  ";
        cin >> mes;
        cout << endl;

        cout << "Ingrese anio de la venta: ";
        cin >> siglo;
        v.SetFechaVenta(dia,mes,siglo);
        cout << endl;
        system("cls");

        cout << "Ingrese importe de la venta: ";
        cin >> importe;
        while(v.SetImporteVenta(importe)==0)
            {
                cout<<"el inporte de venta no puede ser 0 o menor a 0: ";
                cin>>importe;
            }
        cout << endl;

        cout << "Ingrese estado de la venta(1-activo, 0-inactivo): ";
        cin >> estado;
        v.SetEstado(estado);
        cout << endl;

        return 1;
    }

    void MostrarVenta(Venta &Venta){
    cout<<"El numero de venta es: "<<Venta.GetNumeroVenta()<<endl;
    cout<<"El cuil de la venta es: "<<Venta.GetCuit()<<endl;
    Venta.MostrarVentafecha();
    cout<<"El importe de la venta es: "<<Venta.GetImporteVenta()<<endl;
    }

    void BuscarVenta(int opcion){


    }

    void GuardarRegistroVenta(Venta &v){

        ArchivoVentas archV("Ventas.dat");
        bool seguir=true;

        while(seguir){
            archV.GuardarVenta(v);
            cout << "Para ingresar otra venta(1=si,0=no): ";
            cin >> seguir;
            if(seguir){
            seguir=CargarVenta(v, 0);
            }
        }
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
        for(int i; i<=cantReg; i++){
        if(archV.LeerVenta(i, v)){
            if(v.GetEstado()==estado){
                //MostrarVenta(v);
                VtOrdenadas.push_back(v);
                }
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

//------------------------------------------------------------------------//
    int CargarDetalleVenta(int numVenta, DetalleVenta &dv){///mejorar diseño pendiente///

        ArchivoDetalleVentas archDV("DetalleVentas.dat");

        ArchivoVentas archV("Ventas.dat");
        int cantRegV= archV.CantidadRegistros(sizeof(Venta));

        int numeroventa, idproducto, cantidad;
        float precio;

        if(numVenta==0){                                                                        //
                                                                                                //
            do{                                                                                 //
            cout << "Ingrese un numero de venta existente (entre 1 y " << cantRegV << "): ";    //  Carga simple o edicion de un detalle de venta
            cin >> numeroventa;                                                                 //
            cout << endl;                                                                       //
            }while(numeroventa<0||numeroventa>cantRegV);                                        //
            dv.SetNumeroVentaDT(numeroventa);                                                   //
        }else{
                                                                         //
            dv.SetNumeroVentaDT(numVenta);                               //  Carrito
        }                                                                //

        cout << "ingrese un precio mayor o igual a 100 : $";
        cin >> precio;

        while(dv.SetPrecioProductoDT(precio)==0)
            {
            cout << "ingrese un precio mayor o igual a 100 : $";
            cin >> precio;
            }
        cout << endl;

        cout << "ingrese el nuemro de id del producto: ";
        cin >> idproducto;
        dv.SetIdProductoDT(idproducto);
        cout << endl;

        cout << "ingrese la cantidad de productos vendidos: ";
        cin >> cantidad;
        while(dv.SetCantidad(cantidad)==0)
            {
            cout << "ingrese una cantidad mayor a 0 : ";
            cin >> cantidad;
            }
        cout << endl;

        return 1;
    }

    void MostrarDetalleVenta(DetalleVenta &dv){
       cout<<"El numero de venta es: "<<dv.GetNumeroVentaDT()<<endl;
       cout<<"El precio de la venta fue de: $"<<dv.GetPrecioProducto()<<endl;
       cout<<"El numero de id del producto es: "<<dv.GetIdProductoDT()<<endl;
       cout<<"La cantidad de productos comprados: "<<dv.GetCantidad()<<endl;
       }

    void GuardarRegistroDetalleVenta(DetalleVenta &dv){

        ArchivoDetalleVentas archDV("DetalleVentas.dat");
        bool seguir=true;

        while(seguir){
            archDV.GuardarDetalleVenta(dv);
            cout << "Para ingresar otro detalle de venta(1=si,0=no): ";
            cin >> seguir;
            if(seguir){
            seguir=CargarDetalleVenta(0, dv);
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
