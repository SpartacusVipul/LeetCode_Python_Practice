class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        int runningSum = 0;
        int maxSize = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            runningSum += nums[i];
            if (runningSum > maxSize) {
                maxSize = runningSum;
            }
            if (runningSum < 0) {
                runningSum = 0;
            } 
        }
        return maxSize;
    }
};