package abstractClasses.Domain;

public class Rectangle extends Shape{



    private  double length, height;

    public Rectangle(double length, double height)
    {
        this.length = length;
        this.height = height;
    }
    @Override
    public double area() {
        return length * height;

    }

    @Override
    public double perimeter() {
        return 2 * length + 2 * height;
    }
}
