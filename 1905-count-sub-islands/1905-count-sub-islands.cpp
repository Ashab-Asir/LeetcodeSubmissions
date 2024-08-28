class Solution {
public:
    int solve(int i, int j, int n, int m, vector<vector<int>>& dp, vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        dp[i][j] = 1;
        int ans = 1;

        if (i < n - 1 && grid2[i + 1][j] == 1 && dp[i + 1][j] == 0) {
            ans &= solve(i + 1, j, n, m, dp, grid1, grid2);
        }
        if (i > 0 && grid2[i - 1][j] == 1 && dp[i - 1][j] == 0) {
            ans &= solve(i - 1, j, n, m, dp, grid1, grid2);
        }
        if (j < m - 1 && grid2[i][j + 1] == 1 && dp[i][j + 1] == 0) {
            ans &= solve(i, j + 1, n, m, dp, grid1, grid2);
        }
        if (j > 0 && grid2[i][j - 1] == 1 && dp[i][j - 1] == 0) {
            ans &= solve(i, j - 1, n, m, dp, grid1, grid2);
        }
        ans &= grid1[i][j];

        return ans;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dp[i][j] == 0 && grid2[i][j] == 1) {
                    ans += solve(i, j, n, m, dp, grid1, grid2);
                }
            }
        }
        return ans;
    }
};