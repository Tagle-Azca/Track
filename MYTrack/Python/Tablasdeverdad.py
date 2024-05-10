import pandas as pd
import sympy as sp
import itertools


def generar_tabla_verdad(num_premisas):
    """Genera una tabla de verdad para un número especificado de premisas."""
    valores = list(itertools.product([True, False], repeat=num_premisas))
    columnas = ['p', 'q', 'r'][:num_premisas]
    return pd.DataFrame(valores, columns=columnas)


def evaluar_expresion(expresion, contexto):
    """Evalúa una expresión lógica en un contexto dado y devuelve el resultado."""
    # Convertimos las variables lógicas en sus valores correspondientes en el contexto
    expresion = expresion.replace("AND", "and").replace(
        "OR", "or").replace("NOT", "not")
    # Reemplazamos los símbolos de proposiciones por sus valores en el contexto
    for variable in contexto:
        expresion = expresion.replace(variable, str(contexto[variable]))
    # Evalúa la expresión en Python
    return eval(expresion)


def aplicar_operadores_a_df(df, expresiones):
    """Aplica una lista de expresiones lógicas a una tabla de verdad y añade los resultados como nuevas columnas."""
    for expr in expresiones:
        df[expr] = [evaluar_expresion(expr, row)
                    for index, row in df.iterrows()]


def main():
    print("Bienvenido al generador de tablas de verdad.")
    num_premisas = int(input("Introduce el número de premisas (2 o 3): "))
    if num_premisas not in [2, 3]:
        print("Número de premisas debe ser 2 o 3.")
        return

    df = generar_tabla_verdad(num_premisas)
    expresiones = []
    for i in range(1, num_premisas + 1):
        expresion = input(f"Introduce la premisa {i}: ")
        expresiones.append(expresion)
    conclusion = input("Introduce la conclusión: ")
    expresiones.append(conclusion)

    aplicar_operadores_a_df(df, expresiones)

    print("Tabla de verdad generada:")
    print(df)


if __name__ == "__main__":
    main()
