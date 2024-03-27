package abstractClasses.Domain;

public abstract class Shape {
    public abstract double area();

    public abstract double perimeter();

    public final void sayHello(){
        System.out.println("A new shape was created");
    }

    @Override
    public String toString() {
        return this.getClass().getSimpleName();
    }


}
