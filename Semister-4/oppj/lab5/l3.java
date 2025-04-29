class Apple {
    public void show() {
        System.out.println("This is the show method of Apple class.");
    }
}

class Banana extends Apple {
    @Override
    public void show() {
        System.out.println("This is the show method of Banana class.");
    }
}

class Cherry extends Apple {
    @Override
    public void show() {
        System.out.println("This is the show method of Cherry class.");
    }
}

public class l3 {
    public static void main(String[] args) {
        Apple appleRef;

        appleRef = new Apple();
        appleRef.show();

        appleRef = new Banana();
        appleRef.show();

        appleRef = new Cherry();
        appleRef.show();
    }
}