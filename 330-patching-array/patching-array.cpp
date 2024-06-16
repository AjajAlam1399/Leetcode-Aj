class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int cnt=0,size=nums.size();
        long long sum=0;
        int ind=0;

        while(sum<n){

            if(ind<size){
                if(sum+1<nums[ind]){
                    cnt++;
                    sum+=sum+1;
                }
                else{
                    sum+=nums[ind];
                    ind++;
                }
            }
            else{
                cnt++;
                sum+=sum+1;
            }
        }
        return cnt;
    }
};