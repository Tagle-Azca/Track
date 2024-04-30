#include <stdio.h>
#include "Depositos/SolicitudCuenta.h"
#include "Depositos/NombreDestino.h"
#include "Depositos/BancoDestino.h"

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
    char input[50];

    printf("Por favor, selecciona la opción que deseas realizar:\n");
    printf("0 - Depositar\n1 - Retiro de Efectivo\n2 - Estado de Cuenta\n3 - Movimientos Recientes\n4 - Inversión\n5 - Cambio de NIP\n");

    if (fgets(input, sizeof(input), stdin) && sscanf(input, "%d", &choice) == 1)
    {
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
            if (!NomDestino())
            {
                printf("Error en la validación del nombre del destinatario.\n");
                return 1;
            }
            if (BaDestino() == 0)
            {
                printf("Error en la validación del banco destino.\n");
                return 1;
            }
            break;

        default:
            printf("Opción no implementada.\n");
            break;
        }
    }
    else
    {
        printf("Entrada inválida.\n");
        return 1;
    }

    return 0;
}
