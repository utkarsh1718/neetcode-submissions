class Solution {
public:
    int solve(int ind, int amount, vector<int>& coins, vector<vector<int>>& dp){
        if(ind == 0){
            if(amount % coins[ind] == 0) return 1;
            else return 0;
        }
        if(dp[ind][amount] != -1) return dp[ind][amount];
        int notTake = 0 + solve(ind-1, amount, coins, dp);
        int take = 0;
        if(coins[ind] <= amount) take = solve(ind, amount-coins[ind], coins, dp);
        return dp[ind][amount] = take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        // return solve(n-1, amount, coins, dp);

        // vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        // for(int T = 0 ; T <= amount ; T++){
        //     if(T % coins[0] == 0) dp[0][T] = 1;
        // }
        // for(int ind = 1 ; ind < n ; ind++){
        //     for(int T = 0 ; T <= amount ; T++){
        //         int notTake = 0 + dp[ind-1][T];
        //         int take = 0;
        //         if(coins[ind] <= T) take = dp[ind][T-coins[ind]];
        //         dp[ind][T] = take + notTake;
        //     }
        // }
        // return dp[n-1][amount];

        vector<long long> prev(amount+1, 0), cur(amount + 1, 0);
        for(int T = 0 ; T <= amount ; T++){
            if(T % coins[0] == 0) prev[T] = 1;
        }
        for(int ind = 1 ; ind < n ; ind++){
            // vector<long long> cur(amount+1, 0);
            for(int T = 0 ; T <= amount ; T++){
                long long notTake = 0 + prev[T];
                long long take = 0;
                if(coins[ind] <= T) take = cur[T-coins[ind]];
                cur[T] = take + notTake;
            }
            prev = cur;
        }
        return prev[amount];
    }
};