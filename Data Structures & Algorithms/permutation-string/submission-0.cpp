class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        
        if (n1 > n2) return false; // If s1 is longer, it can't be a substring
        
        // Frequency arrays for s1 and the current window in s2
        vector<int> s1_count(26, 0);
        vector<int> window_count(26, 0);
        
        // Fill the frequency map for s1
        for (char c : s1) {
            s1_count[c - 'a']++;
        }
        
        int l = 0, r = 0;
        while (r < n2) {
            // Add the current character to our sliding window
            window_count[s2[r] - 'a']++;
            
            // When the window size matches s1's size
            if (r - l + 1 == n1) {
                // Check if the frequency matches s1 exactly
                if (s1_count == window_count) {
                    return true;
                }
                
                // Slide the left pointer: remove s2[l] from window and increment l
                window_count[s2[l] - 'a']--;
                l++;
            }
            r++;
        }
        
        return false;
    }
};