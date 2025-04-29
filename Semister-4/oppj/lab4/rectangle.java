import java.util.Scanner;

public class rectangle {
    static void read(){
        Scanner x=new Scanner(System.in);
        int l,b;
        System.out.println("Enter the length:");
        l=x.nextInt();
        System.out.println("Enter the breadth:");
        b=x.nextInt();
        calculate(l,b);
    }
    static void calculate(int l,int b){
        int p=0,a=0;
        p=(2*l)+(2*b);
        a=l*b;
        display(p,a);
    }
    static void display(int p,int a){
        System.out.println("Perimeter"+p);
        System.out.println("Area"+a);
    }
    public static void main(String args[]){
        read();
    }
}
