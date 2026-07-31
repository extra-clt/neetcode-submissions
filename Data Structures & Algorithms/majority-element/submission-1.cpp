class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> freq;
        int freqcnt = 0, sol = INT_MIN;
        for (int i : nums) freq[i]++;
        for (int i : nums) {
            if (freqcnt < freq[i]) {freqcnt = freq[i]; sol = i;}
        }
        return sol;
    }
};