class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //multi source bfs
        //unvisited+fresh return -1;
        int r = grid.size(), c = grid[0].size();
        vector<vector<bool>> visited(r, vector<bool> (c, false));
        //vector<vector<int>> dist(r, vector<int> (c, INT_MAX));
        vector<pair<int,int>> store;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 2) {
                    store.push_back({i,j});
                    visited[i][j] = true;
                    grid[i][j] = 0;
                }
                else if (grid[i][j] == 1) {
                    grid[i][j] = INT_MAX;
                }
                else grid[i][j] = -1;
            }
        }
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};
        queue<pair<int,int>> q;
        for (auto i : store) {
            q.push(i);
        }
        int cnt = 0;
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
                    cnt = max(cnt,grid[nx][ny]);
                }
            }
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (!visited[i][j] && grid[i][j] == INT_MAX) return -1;
            }
        }
        return cnt;
    }
};
