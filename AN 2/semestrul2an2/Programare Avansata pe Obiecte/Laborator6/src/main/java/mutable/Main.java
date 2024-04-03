package mutable;

import mutable.domain.ImmutablePerson;
import mutable.domain.MutableDateOfBirth;

public class Main {
    public static void main(String[] args) {

        MutableDateOfBirth mutableDateOfBirth = new MutableDateOfBirth(1, 1, 2000);
        ImmutablePerson person = new ImmutablePerson(1, "Gigel", mutableDateOfBirth);
        System.out.println(person);
        mutableDateOfBirth.setYear(2024);
        System.out.println(person);


    }
}
