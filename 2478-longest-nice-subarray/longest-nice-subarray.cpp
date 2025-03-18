class Solution {
    using ll=long long;
public:
    int longestNiceSubarray(vector<int>& nums) {
        vector<int>setBit(32,0);
        int n=nums.size();
        int s=0,e=0,ans=1;

        while(e<n){
            for(int i=31;i>=0;i--){
                int bit=(nums[e]&(1<<i));

                if(bit){
                    setBit[i]++;
                }
            }
            bool flag=true;
            while(flag){
                bool flag1=false;
                for(int i=0;i<32;i++){
                    if(setBit[i]>1){
                        flag1=true;
                        break;
                    }
                }
                if(flag1){
                    for(int i=31;i>=0;i--){
                        int bit=(nums[s]&(1<<i));

                        if(bit){
                            setBit[i]--;
                        }
                    }
                    s++;
                }
                else{
                    break;
                }
            }
            ans=max(ans,e-s+1);
            e++;
        }
        return ans;
    }
};