class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        //dont consider triplets whose vals greator than target(x,y,z)
        //or even put -1,-1,-1
        int max_x = 0, max_y = 0, max_z = 0;
        for (int i = 0; i < triplets.size(); i++) {
            if (triplets[i][0] <= target[0] && triplets[i][1] <= target[1] && triplets[i][2] <= target[2]) {
                max_x = max(triplets[i][0], max_x);
                max_y = max(triplets[i][1], max_y);
                max_z = max(triplets[i][2], max_z);
            }
        }
        if (max_x == target[0] && max_y == target[1] && max_z == target[2]) return true;
        return false;
    }
};
