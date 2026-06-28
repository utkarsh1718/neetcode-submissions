class Solution {
public:
    vector<vector<int>> ans;
    void solve(int ind, vector<int>& nums){
        int n = nums.size();
        if(ind == n){
            ans.push_back(nums);
            return;
        }

        for(int i = ind ; i < n ; i++){
            swap(nums[i], nums[ind]);
            solve(ind+1, nums);
            swap(nums[i], nums[ind]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        solve(0, nums);
        return ans;
    }
};
