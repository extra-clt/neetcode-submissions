class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0, n = digits.size();
        if (digits[n-1] != 9) {
            digits[n-1] += 1;
            return digits;
        }
        int i = n-1;
        while (i >= 0 && digits[i] == 9) {
            digits[i] = 0;
            i--;
        }
        if (i != -1) {
            digits[i] += 1;
            return digits;
        }
        vector<int> sol(n+1,0);
        sol[0] = 1;
        return sol;

    }
};
