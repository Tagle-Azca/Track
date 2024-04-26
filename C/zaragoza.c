#include <stdio.h>

void mostrarConsonantes(const char *cadena)
{
    while (*cadena)
    {

        if (*cadena != 'A' && *cadena != 'E' && *cadena != 'I' && *cadena != 'O' && *cadena != 'U' && *cadena >= 'A' && *cadena <= 'Z')
        {
            printf("%c", *cadena);
        }
        cadena++;
    }
}

int main()
{
    const char *abecedario = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    mostrarConsonantes(abecedario);
    return 0;
}
