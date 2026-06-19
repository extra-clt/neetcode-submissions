class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool c = false, x = false, y = false;
        if (matrix[0][0] == 0) c = true;
        if (!c) {
            for (int i = 1; i < matrix.size(); i++) {
                if (matrix[i][0] == 0) y = true;
            }
            for (int j = 1; j < matrix[0].size(); j++) {
                if (matrix[0][j] == 0) x = true;
            }
        }
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = -1;
                    matrix[i][0] = -1;
                }
            }
        }
        for (int i = 1; i < matrix.size(); i++) {
            if (matrix[i][0] == -1) {
                for (int j = 0; j < matrix[0].size(); j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int j = 1; j < matrix[0].size(); j++) {
            if (matrix[0][j] == -1) {
                for (int i = 0; i < matrix.size(); i++) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (c) {
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i][0] = 0;
            }
            for (int j = 0; j < matrix[0].size(); j++) {
                matrix[0][j] = 0;
            }
        }
        else if (y) {
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i][0] = 0;
            }
        }
        else if (x) {
            for (int j = 0; j < matrix[0].size(); j++) {
                matrix[0][j] = 0;
            }
        }
    }
};
