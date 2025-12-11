#include <iostream>
#include <fstream>
#include <cstring>
#include "libhabitaciones.h"
using namespace std;

void crearHabitacion();
void habitacionesDisponibles();
void cambiarHabitacion();
void eliminarHabitacion();
void masSolicitada();

void menuhabitaciones() {
    int opc;
    do {
        cout << "\n---- HOTEL ----\n";
        cout << "1. Crear habitacion\n";
        cout << "2. Ver habitaciones disponibles\n";
        cout << "3. Cambiar de habitacion\n";
        cout << "4. Eliminar habitacion\n";
        cout << "5. Habitacion mas solicitada\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opc;

        switch(opc) {
            case 1: crearHabitacion(); 
            break;
            case 2: habitacionesDisponibles(); 
            break;
            case 3: cambiarHabitacion(); 
            break;
            case 4: eliminarHabitacion(); 
            break;
            case 5: masSolicitada(); 
            break;
        }

    } while(opc != 0);

}

void crearHabitacion() {
    Habitacion h;

    cout << "Numero de habitacion: ";
    cin >> h.numero;
    cout << "Precio por noche: ";
    cin >> h.precio;
    cout << "Capacidad: ";
    cin >> h.capacidad;

    h.ocupada = false;
    h.vecesReservada = 0;

    ofstream arch("habitaciones.dat", ios::binary | ios::app);
    arch.write((char*)&h, sizeof(h));
    arch.close();

    cout << "Habitacion creada.\n";
}

void habitacionesDisponibles() {
    ifstream arch("habitaciones.dat", ios::binary);
    Habitacion h;
    bool hay = false;

    cout << "\n--- HABITACIONES DISPONIBLES ---\n";

    while (arch.read((char*)&h, sizeof(h))) {
        if (!h.ocupada) {
            hay = true;
            cout << "Numero: " << h.numero << endl;
            cout << "Precio: " << h.precio << endl;
            cout << "Capacidad: " << h.capacidad << endl;
            cout << "Estado: LIBRE\n";
            cout << "---------------------\n";
        }
    }

    arch.close();

    if (!hay) cout << "No hay habitaciones disponibles.\n";
}

void cambiarHabitacion() {
    int act, nueva;
    cout << "Habitacion actual: ";
    cin >> act;
    cout << "Nueva habitacion: ";
    cin >> nueva;

    fstream arch("habitaciones.dat", ios::binary | ios::in | ios::out);

    Habitacion h;
    long posActual = -1, posNueva = -1;

    while (arch.read((char*)&h, sizeof(h))) {
        long pos = arch.tellg() - (long)sizeof(h);

        if (h.numero == act) posActual = pos;
        if (h.numero == nueva) posNueva = pos;
    }

    if (posActual == -1 || posNueva == -1) {
        cout << "Una de las habitaciones no existe.\n";
        arch.close();
        return;
    }

    // Desocupar la actual
    arch.seekg(posActual);
    arch.read((char*)&h, sizeof(h));
    h.ocupada = false;
    arch.seekp(posActual);
    arch.write((char*)&h, sizeof(h));

    // Ocupar la nueva
    arch.seekg(posNueva);
    arch.read((char*)&h, sizeof(h));

    if (h.ocupada) {
        cout << "La nueva habitacion ya esta ocupada.\n";
        arch.close();
        return;
    }

    h.ocupada = true;
    h.vecesReservada++;

    arch.seekp(posNueva);
    arch.write((char*)&h, sizeof(h));

    cout << "Cambio realizado con exito.\n";
    arch.close();
}

void eliminarHabitacion() {
    int num;
    cout << "Numero de habitacion a eliminar: ";
    cin >> num;

    ifstream arch("habitaciones.dat", ios::binary);
    ofstream temp("temp.dat", ios::binary);

    Habitacion h;
    bool encontrado = false;

    while (arch.read((char*)&h, sizeof(h))) {
        if (h.numero == num) {
            encontrado = true;
        } else {
            temp.write((char*)&h, sizeof(h));
        }
    }

    arch.close();
    temp.close();

    remove("habitaciones.dat");
    rename("temp.dat", "habitaciones.dat");

    if (encontrado)
        cout << "Habitacion eliminada.\n";
    else
        cout << "No existe la habitacion.\n";
}

void masSolicitada() {
    ifstream arch("habitaciones.dat", ios::binary);
    Habitacion h, mayor;
    mayor.vecesReservada = -1;

    while (arch.read((char*)&h, sizeof(h))) {
        if (h.vecesReservada > mayor.vecesReservada)
            mayor = h;
    }

    arch.close();

    if (mayor.vecesReservada == -1) {
        cout << "No hay habitaciones registradas.\n";
        return;
    }

    cout << "\n--- HABITACION MAS SOLICITADA ---\n";
    cout << "Numero: " << mayor.numero << endl;
    cout << "Veces reservada: " << mayor.vecesReservada << endl;
}