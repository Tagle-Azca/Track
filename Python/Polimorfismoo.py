class Auto:
    def moverse(self):
        print("El auto se está moviendo.")

class Moto:
    def moverse(self):
        print("La moto se está moviendo.")

def iniciar_movimiento(vehiculo):
    vehiculo.moverse()

# Creamos instancias de Auto y Moto
auto = Auto()
moto = Moto()

# Ahora usamos la función que actúa polimórficamente
iniciar_movimiento(auto)  # Imprime: El auto se está moviendo.
iniciar_movimiento(moto)  # Imprime: La moto se está moviendo.
