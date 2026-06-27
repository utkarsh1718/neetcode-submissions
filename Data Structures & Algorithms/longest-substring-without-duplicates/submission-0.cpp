class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, ans = 0;
        vector<int> arr(256, 0);
        int n = s.size();
        while(r < n){
            while(arr[s[r]]){
                arr[s[l]]--;
                l++;
            }
            arr[s[r]]++;
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};
