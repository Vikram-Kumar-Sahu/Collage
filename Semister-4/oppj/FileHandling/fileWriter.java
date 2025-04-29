import java.io.*;
//import java.util.FileWriter;
public class fileWriter {
    public static void main(String args[]){
        String data="vikram is not a good boy";
        try{
            FileWriter output = new FileWriter("newFile.txt");
            output.write(data);
            System.out.println("Data is written to the file");
            output.close();
        }
        catch(Exception e){
            e.getStackTrace();
        }
    }
}
