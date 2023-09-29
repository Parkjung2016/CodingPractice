using System;

namespace MyApp // Note: actual namespace depends on the project name.
{
    internal class Program
    {
      static  readonly byte bag_3KG = 3;
        static readonly byte bag_5KG = 5;
        static void Main(string[] args)
        {
            int count = int.Parse(Console.ReadLine());
            int result = 0;
            while(count >= 0)
            {
                if (count % 5==0)
                {
                    result += (count / 5);
                    Console.WriteLine(result);
                    return;
                }
                count -= bag_3KG;
                result++;


            }
            Console.WriteLine(-1);

        }
    }
}