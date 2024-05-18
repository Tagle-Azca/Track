//Cuenta.h
#ifndef CUENTA_H
#define CUENTA_H


typedef struct{
  char ID[21];
  double Saldo;
  char FVencimiento[6];
  char cvv[4];
} Tarjeta;

typedef struct{
  char CuentaID[21];
  Tarjeta TarjetaPrincipal;
  Tarjeta TarjetaSecundaria;
  
} Cuenta;

void InicializarCuenta(Cuenta *Cuenta);

#endif