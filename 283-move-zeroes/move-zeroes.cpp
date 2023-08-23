class Solution {
public:
    // lot of inherent logic, like if the first number is 1 like [1,0,3,0,12], then both left and right are at 1, so, we swap them (does nothing) and increment both left and right, 
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if (n == 0 || n == 1) {
            return;
        }
        // left is made to wait whenever we encounter a zero, 
        // right is incremented till we encounter a non zero 
        // whenever right is non zero, left and right are swapped and left and right are incremented 
        // this way 0 0 0 1 2 3 initially left and right are at first 0 
        // right is incremented till its value becomes 1 
        // now values in left and right are swapped leading to 1 0 0 0 2 3 
        // now left and right are incremented where left will be pointing to second 0 and right to 2 
        // now again since right is not equal to zero and left is equal to zero, we swap 

        // again lot of inherent logic, in case of 0 1 2 3, it becomes 1 0 2 3 then 1 2 0 3 then 1 2 3 0 
        int left = 0, right = 0;
        int temp;
        while (right < n) {
            if (nums[right] == 0) {
                right++;
            } else {
                temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
                left++;
                right++;
            }
        }

    }
};