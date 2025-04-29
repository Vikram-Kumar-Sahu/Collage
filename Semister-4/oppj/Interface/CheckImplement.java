//2.Aim of the program -Define an interface Motor with a data member –capacity and two methods such as run() and consume().
// Define a Java class ‘Washing machine’ which implements this interface and write the code to check the value of the interface data
// member thru an object of the class.
//Input - mentioned in the program
//Output - Capacity of the motor is -----

interface Motor{
     int capacity=0;
     public void run();
     public void consume();
}
class WashingMachine implements Motor {
    public void run(){
         System.out.println("the mortor of the machine is running");
    }
    public void consume(){

        System.out.println("Capacity of the motor is "+ capacity);
    }

}
class CheckImplement{
    public static void main(String[] args){
        WashingMachine w= new WashingMachine();
        w.run();
        w.consume();
    }
}
