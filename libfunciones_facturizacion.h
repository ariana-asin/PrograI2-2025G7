#pragma once
#include <iostream>
#include <cstring>
#include "libfunciones_reservas.h"
#include "libfunciones_habitaciones.h"
using namespace std;
struct facturacion
{
    float total_reserva;
    char nombre [20];
    int nit_o_carnet;
    char razon_social[20];
    char email[20];
    int numero_habitacion; 
    int noches;   
    bool eliminado;         
};
void capitalizar_facturas(char texto[]){ //FUNCION PARA CONVERTIR EL NOMBRE A MINUSCULAS EJ (ARIANA o ariana-->Ariana)
    texto[0]=toupper(texto[0]); 
    for(int i=1; texto[i]!='\0';i++){
        texto[i]=tolower(texto[i]);
    }
}
inline void crearFactura(string archivoFacturas, int numero_habitacion, int noches, float total){
    facturacion factura;
    ofstream archivo;
    archivo.open(archivoFacturas, ios::binary | ios:: app);
    if(archivo.good()){
        cin.ignore();
        cout<<"Ingrese la razon social para la factura:"<<endl;
        cin.getline(factura.razon_social,20);
        capitalizar_facturas(factura.razon_social);
        cout<<"Ingrese su nit o carnet"<<endl;
        cin>>factura.nit_o_carnet;
        cin.ignore();
        cout<<"Ingrese su email para obtener la factura digitalizada"<<endl;
        cin.getline(factura.email,20);
        factura.numero_habitacion = numero_habitacion;
        factura.noches = noches;
        factura.total_reserva = total;
        archivo.write((char*)&factura, sizeof(facturacion));
        cout<<"sus datos fueron registrados existosamente"<<endl;
    }
    else{
        cout<<"No se pudo abrir el archivo"<<endl;
    }
    archivo.close();
}
inline void listado_de_facturas_impresora(string archivoFacturas){
    facturacion factura;
    ifstream archivo;
    ofstream reporte;
    archivo.open(archivoFacturas, ios::binary);
    reporte.open("Reporte_facturas.txt");
    if(archivo.good()){
        system("cls");
        reporte<<"LISTADO DE FACTURAS"<<endl;
        reporte<<"-------------------"<<endl;
        while(archivo.read((char*)&factura,sizeof(facturacion))){
            if(!factura.eliminado){
                reporte<<"CLIENTE:"<<factura.nombre<<endl;
                reporte<<"------------------------------"<<endl;
                reporte<<"\tRazon social:"<<factura.razon_social<<endl;
                reporte<<"\tNit o carnet:"<<factura.nit_o_carnet<<endl;
                reporte<<"\tTotal pagado:"<<factura.total_reserva<<endl;
                reporte<<"\tHabitacion adquirida"<<factura.numero_habitacion<<endl;
                reporte<<"\tNoches reservadas"<<factura.noches<<endl;
                reporte<<"\tEmail:"<<factura.email<<endl;
            }
        }
    }
    else{
        cout<<"No se pudo abrir el archivo."<< endl;
    }
    system("pause");
    archivo.close();
}
inline void listado_de_facturas(string archivoFacturas ){
    facturacion factura;
    ifstream archivo;
    archivo.open(archivoFacturas, ios::binary);
    if(archivo.good()){
        system("cls");
        cout<<"LISTADO DE FACTURAS"<<endl;
        cout<<"-------------------"<<endl;
        while(archivo.read((char*)&factura,sizeof(facturacion))){
            if(!factura.eliminado){
                cout<<"CLIENTE:"<<factura.nombre<<endl;
                cout<<"-----------------------------"<<endl;
                cout<<"\tRazon social: "<<factura.razon_social<<endl;
                cout<<"\tNit o carnet: "<<factura.nit_o_carnet<<endl;
                cout<<"\tHabitacion adquirida"<<factura.numero_habitacion<<endl;
                cout<<"\tTotal pagado:"<<factura.total_reserva<<endl;
                cout<<"\tNoches reservadas"<<factura.noches<<endl;
                cout<<"\tEmail:"<<factura.email<<endl;
            }
        }
    }
    else{
        cout<<"No se pudo abrir el archivo."<< endl;
    }
    system("pause");
    archivo.close();
}
inline void eliminarFactura(string archivoFacturas){
    facturacion factura;
    fstream archivo;
    char nombreBuscado[20];
    bool encontrado = false;
    system("cls");
    cout << "Ingrese la razon social de la factura a eliminar: ";
    cin.ignore();
    cin.getline(nombreBuscado,20);
    capitalizar_facturas(nombreBuscado);
    archivo.open(archivoFacturas,  ios::in | ios::out | ios::binary);
    if (archivo.good())
    {
        while (archivo.read((char*)&factura, sizeof(facturacion)) && !encontrado)
        {
            if (strcmp(nombreBuscado, factura.razon_social)==0 && !factura.eliminado)
            {
                cout<<"FACTURA ELIMINADA: " << endl;
                cout<<"-----------------------------------" << endl;
                cout<<"\tRazon social: " <<factura.razon_social<< endl;
                cout<<"\tNit o carnet:"<<factura.nit_o_carnet<<endl;
                cout<<"\tHabitacion adquirida"<<factura.numero_habitacion<<endl;
                cout<<"\tTotal pagado:"<<factura.total_reserva<<endl;
                cout<<"\tNoches reservadas"<<factura.noches<<endl;
                cout<<"\tEmail:"<<factura.email<<endl;
                cout<< "-----------------------------------" << endl;
                encontrado = true;
                archivo.seekp(-sizeof(facturacion), ios::cur);
                factura.eliminado = true;                
                archivo.write((char*)&factura, sizeof(facturacion));
            }
        }
        if (!encontrado)
        {
            cout << "Factura no encontrada." << endl;
        }
    }
    else
    {
        cout << "No se pudo abrir el archivo." << endl;
    }
    system("pause");
    archivo.close();
}
