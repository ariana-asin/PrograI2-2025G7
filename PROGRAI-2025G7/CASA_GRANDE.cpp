#include "libfunciones_clientes.h"//Ariana Asin
#include "libfunciones_habitaciones.h"//Almari Villarroel
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;
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
                    cout << "================" << endl;
                    cout << "\t1. Nuevo cliente" << endl;
                    cout << "\t2.Lista de clientes" << endl;
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
                    cout << "OPCIONES DE LAS HABITACIONES" << endl;
                    cout << "================" << endl;
                    cout << "\t1.crear habitacion" << endl;
                    cout << "\t2.Eliminar habitacion" << endl;
                    cout << "\t3. Habitaciones disponibles" << endl;
                    cout << "\t0. Salir" << endl;
                    cout << "Seleccione una opcion: ";
                    cin >> subopcion;
                    switch (subopcion){
                        case 1:
                            CrearHabitacion( archivoHabitaciones);
                            system("pause");
                            break;
                        case 2:
                            EliminarHabitacion( archivoHabitaciones);
                            system("pause");
                            break;
                        case 3:
                            HabitacionesDisponibles( archivoHabitaciones);
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
            case 3:
            
                break;

            case 4:
              
                break;
            case 5:{
                char clave_ingresada[20];
                cout<<"Ingrese la contraseña de personal"<<endl;
                cin.ignore();
                cin.getline(clave_ingresada,20);
                if(strcmp(clave_personal,clave_ingresada)==0){
                    do{
                        system("cls");
                        cout << " DATOS REGISTRADOS EN EL HOTEL" << endl;
                        cout << "=========================================" << endl;
                        cout << "\t1. reporte listado clientes (impresora)" << endl;
                        cout << "\t2. ver listado de clientes" << endl;
                        cout << "\t4. reporte de reservas realizadas (impresora) " << endl;
                        cout << "\t5. ver reporte de reservas realizadas" << endl;
                        cout << "\t6. reporte factura (impresora)" << endl;
                        cout << "\t7. ver facturaciones efectuadas" << endl;
                        cout << "\t8. reporte de habitacion mas solicitada y menos solicitada(impresora)" << endl;
                        cout << "\t9. reporte de ingresos al hotel(impresora)" << endl;
                        cout << "\t10. historial del cliente con mayor tiempo de estadia (impresora)" << endl;
                        cout << "\t11. reporte de habitaciones disponibles(impresora)" << endl;
                        cout << "\t0. Volver" << endl;
                        cout << "Seleccione una opcion: ";
                        cin >> subopcion;   
                        switch (subopcion){
                            case 1:
                                listado_de_clientes_impresora(archivoClientes);
                                system("pause");
                                break;
                            case 2:
                                listado_de_clientes( archivoClientes);
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