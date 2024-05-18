// Retiros.c

// Se incluyen los archivos de funciones
#include "Retiros.h"
#include "../Cuenta/Cuenta.h"
#include "../Tickets/Tickets.h" 

// Inclucion de librerias
#include <stdio.h>
#include <string.h>

// Función para retiro
void retiro(Cuenta *cuenta, char *numeroTarjeta, double monto) {
    // Comprobamos si la tarjeta existe en la cuenta
    if (strcmp(cuenta->TarjetaPrincipal.ID, numeroTarjeta) == 0) {
        // Verificar que haya suficiente saldo en la tarjeta principal
        if (cuenta->TarjetaPrincipal.Saldo >= monto) {
            // Realizar el retiro de la tarjeta principal
            cuenta->TarjetaPrincipal.Saldo -= monto;
            // Generar el ticket de retiro
           imprimeTicket('R', cuenta, monto);
            printf("Retiro realizado desde la tarjeta principal.\n");
        } else {
            printf("Saldo insuficiente en la tarjeta principal.\n");
        }
    } else if (strcmp(cuenta->TarjetaSecundaria.ID, numeroTarjeta) == 0) {
        // Verificar que haya suficiente saldo en la tarjeta secundaria
        if (cuenta->TarjetaSecundaria.Saldo >= monto) {
            // Realizar el retiro de la tarjeta secundaria
            cuenta->TarjetaSecundaria.Saldo -= monto;
            // Generar el ticket de retiro
            imprimeTicket('R', cuenta, monto);
            printf("Retiro realizado desde la tarjeta secundaria.\n");
        } else {
            printf("Saldo insuficiente en la tarjeta secundaria.\n");
        }
    } else {
        // La tarjeta no pertenece a la cuenta
        printf("El número de tarjeta no coincide con ninguna tarjeta asociada a esta cuenta.\n");
    }
}