from collections import Counter
class Solution:
    def findTheDifference_(self, s: str, t: str) -> str:
        s_dict = {}
        for char in s:
            if char in s_dict:
                s_dict[char] += 1
            else :
                s_dict[char] = 1
        
        for char in t:
            if char in s_dict:
                s_dict[char] -= 1
                if s_dict[char] == 0:
                    s_dict.pop(char)
            else:
                return char
        return ""
    
    def findTheDifference(self, s: str, t: str) -> str:
        s_counter = Counter(s)
        for ch in t:
            if ch not in s_counter or s_counter[ch] == 0:
                return ch
            else:
                s_counter[ch] -= 1
        return ""
