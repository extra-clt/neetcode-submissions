class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        int p3 = 0, p2 = 1, p1 = 1;
        for (int i = 3; i <= n; i++) {
            int sm = p1+p2+p3;
            p3 = p2;
            p2 = p1; 
            p1 = sm;
        }
        return p1;
    }
};