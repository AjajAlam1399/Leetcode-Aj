class Solution {
    using ll=long long;
public:
    long long repairCars(vector<int>& ranks, int cars) {
        ll s=1 ,e=1e14;
        ll ans=e;

        while(s<=e){
            ll mid=(s+e)/2;
            if(check(ranks,mid,cars)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }

        return ans;
    }

    bool check(vector<int>&ranks,ll ans,int cars){
        ll cnt=0;
        for(int i=0;i<ranks.size();i++){
            cnt+=sqrt((ans/(ll)ranks[i]));
            if(cnt>=cars)return true;
        }
        return false;
    }
};