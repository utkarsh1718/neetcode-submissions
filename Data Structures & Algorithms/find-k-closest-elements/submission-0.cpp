class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = -1, r = -1;
        int n = arr.size();
        for(int i = 0 ; i < n-1 ; i++){
            if(arr[i] <= x && arr[i+1] > x){
                l = i;
                r = i+1;
            }
        }
        if (x < arr[0]) {
            l = -1;
            r = 0;
        }
        else if (x >= arr[n - 1]) {
            l = n - 1;
            r = n;
        }
        vector<int> ans;
        while (k--) {
            if (l < 0) {
                ans.push_back(arr[r++]);
            }
            else if (r >= n) {
                ans.push_back(arr[l--]);
            }
            else if (abs(arr[l] - x) <= abs(arr[r] - x)) {
                ans.push_back(arr[l--]);
            }
            else {
                ans.push_back(arr[r++]);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};