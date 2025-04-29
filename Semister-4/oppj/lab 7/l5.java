public class l5 {

    public static void main(String[] args) {
        int numerator = 10;
        int denominator = 0;
        int result = 0;

        try {
            // Attempt to perform division
            result = numerator / denominator;
        } catch (ArithmeticException e) {
            // Catch the ArithmeticException
            System.out.println("ArithmeticException caught: " + e.getMessage());
        } finally {
            // This block will always execute
            System.out.println("Finally block executed.");
        }

        // Print the result (if no exception occurred)
        System.out.println("Result: " + result);
    }
}