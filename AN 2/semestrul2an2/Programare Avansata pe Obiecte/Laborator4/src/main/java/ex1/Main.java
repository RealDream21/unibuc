package ex1;

public class Main {
    public static void main(String[] args) {
        Cat cat1 = new Cat("tom", 1);
        Cat cat2 = new Cat("tom", 2);
        Cat cat3 = new Cat("tom", 2, Color.BLACK);

        System.out.println(cat1 == cat2);
        System.out.println(cat1.equals(cat2));

        System.out.println(cat3.toString());

        System.out.println(cat1.hashCode());
        System.out.println(cat2.hashCode());

    }
}
