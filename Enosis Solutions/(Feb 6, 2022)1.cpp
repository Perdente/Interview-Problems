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
