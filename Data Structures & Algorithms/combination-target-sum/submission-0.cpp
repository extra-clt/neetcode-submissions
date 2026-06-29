class Solution {
public:
    vector<int> path;
    vector<vector<int>> sol;
    void bt(vector<int>& nums, int target, int val) {
        //if sum> target exit
        int sm = accumulate(path.begin(), path.end(), 0);
        if (sm == target) {
            sol.push_back(path);
            return;
        }
        if (sm > target) return;
        for (int i = 0; i < nums.size(); i++) {
            path.push_back(nums[i]);
            bt(nums,target,val-nums[i]);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        bt(nums,target,target);
        for (auto &i : sol) sort(i.begin(), i.end());
        set<vector<int>> set_sol(sol.begin(), sol.end());
        vector<vector<int>> vec_sol(set_sol.begin(), set_sol.end());
        return vec_sol;
    }
};
