# andres gomez tagle
# sistemas computacionales
# from time import sleep  se tiene que poner esto para poder utilizar el sleep

import random

from time import sleep

# utilice google para poder sacar el dibujo

IMAGENES = ['''
   -----
   |   |
       |
       |
       |
       |

=========''', '''
  -----
  |   |
  O   |
      |
      |
      |
=========''', '''

  -----
  |   |
  O   |
  |   |
      |
      |
=========''', '''

  -----
  |   |
  O   |
 /|   |
      |
      |
=========''', '''

  -----
  |   |
  O   |
 /|\  |
      |
      |
=========''', '''

  -----
  |   |
  O   |
 /|\  |
 /    |
      |
=========''', '''

  -----
  |   |
  O   |
 /|\  |
 / \  |
      |
=========''']

lista = 'alemania australia españa mexico italia brasil canada holanda belgica rusia finlandia afganistan colombia cuba ecuador china jamaica finlandia turquia inglaterra monaco indonesia filipinas arabia tailandia india argentina chile suiza '.split()


def obtenerPalabraAlAzar(listaDePalabras):
    indiceDePalabras = random.randint(0, len(listaDePalabras) - 1)
    return listaDePalabras[indiceDePalabras]


def mostrarTablero(IMAGENES, letrasIncorrectas, letrasCorrectas, palabraSecreta):
    print(IMAGENES[len(letrasIncorrectas)])
    print()

    print('Letras incorrectas:', end=' ')
    for letra in letrasIncorrectas:
        print(letra, end=' ')
    print()

    espacios = '=' * len(palabraSecreta)

    for i in range(len(palabraSecreta)):
        if palabraSecreta[i] in letrasCorrectas:
            espacios = espacios[:i] + palabraSecreta[i] + espacios[i + 1:]

    for letra in espacios:
        print(letra, end=' ')
    print()


def obtenerIntento(letrasProbadas):
    while True:

        print('Adivina una letra: ')
        intento = input()
        intento = intento.lower()
        if len(intento) != 1:
            print('Por favor, introduce una letra.')
        elif intento in letrasProbadas:
            print('Ya has probado esa letra. Elige otra.')
        elif intento not in 'qwertyuiopasdfghjklñzxcvbnm':
            print('Por favor ingresa una LETRA.')
        else:
            return intento


def jugarDeNuevo():
    print('¿Quieres jugar de nuevo? (sí o no)')
    return input().lower().startswith('s')


sleep(1)

print('el juegos de ahorcado')
letrasIncorrectas = ''
letrasCorrectas = ''
palabraSecreta = obtenerPalabraAlAzar(lista)
juegoTerminado = False

sleep(2)
print("TIP: es un pais")

sleep(2)
while True:
    mostrarTablero(IMAGENES, letrasIncorrectas,
                   letrasCorrectas, palabraSecreta)

    intento = obtenerIntento(letrasIncorrectas + letrasCorrectas)

    if intento in palabraSecreta:
        letrasCorrectas = letrasCorrectas + intento

        encontradoTodasLasLetras = True
        for i in range(len(palabraSecreta)):
            if palabraSecreta[i] not in letrasCorrectas:
                encontradoTodasLasLetras = False
                break
        if encontradoTodasLasLetras:
            print('¡Felicidades! ¡La palabra es "' +
                  palabraSecreta + '"! ¡Has ganado!')
            juegoTerminado = True
    else:
        letrasIncorrectas = letrasIncorrectas + intento

        if len(letrasIncorrectas) == len(IMAGENES) - 1:
            mostrarTablero(IMAGENES, letrasIncorrectas,
                           letrasCorrectas, palabraSecreta)
            print('¡Te quedaste sin intentos!\nDespués de ' + str(
                len(letrasIncorrectas)) + ' intentos fallidos y ' + str(
                len(letrasCorrectas)) + ' aciertos, la palabra era "' + palabraSecreta + '"')
            juegoTerminado = True

    if juegoTerminado:
        if jugarDeNuevo():
            letrasIncorrectas = ''
            letrasCorrectas = ''
            juegoTerminado = False
            palabraSecreta = obtenerPalabraAlAzar(lista)
        else:
            break
