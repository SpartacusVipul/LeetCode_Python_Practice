class Solution {
public:
    // basic idea is have two  pointers p1 and p2,
    // p1 is from s, p2 is from t
    // if s[p1] == t[p2] then increment both, 
    // otherwise increment only p2 (on which we are chekcing if s is a subsequence)
    // finally, if p1 goes till its last index, then it means s is a subsequence
    // therefore finally checking p1 == s.size()
    bool isSubsequence(string s, string t) {
        int p1 = 0, p2 = 0;

        while (p2 < t.size() && p1 < s.size()) {
            if (s[p1] == t[p2]) {
                p1++;
                p2++;
            } else {
                p2++;
            }
        }
        return p1 == s.size(); // basically if we reached enf od s, only them s is substring
    }
};