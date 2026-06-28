class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l=0, r=0, maxLen=0, maxf=0;
        unordered_map<char, int> hash;
        while(r < n){
            hash[s[r]-'A']++;
            maxf = max(maxf, hash[s[r]-'A']);
            while((r-l+1)-maxf > k){
                hash[s[l]-'A']--;
                l++;
            }
            if((r-l+1) - maxf <= k){
                maxLen = max(maxLen, r-l+1);
            }
            r++;
        }
        return maxLen;
    }
};
