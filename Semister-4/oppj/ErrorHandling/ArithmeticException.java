import java.util.*;
public class ArithmeticException {
    public static void main(String args[]){
        Scanner x=new Scanner(System.in);
        System.out.println("Enter");
        int a=x.nextInt();
        int div=1;
        try {

             div = a / 0;
            System.out.println(div);
        }
        catch(Exception e){
            System.out.println("Arithmetic Exception Caught"+e.getMessage());
            e.printStackTrace();
        }
        finally {
            System.out.println("Finally block executed.");
        }
    }
}
