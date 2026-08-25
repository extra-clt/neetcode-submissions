class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = {}
        heap = []
        sol = []
        for x in nums:
            freq[x] = freq.get(x,0)-1
        for x in freq:
            heapq.heappush(heap,(freq[x],x))
        for i in range(k):
            val = heapq.heappop(heap)
            sol.append(val[1])
        return sol