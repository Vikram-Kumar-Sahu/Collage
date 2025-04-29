import java.util.*;
class NegativeNumberException extends Exception{
    public NegativeNumberException(String message){
        super(message);
    }
}
public class negativeException {
    static int processInput(){
        Scanner x = new Scanner(System.in);
        System.out.println("Enter a num");
        int a=x.nextInt();
        x.close();
        return a;
    }
    public static void main(String args[]){
        int a=processInput();
        try{
            if(a<0){
                throw new NegativeNumberException("Negative numbers are not allowed.");
            }
            System.out.println("Square of the number: " + (a * a));
        }

        catch(Exception e){
            System.out.println("Negative Exception"+e.getMessage());
        }

    }
}
