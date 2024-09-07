class Solution {
public:
    string longestPrefix(string s) {
        int n=s.size();
        vector<int>lps(n,0);
        int len=0,i=1;

        while(i<n){

            if(s[i]==s[len]){
                lps[i]=len+1;
                len++;
                i++;
            }
            else{
                if(len!=0){
                    len=lps[len-1];
                }
                else{
                    i++;
                }
            }
        }
        if(!lps[n-1])return "";
        string ans="";
        for(i=n-1-lps[n-1]+1;i<=n-1;i++){
            ans.push_back(s[i]);
        }
        return ans;
    }
};