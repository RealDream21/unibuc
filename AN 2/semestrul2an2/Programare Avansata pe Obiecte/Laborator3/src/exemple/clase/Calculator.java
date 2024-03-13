package exemple.clase;

public class Calculator {

    public int suma(int a, int b)
    {
        return a + b;
    }

    public double suma(int a, double b)
    {
        return a + b;
    }

    public double suma(double a, double b)
    {
        return a + b;
    }

    public double suma(double a, double b, double c)
    {
        return a + b + c;
    }

    public static void main(String[] args) {
        Calculator calculator = new Calculator();
        System.out.println(calculator.suma(12, 15));
        System.out.println(calculator.suma(12, 12.7));
        System.out.println(calculator.suma(10.7, 16.8));
        System.out.println(calculator.suma(12.1, 12.3, 12.1));
    }

}
