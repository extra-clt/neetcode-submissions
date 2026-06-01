class Solution {
public:
    int trap(vector<int>& height) {
        int bar = 0, n = height.size(), i = 0, j = n-1, ans = 0;
        vector<int> tmp(n,0);
        tmp[i] = height[i];
        tmp[j] = height[j];
        bar = min(tmp[i], tmp[j]);
        while (i < j) {
            if (height[i] < height[j]) {
                i++;
                tmp[i] = max(bar,height[i]);
            }
            else {
                j--;
                tmp[j] = max(bar,height[j]);
            }
            bar = min(tmp[i], tmp[j]);
            
        }
        for (int i : tmp) cout << i << " ";
        for (int k = 0; k < n; k++) {
            ans += tmp[k]-height[k];
        }
        return ans;
    }
};
//0,2,2,3,3,3,3,3,2,1
//1,2,3