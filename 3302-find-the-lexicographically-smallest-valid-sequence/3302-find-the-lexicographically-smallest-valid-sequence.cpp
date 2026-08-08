class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n=  word2.size();
        vector<int> last( n ,-1);
        int j = n-1;
        for(int i = word1.size()-1; i>=0; --i){
            if(j >= 0 && word1[i] == word2[j]){
                last[j] =i;
                j--;
            }
        }
        j =0 ;
        int flag =1;
        vector<int> ans;
        for(int i =0;  i<word1.size() ; ++i)
{
       if(j<n){
        if(word1[i] == word2[j] ||  (flag == 1 &&(j ==n-1 || i+1<= last[j+1]))){
            if(word1[i] != word2[j]){
                flag = 0;
            }
            ans.push_back(i);
            j++;
        }
       }
}    

  return (j == n)? ans: vector<int>();
}
};