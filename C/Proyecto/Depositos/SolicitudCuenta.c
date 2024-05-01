#include <stdio.h>
#include <string.h>
#include <ctype.h>

int esSoloNumeros(const char *str)
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

int Depositar()
{
    char buffer[100];
    char cuentaOrigen[17];
    char cuentaDestino[17];
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
        sscanf(buffer, "%16s", cuentaOrigen);
        if (buffer[strlen(cuentaOrigen)] != '\n')
        {
            // Limpia el buffer si el usuario ingresa más de 16 dígitos
            while (getchar() != '\n')
                ;
        }
        valido = (strlen(cuentaOrigen) == 16) && esSoloNumeros(cuentaOrigen);
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
        sscanf(buffer, "%16s", cuentaDestino);
        if (buffer[strlen(cuentaDestino)] != '\n')
        {
            // Limpia el buffer si el usuario ingresa más de 16 dígitos
            while (getchar() != '\n')
                ;
        }
        valido = (strlen(cuentaDestino) == 16) && esSoloNumeros(cuentaDestino);
        if (!valido)
        {
            printf("Número de cuenta inválido, debe ser de 16 dígitos numéricos.\n");
        }
    } while (!valido);

    return 1;
}
