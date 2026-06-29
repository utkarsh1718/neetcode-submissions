class Solution {
public:
    vector<vector<int>> ans;
    void solve(int ind, vector<int>& nums){
        if(nums.size() == 1){
            ans.push_back({nums[0]});
            return;
        }
        if(ind == nums.size()){
            ans.push_back(nums);
            return;
        }

        unordered_set<int> used;

        for (int i = ind; i < nums.size(); i++) {

            if (used.count(nums[i]))
                continue;

            used.insert(nums[i]);

            swap(nums[ind], nums[i]);
            solve(ind + 1, nums);
            swap(nums[ind], nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        solve(0, nums);
        return ans;
    }
};