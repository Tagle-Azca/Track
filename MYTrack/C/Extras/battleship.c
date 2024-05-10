#include <stdio.h>
#include <stdlib.h>

void TableroIa(int tabIa[9][9]) // definimos la matriz IA
{
  int lin, col;
  for (lin = 0; lin < 9; lin++)
    for (col = 0; col < 9; col++)
      tabIa[lin][col] = -1; // primero declaramos toda la matriz de un mismo valor
}

void Tableroj1(int tabj1[9][9]) // repetimos para la matriz del j1
{
  int lin, col;
  for (lin = 0; lin < 9; lin++)
    for (col = 0; col < 9; col++)
      tabj1[lin][col] = -1;
}

void Tableroj2(int tabj2[9][9]) // repetimos para la matriz del j1
{
  int lin, col;
  for (lin = 0; lin < 9; lin++)
    for (col = 0; col < 9; col++)
      tabj2[lin][col] = -1;
}

//#####################################################//

void mostrar(
    int tabIa[9][9]) // imprimos la matriz con los valores que elijamos por caso
{

  int lin, col;

  printf("\t1 \t2 \t3 \t4 \t5 \t6 \t7 \t8 \t9"); // imprimos el indice de
                                                 // numeros
  printf("\n");

  for (lin = 0; lin < 9; lin++) {
     printf("%d",lin+1); // imprimos el indice de letras con uso del ascii
    for (col = 0; col < 9; col++) {
      if (tabIa[lin][col] == -1) {
        printf("\t0");
      } else if (tabIa[lin][col] == 0) {
        printf("\t-");
      } else if (tabIa[lin][col] == 1) { // elejimos el valor dependiendo el
                                         // caso
        printf("\tH");
      }
    }
    printf("\n");
  }
}

void mostrarj1(int tabj1[9][9]) // repetimos para la matriz del j1
{

  int lin, col;

  printf("\t1 \t2 \t3 \t4 \t5 \t6 \t7 \t8 \t9");
  printf("\n");

  for (lin = 0; lin < 9; lin++) {
    printf("%d",lin+1);
    for (col = 0; col < 9; col++) {
      if (tabj1[lin][col] == -1) {
        printf("\t0");
      } else if (tabj1[lin][col] == 0) {
        printf("\t-");
      } else if (tabj1[lin][col] == 1) {
        printf("\tH");
      }
    }
    printf("\n");
  }
}

void mostrarj2(int tabj2[][9]) // repetimos para la matriz del j1
{

  int lin, col;

  printf("\t1 \t2 \t3 \t4 \t5 \t6 \t7 \t8 \t9");
  printf("\n");

  for (lin = 0; lin < 9; lin++) {
    printf("%d",lin+1);
    for (col = 0; col < 9; col++) {
      if (tabj2[lin][col] == -1) {
        printf("\t0");
      } else if (tabj2[lin][col] == 0) {
        printf("\t-");
      } else if (tabj2[lin][col] == 1) {
        printf("\tH");
      }
    }
    printf("\n");
  }
}

//#####################################################//

void navio(int naves[9][9]) 
{
        srand(time(NULL));
        int x,y,i;

        while(i < 3)
        {
            x=rand()%9; //Horizontal
            y= rand()%9;

          if (y>=7){
            continue;
          }
          else if(naves[x][y]==1||naves[x][y+1]==1||naves[x][y+2]==1)
          {
            continue;
          }
          else
          {
            naves[x][y]=1;
            naves[x][y+1]=1;
            naves[x][y+2]=1;
            i++;
          }
          }
}

void navioj1(int navesj1[9][9]) // usamos una funcion similar para pedir al
                               // usuario donde genera sus naves
{
  srand(time(NULL));
        int x,y,i;

        while(i < 3)
        {
          printf("Elije La posicion X:\n");
          scanf("%d", &x);
          printf("Elije La posicion Y:\n");
          scanf("%d", &y);
          if (y>=7){
            continue;
          }
          else if(navesj1[x][y]==1||navesj1[x][y+1]==1||navesj1[x][y+2]==1)
          {
            continue;
          }
          else
          {
            navesj1[x][y]=1;
            navesj1[x][y+1]=1;
            navesj1[x][y+2]=1;
            i++;
          }
          }

}

void navioj2(int navesj2[9][9]) // repetimos la funcion para el jugador 2
  {
  srand(time(NULL));
        int x,y,i;

        while(i < 3)
        {
          printf("Elije La posicion X:\n");
          scanf("%d", &x);
          printf("Elije La posicion Y:\n");
          scanf("%d", &y);
          if (y>=7){
            continue;
          }
          else if(navesj2[x][y]==1||navesj2[x][y+1]==1||navesj2[x][y+2]==1)
          {
            continue;
          }
          else
          {
            navesj2[x][y]=1;
            navesj2[x][y+1]=1;
            navesj2[x][y+2]=1;
            i++;
          }
          }
}

//#####################################################//

