class Solution {
public:
    bool subsetSumToK(int ind, int k, vector<int>& arr){
        vector<int> prev(k+1, 0), curr(k+1, 0);
        prev[0] = true, curr[0] = true;
        if(arr[0] <= k) prev[arr[0]] = true;
        for(int i = 1 ; i < arr.size() ; i++){
            for(int target = 1 ; target <= k ; target++){
                bool notTake = prev[target];
                bool take = false;
                if(arr[i] <= target) take = prev[target-arr[i]];\
                curr[target] = take | notTake;
            }
            prev = curr;
        }
        return prev[k];
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(int i = 0 ; i < n ; i++){
            totalSum += nums[i];
        }
        if(totalSum%2 != 0) return false;
        return subsetSumToK(n-1, totalSum/2, nums);
    }
};
