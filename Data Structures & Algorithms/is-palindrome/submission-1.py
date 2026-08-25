class Solution:
    def isPalindrome(self, s: str) -> bool:
        word = ""
        for x in s:
            if x.isalnum():
                word += x.lower()
        return word == word[::-1]