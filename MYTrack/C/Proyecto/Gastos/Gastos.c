// Gastos.c
#include "Gastos.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIAS_DEL_MES 30
#define NUMERO_DE_TARJETAS 2

double gastos[NUMERO_DE_TARJETAS][DIAS_DEL_MES];

void inicializarGastos() {
    srand(time(NULL));
    for (int i = 0; i < NUMERO_DE_TARJETAS; i++) {
        for (int j = 0; j < DIAS_DEL_MES; j++) {
            gastos[i][j] = (double)(rand() % 1000);
        }
    }
}

void mostrarReporteDeGastos() {
    printf("Reporte de Gastos Mensuales:\n");
    for (int i = 0; i < NUMERO_DE_TARJETAS; i++) {
        double totalMensual = 0;
        printf("Tarjeta %d:\n", i + 1);
        for (int j = 0; j < DIAS_DEL_MES; j++) {
            printf("Dia %02d: $%.2f\n", j + 1, gastos[i][j]);
            totalMensual += gastos[i][j];
        }
        printf("Total mensual para Tarjeta %d: $%.2f\n\n", i + 1, totalMensual);
    }
}
