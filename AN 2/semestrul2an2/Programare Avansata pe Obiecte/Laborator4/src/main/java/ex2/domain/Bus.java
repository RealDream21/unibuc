package ex2.domain;

public class Bus extends Car{
//    int seats;
//    int doors;

    public Bus(int registrationNumber, String model, String yearOfPurchase){
        super(registrationNumber, model, yearOfPurchase);
        this.seats = 50;
        this.doors = 3;
    }
    @Override
    public void printDetails() {
        System.out.println("Bus: registrationNumber = " + registrationNumber +
                ", model = " + model +
                ", yearOfPurchase = " + yearOfPurchase +
                ", seats = " + seats +
                ", doors = " + doors);
    }
}
