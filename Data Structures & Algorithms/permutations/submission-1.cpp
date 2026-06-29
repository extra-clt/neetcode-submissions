class Solution {
public:
    vector<int> path;
    vector<vector<int>> sol;
    void bt(vector<int> &nums, vector<bool> &visited) {
        if (path.size() == nums.size()) {
            sol.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i]) continue;
            path.push_back(nums[i]);
            visited[i] = true;
            bt(nums, visited);
            path.pop_back();
            visited[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> visited(nums.size(), false);
        bt(nums, visited);
        return sol;
    }
};
