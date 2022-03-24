
/******************************************************************************

                            Online C# Compiler.
                Code, Compile, Run and Debug C# program online.
Write your code in this editor and press "Run" button to execute it.

*******************************************************************************/

using System;
class HelloWorld {
  static void Main() {
    string test = "LoserShit";
    test = test.ToLower();
    for (int i = 0; i < test.Length; ++i) {
        Console.Write(test[i] + " ");
    }
  }
  
}
