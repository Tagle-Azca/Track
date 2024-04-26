import java.util.Scanner;

public class Booleano {
    public static void main(String args[]){
        boolean varBoolean = true;
        System.out.println("VarBoolean = " + varBoolean);

        // si solo pongo if (varBoolean == true) considera que esta prenguntando si es verdadera)
        if(varBoolean){
            System.out.println("La vandera es Verdadera");
        }
        else{
            System.out.println("la bandera es falsa");
        }

        System.out.println("escribe tu edad: ");
        Scanner consola = new Scanner(System.in);   
        int edad = consola.nextInt();
        
        if( edad >= 18 ){
            System.out.println("Es adulto");
        }
        else{
            System.out.println("no es adulto");

        }
    }
}

