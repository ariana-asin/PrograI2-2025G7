#include <iostream>
using namespace std;
struct facturacion
{
    float total;
    char metodo_de_pago[10];
    bool estado_pago;
    int nit_o_carnet;
    char apellido[20];
};
void crearFactura(string archivoFacturas){
    facturacion factura;
    ofstream archivo;
    archivo.open(archivoFacturas, ios::binary | ios:: app);
    if(archivo.good()){
        cin.ignore();
        cout<<"ingrese el metodo de pago (solo efectivo o tarjeta)"<<endl;
        cin.getline(factura.metodo_de_pago,10);
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