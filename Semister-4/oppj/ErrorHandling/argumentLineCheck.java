import java.util.*;
class CheckArgument extends Exception{
    public CheckArgument(String message){
        super(message);
    }
}
public class argumentLineCheck {
   public static void main(String[] args) {
       try {
           if (args.length < 4) {
               throw new CheckArgument("the elements has less than 4");
           }
           int sum = 0;
           for (int i = 0; i < 4; i++) {
               int num = Integer.parseInt(args[i]);
               sum += num * num;
           }
           System.out.println("Output: " + sum);
       }
       catch (CheckArgument e){
           System.out.println(e.getMessage());
       }

   }
}
