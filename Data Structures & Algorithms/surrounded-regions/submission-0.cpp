class Solution {
public:
    
    void solve(vector<vector<char>>& board) {
        //bfs
        //dont consider X and border O
        //reverse thinking- all Os from border are not replaced
        //unvisited Os are replaced
        int r = board.size(), c = board[0].size();
        vector<vector<bool>> visited(r, vector<bool> (c, false));
        queue<pair<int,int>> q;
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};
        for (int i = 0; i < r; i++) { //j = 0, i changes
            if (board[i][0] == 'O') {
                q.push({i,0});
                visited[i][0] = true;
            }
        }
        for (int j = 1; j < c; j++) { //i = 0, j changes
            if (board[0][j] == 'O') {
                q.push({0,j});
                visited[0][j] = true;
            }
        }
        for (int i = 1; i < r; i++) { //j = c-1, i changes
            if (board[i][c-1] == 'O') {
                q.push({i,c-1});
                visited[i][c-1] = true;
            }
        }
        for (int j = 1; j < c-1; j++) { //i = r-1, j changes
            if (board[r-1][j] == 'O') {
                q.push({r-1,j});
                visited[r-1][j] = true;
            }
        }
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x+dx[i];
                int ny = y+dy[i];
                if (nx>=0 && nx<r && ny>=0 && ny<c && !visited[nx][ny] && board[nx][ny] != 'X') {
                    q.push({nx,ny});
                    visited[nx][ny] = true;
                }
            }
        }
        vector<vector<int>> sol;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (!visited[i][j] && board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};
