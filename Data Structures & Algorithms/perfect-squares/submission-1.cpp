class Solution {
public:
    int solve(int val, vector<int>& dp){
        if(val == 0) return 0;
        int res = val;
        if(dp[val] != -1) return dp[val];
        for(int i = 1; i*i <= val ; i++){
            res = min(res, 1 + solve(val-i*i, dp));
        }
        return dp[val] = res;
    }
    int numSquares(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};