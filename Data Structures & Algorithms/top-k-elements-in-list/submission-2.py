#from collections import Counter
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = Counter(nums)
        ls = freq.most_common(k)
        sol = []
        for x in ls:
            sol.append(x[0])
        return sol

