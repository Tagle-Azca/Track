#include "Transacciones.h"
#include <stdio.h>

char nombreDestino[100];
char bancoDestino[30];

// Función para solicitar el número de cuenta de origen
void solicitarCuentaOrigen()
{
    printf("Ingrese el número de cuenta de origen:\n");
}

// Función para solicitar el número de cuenta de destino
void solicitarCuentaDestino()
{
    printf("Ingrese el número de cuenta de destino:\n");
}

// Función para pedir el nombre del destino
void solicitarNombreDestino()
{
    printf("Ingrese el nombre del titular de la cuenta de destino:\n");
}

// Función para pedir el banco de destino
void solicitarBancoDestino()
{
    printf("Ingrese el banco de destino:\n");
}

// Función para solicitar el monto a transferir
void solicitarMonto()
{
    printf("Ingrese el monto a transferir:\n");
}

// Función para confirmar la transferencia
void confirmarTransferencia()
{
    printf("¿Desea confirmar la transferencia? (s/n):\n");
}

// Función para mostrar el resultado de la transferencia
void mostrarResultado()
{
    printf("La transferencia ha sido realizada con éxito.\n");
}
