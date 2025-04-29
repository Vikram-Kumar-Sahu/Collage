import java.util.*;
public class even {
    public static void main(String args[]){
        Scanner x= new Scanner(System.in);
        System.out.println("enter a number");
        int a=x.nextInt();
        if(a%2==0){
            System.out.println("even num");
        }
        else {
            System.out.println("not even num");
        }
    }
}
