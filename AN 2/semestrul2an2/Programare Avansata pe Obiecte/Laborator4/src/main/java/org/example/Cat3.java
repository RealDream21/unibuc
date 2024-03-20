package org.example;

public class Cat3 {
    public Cat3(){
        System.out.println("default constructor");
    }
    public Cat3(String name){
        System.out.println("constructor " + name);
    }

    static{
        //Apelat la constructia in memorie a clasei
        System.out.println("this is my static constructor");
    }

    static{
        System.out.println("This is my second static constructor");
    }

    {
        System.out.println("this is my first instance of the cat");
    }

}

class MainCat3{
    public static void main(String[] args) {
        new Cat3();
        new Cat3("PAO");
    }
}
