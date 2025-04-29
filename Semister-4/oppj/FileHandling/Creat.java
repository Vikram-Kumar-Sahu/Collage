import java.io.File;
public class Creat {
    public static void main(String args[]){
        File file =new File("newFile1.txt");
        try{
            boolean value=file.createNewFile();
            if(value){
                System.out.println("the file is created ");
            }
            else{
                System.out.println(("the file already exist.."));
            }
        }
        catch (Exception e){
            e.getStackTrace();
        }
    }
}
