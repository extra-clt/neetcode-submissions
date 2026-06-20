class Solution {
public:
    double myPow(double x, int n) {
        //eg:n=14=1110(8421-exp of 2)
        //if bit is 0 or 1, we do x*x ( why? - to get xpow()8421 etc..)
        //if bit is 1, we multiply res with x.

        if (n == 1) return x;
        if (x == 0) return 0;
        bool neg = false;
        long double x_ld = x, res = 1;
        if (n < 0) {
            neg = true;
            n*=-1;
        }
        while (n > 0) {
            if (n & 1) res *= x_ld;
            x_ld *= x_ld;
            n >>= 1;
        }
        if (neg) return 1/res;
        return res;
    }
};
