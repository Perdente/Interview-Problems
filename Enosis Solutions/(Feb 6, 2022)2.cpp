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
int Pascal (int row, int column) {
  if (column == 0)
    return 1;
  if (row == column)
    return 1;
  return Pascal(row - 1, column - 1) + Pascal(row - 1, column);
}

void malena() {
    int n; cin >> n;
    cout << "Input is - " << n << '\n';

    cout << "Output ::: \n";
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cout << Pascal(i, j) << " ";
        }
        cout << '\n';
    }
}
/*
Input is - 6
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

// Recursive code to calculate Pascal's Triangle
int Pascal (int row, int column) {
  if (column == 0) return 1;
  if (row == column) return 1;
  return Pascal(row - 1, column - 1) + Pascal(row - 1, column);
}
// Converts a row from Pascal's Triangle from integer to a string
int rowLength(int row, int column) {
    int current_row;
    string current_row_char = "";
    stringstream out;
    for (int current_row = row; current_row <= row; ++current_row) {
        for (int c = 0; c <= row; ++c) {
            out << " " << Pascal(row, column) << " ";
        }
        current_row_char += out.str();
    }
    return current_row_char.length();
}

void malena() {
    int tot_row; cin >> tot_row;
    cout << "Input is - " << tot_row << '\n';
    cout << "Output - \n";
    // determination of how long the bottom row is
    int bottom_row;
    string bottom_row_char;
    stringstream out;
    for (int r = tot_row; r <= tot_row; ++r) {
        for (int c = 0; c <= r; ++c) {
            out << " " << Pascal(r, c) << " ";
        }
        bottom_row_char += out.str();
    }
    // Printing actual Pascal's Triangle
    for (int row = 0; row <= tot_row; ++row) {
        cout.width((bottom_row_char.length() - rowLength(row, 0)) / 2);
        for (int col = 0; col <= row; ++col) {
            cout << " " << Pascal(row, col) << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}

/*
Input is - 5
Output - 
         1 
        1  1 
      1  2  1 
     1  3  3  1 
   1  4  6  4  1 
 1  5  10  10  5  1 

*/






