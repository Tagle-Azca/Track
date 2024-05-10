#include <stdio.h>
#include <string.h>
#include <ctype.h>

extern char NombreDestinoTicket[50];

int NombreDestino()
{
    char nombre[100];
    ; // Descarta caracteres hasta el final de la línea o EOF

    printf("Ingrese el nombre del destinatario: ");
    fgets(nombre, sizeof(nombre), stdin);
    nombre[strcspn(nombre, "\n")] = 0; // Elimina el salto de línea

    int longitud = strlen(nombre);
    if (longitud < 2 || longitud > 30)
    { // Asegúrate de que la longitud mínima sea mayor que 0
        return 0;
    }
    for (int i = 0; i < longitud; i++)
    {
        if (!isalpha(nombre[i]) && nombre[i] != ' ' && nombre[i] != '-')
        {
            return 0;
        }
    }

    strcpy(NombreDestinoTicket, nombre);

    return 1; // Devuelve 1 si el nombre es válido
}