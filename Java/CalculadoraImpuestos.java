// importe scaner para poder scanner las respuestas del usuario
import java.util.Scanner;


// definimos variable por usar en el cual determinare cuales son las diferentes paramentros que tomare
class RangoImpuesto {
    float limiteInferior;
    float limiteSuperior;
    float baseImpuesto;
    float tasa;

    // aqui lo que hago es tomar los  parámetros el límite inferior, límite superior, base del impuesto y la tasa, 
    // y se asigna a las variables de la instancia de la clase. 

    public RangoImpuesto(float limiteInferior, float limiteSuperior, float baseImpuesto, float tasa) {
        this.limiteInferior = limiteInferior;
        this.limiteSuperior = limiteSuperior;
        this.baseImpuesto = baseImpuesto;
        this.tasa = tasa;
    }
}
// aqui simplemente estamos dando los rangos de umpuestos para que la computadora sepa cuales son
public class CalculadoraImpuestos {
    static void calcularImpuestos(float salario) {
        RangoImpuesto[] rangos = {
                new RangoImpuesto(0.01f, 8952.49f, 0.00f, 0.192f),
                new RangoImpuesto(8952.50f, 75984.55f, 171.88f, 0.640f),
                new RangoImpuesto(75984.56f, 133536.07f, 4461.94f, 0.1088f),
                new RangoImpuesto(133536.08f, 155229.80, 10723.55f, 0.16f),
                new RangoImpuesto(155229.81f, 185852.57f, 14194.54, 0.1792f),
                new RangoImpuesto(185852.58f, 374837.88f, 19682.13f, 0.2136f),
                new RangoImpuesto(374837.89, 590795.99f, 60049.40, 0.2352f),
                new RangoImpuesto(590796.00f, 1127926.99, 110842.74f, 0.30f),
                new RangoImpuesto(1127927.00f, 1503902.46f, 271981.99, 0.32f),
                new RangoImpuesto(1503902.47f, 4511707.37, 392294.17f, 0.34f),
                new RangoImpuesto(4511707.38, Float.POSITIVE_INFINITY, 1414947.85f, 0.35f),
                
        };
        // Inicializa la variable 'impuestos' en cero para acumular el monto total de impuestos.
        float impuestos = 0;
        // Itera a través de los rangos de impuestos.
        for (RangoImpuesto rango : rangos) {
            // Comprueba si el salario está dentro del rango actual.
            if (salario <= rango.limiteSuperior) {
                // Calcula los impuestos acumulando la base de impuestos más la tasa aplicada al excedente del salario en este rango.
                impuestos += rango.baseImpuesto + (salario - rango.limiteInferior) * rango.tasa;
                 // Sale del bucle, ya que se encontró el rango aplicable.
                break;
            }
        }
        // Calcula el salario neto restando los impuestos del salario bruto.
        float salarioNeto = salario - impuestos;

        // Imprime el monto de impuestos y el salario neto con formato.
        System.out.printf("Impuestos: %.2f\n", impuestos);
        System.out.printf("Salario neto: %.2f\n", salarioNeto);
    }
// Función principal donde se inicia la ejecución del programa.
    public static void main(String[] args) {
         // Crea un objeto Scanner para leer la entrada del usuario.
        Scanner scanner = new Scanner(System.in);
        // Solicita al usuario que introduzca el salario.
        System.out.println("Introduce el salario:");
        float salario = scanner.nextFloat();

         // Llama a la función calcularImpuestos con el salario ingresado.
        calcularImpuestos(salario);
    }
}
