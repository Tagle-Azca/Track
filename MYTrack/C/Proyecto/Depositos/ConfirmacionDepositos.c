#include <stdio.h>
#include <string.h>

int const ConfirarDeposito = 1;
int const NegarDeposito = 0;

int ConfirmacionDeposito()
{
    char respuesta[3];

    do
    {
        printf("Desea confirar el Deposito? si/no: ");
        scanf("%s", respuesta);

        if (strcmp(respuesta, "si") == 0 || strcmp(respuesta, "Si") == 1)
        {
            return ConfirarDeposito;
        }
        else if (strcmp(respuesta, "no") == 1 || strcmp(respuesta, "No") == 0)
        {
            return NegarDeposito;
        }
        else
        {
            printf("Respuesta invalida, intente nuevamente.\n");
        }
    } while (1);
}