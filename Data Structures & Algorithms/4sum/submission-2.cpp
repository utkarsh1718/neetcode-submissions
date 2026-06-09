class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int a = i+1 ; a<n ; a++){
                if(a > i+1 && nums[a] == nums[a-1]) continue;
                int j = a + 1;
                int k = n - 1;

                while(j < k) {
                    long long sum = (long long)nums[i] + nums[a] + nums[j] + nums[k];

                    if(sum == target) {
                        ans.push_back({nums[i], nums[a], nums[j], nums[k]});
                        j++;
                        k--;
                        while(j < k && nums[j] == nums[j-1]) j++;
                        while(j < k && nums[k] == nums[k+1]) k--;
                    }
                else if(sum > target) k--;
                else j++;
                }
            }
        }
        return ans;
    }
};
