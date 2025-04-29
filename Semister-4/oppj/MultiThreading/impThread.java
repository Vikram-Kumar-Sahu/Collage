public class impThread implements Runnable{
    public void run(){
        System.out.println("Hello WOrld");
    }
    public static void main(String args[]){
        impThread t= new impThread();
        Thread th= new Thread(t);

        th.start();

    }
}
