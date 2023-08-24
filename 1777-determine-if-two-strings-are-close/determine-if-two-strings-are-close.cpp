class Solution {
public:
    // here set means a vector 
    // base case is obvious, that both words must have the same size 
    // from here, we have two sets to maintain that both words have same set of characters 
    // another two sets to maintain the frequencies of characters encountered
    // both words must have the same characters, 
    // the same characters can have differen frequencies in both the words to be able to be close 
    // so we sort s3 and s4 to check if check if freqeuncoes are matching 
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) {
            return false;
        }

        vector<int> s1(26, 0), s2(26, 0), s3(26, 0), s4(26, 0);
        for (auto i : word1) {
            s1[i - 'a'] = 1;
            s3[i - 'a']++;
        }
        for (auto i : word2) {
            s2[i - 'a'] = 1;
            s4[i - 'a']++;
        }
        

        // check if frequencies are matching, i.e same frequences are present, albiet for different chars
        sort(s3.begin(), s3.end());
        sort(s4.begin(), s4.end());
        return s1 == s2 && s3 == s4;
    }
};