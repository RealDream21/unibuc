package exemple.clase;

public class Cat2 {
    //private, default,
    private String name;
    private int age;

    public Cat2(){}

    public Cat2(String name, int age)
    {
        this.name = name;
        this.age = age;
    }

    public int getAge()
    {
        return this.age;
    }

    public String getName()
    {
        return this.name;
    }

    public void setName(String name)
    {
        this.name = name;
    }
}

class MainCat2{
    public static void main(String[] args) {
        Cat2 cat = new Cat2("Tom", 5);

        System.out.println(cat.getAge());
        System.out.println();
        cat.setName("Tommy");
        System.out.println(cat.getName());
    }

}
