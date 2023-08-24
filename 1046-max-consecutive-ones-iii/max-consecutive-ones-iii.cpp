class Solution {
public:
    // basic idea is when we encounter a 0, we increment a condition counter 
    // if condition counter is greater than k then we start incrementing left index 
    // if nums[leftIndex] == 0 implies we are removing a zero from our window 
    // this leads to reducting in condition counter 
    // everytime calculate the maxWindow size as right - left + 1
    int longestOnes(vector<int>& nums, int k) {
        int leftIndex = 0, rightIndex = 0;
        int condition = 0;
        int resSize = 0;
        while(rightIndex < nums.size()) {
            if (nums[rightIndex] == 0) {
                condition++;
            }
            while (condition > k) {
                if (nums[leftIndex] == 0) {
                    condition--;
                }
                leftIndex++;
            }
            resSize = max(resSize, rightIndex - leftIndex + 1);
            rightIndex++;
        }
        return resSize;
    }
};