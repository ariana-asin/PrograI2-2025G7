#include "libfunciones_clientes.h"//Ariana Asin
#include "libfunciones_facturizacion.h"//Ariana Asin
#include "libfunciones_habitaciones.h"//Almari Villarroel
#include "libfunciones_reservas.h"//Almari Villarroel
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;
Reserva buscarReservaActiva(string archivoReservas, int carnet) {
    fstream archivo(archivoReservas, ios::binary | ios::in);
    Reserva r;
    while (archivo.read((char*)&r, sizeof(Reserva))) {
        if (r.carnet_cliente == carnet && r.estado_reserva) {
            return r; 
        }
    }
    Reserva vacia; 
    return vacia;
}
void MenuOpciones(string archivoClientes,string archivoHabitaciones,string archivoReservas,string archivoFacturas){
    int opcion = 0;
    int subopcion = 0;
    char clave_personal[]="C4s4_gr4nd3";
    do
    {
        system("cls");
        cout << "MENU DE OPCIONES" << endl;
        cout << "================" << endl;
        cout << "\t1. ABM clientes" << endl;
        cout << "\t2. ABM habitaciones " << endl;
        cout << "\t3. ABM reservas" << endl;
        cout << "\t4. Facturacion" << endl;
        cout << "\t5. Datos registrados del hotel" << endl;
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
                    cout << "==========================" << endl;
                    cout << "\t1. Nuevo cliente" << endl;
                    cout << "\t2. Lista de clientes" << endl;
                    cout << "\t3. Eliminar cliente" << endl;
                    cout << "\t4. Editar datos del cliente" << endl;
                    cout << "\t0. Salir" << endl;
                    cout << "Seleccione una opcion: ";
                    cin >> subopcion;
                    switch (subopcion){
                        case 1:
                            crearCliente(archivoClientes);
                            system("pause");
                            break;
                        case 2:
                            listado_de_clientes(archivoClientes);
                            system("pause");
                            break;
                        case 3:
                            eliminarCliente(archivoClientes);
                            system("pause");
                            break;
                        case 4: 
                            editar_datos_cliente(archivoClientes);
                            system("pause");
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Opcion no valida." << endl;
                            system("pause");
                            break;
                    }
                } while (subopcion != 0);
                break;
            case 2:
                do{
                    system("cls");                    
                    cout<<"OPCIONES DE LAS HABITACIONES"<< endl;
                    cout<<"============================"<< endl;
                    cout<<"\t1.Crear habitacion"<< endl;
                    cout<<"\t2.Ver habitaciones disponibles"<<endl;
                    cout<<"\t3.Cambiar de habitacion"<< endl;
                    cout<<"\t4.Eliminar habitacion"<< endl;
                    cout<<"\t5.Habitacion mas solicitada"<<endl;
                    cout<<"\t0.Salir" << endl;
                    cout<<"Seleccione una opcion: ";
                    cin >> subopcion;
                    switch (subopcion){
                        case 1:
                            crearHabitacion(archivoHabitaciones);
                            system("pause");
                            break;
                        case 2:
                            habitacionesDisponibles(archivoHabitaciones);
                            system("pause");
                            break;
                        case 3:
                            cambiarHabitacion(archivoHabitaciones);
                            system("pause");
                            break;
                        case 4:
                            eliminarHabitacion(archivoHabitaciones);
                            system("pause");
                        case 5:
                            masSolicitada(archivoHabitaciones);
                            system("pause");
                        case 0:
                            break;
                        default:
                            cout << "Opcion no valida." << endl;
                            system("pause");
                            break;
                    }
                } while (subopcion != 0);
                break;
            case 3:
                do{
                    system("cls");                    
                    cout<<"OPCIONES DE RESERVACION"<< endl;
                    cout<<"============================"<< endl;
                    cout<<"\t1.Crear reserva"<< endl;
                    cout<<"\t2.Cancelar reserva"<<endl;
                    cout<<"\t3.Mostrar reservas activas"<< endl;
                    cout<<"\t0.Salir" << endl;
                    cout<<"Seleccione una opcion: ";
                    cin >> subopcion;
                    switch (subopcion){
                        case 1:
                            CrearReserva(archivoReservas,archivoHabitaciones);
                            system("pause");
                            break;
                        case 2:
                            CancelarReserva(archivoReservas,archivoHabitaciones);
                            system("pause");
                            break;
                        case 3:
                            MostrarReservas(archivoReservas);
                            system("pause");
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Opcion no valida." << endl;
                            system("pause");
                            break;
                    }
                } while (subopcion != 0);
                break;
            case 4:
                do{
                    system("cls");
                    cout<<"OPCIONES PARA LA FACTURACION"<<endl;
                    cout<<"----------------------------"<<endl;
                    cout<<"\t1.Crear factura"<<endl;
                    cout<<"\t2.Eliminar factura"<<endl;
                    cout <<"\t0.Salir" << endl;
                    cout << "Seleccione una opcion: ";
                    cin >> subopcion;
                    switch (subopcion){
                        case 1:{
                            int carnetCliente;
                            cout << "Ingrese el carnet con el que se registro en el hotel para facturar: ";
                            cin >> carnetCliente;
                            Reserva r = buscarReservaActiva(archivoReservas, carnetCliente);
                            if (r.carnet_cliente != 0) { 
                                crearFactura(archivoFacturas, r.numero_habitacion, r.noches, r.total);
                            } else {
                                cout << "Reserva no encontrada para este cliente." << endl;
                            }
                            system("pause");
                            break;
                        }
                        case 2:
                            eliminarFactura(archivoFacturas);
                            system("pause");
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Opcion no valida." << endl;
                            system("pause");
                            break;
                    }
                } while (subopcion != 0);
                break;
            case 5:{
                char clave_ingresada[20];
                cout<<"Ingrese la contraseña de personal para poder visualizar los datos"<<endl;
                cin.ignore();
                cin.getline(clave_ingresada,20);
                if(strcmp(clave_personal,clave_ingresada)==0){
                    do{
                        system("cls");
                        cout << " DATOS REGISTRADOS EN EL HOTEL" << endl;
                        cout << "==============================" << endl;
                        cout << "\t1.Reporte listado clientes (impresora)" << endl;
                        cout << "\t2.Ver listado de clientes" << endl;
                        cout << "\t3.Reporte de reservas realizadas (impresora) " << endl;
                        cout << "\t4.Ver reporte de reservas realizadas" << endl;
                        cout << "\t5.Reporte factura (impresora)" << endl;
                        cout << "\t6.Ver facturaciones efectuadas" << endl;
                        cout << "\t7.Reporte de habitacion mas solicitada y menos solicitada(impresora)" << endl;
                        cout << "\t8.Reporte de ingresos al hotel(impresora)" << endl;
                        cout << "\t9.Historial del cliente con mayor tiempo de estadia (impresora)" << endl;
                        cout << "\t10.Reporte de habitaciones disponibles(impresora)" << endl;
                        cout << "\t0.Volver" << endl;
                        cout << "Seleccione una opcion: ";
                        cin >> subopcion;   
                        switch (subopcion){
                            case 1:
                                listado_de_clientes_impresora(archivoClientes);
                                system("pause");
                                break;
                            case 2:
                                listado_de_clientes(archivoClientes);
                                system("pause");
                                break;
                            case 3:
                                break;
                            case 4:
                                MostrarReservas(archivoReservas);
                                system("pause");
                                break;
                            case 5:
                                listado_de_facturas_impresora(archivoFacturas);
                                system("pause");
                                break;
                            case 6:
                                listado_de_facturas(archivoFacturas);
                                system("pause");
                                break;
                            case 0:
                                break;
                            default:
                                cout << "Opcion no valida" << endl;
                                system("pause");
                                break;
                        }
                    } while(subopcion != 0);
                }
                else{
                    cout<<"contraseña incorrecta"<<endl;
                    system("pause");
                }
                break;
            }
            case 0:
                break;

            default:
                cout<<"opcion no valida"<<endl;
                system("pause");
                break;
        }
    } while (opcion != 0);
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