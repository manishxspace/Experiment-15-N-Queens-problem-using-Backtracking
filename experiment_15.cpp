#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<string>& board, int n) {
// Check upper-left diagonal
for (int i = row - 1, j = col - 1;
i >= 0 && j >= 0; i--, j--) {
if (board[i][j] == 'Q')
return false;
}

// Check the same column
for (int i = row - 1; i >= 0; i--) {
    if (board[i][col] == 'Q')
        return false;
}

// Check upper-right diagonal
for (int i = row - 1, j = col + 1;
     i >= 0 && j < n; i--, j++) {
    if (board[i][j] == 'Q')
        return false;
}

return true;

}

bool solve(int row, vector<string>& board, int n) {
// All queens have been placed
if (row == n)
return true;

for (int col = 0; col < n; col++) {
    if (isSafe(row, col, board, n)) {
        board[row][col] = 'Q';

        if (solve(row + 1, board, n))
            return true;

        // Backtrack
        board[row][col] = '.';
    }
}

return false;

}

int main() {
int n;
cout << "Enter value of N: ";
cin >> n;

if (n <= 0) {
    cout << "N must be positive.\n";
    return 0;
}

vector<string> board(n, string(n, '.'));

if (solve(0, board, n)) {
    cout << "One valid solution:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
} else {
    cout << "No solution exists for N = " << n << ".\n";
}

return 0;

}
