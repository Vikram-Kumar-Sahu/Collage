import java.util.*;
public class prog1 extends Thread {
    private int min,max;
    public prog1(String name,int min,int max){
        super(name);
        this.min=min;
        this.max=max;
    }
    public void run(){
        for(int i=min;i<=max;i++) {
            System.out.println(Thread.currentThread().getName() + ":"+i);
            try {
                Thread.sleep(5000);  // Fix: Use Thread.sleep() and handle exception
            } catch (InterruptedException e) {
                System.out.println(Thread.currentThread().getName() + " was interrupted!");
            }
        }
    }
    public static void main(String args[]){
        Scanner x=new Scanner(System.in);
        String n1,n2;

        System.out.println("Set the name of the threads");
        n1=x.nextLine();
        n2=x.nextLine();
        System.out.println("Set the lower limit");
        int l=x.nextInt();
        System.out.println("Set the upper limit");
        int u=x.nextInt();
        int m=(l+u)/2;
        prog1 t1 = new prog1(n1,l,m);


        prog1 t2 = new prog1(n2,m+1,u);
        t1.start();
        t2.start();


    }
}
