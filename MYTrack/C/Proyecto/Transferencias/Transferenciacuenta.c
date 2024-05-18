// Transferenciacuenta.c

#include "./Transferencias.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void TranferirEntreTarjetas(Tarjeta *origen, Tarjeta *destino, double monto) {
    if (origen == NULL || destino == NULL) {
        printf("Error: los datos de la tarjeta no son válidos.\n");
        return;
    }
    if (monto <= 0) {
        printf("Error: el monto a transferir debe ser positivo.\n");
        return;
    }
    if (origen->Saldo >= monto) {
        origen->Saldo -= monto;
        destino->Saldo += monto;
        printf("Transferencia exitosa de $%.2f de la tarjeta %s a la tarjeta %s.\n", monto, origen->ID, destino->ID);
    } else {
        printf("Saldo insuficiente en la tarjeta %s. Saldo disponible: $%.2f, monto requerido: $%.2f.\n", origen->ID, origen->Saldo, monto);
    }

}
