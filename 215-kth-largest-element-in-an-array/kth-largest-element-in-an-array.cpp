class Solution {
public:
    // default priority queue implementation in c++ is max heap
    // so, first we insert all elements into the queue, 
    // then we remove first k elements 
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }
        for (int i = 0; i < k - 1; i++) {
            pq.pop();
        }
        int res = pq.top();
        // pq.pop();
        return res;
    }
};