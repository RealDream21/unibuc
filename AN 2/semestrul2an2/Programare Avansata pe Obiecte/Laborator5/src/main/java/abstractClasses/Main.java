package abstractClasses;

import abstractClasses.Domain.Shape;
import abstractClasses.Domain.Circle;
import abstractClasses.Domain.Rectangle;

import java.awt.*;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Rectangle rectangle = new Rectangle(10, 12);
        System.out.println(rectangle.area());
        System.out.println(rectangle.perimeter());

        Circle circle = new Circle(10);
        System.out.println(circle.area());
        System.out.println(circle.perimeter());

        Shape[] shapes = new Shape[3];
        shapes[0] = rectangle;
        shapes[1] = circle;

        System.out.println(Arrays.toString(shapes));
        circle.sayHello();
        rectangle.sayHello();


    }
}
