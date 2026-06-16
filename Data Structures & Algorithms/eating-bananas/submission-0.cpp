class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //minimise: sum of ceil(piles[i]/k) (should be less than h)
        //vary k from 1 to max element of piles - binary search)
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int k = 1, sm = 0;
        while (low <= high) {
            k = low + (high-low)/2;
            sm = 0;
            for (int i : piles) {
                double val = i/double(k);
                sm += ceil(val);
            }
            //if sm<=h, k should be deccreased to reduce sm
            //if sm>h, k should be increased to reduce sm
            if (sm <= h) high = k-1;
            else low = k+1;
        }
        return low;
    }
};
