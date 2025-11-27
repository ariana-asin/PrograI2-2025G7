#include <iostream>
using namespace std;
struct reserva
{
    int carnet_cliente;
    char numero_habitacion[5];
    int codigo_habitacion;
    int noches;
    bool estado_reserva;
    float garantia;
    float total;
};