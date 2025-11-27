#include <iostream>
using namespace std;
struct habitacion
{
    char numero[5];
    float precio_por_noche;
    bool estado;
    int capacidad;
};

void CrearHabitacion(string archivoHabitaciones)
{
    habitacion hab;
    cout << "Ingrese el numero de la habitacion: ";
    cin >> hab.numero;
    cout << "Ingrese el precio por noche: ";
    cin >> hab.precio_por_noche;
    cout << "Ingrese la capacidad de la habitacion: ";
    cin >> hab.capacidad;
    hab.estado = true;
    cout << "Habitacion creada exitosamente." << endl;
}
void EliminarHabitacion(string archivoHabitaciones)
{
    char numero[5];
    cout << "Ingrese el numero de la habitacion a eliminar: ";
    cin >> numero;
}
void HabitacionesDisponibles(string archivoHabitaciones)
{
    habitacion hab;
    cout << "Mostrando habitaciones disponibles..." << endl;
    if (hab.estado=true)
    {
        cout << "Numero: " << hab.numero << ", Precio por noche: " << hab.precio_por_noche << ", Capacidad: " << hab.capacidad << endl;
    }
    else
    {
        cout << "No hay habitaciones disponibles." << endl;
    }
}