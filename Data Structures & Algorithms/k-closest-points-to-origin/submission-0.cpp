class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int dist = 0;
        priority_queue<pair<int,int>> pq;
        for (int i = 0; i < points.size(); i++) {
            dist = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            pq.push(make_pair(dist,i));
            if (pq.size() > k) pq.pop();
        }
        vector<vector<int>> sol;
        while (!pq.empty()) {
            auto [dist, idx] = pq.top(); pq.pop();
            sol.push_back(points[idx]);
        }
        return sol;
    }
};
