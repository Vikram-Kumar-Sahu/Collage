import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;
public class fileDetail {
    public static void main(String args[]){
        Scanner x= new Scanner(System.in);
        int l=0,w=0,c=0;
        System.out.print("Enter file name: ");
        String fileName = x.nextLine();
        try(BufferedReader input= new BufferedReader(new FileReader("newFile.txt"))){
            String line;
            while((line=input.readLine())!=null){
                l++;
                c+=line.length();
                w+=line.split("\\s+").length;
            }
            System.out.println("No. of characters - " + c);
            System.out.println("No. of lines - " + l);
            System.out.println("No. of words - " + w);
        }
        catch (IOException e){
            e.getStackTrace();
        }
    }
}
