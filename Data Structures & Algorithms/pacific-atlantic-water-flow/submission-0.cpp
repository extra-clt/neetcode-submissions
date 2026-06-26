class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        //reverse thinking- see which all idx the borders can reach
        // inner>=border, move inner
        //two multi sourse bfs - atlantic, pacific
        int r = heights.size(), c = heights[0].size();
        vector<vector<bool>> visited_a(r, vector<bool> (c, false));
        vector<vector<bool>> visited_p(r, vector<bool> (c, false));
        //0 - nil, 1- either atlantic/pacific, 2 - both, -1 = not visited
        queue<pair<int,int>> qa,qp;
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};
        for (int i = 0; i < r; i++) {
            qp.push({i,0});
            visited_p[i][0] = true;
        }
        for (int j = 0; j < c; j++) {
            qp.push({0,j});
            visited_p[0][j] = true;
        }
        while (!qp.empty()) {
            auto [x, y] = qp.front(); qp.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x+dx[i];
                int ny = y+dy[i];
                if (nx>=0 && nx<r && ny>=0 && ny<c && !visited_p[nx][ny] && heights[nx][ny]>=heights[x][y]) {
                    qp.push({nx,ny});
                    visited_p[nx][ny] = true;
                }
            }
        }
        for (int i = 0; i < r; i++) {
            qa.push({i,c-1});
            visited_a[i][c-1] = true;
        }
        for (int j = 0; j < c; j++) {
            qa.push({r-1,j});
            visited_a[r-1][j] = true;
        }
        while (!qa.empty()) {
            auto [x, y] = qa.front(); qa.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x+dx[i];
                int ny = y+dy[i];
                if (nx>=0 && nx<r && ny>=0 && ny<c && !visited_a[nx][ny] && heights[nx][ny]>=heights[x][y]) {
                    qa.push({nx,ny});
                    visited_a[nx][ny] = true;
                }
            }
        }
        vector<vector<int>> sol;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (visited_a[i][j] && visited_p[i][j]) sol.push_back({i,j});
            }
        }
        return sol;
    }
};
