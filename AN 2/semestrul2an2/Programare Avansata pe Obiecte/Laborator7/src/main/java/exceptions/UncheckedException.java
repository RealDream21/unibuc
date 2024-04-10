package exceptions;

public class UncheckedException {
    public static void main(String[] args) {
        //ArrayIndexOutOfBoundsException
        int arr[] = new int[5];

        //arr[12] = 10;

        String s = "my string";

        //StringIndexOutOfBoundsException
//        char c = s.charAt(100);

//        String s1 = null;
////        System.out.println(s1.length());
//        if(s1 != null){
//            System.out.println(s.length());
//        }
//        else{
//            //throw an error
//        }

        int a = 123, b = 0;
//        divide(a, b);

        //NumberFormatException
//        int nr = Integer.parseInt("120d");


        //ClassCastException
        String str = "test";
//        Integer nr2 = (Integer)(str);
        Object obj = str;
        Integer nrObj = (Integer)obj;



    }

    public static int divide(int a, int b){
        if(b != 0){
            return a/b;
        }else{
            throw new IllegalArgumentException("B is zero, not allowed when dividing");
        }
    }

}
