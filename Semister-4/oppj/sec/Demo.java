import java.util.*;

class box {
    int length, width, height;

    box(int length, int width, int height) {
        this.length = length;
        this.width = width;
        this.height = height;
    }

    double volume() {
        return (length * width * height);
    }
}

public class Demo {
    public static void main(String[] args) {
        Scanner x = new Scanner(System.in);
        System.out.println("Enter the length, width, and height:");
        int l = x.nextInt();
        int w = x.nextInt();
        int h = x.nextInt();
        box b = new box(l, w, h);
        System.out.println("The volume is " + b.volume());
    }
}
