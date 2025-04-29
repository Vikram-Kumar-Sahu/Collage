//3.Aim of the program -Define an interface with three methods – earnings(), deductions() and bonus() and define a J
// ava class ‘Manager’ which uses this interface without implementing bonus() method. Also define another Java class ‘Substaff’
// which extends from ‘Manager’ class and implements bonus() method.  Write the complete program to find out earnings, deduction
// and bonus of a substaff with basic salary amount entered by the user as per the following guidelines –
//earnings           basic + DA (80% of basic) + HRA (15% of basic)
//deduction PF      	12% of basic
//bonus             50% of basic
//Input -Basic salary - 50000
//Output -Earnings -  97500
//Deduction -6000
//Bonus - 25000
import java.util.*;
interface imp{
    void earnings();
    void deductions();
    void bonus();
}
class Manager implements imp{
    protected int basic;
    protected double totalEarnings;
    protected double totalDeductions;
    public void setBasic(int basic) {
        this.basic = basic;
    }

    public void earnings(){

        totalEarnings+=(basic+(0.8*basic)+(.15*basic));
        System.out.println("Earnings"+totalEarnings);
    }
    public void deductions(){

        totalDeductions-=(.12*basic);
        System.out.println("Deduction"+totalDeductions);
    }
    public void bonus() {}
}
class substaff extends Manager{

    public void bonus(){
        double r2=(0.5*basic);
        System.out.println("Bonus"+(int)r2);
    }
}
public class Salary {
    public static void main(String[] args){
        Scanner x= new Scanner(System.in);
        int a=x.nextInt();
        substaff s1= new substaff();
        s1.setBasic(a);
        s1.earnings();
        s1.deductions();
        s1.bonus();
    }
}
