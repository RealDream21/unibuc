package ex2.domain;

public class Vehicle {
    protected int registrationNumber;
    protected String model;
    protected String yearOfPurchase;

    public Vehicle(int registrationNumber, String model, String yearOfPurchase) {
        this.registrationNumber = registrationNumber;
        this.model = model;
        this.yearOfPurchase = yearOfPurchase;
    }
    public String getModel() {
        return this.model;
    }

}
