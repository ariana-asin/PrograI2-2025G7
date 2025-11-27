#include "libfunciones_clientes.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void MenuOpciones(string archivoClientes,string archivoHabitaciones,string archivoReservas,string archivoFacturas){
    int opcion = 0;
    int subopcion = 0;
    do
    {
        system("cls");
        cout << "MENU DE OPCIONES" << endl;
        cout << "================" << endl;
        cout << "\t1. ABM clientes" << endl;
        cout << "\t2. ABM " << endl;
        cout << "\t3. ABM " << endl;
        cout << "\t4. Facturacion" << endl;
        cout << "\t0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        switch (opcion)
        {
            case 1:
                do
                {
                    system("cls");                    
                    cout << "OPCIONES PARA LOS CLIENTES" << endl;
                    cout << "================" << endl;
                    cout << "\t1. Nuevo cliente" << endl;
                    cout << "\t2. Eliminar cliente" << endl;
                    cout <<"\t3. Editar datos del cliente"<<endl;
                    cout << "\t0. Salir" << endl;
                    cout << "Seleccione una opcion: ";
                    cin >> subopcion;
                    switch (subopcion){
                        case 1:
                            crearCliente(archivoClientes);
                            system("pause");
                            break;
                        case 2:
                            eliminarCliente(archivoClientes);
                            system("pause");
                            break;
                        case 3: 
                            editar_datos_cliente(archivoClientes);
                            system("pause");
                            break;
                        default:
                            if (subopcion != 0)
                            {
                                cout << "Opcion no valida." << endl;
                                system("pause");
                            }
                            break;
                    }
                } while (subopcion != 0);            
                break;
            case 2:

            case 3:
            
            case 4:
               
            default:
               
                break;
        }
    } while (opcion != 0);
    system("cls");
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

