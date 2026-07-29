class Solution {
public:

    // C(n, r), but we only care whether it reaches k.
    long long combination(int n, int r, long long k) {

        if (r > n - r)
            r = n - r;

        long long res = 1;

        for (int i = 1; i <= r; i++) {

            __int128 temp = (__int128)res * (n - r + i);
            temp /= i;

            if (temp >= k)
                return k;

            res = (long long)temp;
        }

        return res;
    }


    // Number of distinct permutations of the multiset.
    // Stops once answer reaches k.
    long long countWays(vector<int>& cnt, int total, long long k) {

        long long ways = 1;
        int remaining = total;

        for (int c : cnt) {

            if (c == 0)
                continue;

            // Choose positions for this character.
            // Example:
            // aabb -> C(4,2) * C(2,2) = 6
            long long choose = combination(remaining, c, k);

            __int128 temp = (__int128)ways * choose;

            if (temp >= k)
                return k;

            ways = (long long)temp;

            remaining -= c;
        }

        return ways;
    }


    string smallestPalindrome(string s, int k) {

        int n = s.size();
        int half = n / 2;

        // Frequency of characters in left half
        vector<int> cnt(26, 0);

        for (int i = 0; i < half; i++) {
            cnt[s[i] - 'a']++;
        }

        // Find middle character if n is odd
        char middle = 0;

        if (n % 2 == 1) {
            for (char c : s) {
                int freq = 0;

                for (char x : s) {
                    if (x == c)
                        freq++;
                }

                if (freq % 2 == 1) {
                    middle = c;
                    break;
                }
            }
        }

        // Check whether k-th permutation exists
        if (countWays(cnt, half, k) < k)
            return "";


        string left;

        // Construct k-th lexicographically smallest left half
        for (int pos = 0; pos < half; pos++) {

            for (int ch = 0; ch < 26; ch++) {

                if (cnt[ch] == 0)
                    continue;

                // Try placing this character
                cnt[ch]--;

                int remaining = half - pos - 1;

                long long ways = countWays(cnt, remaining, k);

                if (ways >= k) {

                    // This character is correct
                    left.push_back(char('a' + ch));
                    break;

                } else {

                    // Skip all permutations starting with this character
                    k -= ways;

                    // Restore character
                    cnt[ch]++;
                }
            }
        }


        // Mirror left half
        string right = left;
        reverse(right.begin(), right.end());

        string ans = left;

        if (middle)
            ans += middle;

        ans += right;

        return ans;
    }
};