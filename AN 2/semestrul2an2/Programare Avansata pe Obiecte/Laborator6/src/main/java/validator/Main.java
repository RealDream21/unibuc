package validator;

import validator.domain.Person;
import validator.validator.PersonValidator;

public class Main {
    public static void main(String[] args) {
        PersonValidator personValidator = new PersonValidator();

        Person person1 = new Person("Ionescu", "Gigel", "0725670003", 40);
        Person person2 = new Person("ionescu", "Gigel", "0725670004", 40);
        Person person3 = new Person("Ionescu", "", "0725670003", 40);
        Person person4 = new Person("Ionescu", "Gigel", "071", 40);
        Person person5 = new Person("Ionescu", "Gigel", "0758912841594812398131", 40);
        Person person6 = new Person("Ionescu", "Gigel", "0258912841594812398131", 40);
        Person person7 = new Person("Ionescu", "Gigel", "0725670003", 6);

        Person[] persons = new Person[]{person1, person2, person3, person4, person5, person6, person7};

        for(Person person: persons){
            personValidator.validate(person);
        }

        System.out.println("Error messages: ");

        for(Person person: persons){
            String message = personValidator.validateWithErrorMessages(person);
            System.out.println(message + " " + person);
        }

    }
}
