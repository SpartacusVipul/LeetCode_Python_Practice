class Solution {
public:
    int pivotIndex2(vector<int>& nums) {
        // modify this approach if you get time or revisit, here we are initially calculating prefix sum from left to right, change to right to left and then the second loop from left to right and it should work
        vector<int> prefixSum(nums.size() + 1, 0);
        int currentSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        for (int i = nums.size() - 1; i > 0; i--) {
            cout << "Prefix Sum: " << prefixSum[i - 1] << " Current Sum: " << currentSum << endl;
            if (prefixSum[i] == currentSum) {
                return i;
            }
            currentSum += nums[i];
        }
        if (prefixSum[0] == currentSum)
            return 0; 
        return -1;
    }
    // pivot index here means, do not consider that index 
    // and then the sum of elements in the left half is equal to sum 
    // of elements in the right half 
    // so, first calculate the total sum of the array 
    // given that for index 0, the sum of left half is equal to zero and at last index 
    // right half is equal to zero 
    // with this, we have a total sum value, 
    // for every index, keep calculating the  prefix sum (sum not including the current element)
    // if we remove current element from total sum and it is equal to 2 * prefix sum it implies 
    // the prefix sum is calcualted as sum of elements in the left half, so 
    // if tital sum - current element is equal to 2 * prefix sum, it implies, left half is equal to right half 
    // so ......
    int pivotIndex(vector<int>& nums) {
        int prefixSum = 0;
        int totalSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            totalSum += nums[i];
        }
        for (int i = 0; i < nums.size(); i++) {
            cout << "prefixSum: " << prefixSum << " totalSum: " << totalSum << endl;
            if (totalSum - nums[i] == 2 * prefixSum) {
                return i;
            }
            prefixSum += nums[i];
        }      
        return -1;
    }
};