class Solution {
    using ll=long long;
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>vec;
        for(int i=0;i<n;i++){
            int prev=nums[i];
            ll curr=0;
            ll dig=1;
            if(prev==0){
                vec.push_back({mapping[0],i});
                continue;
            }
            while(prev){
                int last=prev%10;
                int nowv=mapping[last];
                curr+=dig*nowv;
                dig*=10;
                prev/=10;
            }
            vec.push_back({curr,i});
        }
        sort(vec.begin(),vec.end());
        vector<int>ans;
        for(int i=0;i<n;i++){
            ans.push_back(nums[vec[i].second]);
        }
        return ans;
    }
};