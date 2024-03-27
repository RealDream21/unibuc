package Builder;

import Builder.domain.Pizza;
import Builder.domain.Size;

public class Main {
    public static void main(String[] args) {
        Pizza myPizza = new Pizza.Builder("Quatro Stagioni")
                .withSize(Size.MEDIUM)
                .withOliveTopping(true)
                .withMozarellaTopping(true)
                .withPepperoniTopping(true)
                .withTomatoTopping(true)
                .build();

        Pizza mySecondPizza = new Pizza.Builder("Prosciuto Funghi")
                .withSize(Size.SMALL)
                .withOliveTopping(false)
                .withMozarellaTopping(true)
                .build();

        System.out.println(myPizza.toString());
        System.out.println(mySecondPizza.toString());
    }
}
