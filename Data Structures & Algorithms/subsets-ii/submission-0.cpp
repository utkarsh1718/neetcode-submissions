class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void solve(int ind, vector<int>& nums){
        int n = nums.size();
        if(ind == n){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[ind]);
        solve(ind+1, nums);
        temp.pop_back();
        while(ind+1 < n && nums[ind] == nums[ind+1]) ind++;
        solve(ind+1, nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        solve(0, nums);
        return ans;
    }
};