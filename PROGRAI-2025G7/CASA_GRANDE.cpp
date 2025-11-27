#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct cliente
{
    char nombre[20];
    char apellido[20];
    char fecha_nacimiento[20];
    char email[20];
    char carnet[20];
};
struct habitacion
{
    char numero[5];
    float precio_por_noche;
    bool estado;
    int capacidad;
};
struct reserva
{
    int carnet_cliente;
    char numero_habitacion[5];
    int codigo_habitacion;
    int noches;
    bool estado_reserva;
    float garantia;
    float total;
};
struct facturacion
{
    float total;
    int metodo_de_pago;
    bool estado_pago;
    int nit_o_carnet;
    char apellido[20];
};
void crearCliente(string archivoClientes);
void MenuOpciones(string archivoClientes,string archivoHabitaciones,string archivoReservas,string archivoFacturas)
{
    cout << "BIENVENIDO A HOTEL CASA BLANCA" << endl;
    cout << "===================================" << endl;
    int opcion = 0;
    cout << "\nMENU DE OPCIONES" << endl;
    cout << "======================" << endl;
    cout << "\t1. Registro" << endl;
    cout << "\t2. Facturacion" << endl;
    cout << "\t3. Cambio estadia" << endl;
    cout << "\t0. Salir" << endl;
    cout << "Seleccione una opcion: ";
    cin >> opcion;
    switch (opcion)
    {
        case 1:
            crearCliente(archivoClientes);
            break;
        case 2:
            // facturación
            break;
        case 3:
            // cambio de estadía
            break;
        case 0:
            cout << "Saliendo" << endl;
            break;
        default:
            cout << "Opción inválida." << endl;
    }
}
int main()
{
    string archivoClientes = "Clientes.bin";
    string archivoHabitaciones = "Habitaciones.bin";
    string archivoReservas = "Reservas.bin";
    string archivoFacturas = "Facturas.bin";
    MenuOpciones(archivoClientes, archivoHabitaciones, archivoReservas, archivoFacturas);
    return 0;
}

