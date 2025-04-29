import java.util.Scanner;
import java.util.Arrays;

public class sort {
    public static void main(String []args){
        int e=0,o=0;

        Scanner x=new Scanner(System.in);
        System.out.println("Enter the array size");
        int s=x.nextInt();
        int []arr=new int[s];
        System.out.println("Enter the array nos");
        for(int i=0;i<s;i++){
            arr[i]=x.nextInt();
        }
        int i,j,temp;
        for(i=0;i<s-1;i++){
            for(j=0;j<s-i-1;j++){
                if(arr[j]>arr[j+1]){
                    temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
            }
        }
        System.out.println(Arrays.toString(arr));


    }


}
