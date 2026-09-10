class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:

        low = 0
        res = 0
        f = {}

        for high in range(len(s)):

            f[s[high]] = f.get(s[high], 0) + 1

            while f[s[high]] > 1:
                f[s[low]] -= 1
                low += 1

            length = high - low + 1
            res = max(res, length)

        return res