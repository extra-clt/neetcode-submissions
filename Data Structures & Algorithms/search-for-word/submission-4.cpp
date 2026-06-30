class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    bool bt(int idx, int x, int y, int r, int c, vector<vector<char>>& board, string word, vector<vector<bool>> &visited) {
        //cout << "idx: " << idx << endl;
        //cout << "x,y = " << x << "," << y << endl;
        if (board[x][y] != word[idx]) return false;
        if (idx == word.size()-1) return true;
        //explore neighbors
        for (int i = 0; i < 4; i++) {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if (nx>=0 && nx<r && ny>=0 && ny<c && !visited[nx][ny]) {
                visited[nx][ny] = true;
                //cout << "nx,ny = " << nx << "," << ny << endl;
                bool found = bt(idx+1, nx, ny, r, c, board, word, visited);
                //cout << found << endl;
                if (found) return true;
                visited[nx][ny] = false;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int r = board.size(), c = board[0].size();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                vector<vector<bool>> visited(r, vector<bool> (c, false));
                visited[i][j] = true;
                bool found = bt(0, i, j, r, c, board, word, visited);
                if (found) return true;
            }
        }
        return false;
    }
};
