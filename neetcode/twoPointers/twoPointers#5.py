from typing import List
class Solution:
    def trap(self, height: List[int]) -> int:
        maxLeft, maxRight = height[0], height[len(height)-1]
        ret = 0
        l = 1
        r = len(height) - 2
        while r >= l:
            if maxLeft > maxRight:
                if height[r] > maxRight:
                    maxRight = height[r]
                elif maxRight > height[r]:
                    ret += (maxRight - height[r])
                r -= 1
            else:
                if height[l] > maxLeft:
                    maxLeft = height[l]
                elif maxLeft > height[l]:
                    ret += (maxLeft - height[l])
                l += 1
        return ret