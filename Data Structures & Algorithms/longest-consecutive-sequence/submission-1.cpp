class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        map<int,int> um;
        int maxVal = 1;
        for (int i : nums) um[i] = 1;
        for (auto it = um.begin(); it != um.end(); ++it) {
            int i = it->first;
            if (um.count(i-1)) {
                um[i] += um[i-1];
                maxVal = max(maxVal, um[i]);
            }
        }
        return maxVal;
    }
};
