class Solution {
    using ll=long long;
public:
    int mySqrt(int x) {
        if(x==1)return 1;
        ll start=1,right=x;

        while(start<right){
            ll mid=(start+right)/2;
            if(mid*mid<=x){
                start=mid+1;
            }
            else{
                right=mid;
            }
        }
        return start-1;
    }
};