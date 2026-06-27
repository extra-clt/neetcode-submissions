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
    int countComponents(int n, vector<vector<int>>& edges) {
        //DSU - distinct elem in find vector.
        parent.resize(n);
        size.resize(n,1);
        for (int i = 0; i < n; i++) parent[i] = i;
        for (auto &e : edges) {
            if (find(e[0]) != find(e[1])) unionNode(e[0],e[1]);
        }
        unordered_set<int> store; //stores distinct leaders
        for (int i = 0; i < n; i++) {
            int l = find(i);
            store.insert(l);
        }
        return (int)store.size();
    }
};
