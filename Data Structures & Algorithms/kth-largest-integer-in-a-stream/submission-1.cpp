class KthLargest {
public:
    priority_queue<int,vector<int>,greater<>> pq;
    vector<int> nums;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        this->nums = nums;
        for (int i : nums) {
            pq.push(i);
            if (pq.size() > k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > k) pq.pop();
        return pq.top();
    }
};
