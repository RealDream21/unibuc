package exemple.arrays;

public class Exemplu1 {
    public static void main(String[] args) {
        //type [] name
        //type name[]

        int[] v1, v4;
        int v2[], v3[], v5;

        v1 = new int[10];
        int[] v6 = new int[6];
        int[] v7 = {1,2,3,4,5,6};

        //v7[0], v7[1], .... v7[5] = v7[length(v7)-1];
        for(int i = 0; i < v7.length; i++)
        {
            System.out.println(v7[i] + " ");
        }
        System.out.println();
        System.out.println(v7.length);

        v7[2] = 19;
        v7[15] = -1; //primim ArrayIndexOutOfBoundsException
        for(int i = 0; i < v7.length; i++)
        {
            System.out.println(v7[i] + " ");
        }

        double x1[] = new double[]{11, 12, 15, 26, 37.2, 19};
        double[] x2 = new double[]{};

        double sum = calculeazaSuma(x1);
        System.out.println(sum);
    }

    static double calculeazaSuma(double[] array)
    {
        double sum = 0;
        for(double i:array){
            sum += i;
        }
        return sum;
    }
}
