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

        solve(ind+1, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        solve(0, nums);
        return ans;
    }
};