void tiro(int disp[2]) // empezamos a pedir las coordenadas del disparo al usuario.
{

  printf("linea: ");
  scanf("%d", &disp[0]);
  disp[0]--;

  printf("columna: ");
  scanf("%d", &disp[1]);
  disp[1]--;
}

void tiroIa(int disp[2]) // empezamos a pedir las coordenadas del disparo al usuario.
{

  disp[0] = rand() % 9;
  disp[0]--;

  disp[1] = rand() % 9;
  disp[1]--;
}

//#####################################################//

int herida(int disp[2], int naves[9][9]) // validamos cuando una nave fue impactada para eliminarla
{
    int barco,i,x,y;
      x=disp[0];
  y=disp[1];
  printf("%d %d",x,y);
  if(naves[x][y]==1)
            {
                printf("Le diste al barco en las cordenadas (%d,%d)\n",disp[0]+1,disp[1]+1);
                return 1;
            }


        
        return 0;
    }

int heridaj1(int disp[2], int navesj1[9][9]) // repetimos la funcion para el j1
{
    int barco,i,x,y;
      x=disp[0];
  y=disp[1];
  printf("%d %d",x,y);
  if(navesj1[x][y]==1)
            {
                printf("Le diste al barco en las cordenadas (%d,%d)\n",disp[0]+1,disp[1]+1);
                return 1;
            }


        
        return 0;
    }

int heridaj2(int disp[2], int navesj2[9][9]) // repetimos la funcion para el j2
{
    int barco,i,x,y;
      x=disp[0];
  y=disp[1];
  printf("%d %d",x,y);
  if(navesj2[x][y]==1)
            {
                printf("Le diste al barco en las cordenadas (%d,%d)\n",disp[0]+1,disp[1]+1);
                return 1;
            }


        
        return 0;
    }

//#####################################################//

void flota(int disp[2], int naves[9][9], int bala) // comenzamos a contar el numero de barcos restantes, las
                     // rondas y las balas usadas
{
  int lin = 0, col = 0, sov;

  for (sov = 0; sov < 3; sov++) {
    if (naves[sov][0] == disp[0])
      lin++;
    if (naves[sov][1] == disp[1])
      col++;
  }

  printf("\nRonda %d: \nlin %d -> %d naves\ncol %d -> %d naves\n", bala,
         disp[0] + 1, lin, disp[1] + 1, col);
}

void flotaj1(int disp[2], int navesj1[9][9], int bala) // repetimos para el j1
{
  int lin = 0, col = 0, sov;

  for (sov = 0; sov < 3; sov++) {
    if (navesj1[sov][0] == disp[0])
      lin++;
    if (navesj1[sov][1] == disp[1])
      col++;
  }

  printf("\nRonda %d: \nlin %d -> %d naves\ncol %d -> %d naves\n", bala,
         disp[0] + 1, lin, disp[1] + 1, col);
}

void flotaj2(int disp[2], int navesj2[9][9], int bala) // repetimos para el j2
{
  int lin = 0, col = 0, sov;

  for (sov = 0; sov < 3; sov++) {
    if (navesj2[sov][0] == disp[0])
      lin++;
    if (navesj2[sov][1] == disp[1])
      col++;
  }

  printf("\nRonda %d: \nlin %d -> %d naves\ncol %d -> %d naves\n", bala,
          disp[0] + 1, lin, disp[1] + 1, col);
}
//#####################################################//

void mostrar2(int disp[2], int naves[9][9],int tabIa[9][9]) // mostramos el tablero ya con todas las balas y bajas
{
  if (herida(disp, naves)) // validamos los impactos con las balas
    tabIa[disp[0]][disp[1]] = 1;
  else
    tabIa[disp[0]][disp[1]] = 0;
}

void mostrar2j1(int disp[2], int navesj1[9][9], int tabj1[9][9]) // repetimos para el j1
{
  if (heridaj1(disp, navesj1))
    tabj1[disp[0]][disp[1]] = 1;
  else
    tabj1[disp[0]][disp[1]] = 0;
}

void mostrar2j2(int disp[2], int navesj2[9][9],int tabj2[9][9]) // repetimos para el j2
{
  if (heridaj2(disp, navesj2))
    tabj2[disp[0]][disp[1]] = 1;
  else
    tabj2[disp[0]][disp[1]] = 0;
}

//#####################################################//

int menu() // Creamos el menu de todas nuestras opciones
{

  printf("Bienvinido a batalla naval\n");
  printf("Elige la opcion que te funcione:\n");
  printf("1. Jugador VS IA\n");
  printf("2. Jugador 1 VS Jugador 2\n");
  printf("3. salir del juego\n");

  int opcion = 0;
  fflush(stdout);
  scanf("%d", &opcion);
  switch (opcion) // usamos un switch para ir a la funcion deseada
  {
  case 1:
    solo(); // funcion para jugar contra la Ia
    return 1;
  case 2:
    amigos(); // funcion para jugar contra otro humano
    return 2;
  case 3:
    despedida(); // pata terminar el programa
    return 3;
  }
  return 0;
}

