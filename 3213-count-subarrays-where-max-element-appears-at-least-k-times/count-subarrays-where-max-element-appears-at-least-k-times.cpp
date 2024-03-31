class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long  ans=0;
        int i=-1,j=-1,n=nums.size();
        long long cnt=0;
        int maxel=*max_element(nums.begin(),nums.end());
        while(true){
            bool f1=false;
            bool f2=false;
            while(i<n-1){
                f1=true;
                i++;
                if(nums[i]==maxel){
                    cnt++;
                }
                if(cnt>=k){
                    break;
                }
            }

            while(j<i){
                f2=true;
                if(cnt>=k){
                    ans+=n-i;
                }
                j++;
                if(nums[j]==maxel){
                    cnt--;
                }
                if(cnt<k){
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