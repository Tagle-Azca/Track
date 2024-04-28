#include <stdio.h>

void airplain(char);
void cliente(int, char);

enum OpcionMenu
{
    Vuelos,
    Comprar,
    Status,
    Salir
};

int main()
{
    printf("Menu de opciones");
    int Choice;
    printf("Escoja su opcion deseada (0: Vuelos cercanos, 1: Comprar Vuelos, 2: Status de su vuelo, 3: Salir del programa)");
    scanf("%d", &Choice);

    if (Choice < 0 || Choice > 3)
    {
        printf("Opcion invalida, por favor de intentarnuevamente\n");
        return 1;
    }

    enum OpcionMenu Desicion = (enum OpcionMenu)Choice;

    switch (Desicion)
    {
    case Vuelos:
        printf("por favor seleccione la opcion deseada");
        break;

    default:
        break;
    }

    return 0;
}

/*
 la opcion 1 me mostrara vuelos cercanos para comprar, tendra que tener opcion direacta a la opcion comprar

la opcion 2 me tenra que dar la opcion de poder escoger ciudad de salida y de destino, asi como poder elegir maletas y poder
asientos.
asi como la opcion de pagos

la opcion 3 me deberia de dar el status del vuelo que ya compre y la opcion de poder modificarlo

4 salgo del codigo
*/