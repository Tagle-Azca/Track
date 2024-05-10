#include <stdio.h>
#include <stdlib.h>
#include "Depositos/DepositosFunciones.h" // Asegúrate de que la ruta sea correcta

enum Transaccion
{
    DepositarOPC,
    EstadoDeCuenta,
    MovimientosRecientes,
    Inversion,
    Cancelar
};

const int VALID_INPUT = 1;
const int ErrorMain = 0;

char CuentaOrigenTicket[17];
char CuentaDestinoTicket[17];
char NombreBancoTicket[50];
char NombreDestinoTicket[50];
double monto = 0.0; // Asegúrate de inicializar el monto según tus necesidades

int main()
{
    int choice;
    char input[50];

    printf("Por favor, selecciona la opción que deseas realizar:\n");
    printf("0 - Depositar\n1 - Estado de Cuenta\n2 - Movimientos Recientes\n3 - Inversión\n4 - Cancelar \n");

    if (fgets(input, sizeof(input), stdin) && sscanf(input, "%d", &choice) == VALID_INPUT)
    {
        if (choice < DepositarOPC || choice > Cancelar)
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
