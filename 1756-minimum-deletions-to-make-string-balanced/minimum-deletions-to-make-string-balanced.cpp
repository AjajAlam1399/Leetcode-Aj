class Solution {
    using ll=long long;
public:
    int minimumDeletions(string s) {
         int bcnt=0,acnt=0,n=s.size();
         vector<int>aarr(n);
         vector<int>barr(n);

         for(int i=0;i<n;i++){
            aarr[i]=bcnt;
            if(s[i]=='b')bcnt++;
         }
         for(int i=n-1;i>=0;i--){
            barr[i]=acnt;
            if(s[i]=='a')acnt++;
         }
         int ans=INT_MAX;

         for(int i=0;i<n;i++){
            ans=min(ans,aarr[i]+barr[i]);
         }
         return ans;
    }

    
};