class Solution {
public:
    int countSubstrings(string s) 
    {
        int cnt=0;
        int n=s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,false));

        for(int g=0;g<n;g++){
            for(int i=0,j=g;j<n;i++,j++){
                if(g==0){
                    dp[i][j]=true;
                }
                else if(g==1){
                    dp[i][j]=s[i]==s[j];
                }
                else{
                    if(s[i]==s[j] && dp[i+1][j-1]==true){
                        dp[i][j]=true;
                    }
                }
                if(dp[i][j]){
                cnt++;
            }
            }
            
        }
        return cnt;
    }

    bool isValid(string st,int i,int j){

        while(j>i){
            if(st[i]!=st[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};