class Solution {
    using ll=long long;
public:
    int minTime(string S, vector<int>& order, int k) {
        
        ll n=order.size();
        
        ll total=((n)*(n+1))/2;

        if(k>total)return -1;

        int s=0,e=n-1;
        int ans=0;
        while(s<=e){
            int mid=(s+e)/2;

            if(check(S,order,mid,k)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }

    bool check(string s,vector<int>&order,int mid,int k){
        for(int i=0;i<=mid;i++){
            s[order[i]]='*';
        }
        ll ans=0;
        ll cnt=0;
        ll n=s.size();
        for(int i=0;i<s.size();i++){
            if(s[i]=='*'){
                ans+=n-i;
                ans+=(cnt)*(n-i);
                cnt=0;
            }
            else{
                cnt++;
            }
        }
        // cout<<mid<<"-"<<ans<<endl;
        return ans>=k;
    }
};