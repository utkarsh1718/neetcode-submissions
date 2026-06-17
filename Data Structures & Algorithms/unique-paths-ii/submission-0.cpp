class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& obstacleGrid){
        int up;
        int left;
        if(i >= 0 && j >= 0 && obstacleGrid[i][j] != 1){
            if(i == 0 && j == 0) return 1;
            if(i < 0 || j < 0) return 0;
            if(dp[i][j] != -1) return dp[i][j];
            up = solve(i-1, j, dp, obstacleGrid);
            left = solve(i, j-1, dp, obstacleGrid);
        }
        else{
            return 0;
        }
        return dp[i][j] = (up + left);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return solve(m-1, n-1, dp, obstacleGrid);
 
        // vector<vector<int>> dp(m, vector<int>(n));
        // if(obstacleGrid[0][0] == 1) return 0;
        // dp[0][0] = 1;

        // for(int i = 0; i < m; i++){
        //     for(int j = 0; j < n; j++){
                
        //         if(i == 0 && j == 0) continue;

        //         if(obstacleGrid[i][j] == 1){
        //             dp[i][j] = 0;
        //         }
        //         else{
        //             int up = 0, left = 0;
        //             if(i > 0) up = dp[i-1][j];
        //             if(j > 0) left = dp[i][j-1];
        //             dp[i][j] = up + left;
        //         }
        //     }
        // }

        // return dp[m-1][n-1];

        vector<int> prev(n, 0);

        for(int i = 0; i < m; i++){
            vector<int> temp(n, 0);
            for(int j = 0; j < n; j++){

                if(obstacleGrid[i][j] == 1) {
                    temp[j] = 0;
                }
                else if(i == 0 && j == 0) {
                    temp[j] = 1;
                }
                else {
                    int up = (i > 0) ? prev[j] : 0;
                    int left = (j > 0) ? temp[j-1] : 0;
                    temp[j] = up + left;
                }
            }
            prev = temp;
        }
        return prev[n-1];
    }
};