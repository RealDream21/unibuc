// See https://aka.ms/new-console-template for more information

namespace Laborator
{
    class Program
    {

        bool AlternareParitate(int[] v)
        {
            for (int i = 0; i < v.Length - 1; i++)
                if (v[i] % 2 == v[i + 1] % 2)
                    return false;
            return true;
        }

        bool Palindrom(int n)
        {
            if (n == 0) return true;
            int aux = n;
            int reversed = 0;
            while (n != 0)
            {
                reversed = reversed * 10 + n % 10;
                n /= 10;
            }
            return (aux == reversed);
        }
        static void Main(string[] args)
        {
            Program p = new Program();
            int n;
            Console.Write("Dati numarul de numere: ");
            n = int.Parse(Console.ReadLine());
            int[] v = new int[n];
            for (int i = 0; i < n; i++)
                v[i] = int.Parse(Console.ReadLine());
            Console.WriteLine(p.AlternareParitate(v));
            return;
        }
    }
}
