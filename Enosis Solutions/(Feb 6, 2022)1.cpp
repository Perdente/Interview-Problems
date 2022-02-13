// Given a sentence as a string. Reverse the words keep the sequence and output the reversed word string. 
string s;
getline(cin, s);
stringstream strm(s);
string word;
while (strm >> word) {
    int n = word.size();
    for (int i = n - 1; i >= 0; --i) {
        cout << word[i];
    }
    cout << " ";
}
cout << '\n';
