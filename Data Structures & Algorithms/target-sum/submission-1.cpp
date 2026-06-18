class Solution {
public:
    int solve(vector<int>& nums, int target){
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target+1, 0));
        if(nums[0] == 0) dp[0][0] = 2;
        else dp[0][0] = 1;
        for(int i = 1 ; i <  n ; i++) dp[i][0] = 1;
        if(nums[0] != 0 && nums[0] <= target) dp[0][nums[0]] = 1;
        for(int i = 1 ; i < n ; i++){
            for(int T = 0 ; T<= target ; T++){
                int notPick = dp[i-1][T];
                int pick = 0;
                if(nums[i] <= T) pick = dp[i-1][T-nums[i]];
                dp[i][T] = pick + notPick;
            }
        }
        return dp[n-1][target];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totSum = 0;
        for(auto it : nums) totSum += it;
        int val = (totSum-target)/2;
        if(totSum-target < 0) return 0;
        if((totSum-target) % 2 != 0) return 0;
        return solve(nums, val);

    }
};