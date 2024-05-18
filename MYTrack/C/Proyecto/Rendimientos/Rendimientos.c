#include "Rendimientos.h"

double CalcularRendimiento(double SaldoInicial, int meses) {
  double TasaInteres = 3.5 / 12 / 100; // Tasa de interés mensual
  double Saldo = SaldoInicial;
  for (int i = 0; i < meses; i++) {
    Saldo += Saldo * TasaInteres;
  }
  return Saldo;
}
