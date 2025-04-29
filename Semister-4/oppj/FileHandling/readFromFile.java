import java.io.*;
public class readFromFile {
    public static void main(String[] args){
        char[] arr= new char[100];
        try{
            FileReader input =new FileReader("newFile.txt");
            input.read(arr);
            System.out.println("Data in the file");
            System.out.println(arr);
            input.close();
        }
        catch(Exception e){
            e.getStackTrace();
        }
    }
}
