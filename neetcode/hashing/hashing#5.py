from typing import List
from collections import Counter

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        memo = Counter(nums)
        ret = []
        j = 0
        sortedC = dict(sorted(memo.items(), key=lambda x:-x[1]))
        for key, val in sortedC.items():
            if j < k and key not in ret:
                ret.append(key)
                j += 1
        return ret