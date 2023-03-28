from typing import List
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        uniques = set(nums)
        maxL = 0
        while uniques:
            low = uniques.pop()
            high = low
            while low - 1 in uniques or high + 1 in uniques:
                if low - 1 in uniques:
                    uniques.remove(low - 1)
                    low -= 1
                if high + 1 in uniques:
                    uniques.remove(high + 1)
                    high += 1
            maxL = max(high - low + 1, maxL)
        return maxL