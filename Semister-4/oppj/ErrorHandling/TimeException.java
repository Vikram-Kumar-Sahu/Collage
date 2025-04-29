import java.util.*;
class HrsException extends Exception {
    public HrsException(String message) {
        super(message);
    }
}
class MinException extends Exception {

    public MinException(String message) {
        super(message);
    }
}
    class SecException extends Exception{
    public SecException(String message){
        super(message);
    }
}

class time{
    private int hr,min,sec;
    void settime() throws HrsException,MinException,SecException{
        Scanner x=new Scanner(System.in);
        System.out.println("enter Hour");
        hr= x.nextInt();

        if(hr<0 || hr>24){
                throw new HrsException("Hour is nor valid");
            }

        System.out.println("Enter  min");
        min=x.nextInt();

        if(min<0 || min>60)
                throw new MinException("Minute not Valid");

        System.out.println("Enter second");
        sec=x.nextInt();

        if(sec<0 || sec>60)
            throw new SecException("Second not Valid");

        x.close();
    }
    void display(){
        System.out.println("Time Entered: " + hr + ":" + min + ":" + sec);
    }
}


public class TimeException {
    public static void main(String args[]){
        time t= new time();
        try{
            t.settime();
            t.display();
        }
        catch (MinException| HrsException |SecException e){
            System.out.println("Exception: " + e.getMessage());

        }
    }

}
