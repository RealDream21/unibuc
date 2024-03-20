package ex2.domain;

public class Car extends Vehicle{//is A vehicle
    Engine engine;//car has An engine
    int seats;
    int doors;

    public Car(int registrationNumber, String model, String yearOfPurchase) {
        super(registrationNumber, model, yearOfPurchase);
        this.seats = 5;
        this.doors = 4;
    }

    public void printDetails() {
        System.out.println("Car: registrationNumber = " + registrationNumber +
                ", model = " + model +
                ", yearOfPurchase = " + yearOfPurchase +
                ", seats = " + seats +
                ", doors = " + doors);
    }


}
