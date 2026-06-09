class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto it : times){
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> dist(n+1, 1e9);
        dist[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        while(!pq.empty()){
            int time = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                int edW = it.second;
                int adjNode = it.first;
                if(time + edW < dist[adjNode]){
                    dist[adjNode] = time + edW;
                    pq.push({dist[adjNode], adjNode});
                } 
            }
        }
        for(int i = 1 ; i <= n ; i++){
            if(dist[i] == 1e9) dist[i] = -1;
        }
        int maxi = -1;
        for(int i = 1 ; i <= n ; i++){
            if(dist[i] > maxi) maxi = dist[i];
            if(dist[i] == -1) return -1;
        }
        return maxi;
    }
};
