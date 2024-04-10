package interfaces.generice;

public class CarProducer implements Producer<Car>{


    @Override
    public Car produce() {
        System.out.println("A new car was produced\n");
        return new Car();
    }
}
