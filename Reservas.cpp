#include <iostream>
using namespace std;
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

void CrearReserva(string archivoReservas)
{
    reserva res;
    cout << "Ingrese el carnet del cliente: ";
    cin >> res.carnet_cliente;
    cout << "Ingrese el numero de la habitacion: ";
    cin >> res.numero_habitacion;
    cout << "Ingrese el codigo de la habitacion: ";
    cin >> res.codigo_habitacion;
    cout << "Ingrese el numero de noches: ";
    cin >> res.noches;
    res.estado_reserva = true;
    cout<<"Desea agregar una garantia? (1 para si, 0 para no): ";
    float dejar_garantia;
    if (dejar_garantia == 1)
    {
        cout << "Ingrese el monto de garantia: ";
        cin >> res.garantia;
    }
    else
    {
        res.garantia = 0.0;
    }
    cout << "Reserva creada exitosamente." << endl;
}
void ModificarReserva(string archivoReservas)
{
    reserva res;
    cout << "Ingrese el codigo de la habitacion a modificar: ";
    cin >> res.codigo_habitacion;
}