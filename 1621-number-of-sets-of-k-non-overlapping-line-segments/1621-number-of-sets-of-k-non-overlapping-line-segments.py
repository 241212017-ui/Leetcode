class Solution:
    def numberOfSets(self, n, k):
        MOD = 10**9 + 7

        a = n + k - 1
        b = 2 * k

        fact = [1] * (a + 1)

        for i in range(1, a + 1):
            fact[i] = fact[i - 1] * i % MOD

        ans = fact[a]

        ans = ans * pow(fact[b], MOD - 2, MOD) % MOD
        ans = ans * pow(fact[a - b], MOD - 2, MOD) % MOD

        return ans