/******************************************************************************

                            Online C# Compiler.
                Code, Compile, Run and Debug C# program online.
Write your code in this editor and press "Run" button to execute it.

*******************************************************************************/

using System;
class HelloWorld {
  static void Main() {
    int[] arr = new int[] {5, 6, 8, 1, 2};
    
    string res = String.Concat(arr);
    Console.WriteLine(res);
    
    res = String.Join(", ", arr);
    Console.WriteLine(res);
    
    string test = "John, Tim, Mary, Sue, Bob, Jane";
    string[] resultArray = test.Split(", ");
    foreach (var str in resultArray) {
        Console.WriteLine(str);
    }
    
    string s = "   hello     ";
    s = s. Trim();
    Console.WriteLine(s);
  }
  
}
