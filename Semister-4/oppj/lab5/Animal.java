public class Animal {
    String name;

    public void eat() {
        System.out.println("I can eat");
    }
}

class Dog extends Animal {
    public void display() {
        System.out.println("My name is " + name); // Fixed typo in "iss" to "is"
    }
}

class Main {
    public static void main(String[] args) {
        Dog labrador = new Dog();
        labrador.name = "Rohu";
        labrador.display();
        labrador.eat(); // Call eat method
    }
}
