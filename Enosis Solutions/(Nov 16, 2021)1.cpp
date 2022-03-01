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
