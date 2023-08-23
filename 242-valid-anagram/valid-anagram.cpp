class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        vector<int> charArr(26, 0);
        for (int i = 0; i < s.size(); i++) {
            charArr[s[i] - 'a'] ++; // very important
            charArr[t[i] - 'a'] --; // we cannot add both and do % 2 and check if 0 
            // this is becasue for string aa bb, there will be error
        }

        for (int i = 0; i < 26; i++) {
            if (charArr[i] != 0) {
                return false;
            } 
        }
        return true;
    }
};