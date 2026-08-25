class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        freq = {}
        for idx,x in enumerate(nums):
            if (target-x) in freq:
                return [freq[target-x],idx]
            freq[x] = idx
        return []
        