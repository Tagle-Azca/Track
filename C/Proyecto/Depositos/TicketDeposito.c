#include <stdio.h>
#include "/Users/tagle/Documents/Git/C/Proyecto/Include/SolicitudCuenta.h"
#include "/Users/tagle/Documents/Git/C/Proyecto/Include/NombreDestino.h"
#include "/Users/tagle/Documents/Git/C/Proyecto/Include/BancoDestino.h"
#include "/Users/tagle/Documents/Git/C/Proyecto/Include/SolicitudMonto.h"
#include "/Users/tagle/Documents/Git/C/Proyecto/Include/ConfirmacionDeposito.h"
#include "/Users/tagle/Documents/Git/C/Proyecto/Include/TicketDeposito.h"

// Supongamos que estas son variables globales o locales pasadas correctamente
extern char cuentaOrigenTicket[17];
extern char cuentaDestinoTicket[17];
extern char nombreBancoTicket[50];
extern char NombreDestinoTicket[50];
extern double montoTicket;

void TicketDeposito()
{
    printf("\n====================== TICKET DE DEPOSITO ======================\n");
    printf("    Cuenta de Origen: %s\n", cuentaOrigenTicket);
    printf("    Cuenta Destino: %s\n", cuentaDestinoTicket);
    printf("    Banco Destino: %s\n", nombreBancoTicket);
    printf("    Nombre del Destinatario: %s\n", NombreDestinoTicket);
    printf("    Monto Depositado: $%.2f\n", montoTicket);
    printf("================================================================\n");
}
