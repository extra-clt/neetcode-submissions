class Solution {
public:
    vector<int> path;
    vector<vector<int>> sol;
    void bt(int i, vector<int> &nums) {
        if (i == nums.size()) {
            sol.push_back(path);
            return;
        }
        path.push_back(nums[i]);
        bt(i+1,nums);
        path.pop_back();
        while (i+1 < nums.size() && nums[i] == nums[i+1]) i++;
        bt(i+1,nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        bt(0,nums);
        return sol;
    }
};
