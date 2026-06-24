class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // int n = nums.size();
        // vector<int> suffix(n), prefix(n);
        // for(int i = 0 ; i < n ; i++){
        //     for(int j = i+1 ; j < n ; j++){
        //         suffix[i] *= nums[j];
        //     }
        // }
        // for(int i = n-1 ; i >= 0 ; i--){
        //     for(int j = i-1 ; j >= 0 ; j--){
        //         prefix[i] *= nums[j];
        //     }
        // }
        
        // prefix[0] = 1;
        // for(int i = 1 ; i < n ; i++){
        //     prefix[i] = prefix[i-1]*nums[i-1];
        // }
        // suffix[n-1] = 1;
        // for(int i = n-2 ; i >= 0 ; i--){
        //     suffix[i] = suffix[i+1]*nums[i+1];
        // }
        // vector<int> ans(n);
        // for(int i = 0 ; i < n ; i++){
        //     ans[i] = (suffix[i]*prefix[i]);
        // }
        // return ans;


    int n = nums.size();
    vector<int> ans(n);

    // Step 1: store prefix products
    ans[0] = 1;
    for(int i = 1; i < n; i++) {
        ans[i] = ans[i-1] * nums[i-1];
    }

    // Step 2: multiply with suffix products
    int suffix = 1;
    for(int i = n-1; i >= 0; i--) {
        ans[i] *= suffix;
        suffix *= nums[i];
    }

    return ans;
    }
};
