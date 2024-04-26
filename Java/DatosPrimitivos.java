import java.util.Scanner;

public class DatosPrimitivos {
    public static void main (String args[]){
        byte numeroByte = (byte)127;
        System.out.println("Valor Byte: " + numeroByte);
        System.out.println("Valor minimo Byte: " + Byte.MIN_VALUE);
        System.out.println("Valor minimo Byte: " + Byte.MAX_VALUE);

        short numeroShort = (short)127;
        System.out.println("numeroShort = " + numeroShort);
        System.out.println("Valor minimo Short: " + Short.MIN_VALUE);
        System.out.println("Valor minimo Short: " + Short.MAX_VALUE);

        int numeroInt = (int)2147483647L;
        System.out.println("NumeroInt =" + numeroInt);
        System.out.println("Valor minimo int: " + Integer.MIN_VALUE);
        System.out.println("Valor minimo int: " + Integer.MAX_VALUE);

        long numeroLong = 9223372036854775807L;
        System.out.println("NumeroLong = " + numeroLong);
        System.out.println("Valor minimo Long: " + Long.MIN_VALUE);
        System.out.println("Valor minimo Long: " + Long.MAX_VALUE);



        //Datos primitivos flotantes

        //Float
        float numeroFloat = (float)10.0;
        System.out.println("Numnero float: " + numeroFloat);
        System.out.println("Valor minimo Float: " + Float.MIN_VALUE);
        System.out.println("Valor minimo Flaot: " + Float.MAX_VALUE);
        
    }
}
