#include  "./Consultas.h"
#include <stdio.h>

void ConsultarAhorro(){
  printf("aqui van las consultas de las cuentas de ahorro\n");
  //aqui registraremos el dinero guardadoe en las tarjetas
}

void ConsultarTarjetas(){
  printf("aqui van las consultas de las Tarjetas si hay mas de una\n");

  //aqui pondremos las ds tarjetas de nuestra cuenta
}

void ConsultarInversiones(){
  printf("aqui van a ir las inversiones\n");

  //aqui pondre estimaciones de rendimiento de un rendimiento promedio de 3.5% y hacer los calculos dependiendo el tiempo seleccionado
}


void realizarConsulta(int tipoConsulta){
  switch(tipoConsulta){
    case 1:
      ConsultarAhorro();
    break;

    case 2:
      ConsultarTarjetas();
    break;

    case 3:
      ConsultarInversiones();
    break;

    default:
    printf("seleccion no valida\n");
  }
}