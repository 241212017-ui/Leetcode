class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char , int> f;
        for(char c :t)
        f[c]++;
        int count  =t.size();
        int low =0 ;
        int start =0 ;
        int minLen = INT_MAX;
        for(int high =0 ; high<s.size() ; high++){
            if(f[s[high]]>0)
            count--;
            f[s[high]]--;
            while(count==0){
                if(high -low +1 < minLen){
                    minLen = high -low+1;
                    start = low;
                }
                f[s[low]]++;
                if(f[s[low]]>0)
                count++;
                low++;
            }
            
        }
        if(minLen == INT_MAX)
        return "";
        return s.substr(start , minLen);
        
    }
};