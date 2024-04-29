#include <stdio.h>
#include "Depositos/SolicitudCuenta.h"
#include "Depositos/NombreDestino.h"

enum Transaccion
{
    DepositarOPC,
    RetiroEfectivo,
    EstadoDeCuenta,
    MovimientosRecientes,
    Inversion,
    CambioNIP
};

int main()
{
    int choice;
    printf("Por favor, selecciona la opción que deseas realizar:\n");
    printf("0 - Depositar\n1 - Retiro de Efectivo\n2 - Estado de Cuenta\n3 - Movimientos Recientes\n4 - Inversión\n5 - Cambio de NIP\n");
    scanf("%d", &choice);

    if (choice < DepositarOPC || choice > CambioNIP)
    {
        printf("No es una opción válida.\n");
        return 1;
    }

    switch (choice)
    {
    case DepositarOPC:
        if (!Depositar())
        {
            printf("Error en la solicitud de Cuenta.\n");
            return 1;
        }
        if (!NombreDestino())
        {
            printf("Error en la validación del nombre del destinatario.\n");
            return 1;
        }
        break;
    default:
        printf("Opción no implementada.\n");
        break;
    }

    return 0;
}
