package ex3.domain;

public class Animal {
    private int age;
    private  String name;

    protected String species;

    public Animal(int age){
        this.age = age;
        this.species = "feralCats";
    }

    public Animal(int age, String name){
        this.age = age;
        this.name = name;
    }

    public Animal(int age, String name, String species){
        this (age, name);//cheama constructorul cu aceste proprietati
        this.species = species;
    }

    @Override
    public String toString() {
        return "Animal: age- " + age + ", name - " + name + ", species - " + species;
    }

    public void eat(int food){
        System.out.println("This animal is eating " + food + "kg of food per day");
    }

    public double getAverageWeight(){
        return 100;
    }

}
