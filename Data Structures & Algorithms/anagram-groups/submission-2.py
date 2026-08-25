class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        freq = {}
        for s in strs:
            a = [0] * 26
            word = ""
            for x in s:
                a[ord(x)-ord('a')] += 1
            for x in a:
                word += str(x)
                word += "+"
            #freq[word] = freq.get(word,0)+1
            if word not in freq:
                freq[word] = []
            freq[word].append(s)
        sol = []
        for x in freq:
            sol.append(freq[x])
        return sol
            
