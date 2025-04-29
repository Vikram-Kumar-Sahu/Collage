public class Thread1 extends Thread{
    public void run(){
        System.out.println("Hello WOrld");
    }
    public static void main(String args[]){
        Thread1 t= new Thread1();
        Thread1 t1= new Thread1();
        t.start();
        t1.start();
    }
}
