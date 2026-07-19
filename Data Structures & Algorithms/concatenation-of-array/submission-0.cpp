class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> sol = nums;
        for (int i : nums) sol.push_back(i);
        return sol;
    }
};