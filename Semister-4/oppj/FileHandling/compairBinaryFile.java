import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.*;
public class compairBinaryFile {
    public static void main(String[] args){
        String file1="file1.bin";
        String file2="file2.bin";
        try(FileInputStream input1 = new FileInputStream(file1); FileInputStream input2 =new FileInputStream(file2)){
            int b1,b2;
            int p=0;
            while((b1=input1.read())!=-1 && (b2=input2.read())!=-1){
                p++;
                if(b1!=b2){
                    System.out.println("Two files are not equal: byte position at which they differ is " + p);
                    return;
                }
            }
            if(input1.read() == -1 && input2.read() ==-1){
                System.out.println("Two files are equal");
            } else {
                System.out.println("Two files are not equal: byte position at which they differ is " + (p + 1));
            }
        }
        catch(IOException e){
            e.getStackTrace();
        }
    }
}
