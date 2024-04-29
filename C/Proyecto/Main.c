#include <stdio.h>
#include "Transacciones.h"

enum Transaccion
{
    DepositarOPC,
    RestiroEfectivo,
    EstadeCuenta,
    MovimientosRecientes,
    Inversion,
    cambioNIP
};

int Tarjeta;
char Nombre[100];
char Banco[50];

int main()
{
    int choice;
    printf("por favor seleccionar la opcion que deseas realizar: ");
    scanf("%d", &choice);

    if (choice < 0 || choice > 5)
    {
        printf("NO es una opcion valida.\n");
        return 1;
    }

    enum Transaccion Selecion = (enum Transaccion)choice;

    switch (Selecion)
    {
    case DepositarOPC:
        solicitarCuentaOrigen();
        solicitarCuentaDestino();
        solicitarNombreDestino();
        solicitarBancoDestino();
        solicitarMonto();
        confirmarTransferencia();
        mostrarResultado();
        break;

    default:
        break;
    }
}