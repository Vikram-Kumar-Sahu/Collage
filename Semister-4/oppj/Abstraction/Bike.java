abstract class MotorBike {
    abstract void brake();
}
class SuperBike extends MotorBike{
    public void brake(){
        System.out.println("SuperBike Brake");
    }
}
class MountainBike extends MotorBike{
    public void brake(){
        System.out.println("MountainBike Brake");
    }
}
class Bike{
    public static void main(String[] args){
        MountainBike b1= new MountainBike();
        b1.brake();
        SuperBike b2= new SuperBike();
        b2.brake();
    }
}
