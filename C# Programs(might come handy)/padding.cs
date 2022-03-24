/******************************************************************************
                            Online C# Compiler.
                Code, Compile, Run and Debug C# program online.
Write your code in this editor and press "Run" button to execute it.
*******************************************************************************/

using System;
class HelloWorld {
  static void Main() {
    string str = Console.ReadLine();
    Console.WriteLine(str);
    string[] resArray = str.Split(" ");
    foreach (var s in resArray) {
        string temp = s.PadLeft(50, ' ');
        Console.WriteLine(temp);
    }
    str = "We are the champions. We create history and will keep repeating it :)";
    Console.WriteLine(str);
    string[] resArray1 = str.Split(" ");
    foreach (var s in resArray1) {
        string temp = s.PadRight(50, ' ');
        Console.WriteLine(temp);
    }
  }
  
}

/*
Input: Hello, Team Tigers. Congratulations on your Series win Against South Africa.
Output:
Hello, Team Tigers. Congratulations on your Series win Against South Africa.
                                            Hello,
                                              Team
                                           Tigers.
                                   Congratulations
                                                on
                                              your
                                            Series
                                               win
                                           Against
                                             South
                                           Africa.
We are the champions. We create history and will keep repeating it :)
We                                                
are                                               
the                                               
champions.                                        
We                                                
create                                            
history                                           
and                                               
will                                              
keep                                              
repeating                                         
it                                                
:)                                                

*/
