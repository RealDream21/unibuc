package interfaces.comparable;

public class Cat implements Comparable<Cat>{

    public String name;
    public int age;

    public Cat(java.lang.String name, int age) {
        this.name = name;
        this.age = age;
    }

    public java.lang.String getName() {
        return name;
    }

    public void setName(java.lang.String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    @java.lang.Override
    public java.lang.String toString() {
        return "Cat{" +
                "name=" + name +
                ", age=" + age +
                '}';
    }

    @Override
    public int compareTo(Cat cat) {
        return this.age - cat.age;
    }
}
