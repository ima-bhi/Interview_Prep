class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        //In this -> we only do downward - update first row -> 1,2,6
        for (int i = 1; i < m; i++) {
            grid[i][0] += grid[i - 1][0];
        }

        // in this -> we only take right  -- 1,4,5
        for (int j = 1; j < n; j++) {
            grid[0][j] += grid[0][j - 1];
        }

        // here we update array value as per the min
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }

        return grid[m - 1][n - 1];
    }
};