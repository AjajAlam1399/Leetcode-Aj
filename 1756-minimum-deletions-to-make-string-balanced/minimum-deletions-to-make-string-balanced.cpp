class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        vector<int>b(n,0);
        vector<int>a(n,0);
        int cnt=0;

        for(int i=n-1;i>=0;i--){
            if(s[i]=='b'){
                cnt++;
            }
            b[i]=cnt;
        }
        int ans=n;

        cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                cnt++;
                ans=min(ans,n-cnt-b[i]);
            }
            a[i]=cnt;
        }
        cnt=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='b'){
                cnt++;
                ans=min(ans,n-cnt-a[i]);
            }
        }

        return ans;
    }

};