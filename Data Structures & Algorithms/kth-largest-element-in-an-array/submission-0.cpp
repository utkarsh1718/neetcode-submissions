class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        int n = nums.size();
        for(int i = 0 ; i < n-k+1 ; i++){
            pq.push(nums[i]);
        }
        for(int i = n-k+1 ; i < n ; i++){
            if(nums[i] < pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};
