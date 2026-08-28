class Solution {
public:

    string buildPalindrome(string &half, char mid, int n) {
        string ans = half;

        if (n % 2)
            ans += mid;

        string rev = half;
        reverse(rev.begin(), rev.end());

        ans += rev;

        return ans;
    }

    string lexPalindromicPermutation(string s, string target) {

        int n = s.size();

        // Count characters
        vector<int> cnt(26, 0);

        for (char ch : s) {
            cnt[ch - 'a']++;
        }

        // Check whether a palindrome can be formed
        int odd = 0;
        char mid = '#';

        for (int i = 0; i < 26; i++) {

            if (cnt[i] % 2) {
                odd++;
                mid = char('a' + i);
            }
        }

        if (odd > 1)
            return "";

        // Characters available for first half
        vector<int> halfCnt(26);

        for (int i = 0; i < 26; i++) {
            halfCnt[i] = cnt[i] / 2;
        }

        int halfLen = n / 2;

        string half = "";
        string answer = "";

        function<bool(int, bool)> dfs =
            [&](int pos, bool greater) -> bool {

                // Finished first half
                if (pos == halfLen) {

                    string candidate =
                        buildPalindrome(half, mid, n);

                    /*
                        This is the important part.

                        Even if the first half is equal to
                        target's first half, the mirrored half
                        may make the complete palindrome greater.
                    */
                    if (candidate > target) {
                        answer = candidate;
                        return true;
                    }

                    return false;
                }

                int targetChar = target[pos] - 'a';

                /*
                    Once the prefix is greater,
                    choose the smallest possible remaining
                    characters.
                */
                if (greater) {

                    for (int c = 0; c < 26; c++) {

                        if (halfCnt[c] == 0)
                            continue;

                        halfCnt[c]--;
                        half.push_back(char('a' + c));

                        if (dfs(pos + 1, true))
                            return true;

                        half.pop_back();
                        halfCnt[c]++;
                    }

                    return false;
                }

                /*
                    Prefix is still equal.

                    We cannot choose a character smaller than
                    target[pos].
                */
                for (int c = targetChar; c < 26; c++) {

                    if (halfCnt[c] == 0)
                        continue;

                    halfCnt[c]--;
                    half.push_back(char('a' + c));

                    bool newGreater = (c > targetChar);

                    if (dfs(pos + 1, newGreater))
                        return true;

                    half.pop_back();
                    halfCnt[c]++;
                }

                return false;
            };

        if (dfs(0, false))
            return answer;

        return "";
    }
};