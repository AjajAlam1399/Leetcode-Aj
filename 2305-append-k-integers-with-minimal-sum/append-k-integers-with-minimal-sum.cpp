class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),ind=0,prev=0;
        long long sum=0;

        while(ind<n && k){
            int next=nums[ind];
                for(int i=1;i<next-prev;i++){
                    sum+=prev+i;
                    k--;
                    if(k==0){
                        break;
                    }
                }
            prev=next;
            ind++;
        }
        while(k){
            prev++;
            sum+=prev;
            k--;
        }
        return sum;
    }
};