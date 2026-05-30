class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> arr;
        for (int i : nums) arr[i]++;
        auto cmp = [](pair<int,int> &a, pair<int,int> &b) {
            return a.second > b.second;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> max_pq;
        for (auto it = arr.begin(); it != arr.end(); ++it) {
            max_pq.push({it->first, it->second});// max_pq.push(*it) works too
            if (max_pq.size() > k) max_pq.pop();
        }
        vector<int> sol;
        while (!max_pq.empty()) {
            auto [val,cnt] = max_pq.top();
            max_pq.pop();
            sol.push_back(val);
        }
        return sol;
    }
};
