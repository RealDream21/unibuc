package exemple.arrays;

import java.util.Arrays;

public class Exemplu3 {
    public static void main(String[] args) {
        int[] array1 = {67, 22, 12, 3, 155};
        int[] array11 = {5, 4, 3, 2, 1};
        int[] array2 = new int[5];
        String[] array3 = {"ana", "john", "123", "Ana"};

        for(int elem:array1){
            System.out.println(elem + " ");
        }
        System.out.println();
        System.out.println(Arrays.toString(array1));

        Arrays.sort(array1);
        System.out.println(Arrays.toString(array1));

        Arrays.sort(array11, 0, 3);

        Arrays.fill(array2, 15);
        System.out.println(Arrays.toString(array2));

        int elementSearched = 22;
        //vectorul trebuie sa fi fost sortat inainte
        System.out.println(Arrays.binarySearch(array1, elementSearched));
        System.out.println(Arrays.binarySearch(array1,0, 3, elementSearched)); //cauta intre [start, end)
        System.out.println(Arrays.binarySearch(array1, 15));//spune pe ce pozitie ar trebui sa se gaseasca elem in vectorul sortat
        System.out.println(Arrays.binarySearch(array1, 500));

        System.out.println(Arrays.toString(array1));
        System.out.println(Arrays.toString(array11));
        System.out.println(Arrays.compare(array1, array11));//primul array este mai mic dpdv lexicografic decat al doilea
        System.out.println(Arrays.compare(array11, array1));//primul array este mai mare dpdv lexicografic decat al doilea

    }
}
