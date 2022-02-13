/*
Find most frequent and 2nd most frequent small letter from a given string
*/

string s; cin >> s;
int ar[26];
memset(ar, 0, sizeof ar);
int ma = 0;
for (auto ch: s) {
    ar[ch - 'a']++;
    ma = max(ma, ar[ch - 'a']);
}
int ma1 = 0;
for (int i = 0; i < 26; ++i) {
    if (ar[i] == ma) continue;
    ma1 = max (ma1, ar[i]);
}
cout << ma << " " << ma1 << '\n';
