class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& dp){
        if(i == 0 && j == 0) return 0;
        if(i < 0 || j < 0) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int up = solve(i-1, j, dp);
        int left = solve(i, j-1, dp);
        return dp[i][j] = (up + left);
    }
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return solve(m-1, n-1, dp);
 
        // vector<vector<int>> dp(m, vector<int>(n));
        // dp[0][0] = 1;
        // for(int i = 0 ; i < m ; i++){
        //     for(int j = 0 ; j < n ; j++){
        //         if(i == 0 && j == 0) dp[0][0] = 1;
        //         else{
        //             int up = 0, left = 0;
        //             if(i > 0) up = dp[i-1][j];
        //             if(j > 0) left = dp[i][j-1];
        //             dp[i][j] = up+left;
        //         }
        //     }
        // }
        // return dp[m-1][n-1];

        vector<int> prev(n, 0);
        for(int i = 0 ; i < m ; i++){
            vector<int> temp(n, 0);
            for(int j = 0 ; j < n ; j++){
                if(i == 0 && j == 0) temp[j] = 1;
                else{
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