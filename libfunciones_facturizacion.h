#include <iostream>
#include <cstring>
using namespace std;
struct facturacion
{
    float total;
    char nombre [20];
    int nit_o_carnet;
    char razon_social[20];
    char email[20];
    bool eliminado;
};
void capitalizar_facturas(char texto[]){ //FUNCION PARA CONVERTIR EL NOMBRE A MINUSCULAS EJ (ARIANA o ariana-->Ariana)
    texto[0]=toupper(texto[0]); 
    for(int i=1; texto[i]!='\0';i++){
        texto[i]=tolower(texto[i]);
    }
}
void crearFactura(string archivoFacturas){
    facturacion factura;
    ofstream archivo;
    archivo.open(archivoFacturas, ios::binary | ios:: app);
    if(archivo.good()){
        cin.ignore();
        cout<<"Ingrese el nombre con el que se registro en el hotel"<<endl;
        cin.getline(factura.nombre,20);
        capitalizar(factura.nombre);
        cout<<"Razon social para la factura:"<<endl;
        cin.getline(factura.razon_social,20);
        capitalizar(factura.razon_social);
        cout<<"Ingrese su nit o carnet"<<endl;
        cin>>factura.nit_o_carnet;
        cin.ignore();
        cout<<"Ingrese su email para obtener la factura digitalizada"<<endl;
        cin.getline(factura.email,20);
        archivo.write((char*)&factura, sizeof(facturacion));
        cout<<"sus datos fueron registrados existosamente"<<endl;
    }
    else{
        cout<<"No se pudo abrir el archivo"<<endl;
    }
    archivo.close();
}
void listado_de_facturas_impresora(string archivoFacturas){
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
                //reporte<<"\tTotal pagado:"<<endl;
                //reporte<<"\tHabitacion adquirida"<<endl;
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
void listado_de_facturas(string archivoFacturas ){
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
                //cout<<"\tHabitacion adquirida"<<endl;
                //cout<<"\tTotal pagado:"<<endl;
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
void eliminarFactura(string archivoFacturas){
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
                cout<< "FACTURA ELIMINADA: " << endl;
                cout<< "-----------------------------------" << endl;
                cout<< "\tRazon social: " <<factura.razon_social<< endl;
                cout<<"\tNit o carnet:"<<factura.nit_o_carnet<<endl;
                //cout<<"\tHabitacion adquirida"<<endl;
                //cout<<"\tTotal pagado:"<<endl;
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
void editar_datos_factura(string archivoFacturas){
    facturacion factura;
    fstream archivo;
    char nombreBuscado[20];
    int subopcion;
    bool encontrado = false;
    cout << "Ingrese la razon social de la factura a modificar: ";
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
                cout<< "FACTURA ENCONTRADA: " << endl;
                cout<< "-----------------------------------" << endl;
                cout<< "\tRazon social: " <<factura.razon_social<< endl;
                cout<<"\tNit o carnet:"<<factura.nit_o_carnet<<endl;
                //cout<<"\tHabitacion adquirida"<<endl;
                //cout<<"\tTotal pagado:"<<endl;
                cout<<"\tEmail:"<<factura.email<<endl;
                cout<< "-----------------------------------" << endl;
                encontrado = true;
                archivo.seekp(-sizeof(facturacion), ios::cur);
                cout<<"OPCIONES DE MODIFICADO"<<endl;
                cout<<"----------------------"<<endl;
                cout<<"\t1.Nombre del cliente que estuvo registrado"<<endl;
                cout<<"\t2.Razon social"<<endl;
                cout<<"\t3.Nit o carnet"<<endl;
                cout<<"\t4.Email"<<endl;
                cout<<"\t5.Modificar todos los datos"<<endl;
                cout<<"\t0.salir"<<endl;
                cout<<"Seleccione una opcion de acuerdo a sus necesidades"<<endl;
                cin>>subopcion;
                cin.ignore();
                switch(subopcion){
                    case 1:
                        cout<<"Ingrese el nuevo nombre:"<<endl;
                        cin.getline(factura.nombre,20);
                        capitalizar_facturas(factura.nombre);
                        archivo.write((char*)&factura, sizeof(facturacion));
                        system("pause");
                        break;
                    case 2:
                        cout<<"Ingrese la nueva razon social:"<<endl;
                        cin.getline(factura.razon_social,20);
                        capitalizar_facturas(factura.razon_social);
                        archivo.write((char*)&factura, sizeof(facturacion));
                        system("pause");
                        break;
                    case 3:
                        cout<<"Ingrese el nuevo Nit o carnet(SOLO NUMEROS):"<<endl;
                        cin>>factura.nit_o_carnet;
                        archivo.write((char*)&factura, sizeof(facturacion));
                        system("pause");
                        break;
                    case 4:
                        cin.ignore();
                        cout<<"Ingrese el nuevo gmail"<<endl;
                        cin.getline(factura.email,20);
                        archivo.write((char*)&factura, sizeof(facturacion));
                        system("pause");
                        break;
                    case 5:
                        cout<<"Llene todos los datos por favor"<<endl;
                        cout<<"Ingrese el nuevo nombre: "<<endl;
                        cin.getline(factura.nombre,20);
                        capitalizar_facturas(factura.nombre);
                        cout<<"Ingrese la nueva razon social: "<<endl;
                        cin.getline(factura.razon_social,20);
                        capitalizar_facturas(factura.razon_social);
                        cout<<"Ingrese el nuevo Nit o carnet(SOLO NUMEROS): "<<endl;
                        cin>>factura.nit_o_carnet;
                        cin.ignore();
                        cout<<"Ingrese el nuevo gmail: "<<endl;
                        cin.getline(factura.email,20);
                        archivo.write((char*)&factura, sizeof(facturacion));
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