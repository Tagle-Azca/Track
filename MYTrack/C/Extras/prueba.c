#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// intente poner todo en ingles por buenas pracricas ya que en el ambiente
// laborar casi todo es en ingles

typedef struct {
  char plates[7];
  char color;
  int current_speed;
  int max_speed;
  char refrendo;
} vehicleInfo;

unsigned int encode(vehicleInfo vehicle);
void central(unsigned int encoded_data);
int calculate_fine(vehicleInfo vehicle);
vehicleInfo decode(unsigned int encoded_data);

int main() {
  vehicleInfo vehicle;
  unsigned int encoded_data;
  char input[30];
  int readCount;

  do {
    printf("Ingresar datos del carro: \n");
    fgets(input, sizeof(input), stdin);

    readCount =
        sscanf(input, "%7s-%d %c [%d|%d] %c", vehicle.plates, &vehicle.color,
               &vehicle.current_speed, &vehicle.max_speed, &vehicle.refrendo);
    // convierte metros por hora a kilometros por hora y redondea
    vehicle.current_speed = (int)ceil(vehicle.current_speed / 1000.0);

    if (readCount != 5) {
      printf("Error de formato, por favor intentarlo nuevamente\n");
    }
  } while (readCount != 5);
  encoded_data = encode(vehicle);
  central(encoded_data);

  return 0;
}

unsigned int encode(vehicleInfo vehicle) {
  unsigned int data = 0;
  unsigned int color_bits = vehicle.color == 'R'   ? 0
                            : vehicle.color == 'A' ? 1
                            : vehicle.color == 'B' ? 2
                                                   : 3;
  unsigned int refrendo_bit = vehicle.refrendo == 'Y' ? 1 : 0;

  data = (color_bits << 15) | ((vehicle.current_speed & 0xFF) << 7) |
         ((vehicle.max_speed & 0x7F) << 1) | refrendo_bit;
  return data;
}

vehicleInfo decode(unsigned int encoded_data) {
  vehicleInfo vehicle;
  char color[4] = {'R', 'A', 'B', 'N'};
  vehicle.color = color[(encoded_data >> 15) & 0x3];
  vehicle.refrendo = (encoded_data & 0x1) ? 'Y' : 'N';
  vehicle.current_speed = (encoded_data >> 7) & 0xFF;
  vehicle.max_speed = (encoded_data >> 1) & 0x7F;

  return vehicle;
}

int calculate_fine(vehicleInfo vehicle) {
  int fine = 0;
  int excess_speed = vehicle.current_speed - vehicle.max_speed;
  if (excess_speed > 0) {
    fine = excess_speed * 50;
    fine *= (1 << (excess_speed / 20));
  }
  if (vehicle.refrendo == 'N') {
    fine += fine / 2;
  }
  if (excess_speed <= 0 && vehicle.refrendo == 'N') {
    fine = 1500;
  }
  return fine;
}

void central(unsigned int encoded_data) {
  vehicleInfo vehicle = decode(encoded_data);
  int base_fine = calculate_fine(vehicle);
  int refrendo_fine = 0;
  int total_fine = base_fine;

  if (vehicle.refrendo == 'N') {
    refrendo_fine = base_fine / 2;
    total_fine += refrendo_fine;
  }

  printf("--------------------------------------------------------- \n");
  printf("Informacion y placas        \n    carro: %c, %s\n", vehicle.color,
         vehicle.plates);
  printf("Velocidad actual            :       %d km/h\n",
         vehicle.current_speed);
  printf("Limite de velocidad         :      \t%d km/h\n", vehicle.max_speed);
  printf("Refrendo                    :  \t\t%s\n",
         vehicle.refrendo == 'Y' ? "Al Corriente" : "Vencido");

  printf("\nDesglose de multa: \n");
  if (vehicle.current_speed > vehicle.max_speed) {
    printf("      - Exceso de velocidad (%d km x $200.00 pesos\n",
           vehicle.current_speed - vehicle.max_speed);
  }
  if (vehicle.refrendo == 'N') {
    printf("\n      - Sin refrendo, 1.5x\n");
  }

  printf("--------------------------------------------------------- \n");
  printf("                            Total: \5\5\5\5$%.2f MXN\n", (float)total_fine);
}
