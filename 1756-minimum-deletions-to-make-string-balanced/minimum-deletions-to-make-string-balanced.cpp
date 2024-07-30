class Solution {
    using ll=long long;
public:
    int minimumDeletions(string s) {
         int bcnt=0,acnt=0,n=s.size();

         for(int i=0;i<n;i++){
            if(s[i]=='a')acnt++;
         }

        int ans=INT_MAX;
         for(int i=0;i<n;i++){
            if(s[i]=='a')acnt--;
            ans=min(ans,bcnt+acnt);
            if(s[i]=='b')bcnt++;
         }
         return ans;
    }

    
};