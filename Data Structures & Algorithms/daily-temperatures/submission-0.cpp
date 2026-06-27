class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        vector<int> ans(temperatures.size(), 0);
        st.push({temperatures[0], 0});
        int i = 1;
        while(i < temperatures.size()){ 
            while(!st.empty() && st.top().first < temperatures[i]){
                ans[st.top().second] = i - st.top().second;
                st.pop();
            }
            st.push({temperatures[i], i});
            i++;
        }
        return ans;
    }
};