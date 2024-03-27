package ex3.service;

import ex3.domain.Animal;

public class ZooService {

    Animal[] animals;
    private int lastIndex;

    private int maximNoOfAnimals;

    public ZooService(int maximNoOfAnimals){
        this.animals = new Animal[maximNoOfAnimals];
        this.lastIndex = 0;
        this.maximNoOfAnimals = maximNoOfAnimals;
    }

    public void addAnimal(Animal animal){
        if(lastIndex < animals.length){
            animals[lastIndex] = animal;
            System.out.println("Added animal " + animal.getClass() + " at index " + lastIndex);
            lastIndex++;
        }
        else{
            //print a message, print an error, throw an exception
            throw new RuntimeException("too many animals were added");
        }

    }

}
