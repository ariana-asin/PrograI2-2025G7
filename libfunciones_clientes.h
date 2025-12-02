#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
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
void capitalizar(char texto[]){ //FUNCION PARA CONVERTIR EL NOMBRE A MINUSCULAS EJ (ARIANA o ariana-->Ariana)
    texto[0]=toupper(texto[0]); //convertir la primera letra en mayuscula
    for(int i=1; texto[i]!='\0';i++){
        texto[i]=tolower(texto[i]);//convertir todo lo demas a minuscula
    }
}
void crearCliente(string archivoClientes){
    cliente clientes;
    ofstream archivo;
    archivo.open(archivoClientes, ios::binary | ios:: app);
    if(archivo.good()){
        cin.ignore();
        cout<<"Ingrese su nombre"<<endl;
        cin.getline(clientes.nombre,20);
        capitalizar(clientes.nombre);
        cout<<"Ingrese sus apellidos"<<endl;
        cin.getline(clientes.apellido,20);
        capitalizar(clientes.apellido);
        cout<<"Ingrese su fecha de nacimiento"<<endl;
        cin.getline(clientes.fecha_nacimiento,20);
        cout<<"Ingrese su email"<<endl;
        cin.getline(clientes.email,20);
        cout<<"Ingrese su numero de carnet"<<endl;
        cin.getline(clientes.carnet,20);
        archivo.write((char*)&clientes, sizeof(cliente));
        cout<<"Sus datos fueron registrados existosamente"<<endl;
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
    reporte.open("ListaClientes.txt");
    if(archivo.good()){
        system("cls");
        reporte<<"LISTADO DE CLIENTES"<<endl;
        while(archivo.read((char*)&clientes,sizeof(cliente))){
            if(!clientes.eliminado){
                reporte<<"CLIENTE:"<<endl;
                reporte<<"------------------------------"<<endl;
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
                cout<<"-----------------------------"<<endl;
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
    char nombreBuscado[20];
    bool encontrado = false;
    system("cls");
    cout << "Ingrese el nombre del contacto a eliminar: ";
    cin.ignore();
    cin.getline(nombreBuscado,20);
    capitalizar(nombreBuscado);
    archivo.open(archivoClientes,  ios::in | ios::out | ios::binary);
    if (archivo.good())
    {
        while (archivo.read((char*)&clientes, sizeof(cliente)) && !encontrado)
        {
            if (strcmp(nombreBuscado,clientes.nombre)==0 && !clientes.eliminado)
            {
                cout<< "CLIENTE ELIMINADO: " << clientes.nombre << endl;
                cout<< "-----------------------------------" << endl;
                cout<< "\tNombre: " << clientes.nombre << endl;
                cout<< "\tApellido: " <<clientes.apellido << endl;
                cout<<"\tFecha de nacimiento: "<<clientes.fecha_nacimiento<<endl;
                cout<< "\tEmail: " << clientes.email << endl;
                cout<<"\tCarnet: " <<clientes.carnet<<endl;
                cout<< "-----------------------------------" << endl;
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
    char nombreBuscado[20];
    int subopcion;
    bool encontrado = false;
    cout << "Ingrese el nombre del cliente a modificar en MINUSCULAS:";
    cin.ignore();
    cin.getline(nombreBuscado,20);
    capitalizar(nombreBuscado);
    archivo.open(archivoClientes,  ios::in | ios::out | ios::binary);
    if (archivo.good())
    {
        while (archivo.read((char*)&clientes, sizeof(cliente)) && !encontrado)
        {
            if (strcmp(nombreBuscado,clientes.nombre)==0 && !clientes.eliminado)
            {
                cout<< "CLIENTE ENCONTRADO:" << clientes.nombre << endl;
                cout<< "-----------------------------------" << endl;
                cout<< "\tNombre: " << clientes.nombre << endl;
                cout<< "\tApellido: " <<clientes.apellido << endl;
                cout<<"\tCarnet: "<< clientes.carnet<<endl;
                cout<<"\tFecha de nacimiento"<< clientes.fecha_nacimiento<<endl;
                cout<< "\tEmail: " << clientes.email << endl;
                cout<< "-----------------------------------" << endl;
                encontrado = true;
                archivo.seekp(-sizeof(cliente), ios::cur);
                cout<<"OPCIONES DE MODIFICADO"<<endl;
                cout<<"----------------------"<<endl;
                cout<<"\t1.Nombre"<<endl;
                cout<<"\t2.Apellidos"<<endl;
                cout<<"\t3.Carnet"<<endl;
                cout<<"\t4.Fecha de nacimiento"<<endl;
                cout<<"\t5.Email"<<endl;
                cout<<"\t6.Modificar todos los datos"<<endl;
                cout<<"\t0.salir"<<endl;
                cout<<"Seleccione una opcion de acuerdo a sus necesidades"<<endl;
                cin>>subopcion;
                cin.ignore();
                switch(subopcion){
                    case 1:
                        cout<<"Ingrese el nuevo nombre:"<<endl;
                        cin.getline(clientes.nombre,20);
                        capitalizar(nombreBuscado);
                        archivo.write((char*)&clientes, sizeof(cliente));
                        system("pause");
                        break;
                    case 2:
                        cout<<"Ingrese el nuevo apellido:"<<endl;
                        cin.getline(clientes.apellido,20);
                        capitalizar(clientes.apellido);
                        archivo.write((char*)&clientes, sizeof(cliente));
                        system("pause");
                        break;
                    case 3:
                        cout<<"Ingrese el nuevo numero de carnet:"<<endl;
                        cin.getline(clientes.carnet,20);
                        archivo.write((char*)&clientes, sizeof(cliente));
                        system("pause");
                        break;
                    case 4:
                        cout<<"Ingrese la fecha de nacimiento (xx/yy/zzzz)"<<endl;
                        cin.getline(clientes.fecha_nacimiento,20);
                        archivo.write((char*)&clientes, sizeof(cliente));
                        system("pause");
                        break;
                    case 5:
                        cout<<"Ingrese el nuevo gmail"<<endl;
                        cin.getline(clientes.email,20);
                        archivo.write((char*)&clientes, sizeof(cliente));
                        system("pause");
                        break;
                    case 6:
                        cout<<"Llene todos los datos por favor"<<endl;
                        cout<<"nombre(s):"<<endl;
                        cin.getline(clientes.nombre,20);
                        capitalizar(clientes.nombre);
                        cout<<"apellido(s)"<<endl;
                        cin.getline(clientes.apellido,20);
                        capitalizar(clientes.apellido);
                        cout<<"carnet:"<<endl;
                        cin.getline(clientes.carnet,20);
                        cout<<"fecha de nacimiento:"<<endl;
                        cin.getline(clientes.fecha_nacimiento,20);
                        cout<<"email:"<<endl;
                        cin.getline(clientes.email,20);
                        archivo.write((char*)&clientes, sizeof(cliente));
                        system("pause");
                        break;
                    case 0:
                        cout<<"Modificacion cancelada"<<endl;
                        system("pause");
                        return;
                    default:
                        cout<<"Opcion no valida";
                        system("pause");
                        break;
                    cout<<" Los datos se registraron con exito."<<endl;
                }
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