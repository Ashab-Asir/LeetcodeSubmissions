class Solution {
private:
    void dfs(int i, int j, vector<vector<int>>& grid, int& sum, int& maxSum) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0 || grid[i][j] == -1)
            return;
        int cellValue = grid[i][j];
        sum += cellValue;
        maxSum = max(maxSum, sum); 
        grid[i][j] = -1; 
        dfs(i, j + 1, grid, sum, maxSum); 
        dfs(i + 1, j, grid, sum, maxSum); 
        dfs(i - 1, j, grid, sum, maxSum); 
        dfs(i, j - 1, grid, sum, maxSum); 
        sum -= cellValue;
        grid[i][j] = cellValue;
    }

public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int maxSum = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] != -1 && grid[i][j] != 0) {
                    int sum = 0;
                    dfs(i, j, grid, sum, maxSum);
                }
            }
        }
        return maxSum;
    }
};