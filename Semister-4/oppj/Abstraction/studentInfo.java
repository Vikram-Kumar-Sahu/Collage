//1.Aim of the program -Illustrate the usage of abstract class with following Java classes –
//         An abstract class ‘student’ with two data members roll no, reg no, a method getinput() and an abstract method course()
//A subclass ‘kiitian’ with course() method implementation
//Write the driver class to print the all details of a kiitian object.
//
//Input - Rollno - 2205180
//Registration no - 1234567890
//Output -Rollno - 2205180
//Registration no - 1234567890
//Course - B.Tech. (Computer Science & Engg)
abstract class student{
    int roll,reg;
    public void getinput() {
        roll = 2305989;
        reg=222333;
        System.out.println(roll+"\n"+reg);
    }
    abstract void course();
}

class kiitian extends student{
    void course(){
        System.out.println("B.Tech. (Computer Science & Engg)");
    }
}
public class studentInfo {
    public static void main(String args[]){
        kiitian k1= new kiitian();
        k1.getinput();
        k1.course();
    }
}
