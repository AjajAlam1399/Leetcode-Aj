class Solution {
    using ll=long long;
public:
    int minimumDifference(vector<int>& nums) {
        int tn=nums.size();
        int n=tn/2;
        ll sum=accumulate(nums.begin(),nums.end(),0);

        vector<ll>vec1(nums.begin(),nums.begin()+n);
        vector<ll>vec2(nums.begin()+n,nums.end());

        unordered_map<ll,vector<ll>>map1,map2;

        genrateSubset(vec1,map1);
        genrateSubset(vec2,map2);

        ll ans=INT_MAX;


        for(ll i=0;i<=n;i++){
            auto left=map1[i];
            auto right=map2[n-i];
            sort(right.begin(),right.end());

            for(auto a:left){
                ll target=sum/2-a;
                auto it = lower_bound(right.begin(),right.end(),target);

                if(it!=right.end()){
                    int ind=it-right.begin();
                    target=abs(sum-2*(a+right[ind]));
                    ans=min(ans,target);
                }
                if(it!=right.begin()){
                    it--;
                    int ind=it-right.begin();
                    target=abs(sum-2*(a+right[ind]));
                    ans=min(ans,target);
                }
            }
        }

        return ans;
    }

    void genrateSubset(vector<ll>&nums,unordered_map<ll,vector<ll>>&map){
        ll n=nums.size();

        for(ll i=0;i<=(1<<n);i++){
            ll cnt=0,sum=0;

            for(ll j=0;j<nums.size();j++){
                if((i>>j)&1){
                    sum+=nums[j];
                    cnt++;
                }
            }
            map[cnt].push_back(sum);
        }
    }
};