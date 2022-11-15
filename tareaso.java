 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
import java.io.*;
import java.util.Scanner;
/**
 *
 * @author Daniela
 */
public class Tareaso {
    public static void main(String[] args ) throws Exception{  
        File file = new File("C:\\Users\\pacma\\Downloads\\informe-nautico.txt");
        Scanner scan = new Scanner(file);
        scan.useDelimiter(",");
        String aux =scan.next();
        int dim = Integer.parseInt(aux);
        aux =scan.next();
        int tam =Integer.parseInt(aux);
        int [][] matriz = new int[dim][dim];
        while (scan.hasNext()) {
            String logicalLine = scan.next();
            
// rest of your logic
        }
    }
}
