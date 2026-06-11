class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        int l = 0, r = 1;
        int res = 1;
        string prev = "";
        while(r < n){
            if(arr[r-1] > arr[r] && prev != ">"){
                res = max(res, r-l+1);
                r++;
                prev = ">";
            }
            else if(arr[r-1] < arr[r] && prev != "<"){
                res = max(res, r-l+1);
                r++;
                prev = "<";
            }
            else if(arr[r] == arr[r-1]){
                // r = (arr[r] == arr[r-1]) ? r+1 : r;
                r++;
                l = r-1;
                prev = "";
            }
            else{
                // same direction case
                l = r-1;
                prev = "";
            }
        }
        return res;
    }
};