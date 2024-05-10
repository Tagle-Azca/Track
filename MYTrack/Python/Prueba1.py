import random
import os

Palabras = "Amor Felicidad Viaje Aprender Música Aventura Corazón Montana Magia Pintura Noche imaginacion dia filosofia tristeza tomar constuir"

Password = "Clave1234"

Max_attempts = 3
Attempts = 0


def main_menu():
    print("(A) Palabras al azar ")
    print("")
    print("(B) Multiplicaciones ")
    print("")
    print("(C) Validacion de contraseña ")
    print("")
    print("(D) Abandonar programa")


def Palabras_azar():
    clear_screen()
    palabras = Palabras.split()  # Dividir la cadena en una lista de palabras
    palabra_azar = random.choice(palabras)
    print("Palabra al azar:", palabra_azar)
    print("")


def Multiplicaciones():
    clear_screen()
    uno = int(input("Pon un numero:  "))
    dos = int(input("pon otro numero: "))

    resultado = uno * dos
    print("El resultado de la multiplicacion es: ", resultado)
    print("")


def Validacion():
    global Attempts
    while Attempts < Max_attempts:
        User_Password = input("Ingrese la contraseña: ")
        if User_Password == Password:
            print("Contraseña Valida, Bienvenido")
            print("")
            return
        else:
            Attempts += 1
            print("Contraseña incorrecta, intentos restantes 2: ", Max_attempts)


def clear_screen():
    if os.name == 'nt':
        os.system('cls')  # Para sistemas Windows
    else:
        os.system('clear')


while True:
    main_menu()
    print("")
    choice = input("Seleccione una opción: ")

    if choice == "A":
        Palabras_azar()
    elif choice == "B":
        Multiplicaciones()
    elif choice == "C":
        Validacion()
    elif choice == "D":
        print("")
        print("¡Hasta pronto!")
        break
    else:
        print("Opción inválida. Por favor, seleccione una opción válida.")
