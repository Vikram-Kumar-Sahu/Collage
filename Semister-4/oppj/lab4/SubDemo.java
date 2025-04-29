public class SubDemo {


    static int sub(int a1, int b1) {
        int x = a1 - b1;
        return x; // Return the result
    }


    static int sub(int a1, int b1, int c1) {
        int y = a1 - b1 - c1;
        return y;
    }

    public static void main(String args[]) {
        int a = sub(5, 2);
        int b = sub(20, 10, 4);


        System.out.println("Result of sub(5, 2): " + a);
        System.out.println("Result of sub(20, 10, 4): " + b);
    }
}
