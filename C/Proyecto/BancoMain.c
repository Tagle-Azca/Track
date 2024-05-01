#include <stdio.h>
#include "Depositos/SolicitudCuenta.h"
#include "Depositos/NombreDestino.h"
#include "Depositos/BancoDestino.h"
#include <stdlib.h>

enum Transaccion
{
    DepositarOPC,
    RetiroEfectivo,
    EstadoDeCuenta,
    MovimientosRecientes,
    Inversion,
    CambioNIP
};

const int VALID_INPUT = 1;
const int ErrorMain = 0;

int main()
{
    int choice;
    char input[50];

    printf("Por favor, selecciona la opción que deseas realizar:\n");
    printf("0 - Depositar\n1 - Retiro de Efectivo\n2 - Estado de Cuenta\n3 - Movimientos Recientes\n4 - Inversión\n5 - Cambio de NIP\n");

    int user_input = fgets(input, sizeof(input), stdin) && sscanf(input, "%d", &choice);

    if (user_input == VALID_INPUT)
    {
        if (choice < DepositarOPC || choice > CambioNIP)
        {
            printf("No es una opción válida.\n");
            return VALID_INPUT;
        }
        system("clear");

        switch (choice)
        {
        case DepositarOPC:
            if (!Depositar())
            {
                printf("Error en la solicitud de Cuenta.\n");
                return VALID_INPUT;
            }
            if (!NomDestino())
            {
                printf("Error en la validación del nombre del destinatario.\n");
                return VALID_INPUT;
            }
            if (!BaDestino())
            {
                printf("Error en la validación del banco destino.\n");
                return VALID_INPUT;
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
        return VALID_INPUT;
    }

    return ErrorMain;
}
