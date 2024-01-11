
namespace Laborator2
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");


            // TIPURILE DE DATE

            int nr = 100;
            string str = "Acesta este un text";
            double d = 12.35;
            char c = 'a';
            bool b = true;
            object obj = 100;

            Console.WriteLine("Numarul este " + nr);
            Console.WriteLine("Stringul este: " + str);
            Console.WriteLine("Numarul in virgula mobila este: " + d);
            Console.WriteLine("Caracterul este: " + c);
            Console.WriteLine("Valoarea de adevar este: " + b);
            Console.WriteLine("Obiectul este: " + obj);
        

            // CONVERSII IMPLICITE

            int nrInt = 10;

            // Metoda GetType() preia tipul de date
            Type tipNrInt = nrInt.GetType();

            // Conversie implicita
            double nrDouble = nrInt;

            // Se preia tipul
            Type tipNrDouble = nrDouble.GetType();

            // Afisare valori inainte de conversie
            Console.WriteLine("nrInt value: " + nrInt);
            Console.WriteLine("nrInt Type: " + tipNrInt);

            // Afisare valori dupa conversia implicita
            Console.WriteLine("nrDouble value: " + nrDouble);
            Console.WriteLine("nrDouble Type: " + tipNrDouble);


            // CONVERSII EXPLICITE

            double nDouble = 25.123;

            // Conversie explicita
            int nInt = (int)nDouble;

            // Afisarea valorii inainte de conversie
            Console.WriteLine("Valoarea inainte de conversie a fost: " + nDouble);

            // Afisarea valorii dupa conversie
            Console.WriteLine("Valoarea dupa conversie este: " + nInt);


            // CONVERSIE UTILIZAND PARSE()

            string st = "100";

            // tipul de date
            Type tip1 = st.GetType();

            // Se converteste tipul string in int
            int x = int.Parse(st);

            Type tip2 = x.GetType();

            Console.WriteLine("Valoarea initiala a fost: " + st);
            Console.WriteLine("A avut tipul: " + tip1);

            Console.WriteLine("Noua valoare dupa conversie este: " + x);
            Console.WriteLine("Valoarea dupa conversie are tipul: " + tip2);


            // CONVERSII FOLOSIND CLASA CONVERT
            int num = 25;

            Console.WriteLine("Valoare de tip int: " + num);

            // Se converteste valoarea int in stringul "25"
            string strConvert = Convert.ToString(num);

            Console.WriteLine("Valoarea dupa conversie " + strConvert);
            Console.WriteLine("Tipul dupa conversie: " + strConvert.GetType());

            // Conversie in Double
            Double doubleConvert = Convert.ToDouble(num);
            Console.WriteLine("Valoarea dupa conversie " + doubleConvert);
            Console.WriteLine("Tipul dupa conversie: " + doubleConvert.GetType());


            // NULLABLE

            int? num1 = null;
            int? num2 = 45;

            Console.WriteLine("Valorile sunt: {0}, {1}", num1, num2);


            // ARRAY

            int[] n = new int[11];

            for (int i = 0; i < 10; i++)
            {
                n[i] = i + 1;
            }
            for (int i = 0; i < 10; i++)
            {
                Console.WriteLine("Element[{0}] = {1}", i, n[i]);
            }
        }
    }
}




/*
// PROBLEMA 3

class Program
{
    static void Main(string[] args)
    {

        int n, temp, u, inv = 0;

        Console.Write("Introduceti numarul n: ");
        
        n = int.Parse(Console.ReadLine());

        temp = n;

        if (n < 10)
            Console.WriteLine("Numarul este palindrom");
        else
        {
            while (n != 0)
            {
                u = n % 10;
                inv = inv * 10 + u;
                n = n / 10;
            }

            if (inv == temp)
                Console.WriteLine("Numarul este palindrom");
            else
                Console.WriteLine("Numarul nu este palindrom");
        }
    }
}


*/

/*

// METODA 2  

class Program
{
    void Palindrom(int n)
    {
        int temp, u, inv = 0;

        temp = n;

        if (n < 10)
            Console.WriteLine("Numarul este palindrom");
        else
        {
            while (n != 0)
            {
                u = n % 10;
                inv = inv * 10 + u;
                n = n / 10;
            }

            if (inv == temp)
                Console.WriteLine("Numarul este palindrom");
            else
                Console.WriteLine("Numarul nu este palindrom");
        }
    }

    static void Main(string[] args)
    {
        Program p = new Program();

        Console.Write("Introduceti numarul n: ");

        int n = int.Parse(Console.ReadLine());

        p.Palindrom(n);

        // Metodele statice nu dispun de referinta this 
        // Metodele statice nu pot apela metodele din aceeasi clasa care nu sunt statice
        // Acest lucru este posibil doar prin intermediul unui obiect din clasa respectiva
    }
}


*/


/*

// Problema 4
// METODA 1

using System.Data;

class Paritate
{
    static void Main()
    {
        int n, i, ok;


        // presupunem ca vectorul are elementele de paritati diferite
        ok = 1;

        Console.Write("Numarul de elemente din vector este: ");
        n = int.Parse(Console.ReadLine());

        int[] v = new int[n];

        

        Console.Write("Elementele vectorului sunt: ");
        for (i = 0; i < n; i++)
        {
            
           v[i] = int.Parse(Console.ReadLine());

        }

        for (i = 0; i < n - 1 && ok == 1; i++)
        {
            // se verifica daca sunt de aceeasi paritate
            if (v[i] % 2 == v[i + 1] % 2)
            
                ok = 0;
        }

        if (ok == 1)
            Console.WriteLine("Elementele vectorului alterneaza ca paritate");
        else
            Console.WriteLine("Elementele vectorului nu alterneaza ca paritate");
    }
}


*/

/*

// Problema 4
// METODA 2

using System.Collections;
using System;
using System.Data;
using System.Globalization;

class Paritate
{
    static void Main()
    {
     
        // presupunem ca vectorul are elementele de paritati diferite
        int ok = 1;

        Console.Write("Elementele vectorului sunt: ");

        string[] s = Console.ReadLine().Split(' ');

        int[] v = new int[s.Length];

        for (int i = 0; i < s.Length; i++)
        {
            v[i] = int.Parse(s[i]);           
        }

        for (int j = 0; j < v.Length - 1 && ok == 1; j++)
        {
            if (v[j] % 2 == v[j+1] % 2)
            {
                ok = 0;
            }
        }

        if (ok == 1)
            Console.WriteLine("Elementele vectorului alterneaza ca paritate");
        else
            Console.WriteLine("Elementele vectorului nu alterneaza ca paritate");
    }
}

*/

/*
using Laborator2;
using System;

    class Program
    {
        static void Main(string[] args)
        {
            // Crearea unui obiect al clasei Employee
            Employee emp = new Employee(1, "Pop", "Lucian", 2500);

            // Apelarea metodei Index prin intermediul obiectului emp,
            // obiectul fiind o instanta a clasei Employee
            // Astfel se afiseaza detaliile angajatului
            emp.Index();

        }
    }

*/