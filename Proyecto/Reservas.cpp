#include <iostream>
#include <cstring>
#include <fstream>
#include "libreservas.h"
#include "libhabitaciones.h"
using namespace std;

void MostrarHabitacionesDisponibles() {
    ifstream arch("habitaciones.dat", ios::binary);
    Habitacion h;
    bool hay = false;
    cout << "\n--- HABITACIONES DISPONIBLES ---\n";
    while (arch.read((char*)&h, sizeof(Habitacion))) {
        if (!h.ocupada) {
            hay = true;
            cout << "Numero: " << h.numero 
                 << " | Precio: " << h.precio 
                 << " | Capacidad: " << h.capacidad << endl;
        }
    }
    arch.close();
    if (!hay) cout << "No hay habitaciones disponibles.\n";
}

bool verificarHabitacionLibre(int numero) {
    ifstream arch("habitaciones.dat", ios::binary);
    Habitacion h;
    while (arch.read((char*)&h, sizeof(Habitacion))) {
        if (h.numero == numero) {
            arch.close();
            return !h.ocupada;
        }
    }
    arch.close();
    return false; 
}

void ocuparHabitacion(int numero) {
    fstream arch("habitaciones.dat", ios::binary | ios::in | ios::out);
    Habitacion h;
    while (arch.read((char*)&h, sizeof(Habitacion))) {
        if (h.numero == numero) {
            h.ocupada = true;
            h.vecesReservada++;
            arch.seekp(-sizeof(h), ios::cur);
            arch.write((char*)&h, sizeof(Habitacion));
            break;
        }
    }
    arch.close();
}

void liberarHabitacion(int numero) {
    fstream arch("habitaciones.dat", ios::binary | ios::in | ios::out);
    Habitacion h;
    while (arch.read((char*)&h, sizeof(Habitacion))) {
        if (h.numero == numero) {
            h.ocupada = false;
            arch.seekp(-sizeof(h), ios::cur);
            arch.write((char*)&h, sizeof(Habitacion));
            break;
        }
    }
    arch.close();
}

void CrearReserva() {
    MostrarHabitacionesDisponibles();

    Reserva r;
    cout << "\nCarnet del cliente: ";
    cin >> r.carnet_cliente;

    cout << "Ingrese el numero de habitacion a reservar: ";
    cin >> r.numero_habitacion;

    if (!verificarHabitacionLibre(r.numero_habitacion)) {
        cout << "ERROR: La habitacion esta ocupada o no existe.\n";
        return;
    }

    cout << "Noches: ";
    cin >> r.noches;

    int op;
    cout << "Desea dejar garantia? (1=si,0=no): ";
    cin >> op;
    if (op == 1) {
        cout << "Monto garantia: ";
        cin >> r.garantia;
    } else r.garantia = 0;

    r.estado_reserva = true;
    r.total = r.noches * 100 + r.garantia;

    // Guardar reserva
    ofstream arch("reservas.dat", ios::binary | ios::app);
    arch.write((char*)&r, sizeof(Reserva));
    arch.close();

    // Ocupar habitación
    ocuparHabitacion(r.numero_habitacion);

    cout << "Reserva creada correctamente.\n";
}

void CancelarReserva() {
    int carnet;
    cout << "Ingrese su carnet para cancelar la reserva: ";
    cin >> carnet;

    fstream arch("reservas.dat", ios::binary | ios::in | ios::out);
    Reserva r;
    bool encontrado = false;

    while (arch.read((char*)&r, sizeof(Reserva))) {
        if (r.carnet_cliente == carnet && r.estado_reserva) {
            r.estado_reserva = false;
            arch.seekp(-sizeof(r), ios::cur);
            arch.write((char*)&r, sizeof(Reserva));
            liberarHabitacion(r.numero_habitacion);
            encontrado = true;
            cout << "Reserva cancelada y habitacion liberada.\n";
            break;
        }
    }

    if (!encontrado) {
        cout << "No se encontro reserva activa con ese carnet.\n";
    }

    arch.close();
}

void MostrarReservas() {
    ifstream arch("reservas.dat", ios::binary);
    Reserva r;
    bool hay = false;
    cout << "\n--- RESERVAS ACTIVAS ---\n";
    while (arch.read((char*)&r, sizeof(Reserva))) {
        if (r.estado_reserva) {
            hay = true;
            cout << "Carnet: " << r.carnet_cliente << endl;
            cout << "Habitacion: " << r.numero_habitacion << endl;
            cout << "Noches: " << r.noches << endl;
            cout << "Garantia: " << r.garantia << endl;
            cout << "Total: " << r.total << endl;
            cout << "----------------------\n";
        }
    }
    arch.close();
    if (!hay) cout << "No hay reservas activas.\n";
}

void menu() {
    int opc;
    do {
        cout << "\n--- SISTEMA DE RESERVAS ---\n";
        cout << "1. Crear reserva\n";
        cout << "2. Cancelar reserva\n";
        cout << "3. Mostrar reservas activas\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opc;

        switch(opc) {
            case 1: CrearReserva(); break;
            case 2: CancelarReserva(); break;
            case 3: MostrarReservas(); break;
        }

    } while(opc != 0);

}
