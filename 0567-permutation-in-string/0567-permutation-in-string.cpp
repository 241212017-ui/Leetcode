class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if(s1.size()> s2.size())
        return false;
        vector<int>need(26,0);
        vector<int>window(26,0);
        for(char c : s1)
        need[c-'a']++;
        int k = s1.size();
        for(int i =0;  i<k; i++){
            window[s2[i] -'a']++;
            if(need == window)
            return true;
        }
        for(int i =k ; i<s2.size() ; i++){
            window[s2[i] - 'a']++;
            window[s2[i-k]- 'a']--;
            if(need ==window)
            return true;
        }
        return false;
    }
};