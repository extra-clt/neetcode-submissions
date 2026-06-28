class Solution {
public:
    vector<int> path;
    vector<vector<int>> sol;
    void dfs(int idx, vector<int> &nums) {
        //at each step, choose or dont choose
        //base case idx == nums.size();
        if (idx == nums.size()) {
            sol.push_back(path);
            return;
        }
        path.push_back(nums[idx]);
        dfs(idx+1, nums);
        path.pop_back();
        dfs(idx+1, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
        return sol;
    }
};
