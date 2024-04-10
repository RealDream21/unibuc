package interfaces.functionalInterfaces;

public class Calculator {
    public static void main(String[] args) {
        Function diffFunction = (int a, int b) -> a - b;
        System.out.println(diffFunction.apply(10, 8));

        Function multiplyFunction = (int a, int b) -> {
            return a * b;
        };
        System.out.println(multiplyFunction.apply(10, 20));


        SumFunction sumFunction = new SumFunction();
        System.out.println(sumFunction.apply(10, 17));

        calculate(multiplyFunction);
        calculate((a, b) -> a % b);
        calculate((a, b) -> a * b);

    }

    private static void calculate(Function function){
        System.out.println(function.apply(20, 11));
    }

}
