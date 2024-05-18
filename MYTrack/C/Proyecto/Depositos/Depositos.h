// Depositos.h

#ifndef DEPOSITOS_H
#define DEPOSITOS_H

//Inclucion de librerias
#include<stdio.h>
#include <string.h>

//Se incluyen los archivosde funciones 
#include "../Cuenta/Cuenta.h"

// Función para realizar un depósito en una tarjeta
void Depositar(Cuenta *cuenta, char *numeroTarjeta, double monto);

#endif