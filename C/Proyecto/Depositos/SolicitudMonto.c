#include <stdio.h>
#include <string.h>

const int MoneyError = 0;
int puntoDecimalContado = 0;

int esSoloNumeros(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '.' && puntoDecimalContado == 0)
        {
            puntoDecimalContado = 1;
        }
        else if (!isdigt(str[i]))
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
        resultado = sscanf(buffer, "%lf", &monto);
        if (resultado == 1 && esSoloNumeros(buffer))
        {
            break;
        }
        else
        {
            printf("Error: entrada invalida.");
        }
    } while (1);

    return monto;
}