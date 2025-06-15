#include <iostream>
#include <string>
#include "Producto.h"
#include "Clientes.h"
#include "Venta.h"

using namespace std;
/// arreglar el problema con los espacios de la cadena de texto///
int main()
{
Producto prod;
Cliente cli;
Venta vent;

vent.CargarVenta();
vent.MostrarVenta();



    return 0;
}
