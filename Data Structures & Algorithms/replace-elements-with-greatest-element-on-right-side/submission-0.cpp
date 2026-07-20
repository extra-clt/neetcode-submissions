class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size(), maxElem = -1;
        for (int i = n-1; i >= 0; i--) {
            if (i == n-1) {
                maxElem = arr[i];
                arr[i] = -1;
            }
            else {
                if (arr[i] > maxElem) swap(maxElem, arr[i]);
                else arr[i] = maxElem;
            }
        }
        return arr;
    }
};