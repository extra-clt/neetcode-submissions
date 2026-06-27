class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //dijkstra
        vector<vector<pair<int,int>>> adj(n+1);
        for (auto &e : times) {
            adj[e[0]].push_back({e[1],e[2]});//directed
        }
        vector<int> dist(n+1, INT_MAX); dist[0] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        dist[k] = 0;
        pq.push({0,k});
        while (!pq.empty()) {
            auto [d, node] = pq.top(); pq.pop();
            if (d > dist[node]) continue;
            for (auto &[next, wt] : adj[node]) {
                if (dist[node] + wt < dist[next]) {
                    dist[next] = dist[node] + wt;
                    pq.push({dist[next], next});
                }
            }
        }
        int time = *max_element(dist.begin(), dist.end());
        if (time == INT_MAX) return -1;
        return time;
    }
};
