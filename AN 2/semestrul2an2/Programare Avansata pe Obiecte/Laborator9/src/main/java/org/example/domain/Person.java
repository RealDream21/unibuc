package org.example.domain;

public class Person {
    private int id;
    String name;
    double age;

    public Person(int id, String name, double age){
        this.id = id;
        this.name = name;
        this.age = age;
    }

    public Person(String name, double age)
    {
        this(0, name, age);
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public double getAge() {
        return age;
    }

    public void setAge(double age) {
        this.age = age;
    }

    @Override
    public String toString() {
        return "Person{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", age=" + age +
                '}';
    }
}
