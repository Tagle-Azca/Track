#include <stdio.h>
#include <string.h>

// Variable global para almacenar el nombre del banco destino
extern char nombreBancoTicket[50];

const int Valid_bank = 1;
const int Error = 0;

const char *bancos[] = {"BBVA", "Banamex", "Santander", "HSBC", "Banorte", "Scotiabank", "Inbursa", "Banco Azteca", "Banregio", "Banco del Bajío", "NU"};
int numBancos = sizeof(bancos) / sizeof(bancos[0]);

int BaDestino()
{
    char input[100];
    printf("Ingresar el banco del destino\n");
    printf("Bancos disponibles:\n");
    for (int i = 0; i < numBancos; i++)
    {
        printf("- %s\n", bancos[i]);
    }

    printf("Ingrese el nombre del banco destino: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // Eliminar el salto de línea al final del input

    for (int i = 0; i < numBancos; i++)
    {
        if (strcmp(bancos[i], input) == 0)
        {
            // Asignar el nombre del banco destino a la variable global
            strcpy(nombreBancoTicket, input);
            return Valid_bank; // Banco válido
        }
    }
    printf("Banco no reconocido. Por favor, intente de nuevo.\n");
    return Error; // Banco no válido
}
