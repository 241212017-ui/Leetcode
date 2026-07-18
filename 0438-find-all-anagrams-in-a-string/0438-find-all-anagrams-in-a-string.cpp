class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size()<p.size())
        return {};
        vector<int>need(26, 0);
        vector<int>window(26 ,0);
        vector<int>res;
        for(char c : p)
        need[c - 'a']++;
        int k =  p.size();
        for(int i =0  ; i<k;  i++)
        window[s[i] - 'a']++;
        if(need == window)
        res.push_back(0);
      for(int i =k ; i<s.size(); i++){
        window[s[i] -'a']++;
        window[s[i-k] -'a']--;
        if(need == window)
        res.push_back(i -k+1);
      }
        return res;
    }
};