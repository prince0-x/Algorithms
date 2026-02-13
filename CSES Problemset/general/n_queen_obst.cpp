#include <bits/stdc++.h>
using namespace std;

int solutionCount = 0;
bool issafe(int r, int c, vector<string> &board) {
    for (int col = 0; col < c; col++)
        if (board[r][col] == '#') return false;
    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == '#') return false;
    for (int i = r, j = c; i < 8 && j >= 0; i++, j--)
        if (board[i][j] == '#') return false;
    return true;
}

void n_queen(int n, int c, vector<string> &board) {
    if (n == 0) {
        solutionCount++;
        return;
    }
    if (c >= 8) return;

    for (int r = 0; r < 8; r++) {
        if (board[r][c] != '*' && issafe(r, c, board)) {
            char prev = board[r][c];
            board[r][c] = '#';
            n_queen(n - 1, c + 1, board);
            board[r][c] = prev;
        }
    }
}

int main() {
    vector<string> board(8);
    for (int i = 0; i < 8; i++){
      cin >> board[i];
    }
    n_queen(8, 0, board);
    cout << solutionCount << "\n";
}
