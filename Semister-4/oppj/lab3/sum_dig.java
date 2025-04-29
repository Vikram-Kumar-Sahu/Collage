import java.util.Scanner;

public class sum_dig {
    public static void main(String[] args) {
        int e = 0, o = 0;

        Scanner x = new Scanner(System.in);
        int[][] arr = new int[3][3];
        int i, j, sl = 0, sr = 0;

        System.out.println("Enter the numbers for the 3x3 matrix:");
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                arr[i][j] = x.nextInt();
            }
        }

        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (i == j) {
                    sl += arr[i][j];
                }
                if (i + j == 2) {
                    sr += arr[i][j];
                }
            }
        }

        System.out.println("Left Diagonal: " + sl);
        System.out.println("Right Diagonal: " + sr);
        x.close();
    }
}
