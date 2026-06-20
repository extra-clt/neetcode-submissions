class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        //if i use map, its ordered but o(nlogn)
        //if i dont use map, i need to calc minimum for every group.
        //take all counts
        //for the first minimum, take the next grpsize-1 numbers and
        //subtract count of min. if less<0, return false; 
        //no need to calc min every time, 
        //in that grp if freqleft for a number > 0, thast the min., 
        //if all is zero, then i need to calc. eg: 1234 6789,
        int size = hand.size();
        if (size % groupSize != 0) return false;
        unordered_map<int,int> um;
        unordered_set<int> us;
        int minVal = hand[0];
        for (int i = 0; i < size; i++) {
            um[hand[i]]++;
            us.insert(hand[i]);
            minVal = min(minVal, hand[i]);
        }
        while (size > 0) {
            int cnt = um[minVal];
            for (int i = minVal; i < groupSize+minVal; i++) {
                um[i] -= cnt;
                if (um[i] < 0) return false;
                if (um[i] == 0) us.erase(i);
                size -= cnt;
            }
            if (size == 0) return true;
            int nextmin = -1;
            for (int i = minVal; i < groupSize+minVal; i++) {
                if (um[i]>0) {
                    nextmin = i;
                    break;
                }
            }
            if (nextmin == -1) nextmin = *min_element(us.begin(), us.end());
            minVal = nextmin;
        }
        return true;
    }
};
