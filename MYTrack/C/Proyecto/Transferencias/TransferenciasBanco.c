// TransferenciaBanco.c

#include "Transferencias.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Variables globales para los almacenes de datos
char CuentaDestinoTicket[17];
char NombreBancoTicket[15];
char NombreDestinoTicket[40];

void liBuffer() {
  int c;
  while ((c = getchar()) != '\n' &&
         c != EOF) { /* descarta caracteres hasta el final de la línea */
  }
}

int IngresarBancoDestino();

const char *bancos[] = {"BBVA",     "Banamex",    "Santander", "HSBC",
                        "Banorte",  "Scotiabank", "Inbursa",   "Banco Azteca",
                        "Banregio", "NU"};
int NumBanco = sizeof(bancos) / sizeof(bancos[0]);

// Aqui pedimos el numero de la cuenta y el monto a transferir

int esSoloNumerosCuenta(const char *str) {
  for (int i = 0; str[i] != '\0'; i++) {
    if (!isdigit(str[i])) {
      return 0;
    }
  }
  return 1;
}

void SolicitudCuentaDestino() {
  char buffer[100];
  int valido;

  do {
    printf("Ingrese el número de cuenta destino (16 dígitos): \n");
    liBuffer();
    if (!fgets(buffer, sizeof(buffer), stdin)) {
      // Manejar posible error de lectura
      continue;
    }
    // Eliminar el salto de línea al final del string
    buffer[strcspn(buffer, "\n")] = 0;

    if (strlen(buffer) == 0) {
      printf("No se ingresó ningún número. Intente de nuevo.\n");
      continue;
    }

    if (sscanf(buffer, "%16s", CuentaDestinoTicket) == 1 &&
        strlen(CuentaDestinoTicket) == 16 &&
        esSoloNumerosCuenta(CuentaDestinoTicket)) {
      valido = 1;
    } else {
      printf("Número de cuenta inválido, debe ser de 16 números.\n");
      valido = 0;
    }
  } while (!valido);

  if (IngresarBancoDestino() == 0) {
    printf("Banco seleccionado correctamente\n");
  }
}

int IngresarBancoDestino() {
  char input[20];
  int bancoValido = 0;

  printf("Ingresar el banco del Destino\n");
  for (int i = 0; i < NumBanco; i++) {
    printf("- %s\n", bancos[i]);
  }
  while (!bancoValido) {
    printf("Ingrese el nombre del banco: \n");
    if (fgets(input, sizeof(input), stdin) == NULL) {
      fprintf(stderr,
              "Error al leer el nombre del banco. Intente nuevamente.\n");
      continue;
    }
    // Eliminar el salto de línea al final del string
    input[strcspn(input, "\n")] = '\0';

    for (int i = 0; i < NumBanco; i++) {
      if (strcmp(bancos[i], input) == 0) {
        stpcpy(NombreBancoTicket, input);
        bancoValido = 1;
        break;
      }
    }
    if (!bancoValido) {
      printf("Banco no reconocido. por favor intentar de nuevo");
    }
  }
  return bancoValido;
}

int NombreDestino() {
  char nombre[100];
  int intentos = 0;
  while (intentos < 3) { // Limita el número de intentos
    printf("Ingrese el nombre del destinatario: ");
    if (!fgets(nombre, sizeof(nombre), stdin)) {
      fprintf(stderr, "Error al leer la entrada. Intente de nuevo.\n");
      continue;
    }
    nombre[strcspn(nombre, "\n")] = 0; // Elimina el salto de línea

    int longitud = strlen(nombre);
    if (longitud < 2 || longitud > 30) {
      printf("El nombre debe tener entre 2 y 30 caracteres.\n");
    } else {
      int valido = 1;
      for (int i = 0; i < longitud; i++) {
        if (!isalpha(nombre[i]) && nombre[i] != ' ' && nombre[i] != '-') {
          printf("El nombre solo puede contener letras, espacios o guiones.\n");
          valido = 0;
          break;
        }
      }
      if (valido) {
        strcpy(NombreDestinoTicket, nombre);
        return 1;
      }
    }
    intentos++;
  }
  printf("Se han superado los intentos máximos.\n");
  return 0;
}

int ConfirmarTransferencia() {
  char respuesta[5];
  do {
    printf("Desea Confirmar Transferencia (si/no): ");
    if (fgets(respuesta, sizeof(respuesta), stdin) == NULL) {
      fprintf(stderr, "Error al leer la entrada. Intente de nuevo.\n");
      continue;
    }
    respuesta[strcspn(respuesta, "\n")] =
        0; // Elimina el salto de línea al final del string

    for (int i = 0; respuesta[i]; i++) {
      respuesta[i] = tolower((unsigned char)respuesta[i]);
    }
    if (strcmp(respuesta, "si") == 0) {
      return 1;
    } else if (strcmp(respuesta, "no") == 0) {
      return 0;
    } else {
      printf("Respuesta inválida, intente nuevamente. \n");
    }
  } while (1);
}

void TransferirBancoExterno(Tarjeta *origen, const char *nombreDestino,
                            double monto) {
  if (ConfirmarTransferencia()) {
    if (origen->Saldo >= monto) {
      origen->Saldo -= monto;
      printf("Transferencia de %.2f a cuenta %s en %s realizada con éxito.\n",
             monto, CuentaDestinoTicket, NombreBancoTicket);
      // Aquí podrías añadir un log de la transacción
    } else {
      printf("Saldo insuficiente para realizar la transferencia.\n");
    }
  } else {
    printf("Transferencia cancelada por el usuario.\n");
  }
}


