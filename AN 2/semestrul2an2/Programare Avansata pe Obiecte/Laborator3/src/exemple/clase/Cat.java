package exemple.clase;

public class Cat {
    String name;
    int age;

    static int numberOfCats = 0;
    public Cat() {
        System.out.println("This was the first created cat!");
        numberOfCats++;
    }


    public Cat(String name, int age) {
        this.age = age;
        this.name = name;
        System.out.println("This was a cat with properties");
        numberOfCats++;
    }

    public String displayCat(){
        return "Cat: name = " + this.name + ", age = " + this.age;
    }

    @Override
    public String toString(){
        return "Cat: name = " + this.name + ", age = " + this.age;
    }

}

class MainCat{
    public static void main(String[] args) {
        Cat cat = new Cat();
        System.out.println(cat + " " + cat.name + " " + cat.age);
        System.out.println(Cat.numberOfCats);

        Cat cat2 = new Cat("Tom", 3);
        System.out.println(cat2.displayCat());

        cat2.name = "StillTom";
        System.out.println(cat2.toString());

    }

}
