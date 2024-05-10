import java.util.Scanner;

public class Conversiones {
    public static void main (String args[]){
        // convertir tipo string a tipo int
        var edad = Integer.parseInt("20");
        // var edad = "20"; si hago esto al llamarlo en vez de darme 20 
        // me daria 201 el de arriba es para que haga la suma yua que suma la string con la suma de 1 con el de arriba convierte string a entero
        System.out.println("edad = " + (edad + 1));
        
        // con esto se puede hacer con valores double
        var valorPi = Double.parseDouble("3.1416");
        System.out.println("Valor PI: " + valorPi);

        // pedir valor
        var consola = new Scanner(System.in);
        System.out.println("proporciona tu edad: ");
        edad = Integer.parseInt(consola.nextLine());
        System.out.println("edad: " + edad);

        // 
        // var edadTexto = String.valueOf(10);
        // System.out.println("texto edad: " + edadTexto);

        var caracter = "Hola".charAt(0);
        System.out.println(caracter);
        // los valores enteros no pueden usar el chartAt 
        System.out.println("proporciona un caracter");
        caracter = consola.nextLine().charAt(0);
        System.out.println("caracter: " + caracter);
    }
}
