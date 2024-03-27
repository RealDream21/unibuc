package abstractClasses.Domain;

public class Circle extends Shape{


    private static final double PI = 3.14;

    private double radius;

    public Circle(double radius){
        this.radius = radius;
    }

    @Override
    public double area() {
        return PI * Math.pow(radius, 2);
    }

    @Override
    public double perimeter() {
        return 2 * PI * radius;
    }
}
