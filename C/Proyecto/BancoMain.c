#include <stdio.h>
#include <stdlib.h>
#include "Depositos/DepositosFunciones.h" // Asegúrate de que la ruta sea correcta

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

char cuentaOrigenTicket[17];
char cuentaDestinoTicket[17];
char nombreBancoTicket[50];
char NombreDestinoTicket[50];
double monto = 0.0; // Asegúrate de inicializar el monto según tus necesidades

int main()
{
    int choice;
    char input[50];

    printf("Por favor, selecciona la opción que deseas realizar:\n");
    printf("0 - Depositar\n1 - Retiro de Efectivo\n2 - Estado de Cuenta\n3 - Movimientos Recientes\n4 - Inversión\n5 - Cambio de NIP\n");

    if (fgets(input, sizeof(input), stdin) && sscanf(input, "%d", &choice) == VALID_INPUT)
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
            if (!RealizarDeposito())
            {
                printf("Fallo en realizar depósito.\n");
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
