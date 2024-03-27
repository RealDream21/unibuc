package siruriDeCaractere;

public class Exemplu1 {
    public static void main(String[] args) {
        String empty1 = "";
        String empty2 = new String();

        String s1 = "hello";
        String s2 = new String("hello");
        String s3 = new String(s2);
        char[] ch = {'h', 'e', 'l', 'l', 'o'};
        String s4 = new String(ch);
        String s5 = "hello";

        System.out.println(s1);
        System.out.println(s2);
        System.out.println(s3);
        System.out.println(s4);

        System.out.println(s1 == s2);
        System.out.println(s1 == s4);
        System.out.println(s1 == s5);

        System.out.println("len = " + s1.length());
        System.out.println(empty1.isEmpty());
        System.out.println(s1.isEmpty());

        System.out.println(s1.substring(3));
        System.out.println("hello".substring(3, s1.length()));
        System.out.println(s1.substring(0, 3)); // se opreste inainte de 3
//        System.out.println(s1.substring(3, 15)); //java.lang.StringIndexOutOfBoundsException

        System.out.println(s1.charAt(2));
        System.out.println(s1.indexOf('l'));
        System.out.println(s1.lastIndexOf('l'));

        s1 = s1.toUpperCase(); //.toLowerCase
        System.out.println(s1);

        s1 = s1.concat("PAO");
        System.out.println(s1);

        String s6 = "abc"  + "def";
        System.out.println(s6);

        String result = new String();
        char[] vowels = {'a', 'e', 'i', 'o', 'u'};

        for(char vowel: vowels) {
            result = result.concat(String.valueOf(vowel));// char -> string
        }
        System.out.println(result);





    }

}
