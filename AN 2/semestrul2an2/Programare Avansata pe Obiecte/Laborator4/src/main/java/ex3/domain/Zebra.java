package ex3.domain;

public class Zebra extends Animal{
    public Zebra(int age){
        super(age);
        this.species = "other";
    }

    public Zebra(){
        this(7);
    }

    public Zebra(String name){
        super(5, name);
    }

    @Override
    public void eat(int food){
        System.out.println("This zebra is eating " + food + "kg of food per day");
    }

    public double getAverageWeight(){
        return super.getAverageWeight() - 30;//chem metoda din superclasa
    }
}
