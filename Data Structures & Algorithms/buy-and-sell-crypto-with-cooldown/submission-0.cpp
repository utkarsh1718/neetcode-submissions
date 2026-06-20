class Solution {
public:
    int solve(int ind, vector<int>& prices, int buy, vector<vector<int>>& dp){
        int n = prices.size();
        if(ind == n) return 0;
        int profit = 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        if(buy == 1){
            profit = max(-prices[ind] + solve(ind+1, prices, 0, dp), 0 + solve(ind+1, prices, 1, dp));
        }
        else profit = max(prices[ind] + solve(ind+1, prices, 1, dp), 0 + solve(ind+1, prices, 0, dp));
        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // int buy = 1;
        // vector<vector<int>> dp(n+1, vector<int>(2, -1));
        // return solve(0, prices, buy, dp);

        vector<vector<int>> dp(n+2, vector<int>(2,0));
        dp[n][0] = dp[n][1] = 0;
        for(int ind = n-1 ; ind >= 0 ; ind--){
            for(int buy = 0 ; buy < 2 ; buy++){
                if(buy == 1){
                            dp[ind][1] = max(-prices[ind] + dp[ind+1][0], 0 + dp[ind+1][1]);
                        }
                else dp[ind][0] = max(prices[ind] + dp[ind+2][1], 0 + dp[ind+1][0]);
            }
        }
        return dp[0][1];

    }
};