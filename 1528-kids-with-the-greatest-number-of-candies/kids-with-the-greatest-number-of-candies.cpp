class Solution {
public:
    // pretty straightforward 
    // we need to check if giving all extra candies to a single kid will result in that kid having 
    // maximum number of candies 
    // with this understanding, first find the maximum number of candies among all kids 
    // then for every kid check if their candies + extra candeis is greater than max 
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = INT_MIN;
        for (int i = 0; i < candies.size(); i++) {
            max = candies[i] > max ? candies[i] : max;
        }
        vector<bool> res;
        for (int i = 0; i < candies.size(); i++) {
            if (candies[i] + extraCandies >= max) {
                res.push_back(true);
            } else {
                res.push_back(false);
            }
        }
        return res;
    }
};