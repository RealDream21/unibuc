package ex1;

public class Cat {
    String name;
    int age;
    Color color;
    public Cat(String name) {
        this.name = name;
    }

    public Cat(String name, int age){
        this.name = name;
        this.age = age;
    }

    public Cat(String name, int age, Color color)
    {
        this.name = name;
        this.age = age;
        this.color = color;
    }

    @Override
    public String toString(){
        return "Cat: name- " + name  + ", age- " + age + ", color- " + color.toString();
    }

    @Override
    public boolean equals(Object o){
        if (o == null)
            return false;

        if (o instanceof Cat){
            Cat cat = (Cat) o; //downcasting
            if(name.equals(cat.name) && age == cat.age){
                return this.name.equals(cat.name);
            }
        }
        else{
            return false;
        }
        return false;
    }
    @Override
    public int hashCode(){
        char[] letters = name.toCharArray();

        int sum = 0;
        for (char c:letters){
            sum += c;
        }
        return sum;
    }



}
