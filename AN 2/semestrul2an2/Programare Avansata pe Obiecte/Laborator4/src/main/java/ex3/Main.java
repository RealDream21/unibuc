package ex3;

import ex3.domain.Animal;
import ex3.domain.Zebra;
import ex3.service.ZooService;
import ex3.domain.Lion;

public class Main {
    public static void main(String[] args) {
        Animal animal = new Animal(5);
        Animal bear = new Animal(10, "bear");
        Animal parrot = new Animal(3, "parrot", "bird");


        System.out.println(animal);
        System.out.println(bear);
        System.out.println(parrot);

        Zebra zebra = new Zebra(5);
        System.out.println(zebra);
        System.out.println(new Zebra(7));
        System.out.println(new Zebra("zebra"));

        bear.eat(100);
        zebra.eat(45);

        ZooService zooService = new ZooService(15);
        zooService.addAnimal(bear);
        zooService.addAnimal(parrot);
        zooService.addAnimal(zebra);
        zooService.addAnimal(new Zebra("YoungZebra"));
        zooService.addAnimal(new Lion(5, "YoungLion", "feline"));

    }
}
