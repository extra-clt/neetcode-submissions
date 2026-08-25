class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(t) != len(s):
            return False;
        freq = {}
        for x in s:
            freq[x] = freq.get(x,0)+1
        for y in t:
            freq[y] = freq.get(y,0)-1
        for x in freq:
            if freq[x] != 0:
                return False
        return True

        