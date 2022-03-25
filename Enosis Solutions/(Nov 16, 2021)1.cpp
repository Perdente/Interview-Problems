/*
Find a string is anagram or not?
An anagram of a string is another string that contains the same characters, only the order of characters can be different.
For example, “abcd” and “dabc” are an anagram of each other.
*/
int arr[26];
void malena() {
    string s, t; cin >> s >> t;
    for (auto ch: s) arr[ch - 'a']++;
    for (auto ch: t) arr[ch - 'a']--;
    for (int i = 0; i < 26; ++i) {
        if (arr[i]) {cout << "No" << endl; return;}
    }
    cout << "Yes\n";
}



/*
/******************************************************************************

                            Online C# Compiler.
                Code, Compile, Run and Debug C# program online.
Write your code in this editor and press "Run" button to execute it.

*******************************************************************************/

using System;
class HelloWorld {
  static void Main() {
    int[] arr = new int[26];
    string s = "maddam";
    string t = "mdadam";
    Console.WriteLine($"First string is = {s}");
    Console.WriteLine($"Second string is = {t}");
    char[] sc = s.ToCharArray();
    char[] tc = t.ToCharArray();
    
    foreach (var ch in sc) {
        if (arr[ch - 'a'] == 0) arr[ch - 'a'] = 1;
        else arr[ch - 'a']++;
    }
    
    foreach (var ch in tc) {
        if (arr[ch - 'a'] >= 1) arr[ch - 'a']--;
    }
    bool flag = true;
    foreach (var st in arr) {
        if (st >= 1) flag = false;
    }
    if (flag) Console.WriteLine("Anagram");
    else Console.WriteLine("Anagram");
  }
}

*/
