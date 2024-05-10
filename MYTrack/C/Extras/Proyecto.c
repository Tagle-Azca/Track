#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Asumiendo que el rango de las velocidades no excederá los límites de int
// Para simplificar, no estamos usando una representación comprimida aquí

// Estructura para mantener la información del vehículo
typedef struct {
    char plates[7]; // Incluyendo el espacio para el caracter nulo
    char color;
    int current_speed;
    int max_speed;
    char verification;
} VehicleInfo;

// Funciones prototipo
unsigned int encode(VehicleInfo vehicle);
void decode(unsigned int encoded_data, VehicleInfo *vehicle);
int calculate_fine(VehicleInfo vehicle);

int main() {
    VehicleInfo vehicle;
    unsigned int encoded_data;

    // Simulando la entrada de usuario
    printf("Ingrese la información del vehículo: ");
    scanf("%6s %c %d %d %c", vehicle.plates, &vehicle.color, &vehicle.current_speed, &vehicle.max_speed, &vehicle.verification);
    
    // Codificar la información del vehículo
    encoded_data = encode(vehicle);
    
    // Decodificar la información y calcular la multa
    decode(encoded_data, &vehicle);
    int fine = calculate_fine(vehicle);
    
    printf("Placas: %s\n", vehicle.plates);
    printf("Color: %c\n", vehicle.color);
    printf("Velocidad Actual: %d km/h\n", vehicle.current_speed);
    printf("Límite de Velocidad: %d km/h\n", vehicle.max_speed);
    printf("Verificación: %c\n", vehicle.verification);
    printf("Multa: %d\n", fine);

    return 0;
}

unsigned int encode(VehicleInfo vehicle) {
    // Codificación simple por razones de claridad
    // Esta función podría implementar una lógica de compresión de datos más compleja
    unsigned int encoded_data = 0;
    encoded_data += vehicle.current_speed;
    encoded_data += vehicle.max_speed << 8; // Desplazamos 8 bits a la izquierda
    encoded_data += (vehicle.color == 'R' ? 1 : (vehicle.color == 'A' ? 2 : (vehicle.color == 'B' ? 3 : 4))) << 16;
    encoded_data += (vehicle.verification == 'Y' ? 1 : 0) << 18;
    return encoded_data;
}

void decode(unsigned int encoded_data, VehicleInfo *vehicle) {
    // Decodificación simple por razones de claridad
    vehicle->current_speed = encoded_data & 0xFF; // Extraemos los primeros 8 bits
    vehicle->max_speed = (encoded_data >> 8) & 0xFF; // Desplazamos 8 bits a la derecha y extraemos los siguientes 8 bits
    int color_code = (encoded_data >> 16) & 0x3; // Extraemos 2 bits para el color
    vehicle->color = (color_code == 1 ? 'R' : (color_code == 2 ? 'A' : (color_code == 3 ? 'B' : 'N')));
    vehicle->verification = (encoded_data >> 18) & 0x1 ? 'Y' : 'N';
}

int calculate_fine(VehicleInfo vehicle) {
    int fine = 0;
    if (vehicle.current_speed > vehicle.max_speed) {
        int speed_excess = vehicle.current_speed - vehicle.max_speed;
        fine = speed_excess * 50; // $50 por cada km/h sobre el límite
        int multiplier = speed_excess / 20; // Se duplica por cada 20 km/h sobre el límite
        fine *= (1 << multiplier); // Multiplicar la multa por 2^multiplier
    }
    if (vehicle.verification == 'N') {
        fine += fine / 2; // 50% adicional si la verificación está vencida
    }
    return fine;
}
