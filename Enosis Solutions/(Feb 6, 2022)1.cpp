// Given a sentence as a string. Reverse the words keep the sequence and output the reversed word string. 
string s;
getline(cin, s);
stringstream strm(s);
string word;
while (strm >> word) {
    int i = 0, j = word.size() - 1;
    while (i < j) {
        char ch = word[i];
        word[i] = word[j];
        word[j] = ch;
        i++, j--;
    }
    cout << word << " ";
}
cout << '\n';




/*
using System;
class HelloWorld {
  static void Main() {
    string line = Console.ReadLine();
    foreach (var str in line.Split(' ')) {
        Console.Write(str + " ");
        char[] charArray = str.ToCharArray();
        int i = 0, j = str.Length - 1;
        while (i < j) {
            char ch = charArray[i];
            charArray[i] = charArray[j];
            charArray[j] = ch;
            i++; j--;
        }
        Console.WriteLine(charArray);
    }
  }
}

Input: Hello madam. How are you loser? You fucking king of shit.
Output: 
Hello olleH
madam. .madam
How woH
are era
you uoy
loser? ?resol
You uoY
fucking gnikcuf
king gnik
of fo
shit. .tihs
*/
