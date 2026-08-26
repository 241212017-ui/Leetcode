class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int left = 0;
        int n = s.length();
        int ones = 0;
        string ans = "";

        for (int right = 0; right < n; right++) {

            // Add current character
            if (s[right] == '1') {
                ones++;
            }

            // More than k ones -> shrink window
            while (ones > k) {
                if (s[left] == '1') {
                    ones--;
                }
                left++;
            }

            // Exactly k ones
            if (ones == k) {

                // Remove leading zeroes
                while (s[left] == '0') {
                    left++;
                }

                string current = s.substr(left, right - left + 1);

                // Update answer
                if (ans == "" ||
                    current.length() < ans.length() ||
                    (current.length() == ans.length() && current < ans)) {
                    ans = current;
                }
            }
        }

        return ans;
    }
};