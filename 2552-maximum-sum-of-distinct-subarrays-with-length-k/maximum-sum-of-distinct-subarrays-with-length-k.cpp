class Solution {
    using ll=long long;
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0;
        unordered_map<int,int>map;
        unordered_set<int>duplicate;
        ll sum=0,ans=0;
        while(j<n){
            int num=nums[j];
            sum+=num;
            map[num]++;
            if(map[num]>1 && duplicate.find(num)==duplicate.end()){
                duplicate.insert(num);
            }
            if(j-i+1==k){
                if(duplicate.size()==0){
                    ans=max(ans,sum);
                }
                int snum=nums[i];
                sum-=snum;
                map[snum]--;
                if(map[snum]<=1){
                    duplicate.erase(snum);
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};