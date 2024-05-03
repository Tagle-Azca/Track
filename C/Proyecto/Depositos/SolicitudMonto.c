#include <stdio.h>
#include <string.h>

// Variable global para almacenar el monto del depósito
extern double montoTicket;

int esSoloNumerosMonto(const char *str)
{
    int puntoDecimalContado = 0; // Hacerlo local para resetear cada vez que se llama a la función

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '.')
        {
            if (puntoDecimalContado == 1) // Ya se encontró un punto decimal antes
            {
                return 0;
            }
            puntoDecimalContado = 1;

            // Comprobar si hay al menos un dígito después del punto decimal
            if (!isdigit(str[i + 1]))
            {
                return 0;
            }
        }
        else if (!isdigit(str[i]))
        {
            return 0;
        }
    }
    return 1;
}

void SolicitudMonto()
{
    char buffer[100];
    double monto = 0.0;
    int resultado;

    do
    {
        printf("Ingrese monto a depostitar: ");
        if (!fgets(buffer, sizeof(buffer), stdin))
        {
            continue;
        }
        // Eliminar posible nueva línea al final del buffer, antes de la validación
        buffer[strcspn(buffer, "\n")] = 0;

        resultado = sscanf(buffer, "%lf", &monto);
        if (resultado == 1 && esSoloNumerosMonto(buffer))
        {
            // Asignar el monto del depósito a la variable global
            montoTicket = monto;
            break;
        }
        else
        {
            printf("Error: entrada invalida.\n");
        }
    } while (1);
}
