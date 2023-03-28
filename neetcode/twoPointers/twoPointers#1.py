import re
class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()
        s = re.sub(r'[^a-zA-Z0-9]', '', s)
        for i in range(len(s)):
            if(i > len(s)/2):
                continue
            if(s[i] != s[len(s)-i-1]):
                return False
        return True