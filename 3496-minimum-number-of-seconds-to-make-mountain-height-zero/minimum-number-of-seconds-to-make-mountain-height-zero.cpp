class Solution {
    using ll =long long;
public:
    long long minNumberOfSeconds(ll h, vector<int>& arr) {
        
        long long s=1,e=*max_element(arr.begin(),arr.end());
        e=e*((h*(h+1))/2);

        ll ans=e;

        while(s<=e){
            ll mid =(s+e)/2;
            if(check(arr,mid,h)){
                ans=min(ans,mid);
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }

    bool check(vector<int>&arr,ll mid,ll h){
        ll cnt=0;

        for(int i=0;i<arr.size();i++){
            cnt+=maxDec(h,(ll)arr[i],mid);
        }
        return cnt>=h;
    }
    ll maxDec(ll h , ll val , ll maxSec){

        ll s=1, e=h;
        ll ans=0;
        while(s<=e){
            ll mid = (e+s)/2;
            ll sec = (((mid)*(mid+1))/2)*val;
            if(sec<=maxSec){
                ans = mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return ans;
    }
};