class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n=nums.size();
        vector<pair<int,char>>vec;

        for(int i=0;i<n;i++){
            int start=nums[i]-k;
            int end=nums[i]+k;
            vec.push_back({start,'x'});
            vec.push_back({end,'y'});
        }
        sort(vec.begin(),vec.end());
        int ans=1;
        int cnt=0;

        for(int i=0;i<vec.size();i++){
            if(vec[i].second=='x')cnt++;
            else cnt--;
            ans=max(ans,cnt);
        }
        return ans;
    }
};