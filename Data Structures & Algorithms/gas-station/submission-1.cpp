class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //if total cost> gas then -1
        //if curr tot gas < cost, not possible
        //-1 0 -1 3
        //-1 -1 1
        int idx = 0, currgas = 0, store = 0;
        for (int i = 0; i < gas.size(); i++) {
            int c = gas[i]-cost[i];
            store += c;
            currgas += c;
            if (currgas < 0) {
                idx = i+1;
                currgas = 0;
            }
        }
        if (store < 0) return -1;
        if (idx >= gas.size()) return -1;
        int check = 0;
        for (int i = idx; i < gas.size(); i++) {
            check += gas[i]-cost[i];
            if (check < 0) return -1;
        }
        for (int i = 0; i < idx; i++) {
            check += gas[i]-cost[i];
            if (check < 0) return -1;
        }
        return idx;
    }
};
