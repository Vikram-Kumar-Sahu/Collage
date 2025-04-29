import java.util.*;
public class no_digits {
    public static void main(String args[])
    {
        Scanner x = new Scanner(System.in);
        int n = x.nextInt();
        int c=0;
        while(n>0){
            c=c*10+(n%10);
            n/=10;
        }
        System.out.println("the no of digits present are"+c);
    }
}
