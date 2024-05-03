#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Variables globales para almacenar los datos de cuenta
extern char cuentaOrigenTicket[17];
extern char cuentaDestinoTicket[17];

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
        sscanf(buffer, "%16s", cuentaOrigenTicket);
        if (buffer[strlen(cuentaOrigenTicket)] != '\n')
        {
            // Limpia el buffer si el usuario ingresa más de 16 dígitos
            while (getchar() != '\n')
                ;
        }
        valido = (strlen(cuentaOrigenTicket) == 16) && esSoloNumerosCuenta(cuentaOrigenTicket);
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
        sscanf(buffer, "%16s", cuentaDestinoTicket);
        if (buffer[strlen(cuentaDestinoTicket)] != '\n')
        {
            // Limpia el buffer si el usuario ingresa más de 16 dígitos
            while (getchar() != '\n')
                ;
        }
        valido = (strlen(cuentaDestinoTicket) == 16) && esSoloNumerosCuenta(cuentaDestinoTicket);
        if (!valido)
        {
            printf("Número de cuenta inválido, debe ser de 16 dígitos numéricos.\n");
        }
    } while (!valido);
}
