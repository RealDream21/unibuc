package exceptions;

public class HandleExceptionExamples {
    public static void main(String[] args) {
        //doTryCatch();
        //doTryFinally();
        //doTryCatchFinally();
        doTest();

    }

    private static void doTryCatch(){
        int[] arr = new int[5];
        try{
            arr[12] = 50;
        } catch (ArrayIndexOutOfBoundsException e){
            System.out.println("We caught an exception");
        }
        System.out.printf("Final of the method");
    }

    private static void doTryFinally(){
        int arr[] = new int[5];
        try{
            arr[12] = 50;
        }finally {
            System.out.println("Execute the final block");
        }
        System.out.println("Final of the method");
    }
    private static void doTryCatchFinally(){
        int arr[] = new int[5];
        try{
            arr[12] = 50;
        }catch(ArrayIndexOutOfBoundsException e){
            System.out.println("We caught an exception");
        }
        finally {
            System.out.println("Final of the method");
        }
    }

    private static void doTest(){
        int arr[] = new int[5];
        try{
            arr[12] = 50;
        }catch(ArrayIndexOutOfBoundsException | NullPointerException e){
            System.out.println("We caught an exception 1");
        }
        catch (Exception e){
            System.out.println("We caught an exception");
        }finally{
            System.out.println("Execute the final block");
        }
        System.out.println("Final of the method");
    }
}
