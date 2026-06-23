class Solution {
public:
    int solve(int l, int r, vector<int>& piles, vector<vector<int>>& dp){
        if(l > r) return 0;
        bool even = (r-1)%2 == 0;
        if(dp[l][r] != -1) return dp[l][r];
        int leftTake = even ? piles[l] : 0;
        int rightTake = even ? piles[r] : 0;
        return dp[l][r] = max(solve(l+1, r, piles, dp) + leftTake, solve(l, r-1, piles, dp) + rightTake);
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int total = accumulate(piles.begin(), piles.end(), 0);
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int A = solve(0, n-1, piles, dp);
        return A > total - A;
    }
};