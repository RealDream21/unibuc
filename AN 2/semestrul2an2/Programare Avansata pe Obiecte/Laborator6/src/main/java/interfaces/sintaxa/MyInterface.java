package interfaces.sintaxa;

public abstract interface MyInterface {

    public final static double PI = 3.14;

    public abstract void doSomething();

    public default void sayHello(){
        System.out.println("Hello!");
    }

    public static void anotherHello(){
        System.out.println("Another Hello!");
    }

    private void test(){
        System.out.println("Private teste");
    }

    private static void anotherTest(){
        System.out.println("Private static test");
    }


}
