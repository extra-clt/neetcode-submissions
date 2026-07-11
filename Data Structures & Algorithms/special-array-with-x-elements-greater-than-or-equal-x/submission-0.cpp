class Solution {
public:
    int specialArray(vector<int>& nums) {
        map<int,int> m;
        for (int i : nums) m[i]++;
        int pref = 0, tot = nums.size();
        for (auto it = m.begin(); it != m.end(); ++it) {
            int tmp = it->second;
            it->second = tot - pref;
            pref += tmp;
        } 
        int prev = 0, curr = -1, val = -1;
        /*for (auto it = m.begin(); it != m.end(); ++it) {
            cout << it->first << "," << it->second << endl;
        }*/
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (it->first == it->second) return it->first;
            else if (it->first < it->second) prev = it->first;
            else {
                curr = it->first; 
                val = it->second;
                break;
            }
        }
        if (curr == -1) return -1;
        for (int i = prev+1; i < curr; i++) {
            if (i == val) return i;
        }
        return -1;
    }
};