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
        solve(ind+1, candidates, k - candidates[ind]);
        temp.pop_back();
        
        int next = ind + 1;
        while (next < n && candidates[next] == candidates[ind]) next++;
        solve(next, candidates, k);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        solve(0, candidates, target);
        return ans;
    }
};