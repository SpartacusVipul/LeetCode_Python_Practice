class Solution {
public:
    // basic idea is maintain two arrays, prefix and poistfix
    // an index in prefix array maintains product of all elements till that index to the left of the index
    // an index in postfix array maintains product of all elements till that index to the right of the index
    // finally, once we have prefix and postfix, product of array except self at i is prefix[i - 1] * postfix[i + 1]
    // because i - 1 has product of all left elements including i - 1 same for postfix i + 1
    // base case first element is just postfix[1], last element is prefix[n - 2]
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size(), 0), postfix(nums.size(), 0);
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            prefix[i] = nums[i] * (i > 0 ? prefix[i - 1] : 1);
            postfix[n - i - 1] = nums[n - i - 1] * (n - i - 1 < n - 1 ? postfix[n - i] : 1);
        }

        // for (int i = 0; i < n; i++) {
        //     cout << "prefix: " << prefix[i] << " postfix: " << postfix[i] << endl;
        // }

        vector<int> resVec(nums.size(), 0);
        for (int i = 1; i < nums.size() - 1; i++) {
            resVec[i] = prefix[i - 1] * postfix[i + 1];
        }
        resVec[0] = postfix[1];
        resVec[n - 1] = prefix[n - 2];
        return resVec;
    }
};