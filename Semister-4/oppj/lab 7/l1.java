// class l1 {
//     public static void main(String[] args) {
//         try {
//             int data = 100 / 0;

//         } catch (ArithmeticException e) {
//             System.out.println(e);
//         }
//     }
// }
import java.util.Scanner;

public class l1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] array = new int[4];

        System.out.println("Enter 5 numbers (array size is 4):");
        try {
            for (int i = 0; i < 5; i++) {
                array[i] = sc.nextInt();
            }
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Exception in thread \"main\" " + e);
        }
    }
}
