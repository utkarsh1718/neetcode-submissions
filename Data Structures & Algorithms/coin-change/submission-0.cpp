class Solution {
public:
    int solve(int ind, vector<int>& coins, int amount, vector<vector<int>>& dp){
        int n = coins.size();
        if(ind == 0){
            if(amount % coins[ind] == 0) return amount/coins[ind];
            else return 1e9;
        }
        if(dp[ind][amount] != -1) return dp[ind][amount];
        int notTake = 0 + solve(ind-1, coins, amount, dp);
        int take = 1e9;
        if(coins[ind] <= amount) take = 1 + solve(ind, coins, amount - coins[ind], dp);
        return dp[ind][amount] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        // int ans = solve(n-1, coins, amount, dp);
        // if(ans >= 1e9) return -1;
        // return ans;

        // vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        // for(int T = 0 ; T <= amount ; T++){
        //     if(T%coins[0] == 0) dp[0][T] = T/coins[0];
        //     else dp[0][T] = 1e9;
        // }
        // for(int ind = 1 ; ind < n ; ind++){
        //     for(int T = 0 ; T <= amount ; T++){
        //         int notTake = 0 + dp[ind-1][T];
        //         int take = 1e9;
        //         if(coins[ind] <= T) take = 1 + dp[ind][T - coins[ind]];
        //         dp[ind][T] = min(take, notTake);
        //     }
        // }
        // int ans = dp[n-1][amount];
        // if(ans >= 1e9) return -1;
        // return ans;

        vector<int> prev(amount+1,0), cur(amount+1, 0);
        for(int T = 0 ; T <= amount ; T++){
            if(T%coins[0] == 0) prev[T] = T/coins[0];
            else prev[T] = 1e9;
        }
        for(int ind = 1 ; ind < n ; ind++){
            for(int T = 0 ; T <= amount ; T++){
                int notTake = 0 + prev[T];
                int take = 1e9;
                if(coins[ind] <= T) take = 1 + cur[T - coins[ind]];
                cur[T] = min(take, notTake);
            }
            prev = cur;
        }
        int ans = prev[amount];
        if(ans >= 1e9) return -1;
        return ans;
        
    }
};