#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Variables globales para almacenar los datos de cuenta
extern char CuentaOrigenTicket[17];
extern char CuentaDestinoTicket[17];

int esSoloNumerosCuenta(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!isdigit(str[i]))
        {
            return 0;
        }
    }
    return 1;
}

void SolicitudCuenta()
{
    char buffer[100];
    int valido;

    // Solicitar cuenta de origen
    do
    {
        printf("Ingrese el número de cuenta de origen (16 dígitos): ");
        if (!fgets(buffer, sizeof(buffer), stdin))
        {
            // Manejar posible error de lectura
            continue;
        }
        sscanf(buffer, "%16s", CuentaOrigenTicket);
        if (buffer[strlen(CuentaOrigenTicket)] != '\n')
        {
            // Limpia el buffer si el usuario ingresa más de 16 dígitos
            while (getchar() != '\n')
                ;
        }
        valido = (strlen(CuentaOrigenTicket) == 16) && esSoloNumerosCuenta(CuentaOrigenTicket);
        if (!valido)
        {
            printf("Número de cuenta inválido, debe ser de 16 dígitos numéricos.\n");
        }
    } while (!valido);

    // Solicitar cuenta destino
    do
    {
        printf("Ingrese el número de cuenta de destino (16 dígitos): ");
        if (!fgets(buffer, sizeof(buffer), stdin))
        {
            // Manejar posible error de lectura
            continue;
        }
        sscanf(buffer, "%16s", CuentaDestinoTicket);
        if (buffer[strlen(CuentaDestinoTicket)] != '\n')
        {
            // Limpia el buffer si el usuario ingresa más de 16 dígitos
            while (getchar() != '\n')
                ;
        }
        valido = (strlen(CuentaDestinoTicket) == 16) && esSoloNumerosCuenta(CuentaDestinoTicket);
        if (!valido)
        {
            printf("Número de cuenta inválido, debe ser de 16 dígitos numéricos.\n");
        }
    } while (!valido);
}
