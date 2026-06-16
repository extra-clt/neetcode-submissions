class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (target < matrix[0][0]) return false;
        int l = 0, h = matrix.size()-1;
        while (l <= h) {
            int m = l + (h-l)/2;
            if (matrix[m][0] == target) return true;
            else if (matrix[m][0] < target) l = m+1;
            else h = m-1;
        }
        //cout << "h: " << h << " l: " << l << endl;
        //h or l--
        int l1 = 0, h1 = matrix[0].size()-1;
        while (l1 <= h1) {
            //cout << "l1: " << l1 << ",h1: " << h1 << endl;
            int m1 = l1 + (h1-l1)/2;
            if (matrix[h][m1] == target) return true;
            else if (matrix[h][m1] < target) l1 = m1+1;
            else h1 = m1-1;
        }
        return false;
    }
};
