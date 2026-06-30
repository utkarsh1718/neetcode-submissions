class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> pq;
        for (int i = 0; i < k; i++) {
            int x = points[i][0];
            int y = points[i][1];
            int dist = x*x + y*y;

            pq.push({dist, points[i]});
        }

        for (int i = k; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];
            int dist = x*x + y*y;

            if (dist < pq.top().first) {
                pq.pop();
                pq.push({dist, points[i]});
            }
        }
        vector<vector<int>> ans;

        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
