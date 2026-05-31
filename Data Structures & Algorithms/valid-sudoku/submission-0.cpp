class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //rows (i,j)
        for (int i = 0; i < 9; i++) {
            unordered_map<char,int> um;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    um[board[i][j]]++;
                    if (um[board[i][j]] > 1) return false;
                }
            }
        }
        //col
        for (int j = 0; j < 9; j++) {
            unordered_map<char,int> um;
            for (int i = 0; i < 9; i++) {
                if (board[i][j] != '.') {
                    um[board[i][j]]++;
                    if (um[board[i][j]] > 1) return false;
                }
            }
        }
        //grid
        for (int i = 0; i < 9; i+=3) {
            for (int j = 0; j < 9; j+=3) {
                unordered_map<char,int> um;
                for (int k = i; k < i+3; k++) {
                    for (int l = j; l < j+3; l++) {
                        if (board[k][l] != '.') {
                            um[board[k][l]]++;
                            if (um[board[k][l]] > 1) return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
