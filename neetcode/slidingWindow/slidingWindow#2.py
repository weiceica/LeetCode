class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        c = set()
        ret, r = 0, 0
        for l, lval in enumerate(s):
            while lval in c:
                c.remove(s[r])
                r += 1
            c.add(lval)
            ret = max(ret, l - r + 1)
        return ret
        
            
