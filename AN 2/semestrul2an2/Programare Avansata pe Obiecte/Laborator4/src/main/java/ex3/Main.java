package ex3;

import ex3.domain.Animal;
import ex3.domain.Zebra;

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



    }

}
