// Tickets.h
#ifndef TICKETS_H
#define TICKETS_H

// Inclucion de librerias
#include <stdio.h>
#include <string.h>

//Se incluyen los archivosde funciones 
#include "../Cuenta/Cuenta.h"

// Funcion para imprimir el ticket
void imprimeTicket(char tipoOperacion, Cuenta *cuenta, double monto);

#endif
