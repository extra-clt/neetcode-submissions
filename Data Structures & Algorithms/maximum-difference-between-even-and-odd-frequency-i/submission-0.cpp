class Solution {
public:
    int maxDifference(string s) {
        //highest odd - smallest even
        unordered_map<int,int> um;
        int maxOdd = INT_MIN, minEven = INT_MAX;
        for (char c : s) um[c]++;
        for (char c : s) {
            if (um[c] & 1) maxOdd = max(maxOdd, um[c]);
            else minEven = min(minEven, um[c]);
        }
        return maxOdd - minEven;
    }
};