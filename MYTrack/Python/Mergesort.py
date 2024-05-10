def Mergesort(mylist):
    # Si la lista tiene más de un elemento, necesitamos ordenarla.
    if len(mylist) > 1:
        # Encuentra el punto medio de la lista para dividirla en dos partes más pequeñas.
        mid = len(mylist) // 2
        left = mylist[:mid]  # La primera mitad de la lista.
        right = mylist[mid:]  # La segunda mitad de la lista.
        
        # Ordena cada mitad de la lista llamando a la misma función.
        Mergesort(left)
        Mergesort(right)
        
        # Preparamos índices para recorrer las dos mitades y la lista grande.
        i = j = k = 0
        
        # Comienza a combinar las mitades en una lista grande y ordenada.
        while i < len(left) and j < len(right):
            # Elige el elemento más pequeño de las dos mitades y lo pone en la lista grande.
            if left[i] < right[j]:
                mylist[k] = left[i]  # Toma el elemento de la mitad izquierda.
                i += 1  # Mueve al siguiente elemento en la mitad izquierda.
            else:
                mylist[k] = right[j]  # Toma el elemento de la mitad derecha.
                j += 1  # Mueve al siguiente elemento en la mitad derecha.
            k += 1  # Mueve al siguiente espacio libre en la lista grande.
            
        # Si aún quedan elementos en la mitad izquierda, los agregamos a la lista grande.
        while i < len(left):
            mylist[k] = left[i]  # Añade el elemento restante de la izquierda.
            i += 1  # Avanza al siguiente elemento en la izquierda.
            k += 1  # Avanza al siguiente espacio libre en la lista grande.

        # Si aún quedan elementos en la mitad derecha, los agregamos a la lista grande.
        while j < len(right):
            mylist[k] = right[j]  # Añade el elemento restante de la derecha.
            j += 1  # Avanza al siguiente elemento en la derecha.
            k += 1  # Avanza al siguiente espacio libre en la lista grande.

# Lista de ejemplo que queremos ordenar.
mylist = [345, 345, 23, 2, 1, 6, 2, 78, 3, 34]

# Llamamos a la función para ordenar la lista.
Mergesort(mylist)

# Mostramos la lista ya ordenada.
print(mylist)