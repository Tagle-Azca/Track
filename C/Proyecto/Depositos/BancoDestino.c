#include <stdio.h>
#include <string.h>

// Variable global para almacenar el nombre del banco destino
extern char nombreBancoTicket[50];

const int Valid_bank = 1;
const int Error = 0;

const char *bancos[] = {"BBVA", "Banamex", "Santander", "HSBC", "Banorte", "Scotiabank", "Inbursa", "Banco Azteca", "Banregio", "NU"};
int numBancos = sizeof(bancos) / sizeof(bancos[0]);

int BaDestino()
{
    char input[100];
    int bancoValido = 0; // Variable para indicar si se ha seleccionado un banco válido

    printf("Ingresar el banco del destino\n");
    printf("Bancos disponibles:\n");
    for (int i = 0; i < numBancos; i++)
    {
        printf("- %s\n", bancos[i]);
    }

    while (!bancoValido) // Continuar preguntando hasta que se seleccione un banco válido
    {
        printf("Ingrese el nombre del banco destino: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0'; // Eliminar el salto de línea al final del input

        for (int i = 0; i < numBancos; i++)
        {
            if (strcmp(bancos[i], input) == 0)
            {
                // Asignar el nombre del banco destino a la variable global
                strcpy(nombreBancoTicket, input);
                bancoValido = 1; // Establecer que se ha seleccionado un banco válido
                break;           // Salir del bucle for
            }
        }

        if (!bancoValido) // Si el banco no es válido, mostrar mensaje de error
        {
            printf("Banco no reconocido. Por favor, intente de nuevo.\n");
        }
    }

    return Valid_bank; // Indicar que se ha seleccionado un banco válido
}
