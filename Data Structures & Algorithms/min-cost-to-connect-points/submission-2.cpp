class Solution {
public:
    vector<int> parent, size;
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa == pb) return;
        if (size[pa] < size[pb]) swap(pa,pb);
        parent[pb] = pa;
        size[pa] += size[pb];
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        //MST
        vector<vector<int>> edges;
        for (int i = 0; i < points.size(); i++) {
            for (int j = i+1; j < points.size(); j++) {
                int dist = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                edges.push_back({i, j, dist});
            }
        }
        sort(edges.begin(), edges.end(), [] (vector<int> &a, vector<int> &b) {
            return a[2] < b[2]; //wt based
        });
        int n = points.size();
        parent.resize(n);
        size.resize(n,1);
        for (int i = 0; i < n; i++) parent[i] = i;
        int mincst = 0;
        for (auto &e : edges) {
            //p1 p2 dist
            //size of edges = n(n-1)/2;
            int u = e[0], v = e[1], wt = e[2];
            if (find(u) != find(v)) {
                unite(u,v);
                mincst += wt;
            }
        }
        return mincst;
    }
};
