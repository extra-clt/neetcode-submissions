class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        //iter=0;
        //i=0; j=0 to n-1;
        //if j==n: j--, i=0 to m-1;
        //if i==m; i--, j=n-1 to 0;
        //if j==-1; j++, i=m-1 to 1;

        //iter=0 to less than min(m,n)/2;
        //i=iter; j=iter to n-1-iter;
        //if j==n-iter: j--, i=iter+1 to m-1-iter;
        //if i==m-iter; i--, j=n-2-iter to iter;
        //if j==iter-1; j++, i=m-2-iter to 1+iter;
        //after all iter,(iter++ occurs at last)
        //if m==n: add matrix[m-2*iter,n-2*iter]
        //if m>n: i = iter to m-iter-1, j = n-2*iter add those elem
        //if n>m: j = iter to n-iter-1, i = m-2*iter add those elem

        int m = matrix.size(), n = matrix[0].size(), iter = 0;
        vector<int> sol;
        int tot_iter = min(m,n)/2;
        for (iter = 0; iter < tot_iter; iter++) {
            int i = iter, j = iter;
            for (j = iter; j < n-iter; j++) {
                sol.push_back(matrix[i][j]);
            }
            j--;
            for (i = iter+1; i < m-iter; i++) {
                sol.push_back(matrix[i][j]);
            }
            i--;
            for (j = n-2-iter; j >= iter; j--) {
                sol.push_back(matrix[i][j]);
            }
            j++;
            for (i = m-2-iter; i >= 1+iter; i--) {
                sol.push_back(matrix[i][j]);
            }
        }
        if (m == n && m%2 != 0) {
            sol.push_back(matrix[m/2][n/2]);
        }
        else if (m>n && n%2 != 0) {
            for (int i = iter; i < m-iter; i++) {
                sol.push_back(matrix[i][n/2]);
            }
        }
        else if (n>m && m%2 != 0) {
            for (int j = iter; j < n-iter; j++) {
                sol.push_back(matrix[m/2][j]);
            }
        }
        return sol;
    }
};




