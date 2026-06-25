class Solution {
public:
    int dfs(vector<vector<int>>& grid, int startR, int startC, int area, vector<vector<bool>>& visited) {
        int r = grid.size(), c = grid[0].size();
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};
        queue<pair<int,int>> q;
        q.push({startR,startC});
        area++;
        visited[startR][startC] = true;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x+dx[i];
                int ny = y+dy[i];
                if (nx>=0 && nx<r && ny>=0 && ny<c && !visited[nx][ny] && grid[nx][ny] == 1) {
                    visited[nx][ny] = true;
                    area++;
                    q.push({nx,ny});
                }
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area = 0, maxArea = 0, r = grid.size(), c = grid[0].size();
        vector<vector<bool>> visited(r, vector<bool> (c,false));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    int area = dfs(grid, i, j, 0, visited);
                    maxArea = max(area, maxArea);
                }
            }
        }
        return maxArea;
    }
};
