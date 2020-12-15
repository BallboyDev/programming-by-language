import java.io.FileReader;
import java.io.FileWriter;

public class CharStream{
    public static void main(String[] args){
        FileReader inputStream = null;
        FileWriter outputStream = null;

        try{
            inputStream = new FileReader("Test.java");
            outputStream = new FileWriter("output.txt");
            int c;

            while((c = inputStream.read()) != -1){
                outputStream.write(c);
            }
        } catch(Exception e){
            e.printStackTrace();
        } 
    }
}