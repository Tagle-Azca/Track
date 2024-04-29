#include <stdio.h>
#include <string.h>

int Depositar()
{
    char cuentaOrigen[17];  // Almacenar cuenta de origen
    char cuentaDestino[17]; // Almacenar cuenta destino
    int valido;

    // Solicitar cuenta de origen
    do
    {
        printf("Ingrese el número de cuenta de origen (16 dígitos): ");
        scanf("%16s", cuentaOrigen);
        valido = strlen(cuentaOrigen) == 16; // Validar longitud
        if (!valido)
        {
            printf("Número de cuenta inválido, debe ser de 16 dígitos numéricos.\n");
        }
    } while (!valido);

    // Solicitar cuenta destino
    do
    {
        printf("Ingrese el número de cuenta de destino (16 dígitos): ");
        scanf("%16s", cuentaDestino);
        valido = strlen(cuentaDestino) == 16; // Validar longitud
        if (!valido)
        {
            printf("Número de cuenta inválido, debe ser de 16 dígitos numéricos.\n");
        }
    } while (!valido);

    return 1; // Devolver 1 si todo es válido
}
