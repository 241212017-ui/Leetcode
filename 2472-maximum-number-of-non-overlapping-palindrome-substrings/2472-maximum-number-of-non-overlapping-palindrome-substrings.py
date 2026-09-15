class Solution(object):
    def maxPalindromes(self, s, k):
        n = len(s)

        # palindrome[l][r] = True if s[l...r] is a palindrome
        palindrome = [[False] * n for _ in range(n)]

        # Build palindrome table
        for length in range(1, n + 1):
            for l in range(n - length + 1):
                r = l + length - 1

                if s[l] == s[r]:
                    if length <= 2:
                        palindrome[l][r] = True
                    else:
                        palindrome[l][r] = palindrome[l + 1][r - 1]

        # dp[i] = maximum palindromes using first i characters
        dp = [0] * (n + 1)

        for i in range(1, n + 1):
            # Don't choose a palindrome ending at i-1
            dp[i] = dp[i - 1]

            # Try every palindrome ending at i-1
            for j in range(i - k + 1):
                if palindrome[j][i - 1]:
                    dp[i] = max(dp[i], dp[j] + 1)

        return dp[n]