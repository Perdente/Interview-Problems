/*
Given a string the interview asked to make each new line of the string center aligned. Each new line was identified by special character '\r\n'
*/

// Question is not clear, though maybe input is a paragraph of small latin letters and some special character '$' in it.
// Say our input is - 
// hello world $ How are you? $ Is it cold there?
// Our expected output would be - 
//                         hello world 
//                         How are you? 
//                         Is it cold there? 

void malena() {
    string s;
    getline(cin, s);
    stringstream str(s);
    string word;
    int width = 50; // here, width is orbitrary
    cout << string(width / 2, ' '); // each first word we create sufficient amount of width
    while (str >> word) {
        if (word == "$") {
            cout << '\n'; // when we interact with special character '$' then we have our new line.
            cout << string(width / 2 , ' '); // immediatly after that we create our new space
        }
        else {
            cout << word << " ";
        }
    }
}


/*


using System;
class HelloWorld {
  static void Main() {
      string text = Console.ReadLine();
      string[] res = text.Split(" $ ");
      foreach(var st in res) {
          Console.WriteLine(string.Format("{0}", centeredString(st, 100)));
      }
  }
    static string centeredString(string s, int width)
    {
        if (s.Length >= width)
        {
            return s;
        }
    
        int leftPadding = (width - s.Length) / 2;
        int rightPadding = width - s.Length - leftPadding;
    
        return new string(' ', leftPadding) + s + new string(' ', rightPadding);
    }
}
Input: hello world $ How are you? $ Is it cold there?
Output: 
                                            hello world                                             
                                            How are you?                                            
                                         Is it cold there?                       

*/
