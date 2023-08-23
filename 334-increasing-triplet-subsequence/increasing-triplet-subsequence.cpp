class Solution {
public:
    // similar to produyct of array except selft
    // left min array element at index i holdes minimum element to the left of the index including the index element
    // right max array element at index i holds maximum element to the right of the index including the index element
    // finally we iterate from 1 to n - 2 and see if any element i such that leftMin[i - 1] < nums[i] && nums[i] < rightMax[i + 1]
    bool increasingTriplet(vector<int>& nums) {
        vector<int> leftMin(nums.size(), INT_MAX), rightMax(nums.size(), INT_MIN);
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            leftMin[i] = min(nums[i], i > 0 ? leftMin[i - 1] : INT_MAX);
            rightMax[n - i - 1] = max(nums[n - i - 1], n - i - 1 < n - 1 ? rightMax[n - i] : INT_MIN);
        }

        for (int i = 1; i < nums.size() - 1; i++) {
            if (leftMin[i - 1] < nums[i] && nums[i] < rightMax[i + 1]) {
                return true;
            }
        }
        return false;
    }
};