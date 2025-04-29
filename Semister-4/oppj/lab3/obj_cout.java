public class obj_cout {
    public static int count;


    public obj_cout() {
        count++;
    }

    public static void main(String[] args) {
        obj_cout ob1 = new obj_cout();
        obj_cout ob2 = new obj_cout();
        obj_cout ob3 = new obj_cout();
        obj_cout ob4 = new obj_cout();
        obj_cout ob5 = new obj_cout();

        System.out.println("Total number of objects: " + obj_cout.count);
    }
}
