class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        /*
        bitset<32> b(n);
        string s = b.to_string();
        reverse(s.begin(), s.end());
        uint32_t num = static_cast<uint32_t>(stoul(s, nullptr, 2));
        return num;
        */
        uint32_t sol = 0; uint32_t i = 0;
        while (i<32) {
            if (n&1) {
                sol += pow(2,31-i);
            }
            n >>= 1;
            i++;
        }
        return sol;
    }
};
