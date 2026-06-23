class Solution {
public:
    int solve(int i, int j, vector<int>& nums, vector<vector<int>>& dp){
        if(i > j) return 0;
        int maxi = INT_MIN;
        if(dp[i][j] != -1) return dp[i][j];
        for(int k = i ; k <= j ; k++){
            int coins = nums[i-1]*nums[k]*nums[j+1] + solve(i, k-1, nums, dp) + solve(k+1, j, nums, dp);
            maxi = max(maxi, coins);
        }
        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        // vector<vector<int>> dp(n+2, vector<int>(n+2, -1));
        // return solve(1, n, nums, dp);

        int N = nums.size();
        vector<vector<int>> dp(N, vector<int>(N, 0));
        for(int i = N-2; i >= 1; i--){
            for(int j = i; j <= N-2; j++){
                int maxi = 0;
                for(int k = i; k <= j; k++){
                    int coins = nums[i-1] * nums[k] * nums[j+1] + dp[i][k-1] + dp[k+1][j];
                    maxi = max(maxi, coins);
                }
                dp[i][j] = maxi;
            }
        }
    return dp[1][N-2];
    }
};