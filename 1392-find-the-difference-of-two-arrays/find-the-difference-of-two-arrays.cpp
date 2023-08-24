class Solution {
public:
    // first insert all elements of both vectors into two different sets 
    // once inserted, we have a vector of res which has set<int> elemnts 
    // iterate over nums1, and if an element from nums1 is not found in s2, then insert into res[0] 
    // same for nums2 
    // finally convert the set to a vector 
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1, s2;
        for (auto it: nums1) {
            s1.insert(it);
        }
        for (auto it: nums2) {
            s2.insert(it);
        }

        vector<set<int>> res(2);
        for (auto it: nums1) {
            if (s2.count(it) == 0) {
                res[0].insert(it);
            }
        }
        for (auto it: nums2) {
            if (s1.count(it) == 0) {
                res[1].insert(it);
            }
        }
        vector<vector<int>> ans(2);
        ans[0] = vector<int>(res[0].begin(), res[0].end());
        ans[1] = vector<int>(res[1].begin(), res[1].end());
        
        return ans;
    }
};