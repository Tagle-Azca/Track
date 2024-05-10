#include <stdio.h>
#include <math.h>

typedef struct {
    char plates[7];
    char color;
    int current_speed;
    int max_speed;
    char refrendo;
} VehicleInfo;

unsigned int encode(VehicleInfo vehicle);
void central(unsigned int encoded_data);
int calculate_fine(VehicleInfo vehicle);
VehicleInfo decode(unsigned int encoded_data);

int main() {
    VehicleInfo vehicle;
    unsigned int encoded_data;
    char input[30];

    printf("Ingresar datos del carro: ");
    fgets(input, sizeof(input), stdin);

    sscanf(input, "%s %c [%d|%d] %c", vehicle.plates, &vehicle.color,
        &vehicle.current_speed, &vehicle.max_speed, &vehicle.refrendo);

    // Convertir m/h a km/h y redondear hacia arriba
    vehicle.current_speed = (int)ceil(vehicle.current_speed / 1000.0);
    
    encoded_data = encode(vehicle);
    central(encoded_data);

    return 0;
}





unsigned int encode(VehicleInfo vehicle) {
    unsigned int data = 0;
    data |= (vehicle.color == 'R' ? 0 : (vehicle.color == 'A' ? 
    1 : (vehicle.color == 'B' ? 2 : 3))) << 19;
    data |= (vehicle.current_speed & 0x1FF) << 10;
    data |= (vehicle.max_speed & 0xFF) << 2;
    data |= (vehicle.refrendo == 'Y');
    return data;
}

VehicleInfo decode(unsigned int encoded_data) {
    VehicleInfo vehicle;
    vehicle.color = (encoded_data >> 19) == 0 ? 'R' :
                    (encoded_data >> 19) == 1 ? 'A' :
                    (encoded_data >> 19) == 2 ? 'B' : 'N';
    vehicle.current_speed = (encoded_data >> 10) & 0x1FF;
    vehicle.max_speed = (encoded_data >> 2) & 0xFF;
    vehicle.refrendo = (encoded_data & 0x1) == 1 ? 'Y' : 'N';
    return vehicle;
}

int calculate_fine(VehicleInfo vehicle) {
    int fine = 0;
    if (vehicle.current_speed > vehicle.max_speed) {
        int excess_speed = vehicle.current_speed - vehicle.max_speed;
        fine = excess_speed <= 20 ? excess_speed * 50 :
               excess_speed <= 40 ? excess_speed * 100 :
               excess_speed <= 60 ? excess_speed * 200 :
               excess_speed * 400;
        fine *= (1 << (excess_speed / 20));
    }

    if (vehicle.refrendo == 'N') {
        fine += fine / 2; // 50% adicional por refrendo no pagado
    }

    // Si el vehículo está dentro del límite de velocidad pero sin refrendo, aplicar multa de $1500
    if (vehicle.current_speed <= vehicle.max_speed && vehicle.refrendo == 'N') {
        fine = 1500;
    }

    return fine;
}

void central(unsigned int encoded_data) {
    VehicleInfo vehicle = decode(encoded_data);
    int fine = calculate_fine(vehicle);

    // Muestra la información del vehículo y la multa
    printf("Informacion y Placas del Vehiculo: Auto %c %s\n",
           vehicle.color, vehicle.plates);
    printf("Velocidad Actual: %d km/h\n", vehicle.current_speed);
    printf("Limite de velocidad en via: %d km/h\n", vehicle.max_speed);
    printf("Refrendo: %s\n", vehicle.refrendo == 'Y' ? "ACTIVO" : "VENCIDO");
    printf("Multa: $%d.00 MXN\n", fine);
}

unsigned int encode(VehicleInfo vehicle) {
    // Codificación utilizando la menor cantidad de bits posible
    unsigned int data = 0;
    data |= (vehicle.color == 'R' ? 0 : (vehicle.color == 'A' ? 1 : (vehicle.color == 'B' ? 2 : 3))) << 19;
    data |= (vehicle.current_speed & 0x1FF) << 10;
    data |= (vehicle.max_speed & 0xFF) << 2;
    data |= (vehicle.refrendo == 'Y');
    return data;
}
