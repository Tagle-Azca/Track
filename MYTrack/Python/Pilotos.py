Lista_Piloto = {
    "Lewis hamilon": 7,
    "max verstappen": 3,
    "Fernando Alonso": 2,
    "Checo perez": 0,
    "Sebastian Vettel": 4,
    "Charles Leclerc": 0,
    "Valtteri Bottas": 0,
    "Daniel Ricciardo": 0,
    "Kimi Räikkönen": 1,
    "Lando Norris": 0,
    "Esteban Ocon": 0,
    "Carlos Sainz": 0,
    "Pierre Gasly": 0,
    "George Russell": 0,
    "Nico Hülkenberg": 0,
    "Romain Grosjean": 0,
    "Pastor Maldonado": 0,
    "Jenson Button": 0,
    "Michael Schumacher": 7,
    "Ayrton Senna": 3,
}


while True:
    print("Lista de pilotos de la Formula 1")
    for Piloto in Lista_Piloto:
        print(Piloto)
    print("Acabar")

    Piloto_Seleccionado = input("escoge un piloto: ")

    if Piloto_Seleccionado.lower() == 'Acabar':
        break

    if Piloto_Seleccionado in Lista_Piloto:
        campeonatos = Lista_Piloto[Piloto_Seleccionado]
        print(
            F"{Piloto_Seleccionado}Ha ganado {campeonatos} Campeonatos en la Formula 1")

    else:
        print("No se encuentra el piloto seleccionado")

    Continuar = input("quieres continuar? (si/no): ")
    if Continuar.lower() != 'si':

        break

print("Gracias por usar el programa")
