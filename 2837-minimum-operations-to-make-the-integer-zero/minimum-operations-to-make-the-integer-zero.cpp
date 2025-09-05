class Solution {
    using ll=long long;
public:
    int makeTheIntegerZero(int num1, int num2) {
        
        ll s=0,e=64;

        int ans=-1;

        for(int i=1;i<64;i++){
            ll curr=num1-1LL*i*num2;
            // cout<<curr<<"-"<<i<<endl;
            if(curr<0){
                continue;
            }
            int cnt=0;
            for(int j=0;j<64;j++){
                int bit=((curr>>j)&(1));
                if(bit){
                    cnt++;
                }
            }
            if(cnt<=i && i<=curr){
                return i;
            }
        }
        return -1;
    }
};