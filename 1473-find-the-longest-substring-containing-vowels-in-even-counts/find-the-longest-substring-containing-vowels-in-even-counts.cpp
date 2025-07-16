class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n=s.size();
        vector<int>dp(1<<6,n+1);

        dp[0]=-1;

        int ans=0;
        int curr=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'){
                curr^=(1<<0);
            }
            else if(s[i]=='e'){
                curr^=(1<<1);
            }
            else if(s[i]=='i'){
                curr^=(1<<2);
            }
            else if(s[i]=='o'){
                curr^=(1<<3);
            }
            else if(s[i]=='u'){
                curr^=(1<<4);
            }
            ans=max(ans,i-dp[curr]);
            dp[curr]=min(dp[curr],i);
        }
        return ans;
    }
};