/*
Longest Common subsequence of string
*/

const int N = 3e3 + 5;
int dp[N][N];
string a, b;
int lcs_length(int i, int j) {
    int n = a.size(), m = b.size();
    if (i == n or j == m) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    if (a[i] == b[j]) return lcs_length(i + 1, j + 1) + 1;
    int x = 0, y = 0;
    x = lcs_length(i + 1, j);
    y = lcs_length(i, j + 1);
    return dp[i][j] = max(x, y);
}

void print_lcs(int i, int j) {
    int n = a.size(), m = b.size();
    if (i == n or j == m) return;
    if (a[i] == b[j]) {
        cout << a[i];
        print_lcs(i + 1, j + 1);
        return;
    }
    int x = 0, y = 0;
    x = lcs_length(i + 1, j);
    y = lcs_length(i, j + 1);
    if (x >= y) {
        print_lcs(i + 1, j);
    }else {
        print_lcs(i, j + 1);
    }
}

void malena() {
    cin >> a >> b;
    memset(dp, -1, sizeof dp);
    print_lcs(0, 0);
}









/*
using System;
class HelloWorld {
  static void Main() {
   string s = "LoserPartha";
   string t = "Partha";
   char[] a = s.ToCharArray();
   char[] b = t.ToCharArray();
   int ans = lcs_length(0, 0, a, b);
   Console.WriteLine(ans);
  }
  public static int lcs_length(int i, int j, char[] a, char[] b) {
    int n = a.Length;
    int m = b.Length;
    if (i == n || j == m) return 0;
    if (a[i] == b[j]) return lcs_length(i + 1, j + 1, a, b) + 1;
    int x = 0;
    int y = 0;
    x = lcs_length(i + 1, j, a, b);
    y = lcs_length(i, j + 1, a, b);
    return Math.Max(x, y);
  }
}
*/
