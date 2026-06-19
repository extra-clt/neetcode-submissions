class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int len = matrix.size();
        for (int i = 0; i < len/2; i++) {
            for (int j = 0; j < len; j++) {
                swap(matrix[i][j],matrix[len-i-1][j]);
            }
        }
        for (int i = 0; i < len; i++) {
            for (int j = i+1; j < len; j++) {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
};
/*
15 13 2 5 
14 3 4 1 
12 6 8 9 
16 7 10 11 
*/