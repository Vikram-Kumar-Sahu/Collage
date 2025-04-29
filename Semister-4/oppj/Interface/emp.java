//4.Aim of the program - Define an interface Emploee with a method getDetails() to get emplyee details as Empid and Ename.
// Also define a derived interface Manager with a method getDeptDetails() to get department details such as Deptid and Deptname.
// Then define a class Head which implements Manager interface and also prints all details of the employee. Write the complete program
// to display all details of one head of the department.
//Input - Enter employee id - 123
//Enter employee name - Sidharth Ambani
//Enter department id - 06
//Enter department name -Marketing
//Output - Employee id - 123
//Employee name - Sidharth Ambani
//Department id - 06
//Department name -Marketing
interface Emploee{
    void getDetails();
}
interface Managers extends Emploee{
    void getDeptDetails();
}
class Head implements Managers{
    protected int empid;
    protected String ename;
    protected int deptid;
    protected String deptname;
    public void set(int empid,String ename,int deptid,String deptname){
        this.empid=empid;
        this.ename=ename;
        this.deptid=deptid;
        this.deptname=deptname;
    }
    public void getDetails(){
        System.out.println("Empid"+empid+"Emp name"+ename);
    }
    public void getDeptDetails(){
        System.out.println("Deptid"+deptid+"Dept name"+deptname);
    }
}

public class emp {
    public static void main(String agrs[]){
        Head x = new Head();
        x.set(001,"Vikram",101,"Inventory");
        x.getDetails();
        x.getDeptDetails();
    }
}
