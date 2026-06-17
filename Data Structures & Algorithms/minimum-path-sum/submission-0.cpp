class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i == 0 && j == 0) return grid[0][0];
        if(i < 0 || j < 0) return 1e9;
        if(dp[i][j] != -1) return dp[i][j];
        int up = solve(i-1, j, grid, dp) + grid[i][j];
        int left = solve(i, j-1, grid, dp) + grid[i][j];
        return dp[i][j] = min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return solve(m-1, n-1, grid, dp);

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        int mini = INT_MAX;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(i == 0 && j == 0) continue;
                else{
                    int up = 1e9, left = 1e9;
                    if(i > 0) up = dp[i-1][j] + grid[i][j];
                    if(j > 0) left = dp[i][j-1] + grid[i][j];
                    mini = min(up, left);
                    dp[i][j] = mini;
                }
            }
        }
        return dp[m-1][n-1];
    }
};