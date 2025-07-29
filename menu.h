#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "vector"
#include "Producto.h"
#include "Clientes.h"
#include "Venta.h"
#include "Detalle_Venta.h"
///libreria grafica///
#include "rlutil.h"
using namespace std;

/// selección y graficos ///
    void Menu();

    void Pilares();

    void DibujarCaja(int EjX, int EjY, int TamH, int TamV,int ClRelln, int ClExtr);

    void comprar();

    void Listado();

    void Busqueda();

    void Informes();

    void CargarRegistros();

    int SeleccionMenus(int EjeX, int EjeY, int CntOpc, int SaltosDeLinea);

    int SeleccionMenuAnim(Cadena *opciones,int EjeX, int EjeY, int CantOpc,int SaltosDeLinea, int TamCj, int ClRell, int ClExtr, int ClRslt, int ClLtr, int ClFlch);

    int SeleccionCantidad(int ejeX, int ejeY, int Max,int Min);

    void TextoMenuPrincipal(Cadena *opciones);

    void TextoMenuCompra(Cadena *opciones);

    void TextoMenuListado(Cadena *opciones);

    void TextoMenuBusqueda(Cadena *opciones);

    void TextoMenuInformes(Cadena *opciones);

    void TextoMenuCargarRegistro(Cadena *opciones);

    void TextoTiposDeProducto();

    void TextoTiposDeProducto2(Cadena *opciones);

    void TxtEditProducto(Cadena *opciones);

/// funcionalidad ///

/*---------
  PRODUCTOS
  ---------*/

    int CargarProducto(Producto &p, int switchEdit, bool opcCarga);

    void MostrarProducto(Producto &p);

    void BuscarProducto(bool opcion); // opcion1= buscar por numero de equipo| opcion0=buscar por rango de precio

    void GuardarRegistroProducto(Producto &p); // guarda y pregunta si se quiere continuar guardando productos

    void ListadoDeProductos(bool opcion); // opcion1= ordenados por precio, opcion0= ordenados por stock

    void CargaDirecta();//carga de manera directa el producto copiado//

    void MenuRegistroProducto();

/*---------
  CLIENTES
  ---------*/

    int CargarCliente(Cliente &cl, bool opcionCarga);//  verifica si ya existe el cliente y pregunta si se quiere reingresar el mismo(en el caso de que se quiera actualizar o corregir un error)

    void MostrarCliente(Cliente &cl);

    void BuscarCliente();

    void GuardarRegistroCliente(Cliente &cl, bool opcionSeg);//Guarda y pregunta si quiere continuar guardando ||opcionSeg 1: para tener la opcion de ingresar mas clientes, opcionSeg: 0 para no tener la opcion

    void ListadoDeClientes();

    void MenuRegistroCliente();

/*---------
  VENTAS
  ---------*/

    void CargarVenta(Venta &v, const char *cuit, double IMPORTE, bool opcionFuncion);//(carrito=1 | carga simple o editar= 0) en caso de ingresar 0 podes ingresar una venta de forma manual o reingresar una existente.
                                                                     // En caso de ingresar 1 se establece automaticamente el numero de venta y podes ingresar los datos restantes de la nueva venta
    void MostrarVenta(Venta &v);

    void BuscarVenta(int opcion);//

    void GuardarRegistroVenta(Venta &v);

    void ListadoDeVentas();

    void MenuRegistroVentas();

/*---------
  DETALLE VENTAS
  ---------*/

    bool CargarDetalleVenta(DetalleVenta &dv, int NUMVENTA, int IDPRODUCTO, int CANTIDAD, bool opcionCarga);

    void MostrarDetalleVenta(DetalleVenta &dv);

    void BuscarDetalleVenta();

    void GuardarRegistroDetalleVenta(DetalleVenta &dv, bool opcionSeguir);

    void ListadoDetalleVentasPorNumeroDeVenta();

/*---------
    COMPRA
  ---------*/

    void CopiarYOrdenarProductos(vector<Producto> &vecPrMod, int tipoPr, bool estado);

    void ListadoDeProductosCompra(vector<Producto> &vecPr);

    int MenuProductosCompra(vector<Producto> &vecPrMod, vector<Producto> &vecPrSelec);

    void ListadoDeProductosCarrito(vector<Producto> &vecPrSelec, vector<Producto> &vecPrOrg);

    void MenuCarrito(vector<Producto> &vecPrSelec, vector<Producto> &vecPrOrg, vector<Producto> &vecPrMod);

    void GuardarVentaCarrito(vector<Producto> &vecPrSelec, vector<Producto> &vecPrOrg, vector<Producto> &vecPrMod, bool &salida);

    double CalculoImporteTotal(vector<Producto> &vecPrSelec, vector<Producto> &vecPrOrg);

    int CalculoCantidadProductosSeleccionados(vector<Producto> &vecPrSelec, vector<Producto> &vecPrOrg, int indice);


/*---------
   INFORMES
  ---------*/
void RecaudacionAnual();

void RecaudacionCliente();

void RecaudacionEquipo();

void informetipocliente();


  void LimpiarBuffer();

#endif // MENU_H_INCLUDED
