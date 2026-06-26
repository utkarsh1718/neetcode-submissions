class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void solve(int ind, vector<int>& candidates, int k){
        int n = candidates.size();
        if(k == 0){
            ans.push_back(temp);
            return;
        }

        if(k < 0 || ind == n) return;

        temp.push_back(candidates[ind]);
        solve(ind, candidates, k - candidates[ind]);
        temp.pop_back();
        
        solve(ind + 1, candidates, k);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        solve(0, candidates, target);
        return ans;
    }
};