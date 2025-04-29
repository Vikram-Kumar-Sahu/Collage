import java.util.*;
public class ArrOutOfBound {
    public static void main(String args[]){
        int[] arr = new int[4];
        Scanner x=new Scanner(System.in);
        System.out.println("Enter");
        try {
            for (int i = 0; i < 5; i++) {
                arr[i] = x.nextInt();
            }
        }
        catch (Exception e){
            System.out.println(e.getMessage());
        }
    }
}
