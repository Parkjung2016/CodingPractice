using System;

namespace MyApp // Note: actual namespace depends on the project name.
{
    internal class Program
    {
       public static int[] arr = new int[41];
        static void Main(string[] args)
        {
            int count = int.Parse(Console.ReadLine());
         
            for (int i = 0; i < count; i++)
            {
                int x= int.Parse(Console.ReadLine());
                switch (x)
                {
                    case 0:
                        Console.WriteLine("1 0");
                        break;
                    case 1:
                        Console.WriteLine("0 1");
                        break;
                     default:
                        fibonacci(x);
                        Console.WriteLine($"{arr[x - 1]} {arr[x]}");
                        break;
                }

            }



        }

        public static int fibonacci(int n)
        {
            if (n <= 0)
            {
                arr[0] = 0;
                return 0;
            }
            else if (n == 1)
            {
                arr[1] = 1;

                return 1;
            }
            if (arr[n]!=0)
            {
                return arr[n];
            }
            else
            {
                return arr[n] = fibonacci(n - 1) + fibonacci(n - 2);
            }
        }
    }
}