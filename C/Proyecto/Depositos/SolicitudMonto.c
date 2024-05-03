#include <stdio.h>
#include <ctype.h>
#include <string.h>

extern double montoTicket;
double montoTicket; // Definición de la variable global

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

double SolicitudMonto()
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
            montoTicket = monto;
            break;
        }
        else
        {
            printf("Error: entrada invalida.\n");
        }
    } while (1);

    return monto;
}
