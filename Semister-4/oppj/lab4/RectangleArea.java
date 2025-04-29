import java.util.Scanner;

class Rectangle {
    private double length;
    private double breadth;

    // Default constructor
    public Rectangle() {
        length = 0;
        breadth = 0;
    }

    public Rectangle(double len, double brd) {
        length = len;
        breadth = brd;
    }

    public double calculateArea() {
        return length * breadth;
    }
}

public class RectangleArea {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        Rectangle defaultRectangle = new Rectangle();
        System.out.println("Area of rectangle with default dimensions: " + defaultRectangle.calculateArea());

        // Using the parameterized constructor
        System.out.print("Enter the length of the rectangle: ");
        double length = scanner.nextDouble();
        System.out.print("Enter the breadth of the rectangle: ");
        double breadth = scanner.nextDouble();

        Rectangle userRectangle = new Rectangle(length, breadth);
        System.out.println("Area of rectangle with user-defined dimensions: " + userRectangle.calculateArea());

        scanner.close();
    }
}