/*Write an algorithm to reverse a string.*/ 
/*
Algorithm - 
1. Start
2. Declare all the variables ( integer and character type )
3. Enter the string to be reversed
4. Find out the length of string
5. Swap the position of array element using loop
6. Store the swapped position
7. Print the reversed string as console output
8. Stop
*/
string s; cin >> s;
int i = 0, j = s.size() - 1;
while (i < j) {
    char ch = s[i];
    s[i] = s[j];
    s[j] = ch;
    i++, j--;
}
cout << s << '\n';
