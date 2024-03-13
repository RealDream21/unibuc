package exemple.arrays;

public class Exemplu2 {
    static void afiseazaMatrice(int[][] array)
    {
        for(int i = 0; i < array.length; i++)
        {
            for(int j = 0; j < array[i].length; j++)
                System.out.print(array[i][j]);
            System.out.println();
        }
    }
    public static void main(String[] args) {
        int [][] a;
        int b [][];
        int[] c[], d;
        a = new int[3][3];
        int t[][] = new int[][]{{14}, {12, 13, 11}, {1}, {1, 2, 3, 4, 5, 6}};
        b = new int[3][];
        b[0] = new int[3];
        b[1] = new int [7];

        int n = 8;
        b[2] = new int[n];

//        afiseazaMatrice(b);
        afiseazaDinNouMatrice(b);
    }

    static void afiseazaDinNouMatrice(int array[][])
    {
        for(int[] row: array)
        {
            for(int elem: row){
                System.out.print(elem);
            }
            System.out.println();

        }

    }
}
