class Solution {
public:
    int solve(int num, int original, vector<int>& dp){
        if(num == 1) return 1;
        int res = (num == original) ? 0 : num;
        if(dp[num] != -1) return dp[num];
        for(int i = 1; i < num ; i++){
            int val = solve(i, original, dp) * solve(num-i,original, dp);
            res = max(res, val);
        }
        return dp[num] = res;
    }
    int integerBreak(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, n, dp);
    }
};