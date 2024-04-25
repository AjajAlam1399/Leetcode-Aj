class Solution {
    bool isPrime(int num){
        if(num==1){
            return false;
        }
        for(int i=2;i*i<=num;i++){
            if(num%i==0)return false;
        }
        return true;

    }
public:
    int maximumPrimeDifference(vector<int>& nums) {
       int ans=0;
        int ind=-1;
        for(int i=0;i<nums.size();i++){
            if(isPrime(nums[i])){
                if(ind==-1){
                    ind=i;
                }
                else{
                    ans=max(ans,i-ind);
                }
            }
        }
        return ans;
    }
};