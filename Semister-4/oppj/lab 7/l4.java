class CheckArgument extends Exception {
    public CheckArgument(String message) {
        super(message);
    }
}

public class l4 {
    public static void main(String[] args) {
        try {
            if (args.length < 4) {
                throw new CheckArgument("Number of arguments is less than four");
            }

            int sumOfSquares = 0;
            for (int i = 0; i < 4; i++) {
                int num = Integer.parseInt(args[i]);
                sumOfSquares += num * num;
            }

            System.out.println("Output: " + sumOfSquares);
        } catch (CheckArgument e) {
            System.out.println("Exception occurred - " + e);
        } catch (NumberFormatException e) {
            System.out.println("Exception occurred - Invalid number format");
        }
    }
}