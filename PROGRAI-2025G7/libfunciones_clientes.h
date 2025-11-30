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
    bool eliminado;
};
void crearCliente(string archivoClientes){
    cliente clientes;
    ofstream archivo;
    archivo.open(archivoClientes, ios::binary | ios:: app);
    if(archivo.good()){
        cin.ignore();
        cout<<"ingrese su nombre"<<endl;
        cin.getline(clientes.nombre,20);
        cout<<"ingrese sus apellidos"<<endl;
        cin.getline(clientes.apellido,20);
        cout<<"ingrese su fecha de nacimiento"<<endl;
        cin.getline(clientes.fecha_nacimiento,20);
        cout<<"ingrese su email"<<endl;
        cin.getline(clientes.email,20);
        cout<<"ingrese su numero de carnet"<<endl;
        cin.getline(clientes.carnet,20);
        archivo.write((char*)&clientes, sizeof(cliente));
        cout<<"sus datos fueron registrados existosamente"<<endl;
    }
    else{
        cout<<"No se pudo abrir el archivo"<<endl;
    }
    archivo.close();
}
void listado_de_clientes_impresora(string archivoClientes){
    cliente clientes;
    ifstream archivo;
    ofstream reporte;
    archivo.open(archivoClientes, ios::binary);
    reporte.open("Reporte.txt");
    if(archivo.good()){
        system("cls");
        reporte<<"LISTADO DE CLIENTES"<<endl;
        while(archivo.read((char*)&clientes,sizeof(cliente))){
            if(!clientes.eliminado){
                reporte<<"CLIENTE:"<<endl;
                reporte<<"-------------------------------"<<endl;
                reporte<<"\tNombre(s):"<<clientes.nombre<<endl;
                reporte<<"\tApeliido(s):"<<clientes.apellido<<endl;
                reporte<<"\tFecha de nacimiento:"<<clientes.fecha_nacimiento<<endl;
                reporte<<"\tEmail:"<<clientes.email<<endl;
                reporte<<"\tCarnet: "<<clientes.carnet<<endl;
            }
        }
    }
    else{
        cout<<"No se pudo abrir el archivo."<< endl;
    }
    system("pause");
    archivo.close();
}
void listado_de_clientes(string archivoClientes){
    cliente clientes;
    ifstream archivo;
    archivo.open(archivoClientes, ios::binary);
    if(archivo.good()){
        system("cls");
        cout<<"LISTADO DE CLIENTES"<<endl;
        while(archivo.read((char*)&clientes,sizeof(cliente))){
            if(!clientes.eliminado){
                cout<<"CLIENTE:"<<endl;
                cout<<"-------------------------------"<<endl;
                cout<<"\tNombre(s):"<<clientes.nombre<<endl;
                cout<<"\tApeliido(s):"<<clientes.apellido<<endl;
                cout<<"\tFecha de nacimiento:"<<clientes.fecha_nacimiento<<endl;
                cout<<"\tEmail:"<<clientes.email<<endl;
                cout<<"\tCarnet: "<<clientes.carnet<<endl;
            }
        }
    }
    else{
        cout<<"No se pudo abrir el archivo."<< endl;
    }
    system("pause");
    archivo.close();
}
void eliminarCliente(string archivoClientes){
    cliente clientes;
    fstream archivo;
    string nombreBuscado;
    bool encontrado = false;
    system("cls");
    cout << "Ingrese el nombre del contacto a eliminar: ";
    cin.ignore();
    getline(cin, nombreBuscado);
    archivo.open(archivoClientes,  ios::in | ios::out | ios::binary);
    if (archivo.good())
    {
        while (archivo.read((char*)&clientes, sizeof(cliente)) && !encontrado)
        {
            if (nombreBuscado == clientes.nombre && !clientes.eliminado)
            {
                cout << "CLIENTE ELIMINADO: " << clientes.nombre << endl;
                cout << "-----------------------------------" << endl;
                cout << "\tNombre: " << clientes.nombre << endl;
                cout << "\tApellido: " <<clientes.apellido << endl;
                cout << "\tEmail: " << clientes.email << endl;
                cout << "-----------------------------------" << endl;
                encontrado = true;
                archivo.seekp(-sizeof(cliente), ios::cur);
                clientes.eliminado = true;                
                archivo.write((char*)&clientes, sizeof(cliente));
            }
        }
        if (!encontrado)
        {
            cout << "Cliente no encontrado." << endl;
        }
    }
    else
    {
        cout << "No se pudo abrir el archivo." << endl;
    }
    system("pause");
    archivo.close();
}
void editar_datos_cliente(string archivoClientes){
    cliente clientes;
    fstream archivo;
    string nombreBuscado;
    bool encontrado = false;
    system("cls");
    cout << "Ingrese el nombre del cliente a modificar: ";
    cin.ignore();
    getline(cin, nombreBuscado);
    archivo.open(archivoClientes,  ios::in | ios::out | ios::binary);
    if (archivo.good())
    {
        while (archivo.read((char*)&clientes, sizeof(cliente)) && !encontrado)
        {
            if (nombreBuscado == clientes.nombre && !clientes.eliminado)
            {
                cout << "CLIENTE ENCONTRADO: " << clientes.nombre << endl;
                cout << "-----------------------------------" << endl;
                cout << "\tNombre: " << clientes.nombre << endl;
                cout << "\tApellido: " <<clientes.apellido << endl;
                cout<<"\t Carnet: "<< clientes.carnet<<endl;
                cout<<"\t Fecha de nacimiento"<< clientes.fecha_nacimiento<<endl;
                cout << "\tEmail: " << clientes.email << endl;
                cout << "-----------------------------------" << endl;
                encontrado = true;
                archivo.seekp(-sizeof(cliente), ios::cur);
                cout << "Ingrese el nuevo email: ";
                cin.getline(clientes.email, 20);
                cout << "Ingrese el nuevo carnet: ";
                cin >> clientes.carnet;
                cin.ignore();
                cout << "Ingrese la nueva fecha de nacimiento: ";
                cin.getline(clientes.fecha_nacimiento, 20);
                archivo.write((char*)&clientes, sizeof(cliente));
            }
        }
        if (!encontrado)
        {
            cout << "Cliente no encontrado." << endl;
        }
    }
    else
    {
        cout << "No se pudo abrir el archivo." << endl;
    }
    system("pause");
    archivo.close();
}