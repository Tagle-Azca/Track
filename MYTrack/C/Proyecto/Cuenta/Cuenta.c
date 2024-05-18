// Cuenta.c
#include "Cuenta.h"
#include <stdio.h>
#include <string.h>


void InicializarCuenta(Cuenta *Cuenta) {
  // ID de la cuenta
  strcpy(Cuenta->CuentaID, "739678");

  // Estructura de la tarjeta principal
  // Banco Santander
  strcpy(Cuenta->TarjetaPrincipal.ID, "5579 0990 1212 0506");
  Cuenta->TarjetaPrincipal.Saldo = 165689.09;
  strcpy(Cuenta->TarjetaPrincipal.FVencimiento, "03/27");
  strcpy(Cuenta->TarjetaPrincipal.cvv, "056");

  // Estructura  de la tarjeta secundaria
  strcpy(Cuenta->TarjetaSecundaria.ID, "5579 0990 2121 0605");
  Cuenta->TarjetaSecundaria.Saldo = 00.00;
  strcpy(Cuenta->TarjetaSecundaria.FVencimiento, "05/30");
  strcpy(Cuenta->TarjetaSecundaria.cvv, "192");
}

