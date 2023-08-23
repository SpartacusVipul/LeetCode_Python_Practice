#include <iostream>
#include <string>
#include <sstream>
#include <vector>
class Solution {
public:
    // go through the soluition again, 
    // this is a scanning from right
    // find a word add this to res, and so on
    string reverseWords(string s) {
        string rev = "";
        int i = 0, j;
        while (i < s.size()) {
            // loop to skip iniital spaces 
            while (i < s.size() && s[i] == ' ') {
                i++;
            }
            j = i;
            // loop to iterate over the word till we encounter a space 
            while (j < s.size() && s[j] != ' ') {
                j++;
            }
            // cout << "i: " << i << " j:" << j << endl;
            // if there is no word then j - i will be equal to zero
            if (j - i == 0) {
                break;
            }
            // extracting substring from the string, substr(startindex, length from the start index)
            string word = s.substr(i,j - i);
            if (rev.size() == 0) {
                rev = word;
                // cout << "|" << rev << "|" << endl;
            } else {
                // tricky part is to do below, where we are adding the total string in the end 
                rev = word + " " + rev;
                // cout << "|" << rev << "|" << endl;
            }
            i = j;
        }
        return rev;
    }
};