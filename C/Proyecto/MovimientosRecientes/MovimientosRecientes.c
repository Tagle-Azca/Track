#include <stdio.h>
#include <stdlib.h>

// Estructura para almacenar los detalles de cada depósito
typedef struct
{
    char cuentaDestino[100];
    char bancoDestino[100];
    char nombreDestino[100];
    double monto;
} Deposito;

// Lista de depósitos (simplificada para este ejemplo)
#define MAX_DEPOSITOS 100
Deposito depositos[MAX_DEPOSITOS];
int numDepositos = 0;

// Función para agregar un depósito a la lista
void agregarDeposito(Deposito d)
{
    if (numDepositos < MAX_DEPOSITOS)
    {
        depositos[numDepositos++] = d;
    }
    else
    {
        printf("Alcanzado el máximo de depósitos.\n");
    }
}