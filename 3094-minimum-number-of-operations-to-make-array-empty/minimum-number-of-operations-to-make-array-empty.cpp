class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>map;
        int n=nums.size();

        for(int i=0;i<n;i++){
            map[nums[i]]++;
        }
        int ans=0;

        for(auto it  :map){
            int val=it.second;
            if(val==1)return -1;
            if(val%3==0){
                ans+=val/3;
            }
            else if(val%3==1){
                ans+=val/3;
                ans--;
                ans+=2;
            }
            else if (val%3==2){
                ans+=val/3;
                ans++;
            }
        }
        return ans;
    }
};