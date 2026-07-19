class Solution {
public:
    string smallestSubsequence(string s) {
  vector<int> lastindex(26);
  for(int i =0;  i<s.size(); i++)
  lastindex[s[i]-'a'] = i;
  vector<bool> instack(26, false);
  string st;
  for(int i =0;  i<s.size();  i++){
    char ch = s[i];
    if(instack[ch- 'a'])
    continue;
    while(!st.empty() && st.back() > ch && lastindex[st.back() - 'a']>i){
        instack[st.back()-'a']  =false;
        st.pop_back();
    }
    st.push_back(ch);
    instack[ch-'a'] =true;
  }
   return st;
    }
};