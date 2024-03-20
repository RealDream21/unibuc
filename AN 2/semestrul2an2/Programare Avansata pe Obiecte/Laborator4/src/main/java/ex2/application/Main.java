package ex2.application;

import ex2.domain.Car;
import ex2.domain.Bus;
import ex2.domain.Vehicle;

public class Main {
    public static void main(String[] args) {
        Car car = new Car(1, "A6", "2024");
        car.printDetails();

        Bus bus = new Bus(2, "Mercedes", "2009");
        bus.printDetails();

        Vehicle vehicle = new Vehicle(3, "bike", "2024");

        System.out.println(vehicle.toString());
        System.out.println(vehicle.getModel());


        Car car2 = new Bus(4, "123", "1234");
        car2.printDetails();

//        Car car3 = new Vehicle(5, "123", "1234")

    }
}
