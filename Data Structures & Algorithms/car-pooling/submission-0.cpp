class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // Sort by pickup location
        sort(trips.begin(), trips.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[1] < b[1];
             });

        // {drop_location, passengers}
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        int currPassengers = 0;

        for (auto& trip : trips) {
            int passengers = trip[0];
            int from = trip[1];
            int to = trip[2];

            // Drop off everyone whose destination has been reached
            while (!pq.empty() && pq.top().first <= from) {
                currPassengers -= pq.top().second;
                pq.pop();
            }

            // Pick up current passengers
            currPassengers += passengers;

            if (currPassengers > capacity)
                return false;

            pq.push({to, passengers});
        }

        return true;
    }
};