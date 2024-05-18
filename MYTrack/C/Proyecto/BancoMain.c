// BancoMain.c

#include "Cuenta/Cuenta.h"
#include "Depositos/Depositos.h"
#include "EstadoCuenta/EstadoCuenta.h"
#include "Gastos/Gastos.h"
#include "Rendimientos/Rendimientos.h"
#include "Retiros/Retiros.h"
#include "Tickets/Tickets.h"
#include "Transferencias/Transferencias.h"

// Inclucion de librerias
#include <stdio.h>
#include <string.h>
#include <time.h> // Para obtener la fecha actual

// Para compilar
/* gcc BancoMain.c Cuenta/Cuenta.c Depositos/Depositos.c Rendimientos/Rendimientos.c Retiros/Retiros.c Transferencias/TransferenciaBanco.c Transferencias/Transferenciacuenta.c Tickets/Tickets.c EstadoCuenta/EstadoCuenta.c Gastos/Gastos.c -o Banco */
//./Banco

// Declaración de la función SolicitudCuentaDestino
void SolicitudCuentaDestino();

void limpiarBuffer() {
  int c;
  while ((c = getchar()) != '\n' &&
         c != EOF) { /* descarta caracteres hasta el final de la línea */
  }
}

// Estructuras principal del codigo
int main() {

  Cuenta cuenta;
  // Inicializar la cuenta
  InicializarCuenta(&cuenta);
  int opcion;
  double monto;           // Variable para almacenar el monto
  char numeroTarjeta[17]; // Variable para almacenar el número de tarjeta
  double SaldoInicial;
  int tipoTransferencia;
  const char *CuentaDestinoTicket;

  do {
    printf("\n**** Sistema Bancario ****\n");
    printf("1. Estado de cuenta\n");
    printf("2. Deposito\n");
    printf("3. Retiro\n");
    printf("4. Transferencia\n");
    printf("5. Rendimientos\n");
    printf("6. Gastos\n");
    printf("7. Salir\n");
    printf("Ingrese una opción: \n");
    if (scanf("%d", &opcion) != 1) {
      fprintf(stderr, "Entrada inválida. Por favor, introduzca un número.\n");
      while (getchar() != '\n')
        ;
      continue;
    }

    switch (opcion) {
    case 1:
      MostrarEstadoCuenta(&cuenta);
      break;

    case 2:
      // Deposito
      printf("Ingrese el numero de Tarjeta (16 digitos): ");
      if (scanf("%s", numeroTarjeta) != 1) {
        fprintf(stderr, "Error en la entrada. Intente nuevamente.\n");
        limpiarBuffer();
        continue;
      }
      printf("Ingrese el monto a depositar: ");
      if (scanf("%lf", &monto) != 1) {
        fprintf(stderr, "Error en la entrada. Intente nuevamente.\n");
        limpiarBuffer();
        continue;
      }
      Depositar(&cuenta, numeroTarjeta, monto);
      break;

    case 3:
      // Retiro
      printf("Ingrese el numero de cuenta (16 digitos): ");
      if (scanf("%16s", numeroTarjeta) != 1) {
        fprintf(stderr, "Error en la entrada. Intente nuevamente.\n");
        continue;
      }
      printf("Ingrese el monto a retirar: ");
      if (scanf("%lf", &monto) != 1) {
        fprintf(stderr, "Error en la entrada. Intente nuevamente.\n");
        continue;
      }
      retiro(&cuenta, numeroTarjeta, monto);
      break;
    case 4:
      // Transferencias
      printf("Seleccione el tipo de transferencia:\n");
      printf("1. Transferencia SPEI\n");
      printf("2. Transferencia entre tarjetas\n");
      printf("Ingrese opción: ");
      if (scanf("%d", &tipoTransferencia) != 1) {
        fprintf(stderr, "Error en la entrada. Intente nuevamente.\n");
        limpiarBuffer();
        continue;
      }
      switch (tipoTransferencia) {
      case 1:
        // Transferencia SPEI
        printf("Ingrese el monto a transferir: ");
        if (scanf("%lf", &monto) != 1) {
          fprintf(stderr, "Error en la entrada. Intente nuevamente.\n");
          limpiarBuffer();
          break; // Sale del switch y regresa al menú principal
        }
        SolicitudCuentaDestino();
        TransferirBancoExterno(&cuenta.TarjetaPrincipal, CuentaDestinoTicket,
                               monto);
        break;
      case 2:
        // Transferencia entre tarjetas
        printf("Ingrese el monto a transferir a tarjeta secundaria: ");
        if (scanf("%lf", &monto) != 1) {
          fprintf(stderr, "Error en la entrada. Intente nuevamente.\n");
          break; // Sale del switch y regresa al menú principal
        }
        TranferirEntreTarjetas(&cuenta.TarjetaPrincipal,
                               &cuenta.TarjetaSecundaria, monto);
        break;
      default:
        printf("Opción no válida\n");
        break;
      }
      break; // Este break asegura salir del caso 4 y regresar al menú principal

    case 5:
      // Rendimientos
      printf("Ingrese saldo inicial: \n");
      if (scanf("%lf", &SaldoInicial) != 1) {
        fprintf(stderr, "Error en la entrada. Intente nuevamente.\n");
        limpiarBuffer();
        continue;
      }
      limpiarBuffer();

      printf("Calculo de rendimiento del 3.5 anual\n");
      printf("\nSaldo después de 1 mes: %.2f\n",
             CalcularRendimiento(SaldoInicial, 1));
      printf("Saldo después de 6 meses: %.2f\n",
             CalcularRendimiento(SaldoInicial, 6));
      printf("Saldo después de 1 año: %.2f\n",
             CalcularRendimiento(SaldoInicial, 12));
      printf("Saldo después de 5 años: %.2f\n",
             CalcularRendimiento(SaldoInicial, 60));
      printf("Saldo después de 10 años: %.2f\n",
             CalcularRendimiento(SaldoInicial, 120));
      break;
    case 6:
      inicializarGastos();
      mostrarReporteDeGastos();
      break;

    case 7:
      printf("Gracias :) regrese pronto\n");
      break;

    default:
      printf("opcion no valida, intente nuevamente. \n");
      break;
    }
  } while (opcion != 7);
  return 0;
}