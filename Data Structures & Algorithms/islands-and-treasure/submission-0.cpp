class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        //find source and do bfs
        //dist_i = min. distNode+1
        int r = grid.size(), c = grid[0].size();
        vector<vector<bool>> visited(r, vector<bool> (c, false));
        vector<pair<int,int>> store;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 0) {
                    store.push_back({i,j});
                    visited[i][j] = true;
                }
            }
        }
        if (store.empty()) return;
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};
        queue<pair<int,int>> q;
        for (auto i : store) {
            q.push(i);
        }
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx>=0 && nx<r && ny>=0 && ny<c && !visited[nx][ny] && grid[nx][ny] != -1) {
                    q.push({nx,ny});
                    visited[nx][ny] = true;
                }
                if (nx>=0 && nx<r && ny>=0 && ny<c) {
                    grid[nx][ny] = min(grid[nx][ny], grid[x][y]+1);
                }
            }
        }
    }
};
