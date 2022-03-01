/*
Input:
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1
1 6 15 20 15 6 1

Output this pattern as center-aligned
*/

// Printing Pascal's Triangle Left Aligned - 
int dp[1000][1000];
int pascal_triangle(int row, int col) {
    if (col == 0 or row == col) return 1;
    if (dp[row][col] != -1) return dp[row][col];
    return dp[row][col] = pascal_triangle(row - 1, col - 1) + pascal_triangle(row - 1, col);
}

void malena() {
    int numRows; cin >> numRows;
    vector<vector<int>> ans(numRows);
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j <= i; ++j) {
            cout << pascal_triangle(i, j) << " ";
        }
        cout << '\n';
    }
}

/*
Input is - 7
Output ::: 
1 
1 1 
1 2 1 
1 3 3 1 
1 4 6 4 1 
1 5 10 10 5 1 
1 6 15 20 15 6 1 

*/


// Printing Pascal's Triangle Center Aligned

int dp[1000][1000];
int pascal_triangle(int row, int col) {
    if (col == 0 or row == col) return 1;
    if (dp[row][col] != -1) return dp[row][col];
    return dp[row][col] = pascal_triangle(row - 1, col - 1) + pascal_triangle(row - 1, col);
}

void malena() {
    int numRows; cin >> numRows;
    vector<vector<int>> ans(numRows);
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < numRows; ++i) {
        cout << string(numRows - i - 1, ' '); // printing spaces for each row
        for (int j = 0; j <= i; ++j) {
            cout << pascal_triangle(i, j) << " ";
        }
        cout << '\n';
    }
}
/*
Input is - 5
Output - 
         1          space - 5
        1  1        space - 4
      1  2  1       space - 3
     1  3  3  1     space - 2
   1  4  6  4  1    space - 1
 1  5  10  10  5  1 space - 0

*/






