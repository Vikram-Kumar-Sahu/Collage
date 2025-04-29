import java.util.Scanner;

interface Salary {
    double earnings();

    double deductions();

    double bonus();
}

class Manager implements Salary {
    double basicSalary;

    Manager(double basicSalary) {
        this.basicSalary = basicSalary;
    }

    @Override
    public double earnings() {
        return basicSalary + (0.80 * basicSalary) + (0.15 * basicSalary);
    }

    @Override
    public double deductions() {
        return 0.12 * basicSalary;
    }

    @Override
    public double bonus() {
        throw new UnsupportedOperationException("Bonus method not implemented");
    }
}

class Substaff extends Manager {
    Substaff(double basicSalary) {
        super(basicSalary);
    }

    @Override
    public double bonus() {
        return 0.50 * basicSalary;
    }
}

public class l3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter basic salary: ");
        double basicSalary = sc.nextDouble();

        Substaff substaff = new Substaff(basicSalary);
        System.out.println("Earnings: " + substaff.earnings());
        System.out.println("Deductions: " + substaff.deductions());
        System.out.println("Bonus: " + substaff.bonus());
    }
}