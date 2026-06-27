class Solution {
public:
    vector<int> parent, size;
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void unionNode(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa == pb) return;
        if (size[pa] < size[pb]) swap(pa,pb);
        parent[pb] = pa;
        size[pa] += size[pb];
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        //DSU - when cycle detected than edge (u,v) is the answer
        int n = edges.size();
        parent.resize(n+1);
        size.resize(n+1,1);
        for (int i = 0; i < n+1; i++) parent[i] = i;
        for (auto &e : edges) {
            if (find(e[0]) != find(e[1])) unionNode(e[0],e[1]);
            else return {e[0],e[1]};
        }
        return {};
    }
};
