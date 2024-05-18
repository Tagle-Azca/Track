// Transferencias.h
#ifndef TRANSFERENCIAS_H
#define TRANSFERENCIAS_H
#include  "../Cuenta/Cuenta.h"

void TranferirEntreTarjetas(Tarjeta *origen, Tarjeta *Destino, double Monto);

void TransferirBancoExterno(Tarjeta *origen, const char *nombreDestino, double monto);

#endif