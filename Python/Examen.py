# Define the  password
password = "Clave123"

# Aqui se define el numero de intentos de la contraseña
max_attempts = 3
attempts = 0

# la funcion de Main Menu


def main_menu():
    print("MENÚ PRINCIPAL DE OPCIONES")
    print("")
    print("1. Validar el password para entrar al sistema")
    print("2. Mostrar preguntas detonadoras")
    print("3. Salir")

# Validacion de clave


def Validar_Clave():
    global attempts
    while attempts < max_attempts:
        user_password = input("Ingrese la clave: ")
        if user_password == password:
            print("")
            print("Contraseña válida. Acceso concedido.")
            print("")
            return
        else:
            attempts += 1
            print("Clave incorrecta, te quedan dos intentos, escrive la clave de acceso: ",
                  max_attempts - attempts)

    print("")
    print("Acceso negada. Has agotado tus intentos.")
    exit()

# aqui muestra las preguntas


def preguntas():
    print("Preguntas detonadoras:")
    print("")
    print("¿Cómo podemos satisfacer mejor sus necesidades? ")
    print("¿Qué le impide tomar una decisión de compra en este momento? ")
    print("¿Hay algo más en lo que podamos ayudar al cliente? ")
    print("")
    # Add your questions here


# se hace el loop del main
while True:
    main_menu()
    choice = input("Seleccione una opción: ")

    if choice == "1":
        Validar_Clave()
    elif choice == "2":
        preguntas()
    elif choice == "3":
        print("¡Hasta luego! Gracias por usar el programa.")
        break
    else:
        print("Opción inválida. Por favor, seleccione una opción válida.")
