package interfaces.sintaxa;

public class MyClass implements MySecondInterface{

    @Override
    public void doSomething(){
        System.out.println("is doing something");
    }

    public void sayHello(){
        System.out.println("Hello from the class");
    }

    @Override
    public void doSomethingElse(){
    }
}

class Main{
    public static void main(String[] args) {
        MyClass object = new MyClass();
        object.doSomething();
        object.sayHello();
        MyInterface.anotherHello();
    }

}
