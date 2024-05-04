#include <stdio.h>
#include "/Users/tagle/Documents/Git/C/Proyecto/Include/SolicitudCuenta.h"
#include "/Users/tagle/Documents/Git/C/Proyecto/Include/NombreDestino.h"
#include "/Users/tagle/Documents/Git/C/Proyecto/Include/BancoDestino.h"
#include "/Users/tagle/Documents/Git/C/Proyecto/Include/SolicitudMonto.h"
#include "/Users/tagle/Documents/Git/C/Proyecto/Include/ConfirmacionDeposito.h"
#include "/Users/tagle/Documents/Git/C/Proyecto/Include/TicketDeposito.h"

// Supongamos que estas son variables globales o locales pasadas correctamente
extern char CuentaOrigenTicket[17];
extern char CuentaDestinoTicket[17];
extern char NombreBancoTicket[50];
extern char NombreDestinoTicket[50];
extern double MontoTicket;

void TicketDeposito()
{
    printf("\n====================== TICKET DE DEPOSITO ======================\n");
    printf("    Cuenta de Origen: %s\n", CuentaOrigenTicket);
    printf("    Cuenta Destino: %s\n", CuentaDestinoTicket);
    printf("    Banco Destino: %s\n", NombreBancoTicket);
    printf("    Nombre del Destinatario: %s\n", NombreDestinoTicket);
    printf("    Monto Depositado: $%.2f\n", MontoTicket);
    printf("================================================================\n");
}
