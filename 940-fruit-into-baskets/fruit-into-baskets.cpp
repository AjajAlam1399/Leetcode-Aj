class Solution {
public:
    int totalFruit(vector<int>& nums) {
        unordered_map<int,int>map;
        int n=nums.size();
        int s=0,e=0;
        int ans=1;
        while(e<n){
            map[nums[e]]++;

            while(map.size()>2){
                map[nums[s]]--;
                if(map[nums[s]]==0){
                    map.erase(nums[s]);
                }
                s++;
            }
            ans=max(ans,e-s+1);
            e++;
        }

        return ans;
    }
};