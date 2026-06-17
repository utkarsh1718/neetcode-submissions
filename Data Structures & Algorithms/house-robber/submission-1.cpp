class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);
        for(int i = 2 ; i <= n-1 ; i++){
            int take = nums[i] + prev2;
            int notTake = prev1;
            int curi = max(take, notTake);
            
            prev2 = prev1;
            prev1 = curi;
        }
        return prev1;
    }
};
