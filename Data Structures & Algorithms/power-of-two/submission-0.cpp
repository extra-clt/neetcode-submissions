class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n<0) return false;
        while (!(n&1) && n>0) {
            n >>= 1;
            cout << n << " ";
        }
        if (n == 1) return true;
        return false;
    }
};