class Solution {
    int clearBit(int num,int pos){
        int val=1<<pos;
        val=~val;
        int ans=(num&val);
        // cout<<ans<<endl;
        return ans;
    }
public:
    int rangeBitwiseAnd(int left, int right) {
        
        int leftsetbit=-1;
        int rightsetbit=-1;
        bool flag1=false;
        bool flag2=false;
        for(int i=31;i>=0;i--){
            int bit1=((left>>i)&1);
            int bit2=((right>>i)&1);
            if(bit1 && leftsetbit==-1){
                leftsetbit=i;
                flag1=true;
            }
            if(bit2 && rightsetbit==-1){
                rightsetbit=i;
                flag2=true;
            }
            if(flag1 && flag2){
                break;
            }
        }
        // cout<<leftsetbit<<" "<<rightsetbit<<endl;
        if(leftsetbit==-1 || rightsetbit==-1 || leftsetbit!=rightsetbit){
            return 0;
        }
        return (1<<leftsetbit)+rangeBitwiseAnd(clearBit(left,leftsetbit),clearBit(right,rightsetbit));
    }
};