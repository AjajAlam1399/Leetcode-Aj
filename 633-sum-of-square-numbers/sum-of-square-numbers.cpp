class Solution {
    using ll=long long;
public:
    bool judgeSquareSum(int c) {
         
         for(ll i=0;i*i<=c;i++){
            ll a=i*i;
            ll b=c-a;
            ll srtt=sqrt(b);
            if(b==srtt*srtt)return true;
         }
         return false;
    }
};