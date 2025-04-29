import java.util.Scanner;
class plate{
    int length;
    int breath;
    plate(int length,int breath){
        this.length = length;
        this.breath = breath;
    }
    public void display(){
        System.err.println("Area of plate is: "+length*breath);
    }
}
class box extends plate{
    int height;
    box(int length,int breath,int height){
        super(length,breath);
        this.height = height;
    }
    @Override
    public void display(){
        System.out.println("Volume of box is: "+length*breath*height);
    }
}
class woodbox extends box{
    String type;
    woodbox(int length,int breath,int height,String type){
        super(length,breath,height);
        this.type = type;
    }
    @Override
    public void display(){
        System.out.println("Type of wood is: "+type);
    }
}


public class l2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int l = sc.nextInt();
        int b = sc.nextInt();
        int h = sc.nextInt();
        String type = sc.nextLine();
        woodbox w = new woodbox(l,b,h,type);
        w.display();
        // box b1 = new box(l,b,h);
        // b1.display();
        // plate p = new plate(l,b);
        // p.display();
    }
}
