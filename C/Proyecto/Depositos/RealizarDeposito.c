#include <stdio.h>
#include "/Users/tagle/Documents/Git/C/Proyecto/Include/SolicitudCuenta.h"
#include "/Users/tagle/Documents/Git/C/Proyecto/Include/NombreDestino.h"
#include "/Users/tagle/Documents/Git/C/Proyecto/Include/BancoDestino.h"
#include "/Users/tagle/Documents/Git/C/Proyecto/Include/SolicitudMonto.h"
#include "/Users/tagle/Documents/Git/C/Proyecto/Include/ConfirmacionDeposito.h"
#include "/Users/tagle/Documents/Git/C/Proyecto/Include/TicketDeposito.h"

int RealizarDeposito()
{
    if (!SolicitudCuenta())
    {
        printf("Error en la solicitud de Cuenta.\n");
        return 0;
    }
    if (!BaDestino())
    {
        printf("Error en la validación del banco destino.\n");
        return 0;
    }
    if (!NombreDestino())
    {
        printf("Error en la validación del nombre del destinatario.\n");
        return 0;
    }

    if (!SolicitudMonto())
    {
        printf("Error en la validación del monto.\n");
        return 0;
    }
    if (!ConfirmacionDeposito())
    {
        printf("Error en la validación del Deposito.\n");
        return 0;
    }

    TicketDeposito();

    return 1;
}
