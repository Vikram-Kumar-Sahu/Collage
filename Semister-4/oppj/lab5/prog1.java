import java.util.Scanner;

class Plastic2D {
    double length, width; // Dimensions for the 2D sheet
    static final double COST_PER_SQUARE_FT = 40; // Cost per square foot

    // Constructor for 2D dimensions
    public Plastic2D(double length, double width) {
        this.length = length;
        this.width = width;
    }

    // Method to calculate the cost of the 2D sheet
    public double calculateCost() {
        double area = length * width;
        return area * COST_PER_SQUARE_FT;
    }
}

class Plastic3D extends Plastic2D {
    double height; // Additional dimension for the 3D box
    static final double COST_PER_CUBIC_FT = 60; // Cost per cubic foot

    // Constructor for 3D dimensions
    public Plastic3D(double length, double width, double height) {
        super(length, width); // Call parent class constructor for length and width
        this.height = height;
    }

    // Method to calculate the cost of the 3D box
    @Override
    public double calculateCost() {
        double volume = length * width * height;
        return volume * COST_PER_CUBIC_FT;
    }
}

public class prog1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter the type of plastic (2D/3D): ");
        String type = scanner.nextLine().trim();

        if (type.equalsIgnoreCase("2D")) {
            System.out.print("Enter length (ft): ");
            double length = scanner.nextDouble();

            System.out.print("Enter width (ft): ");
            double width = scanner.nextDouble();

            Plastic2D sheet = new Plastic2D(length, width);
            System.out.println("The cost of the 2D sheet is: Rs " + sheet.calculateCost());
        } else if (type.equalsIgnoreCase("3D")) {
            System.out.print("Enter length (ft): ");
            double length = scanner.nextDouble();

            System.out.print("Enter width (ft): ");
            double width = scanner.nextDouble();

            System.out.print("Enter height (ft): ");
            double height = scanner.nextDouble();

            Plastic3D box = new Plastic3D(length, width, height);
            System.out.println("The cost of the 3D box is: Rs " + box.calculateCost());
        } else {
            System.out.println("Invalid type of plastic entered. Please enter either '2D' or '3D'.");
        }

        scanner.close();
    }
}
