import java.util.Scanner;
public class ev_od {
           public static void main(String []args){
               int e=0,o=0;
            Scanner x=new Scanner(System.in);
            int []arr=new int[10];
            System.out.println("Enter any ten nos");
            for(int i=0;i<10;i++){
                arr[i]=x.nextInt();
            }

            for(int i=0;i<10;i++){
                if(arr[i]%2==0)
                    e++;
                else o++;
            }
            System.out.println("Even Nos:"+e);
            System.out.println("Odd Nos:"+o);

        }


}
