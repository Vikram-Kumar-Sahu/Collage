import java.util.*;
public class ser1 {
    public static void main(String args[])
    {
        Scanner x = new Scanner(System.in);
        int n = x.nextInt();
        int m=x.nextInt();
        int c=1;
       for(int i=1;i<=m;i++){
          c=c*n;
       }
        System.out.println(c);
    }
}