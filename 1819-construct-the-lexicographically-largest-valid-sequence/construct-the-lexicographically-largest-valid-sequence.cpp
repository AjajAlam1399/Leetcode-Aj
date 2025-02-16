class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int>ans(2*n-1);
        int bitmask=0;
        fun(0,bitmask,n,ans);
        return ans;
    }

    bool fun(int ind,int &bitmask,int n,vector<int>&ans){
        if(ind==2*n-1){
            return true;
        }
        if(ans[ind]){
            if(fun(ind+1,bitmask,n,ans))return true;
        }
        else{
            for(int i=n;i>=1;i--){
                int bit=((bitmask)&(1<<i));
                if(!bit && i==1){
                    ans[ind]=i;
                    bitmask=(bitmask)|(1<<i);
                    if(fun(ind+1,bitmask,n,ans)){
                        return true;
                    }
                    ans[ind]=0;
                    bitmask=((bitmask)&(~(1<<i)));
                }
                else{
                    if(!bit && ind+i<2*n-1 && !ans[ind+i]){
                        ans[ind]=i;
                        ans[ind+i]=i;
                        bitmask=(bitmask)|(1<<i);
                        if(fun(ind+1,bitmask,n,ans)){
                            return true;
                        }
                        ans[ind]=0;
                        ans[ind+i]=0;
                        bitmask=((bitmask)&(~(1<<i)));
                    }
                }
            }
        }
        return false;
    }
};