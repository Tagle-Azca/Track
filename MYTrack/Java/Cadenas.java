public class Cadenas{
        public static void main(String args[]){
    var usuario = "Juan";
    var titulo = "Ingeniero";

    var union = titulo + " " +  usuario;
        System.out.println("union = " + union);            
            
        
            var uno = 1;
            var dos = 2;
            
            System.out.println(uno + dos);
            System.out.println(uno + dos + usuario);
            System.out.println(usuario + uno + dos);
            System.out.println(usuario + (uno + dos));
        }
}
