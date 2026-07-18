class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> res;

        if (s.empty() || words.empty())
            return res;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int windowLen = wordLen * wordCount;

        if (s.size() < windowLen)
            return res;

        unordered_map<string, int> need;

        for (string word : words)
            need[word]++;

        // Try every possible starting offset
        for (int offset = 0; offset < wordLen; offset++) {

            unordered_map<string, int> window;
            int left = offset;
            int count = 0;

            for (int right = offset; right + wordLen <= s.size(); right += wordLen) {

                string word = s.substr(right, wordLen);

                if (need.count(word)) {

                    window[word]++;
                    count++;

                    while (window[word] > need[word]) {
                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    if (count == wordCount) {
                        res.push_back(left);

                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                } else {

                    window.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }

        return res;
    }
};