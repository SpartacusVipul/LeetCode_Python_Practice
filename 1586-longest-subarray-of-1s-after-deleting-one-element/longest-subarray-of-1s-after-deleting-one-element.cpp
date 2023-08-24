class Solution {
public:
    // problem says, we should delete one element, no other option, 
    // but still rightIndex - leftInbex will work
    // assume we deleted a zero between, then rightIndex - leftIndex will be thee size of subarry with all 1's
    // assume we did not delete an element, then rightIndex - leftIndex + 1 will be all 1's, but since we delete one 1, we get rightIndex - leftIndex
    // as of Aug 23, I do not remember solving this problem 
    // but as per the above explanation, as we always have to delete one element, even if there are all 1's 
    // this is same as previous problem with k = 1 annd size = right - left 
    int longestSubarray(vector<int>& nums) {
        int leftIndex = 0, rightIndex = 0;
        int condition = 0; // max condition is given as 1
        int resSize = 0;
        while (rightIndex < nums.size()) {
            if (nums[rightIndex] == 0) {
                condition++;
            }
            while (condition > 1) {
                if (nums[leftIndex] ==0) {
                    condition--;
                }
                leftIndex++;
            }
            resSize = max(resSize, rightIndex - leftIndex);
            rightIndex++;
        }
        return resSize;
    }
};