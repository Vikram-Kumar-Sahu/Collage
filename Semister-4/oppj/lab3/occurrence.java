import java.util.Arrays;
import java.util.Scanner;

public class occurrence {
    public static void main(String []args){
        int e=0,o=0;

        Scanner x=new Scanner(System.in);
        System.out.println("Enter the array size");
        int s=x.nextInt();
        int []arr=new int[s];
        int []counts=new int[s];
        boolean []counted = new boolean[s];
        System.out.println("Enter the array nos");
        for(int i=0;i<s;i++){
            arr[i]=x.nextInt();
        }
        System.out.println("Occurrence of each nos");
        for (int i=0;i<s;i++){
            if(!counted[i]){
                int count=1;
                for(int j=i+1;j<s;j++){
                    if(arr[i]==arr[j]){
                        count++;
                        counted[j]=true;
                    }
                }
                counts[i]=count;
                counted[i]=true;
                System.out.println("occurrrence of" +arr[i] +" = " + counts[i]);
            }
        }




    }

}
