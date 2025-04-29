import java.util.Scanner;
public class largest {
    public static void main(String []args){
        Scanner x=new Scanner(System.in);
        int []arr=new int[3];
        System.out.println("Enter any three nos");
        for(int i=0;i<3;i++){
            arr[i]=x.nextInt();
        }
        int k=Integer.MIN_VALUE;
        for(int i=0;i<3;i++){
            if(k<arr[i])
                k=arr[i];
        }
        System.out.println("The largest number of the array is:"+k);

    }
}
