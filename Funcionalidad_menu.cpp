#include <iostream>
#include "menu.h"
#include "Fecha.h"
#include "cadena.h"
#include "Producto.h"
#include "Clientes.h"
#include "Venta.h"
#include "Detalle_Venta.h"
#include "Archivo_Clientes.h"
#include "Archivo_Productos.h"
#include "Archivo_Ventas.h"
#include "Archivo_Detalle_Ventas.h"
using namespace std;


    void ListadoDeProductosPorTipo(){

        int TipoDeProducto;
        bool estado, ban=false;
        cout << "Ingrese un tipo de producto(1 a 10)" << endl;
        MuestraTextoTiposDeProducto();
        cin >> TipoDeProducto;
        cout << "Ingrese estado en inventario(1: listado, 0: no listado)" << endl;
        cin >> estado;

        ArchivoProductos archPr("Productos.dat");
        int cantReg=archPr.CantidadRegistros(sizeof(Producto));

        do{
        ban=false;
        switch(TipoDeProducto){
        case 1:{
            Producto pr;
            for(int i; i<=cantReg; i++){
                pr= archPr.LeerProducto(i);
                if(pr.GetTipoEquipo()==1&& pr.GetEstado()==estado){
                        pr.MostrarProducto();
                }
            }
        }
            break;
        case 2:{
            Producto pr;
            for(int i; i<=cantReg; i++){
                pr= archPr.LeerProducto(i);
                if(pr.GetTipoEquipo()==2&& pr.GetEstado()==estado){
                        pr.MostrarProducto();
                }
            }
        }
            break;
        case 3:{
            Producto pr;
            for(int i; i<=cantReg; i++){
                pr= archPr.LeerProducto(i);
                if(pr.GetTipoEquipo()==3&& pr.GetEstado()==estado){
                        pr.MostrarProducto();
                }
            }
        }
            break;
        case 4:{
            Producto pr;
            for(int i; i<=cantReg; i++){
                pr= archPr.LeerProducto(i);
                if(pr.GetTipoEquipo()==4&& pr.GetEstado()==estado){
                        pr.MostrarProducto();
                }
            }
        }
            break;
        case 5:{
            Producto pr;
            for(int i; i<=cantReg; i++){
                pr= archPr.LeerProducto(i);
                if(pr.GetTipoEquipo()==5&& pr.GetEstado()==estado){
                        pr.MostrarProducto();
                }
            }
        }
            break;
        case 6:{
            Producto pr;
            for(int i; i<=cantReg; i++){
                pr= archPr.LeerProducto(i);
                if(pr.GetTipoEquipo()==6&& pr.GetEstado()==estado){
                        pr.MostrarProducto();
                }
            }
        }
            break;
        case 7:{
            Producto pr;
            for(int i; i<=cantReg; i++){
                pr= archPr.LeerProducto(i);
                if(pr.GetTipoEquipo()==7&& pr.GetEstado()==estado){
                        pr.MostrarProducto();
                }
            }
        }
            break;
        case 8:{
            Producto pr;
            for(int i; i<=cantReg; i++){
                pr= archPr.LeerProducto(i);
                if(pr.GetTipoEquipo()==8&& pr.GetEstado()==estado){
                        pr.MostrarProducto();
                }
            }
        }
            break;
        case 9:{
            Producto pr;
            for(int i; i<=cantReg; i++){
                pr= archPr.LeerProducto(i);
                if(pr.GetTipoEquipo()==9&& pr.GetEstado()==estado){
                        pr.MostrarProducto();
                }
            }
        }
            break;
        case 10:{
            Producto pr;
            for(int i; i<=cantReg; i++){
                pr= archPr.LeerProducto(i);
                if(pr.GetTipoEquipo()==10&& pr.GetEstado()==estado){
                        pr.MostrarProducto();
                }
            }
        }
            break;
        default:{
            cout << "Reingrese el tipo de producto(1 a 10)" << endl;
            MuestraTextoTiposDeProducto();
            cin >> TipoDeProducto;
            ban=true;
            break;
            }
        }
        } while(ban);
    }
