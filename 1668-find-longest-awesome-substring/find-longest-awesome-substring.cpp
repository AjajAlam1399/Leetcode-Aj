class Solution {
public:
    int longestAwesome(string s) {

        int n=s.size();

        vector<int>dp(1<<11,n);
        dp[0]=-1;

        int ans=0;
        int curr=0;

        for(int i=0;i<n;i++){
            curr^=(1<<(s[i]-'0'));

            ans=max(ans,i-dp[curr]); // even length

            for(int j=0;j<10;j++){ // odd length
                int temp=curr;
                ans=max(ans,i-dp[(temp^=(1<<j))]);
            }

            dp[curr]=min(dp[curr],i);
        }

        return ans;
    }
};