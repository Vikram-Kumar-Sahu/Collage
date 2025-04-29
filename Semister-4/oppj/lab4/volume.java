import java.util.*;
public class volume {
//    private double length;
//    private double width;
//    private double height;

    static double find(int l,int w,int h){
        double a=l*w*h;
        return (a);
    }
    public static void main(String args[]){
        Scanner x=new Scanner(System.in);
        int l,h,w;
        System.out.println("Enter the length");
        l=x.nextInt();
        System.out.println("Enter the width");
        w=x.nextInt();
        System.out.println("Enter the height");
        h=x.nextInt();
        double a=find(l,w,h);
        System.out.println("The Volume is"+a);
    }
}
