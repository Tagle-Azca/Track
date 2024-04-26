# Corregiremos el cálculo de las letras para las placas de los vehículos

def decode_plates(encoded_plates):
    # Decodificar las letras de las placas
    letters = ''
    for _ in range(3):  # Tres letras en la placa
        encoded_plates, index = divmod(encoded_plates, 26)
        letters = chr(index + 65) + letters  # Construir la cadena de letras al revés
    return letters

def central(encoded_data):
    # Decodificar los datos a partir del número entero
    decoded_bits = f"{encoded_data:039b}" # 39 bits en total según la función de codificación
    
    # Extraer los bits y convertir de vuelta a los valores originales
    plates_num = int(decoded_bits[:17], 2)
    plates_digits = int(decoded_bits[17:21], 2)
    color_bits = decoded_bits[21:23]
    current_speed = int(decoded_bits[23:31], 2)
    max_speed = int(decoded_bits[31:38], 2)
    verification_bit = decoded_bits[38]
    
    # Reconstruir las placas a partir del número
    letters = decode_plates(plates_num)
    
    # Mapear los bits de color de vuelta a la letra correspondiente
    color = {v: k for k, v in color_to_bits.items()}[color_bits]
    
    # Verificar el estado del refrendo
    verification = 'Pagado' if verification_bit == '1' else 'Vencido'
    
    # Calcular la multa
    speed_excess = current_speed - max_speed
    fine = 0
    if speed_excess > 0:
        # Calcular el monto base de la multa
        base_fine = speed_excess * 50
        # Aplicar multiplicadores según el exceso de velocidad
        multiplier = speed_excess // 20
        fine = base_fine * (2 ** multiplier)
    if verification_bit == '0':
        additional_fine = fine * 0.5 if fine > 0 else 1500  # multa fija por falta de refrendo si no hay exceso de velocidad
        fine += additional_fine
    
    # Mostrar la multa
    print(f"Información y Placas del Vehículo: Auto {color}, {letters}-{plates_digits:02}")
    print(f"Velocidad Actual: {current_speed} km/h")
    print(f"Límite de velocidad en vía: {max_speed} km/h")
    print(f"Refrendo: {verification}")
    print(f"Desglose de multa:")
    if speed_excess > 0:
        print(f" - Exceso de velocidad ({speed_excess} km x $50.00 pesos) = ${base_fine:.2f} MXN")
        if multiplier > 0:
            additional_fine = (2 ** multiplier - 1) * base_fine
            print(f" - Multa duplicada por cada 20 km/h sobre el límite = ${additional_fine:.2f} MXN")
    if verification_bit == '0' and fine > 0:
        print(f" - Sin Refrendo, multa incrementada al 50% = ${additional_fine:.2f} MXN")
    elif verification_bit == '0':
        print(f" - Multa por falta de refrendo vehicular = $1500.00 MXN")
    print(f"Total: ${fine:.2f} MXN")

# Volveremos a probar el flujo completo con la entrada de muestra
input_data = "HZX-45 R [85510|80] N"
main(input_data)
