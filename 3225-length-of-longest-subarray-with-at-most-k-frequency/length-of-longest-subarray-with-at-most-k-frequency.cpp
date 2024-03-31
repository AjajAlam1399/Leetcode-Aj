class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i=-1,j=-1,n=nums.size();
        int ans=0;

        unordered_map<int,int>map;

        while(true){
            bool f1=false;
            bool f2=false;
            while(i<n-1){
                f1=true;
                i++;
                map[nums[i]]++;
                if(map[nums[i]]<=k){
                    ans=max(ans,i-j);
                }
                else{
                    break;
                }
            }
            while(j<i){
                f2=true;
                j++;
                map[nums[j]]--;
                if(map[nums[i]]<=k){
                    ans=max(ans,i-j);
                    break; 
                }
            }

            if(!f1 && !f2){
                break;
            }
        }
        return ans;
    }
};