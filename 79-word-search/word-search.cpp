#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int r, int c, int idx, vector<vector<char>>& board, string& word) {

        // If all characters matched
        if (idx == word.size())
            return true;

        // Boundary + mismatch check
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() ||
            board[r][c] != word[idx])
            return false;

        // Mark current cell as visited
        char temp = board[r][c];
        board[r][c] = '#';

        // Explore 4 directions
        bool found = dfs(r + 1, c, idx + 1, board, word) ||
                     dfs(r - 1, c, idx + 1, board, word) ||
                     dfs(r, c + 1, idx + 1, board, word) ||
                     dfs(r, c - 1, idx + 1, board, word);

        // Backtrack (restore cell)
        board[r][c] = temp;
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        // Try each cell as starting point
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(i, j, 0, board, word))
                        return true;
                }
            }
        }
        return false;
    }
};