//#####################################################//

int solo() // funcion para jugar solo
{
  printf("IA atacando\n");
  int tabIa[9][9]; // definimos la matriz de la nave
  int naves[9][9]; // definimos la matriz del numero de naves
  int disp[2];     // definimos los disparos que habra
  int balas = 0;
  int hoyos = 0;

  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++)
      {
        naves[i][j] = 0;
        printf("%d",naves[i][j]);
      }
    printf("\n");
  }
  TableroIa(tabIa); // llamamos a las funciones necesarias
  navio(naves);

  printf("Jugador 1;\n");
  int balasj1 = 0;
  int hoyosj1 = 0;
  int tabj1[9][9];
  int navesj1[9][9];
  int turno;
  

  Tableroj1(tabj1);
  navioj1(navesj1);

  printf("\n");
  printf("Elije el turno:");
  scanf("%d", &turno);
  do {
    if (turno == 1) {
      do {
        if (turno == 1) {
          printf("Jugador 1\n");
          mostrar(tabIa);
          tiro(disp);
          printf("Elije el turno:");
          scanf("%d", &turno);
          balas++;

          if (herida(disp, naves)) {
            flota(disp, naves, balas);
            hoyos++;
          } else
            flota(disp, naves, balas);

          mostrar2(disp, naves, tabIa);
        }

      } while (hoyos != 9 && turno == 1);

    }

    else if (turno == 2) {
      do {
        if (turno == 2) {
          printf("IA atacando\n");
          mostrarj1(tabj1);
          tiroIa(disp);
          balasj1++;
          printf("Elije el turno:");
          scanf("%d", &turno);

          if (heridaj1(disp, navesj1)) {
            flotaj1(disp, navesj1, balasj1);
            hoyosj1++;
          } else
            flotaj1(disp, navesj1, balasj1);

          mostrar2j1(disp, navesj1, tabj1);
        }
      } while (hoyosj1 != 9 && turno == 2);
    }
  } while (hoyosj1 != 9 && hoyos != 9);

  printf("\n\n\nTerminaste. Tiraste las 3 naves con: %d balas\n");
  printf("Jugador 1:\n");
  mostrarj1(tabj1);
  printf("IA:\n");
  mostrarj2(tabIa);
  menu();
}

//#####################################################//

int amigos() {
  printf("Jugador 1:\n");

  int disp[2];
  int balasj1 = 0;
  int hoyosj1 = 0;
  int tabj1[9][9];
  int navesj1[9][9];
  int turno;


  Tableroj1(tabj1);
  navioj1(navesj1);

  printf("\n");

  printf("Jugador 2:\n");

  int balasj2 = 0;
  int hoyosj2 = 0;
  int tabj2[9][9];
  int navesj2[9][9];
  
  /*for(int i=0;i<9;i++){
    for(int j=0;j<9;j++)
      {
        navesj2[i][j] = 0;
        printf("%d",navesj2[i][j]);
      }
    printf("\n");
  }*/

  Tableroj2(tabj2);
  navioj1(navesj2);

  printf("\n");
  printf("Elije el turno:");
  scanf("%d", &turno);

  do {
    if (turno == 1) {
      do {
        if (turno == 1) {
          printf("Jugador 1\n");
          mostrarj2(tabj2);
          tiro(disp);
          printf("Elije el turno:");
          scanf("%d", &turno);
          balasj2++;

          if (heridaj2(disp, navesj2)) {
            flotaj2(disp, navesj2, balasj2);
            hoyosj2++;
          } else
            flotaj2(disp, navesj2, balasj2);

          mostrar2j2(disp, navesj2, tabj2);
        }

      } while (hoyosj2 != 9 && turno == 1);

    }

    else if (turno == 2) {
      do {
        if (turno == 2) {
          printf("Jugador 2\n");
          mostrarj1(tabj1);
          tiro(disp);
          balasj1++;
          printf("Elije el turno:");
          scanf("%d", &turno);

          if (heridaj1(disp, navesj1)) {
            flotaj1(disp, navesj1, balasj1);
            hoyosj1++;
          } else
            flotaj1(disp, navesj1, balasj1);

          mostrar2j1(disp, navesj1, tabj1);
        }
      } while (hoyosj1 != 9 && turno == 2);
    }
  } while (hoyosj1 != 9 && hoyosj2 != 9);

  printf("\n\n\nTerminaste. Tiraste las 3 naves con: %d balas\n");
  printf("Jugador 1:\n");
  mostrarj1(tabj1);
  printf("Jugador 2:\n");
  mostrarj2(tabj2);
  menu();
}
//#####################################################//

int despedida() {
  printf("bye vuelve pronto"); // llammos la funciion de menu que contiene a todas las
                      // funciones
}

//#####################################################//

int main() { menu(); }
