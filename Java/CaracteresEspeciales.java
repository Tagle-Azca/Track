import java.util.Scanner;

public class CaracteresEspeciales {
    public static void main (String args[]){
        System.out.println("Escribe tu nombre:");
        //leera lo que ponga el usuario
        Scanner consola = new Scanner(System.in);
        var nombre = consola.nextLine();//nextline espera a que el usuario escriba algo y una vez que lo hace el resultado se asigna a la variable 
        System.out.println("Usuario = " + nombre);
        System.out.println("Escribe titulo:");
        var titulo = consola.nextLine();
        System.out.println("Nombre: " + nombre + "\n" + "Titulo: "  + titulo);


        // System.out.println("Nueva linea:\n" + nombre);
        // System.out.println("Tabulador: \t" + nombre);
        // System.out.println("Retroceso: \b" + nombre);
    }
}