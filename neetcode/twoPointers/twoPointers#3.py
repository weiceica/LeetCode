from typing import List
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        ret = []
        nums.sort()
        for i in range(len(nums)):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            l = i + 1
            h = len(nums) - 1
            while l < h:
                if nums[i] + nums[l] + nums[h] == 0:
                    ret.append([nums[i], nums[l], nums[h]])
                    l += 1
                    while nums[l-1] == nums[l] and l < h:
                        l += 1
                elif nums[l] + nums[h] > -nums[i]:
                    h -= 1
                else:
                    l += 1
        return ret