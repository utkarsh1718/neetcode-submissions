class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int i = 0;
        while(i < n){
            int start = intervals[i][0];
            int end = intervals[i][1];
            
            // merge all overlapping intervals
            while(i + 1 < n && intervals[i + 1][0] <= end){
                end = max(end, intervals[i + 1][1]);
                i++;
            }
            
            vector<int> temp;
            temp.push_back(start);
            temp.push_back(end);
            ans.push_back(temp);
            
            i++;
        }
        
        return ans;
    }
};