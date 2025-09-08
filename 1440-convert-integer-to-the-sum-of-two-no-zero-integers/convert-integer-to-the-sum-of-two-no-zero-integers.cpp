class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int a,b;
        for(int i=1;i<=n;i++){
            a=i;
            if(checkZero(a)){
                b=n-i;
                if(checkZero(b)){
                    break;
                }
            }
        }
        return {a,b};
    }
    bool checkZero(int n){

        int temp=n;

        while(temp){
            int mod=temp%10;
            if(mod==0)return false;
            temp=temp/10;
        }
        return true;
    }
};