class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);
        vector<int> topo;
        for (auto &e : prerequisites) {
            adj[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int node = q.front(); q.pop();
            topo.push_back(node);
            for (auto &i : adj[node]) {
                indegree[i]--;
                if (indegree[i] == 0) q.push(i);
            }
        }
        if (topo.size() < numCourses) return false;
        return true;
    }
};
