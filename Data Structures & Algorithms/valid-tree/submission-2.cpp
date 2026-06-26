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
    bool validTree(int n, vector<vector<int>>& edges) {
        //DSU
        //valid tree - all connected + acyclic
        if (edges.size() != n-1) return false;//for connected n must have n-1 edges
        parent.resize(n);
        size.resize(n,1);
        for (int i = 0; i < n; i++) parent[i] = i;
        for (auto &e : edges) {
            if (find(e[0]) == find(e[1])) return false; //cycle exists
            unionNode(e[0],e[1]);
        }
        /*for (int i = 1; i < n; i++) {
            if (find(0) != find(i)) return false; //disconnected
        }*/
        return true;
    }
};