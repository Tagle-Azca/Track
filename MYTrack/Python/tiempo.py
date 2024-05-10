from datetime import datetime


def obtener_fecha():
    while True:
        fecha_usuario_str = input(
            "Ingresa una fecha en el formato DD MM YYYY:\n")
        try:
            fecha_usuario = datetime.strptime(fecha_usuario_str, "%d %m %Y")
            return fecha_usuario
        except ValueError:
            print("")
            print("Error: El formato de fecha no es válido. Inténtalo de nuevo.")
            print("")


# Obtener la fecha del usuario
fecha_usuario = obtener_fecha()

# Obtener la fecha y hora actual
fecha_actual = datetime.now()

# Calcular la diferencia en días
diferencia_en_dias = abs((fecha_actual - fecha_usuario).days)

# Mostrar el resultado
if fecha_usuario.date() == fecha_actual.date():
    print("")
    print("Es la fecha de hoy")
else:
    print("")
    print("La diferencia en días es:")
    print(f"{diferencia_en_dias} días.")
