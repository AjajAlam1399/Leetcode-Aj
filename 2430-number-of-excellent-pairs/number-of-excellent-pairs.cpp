class Solution {
    using ll=long long;
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        ll n=nums.size();
        unordered_map<ll,ll>duplicate;
        vector<vector<ll>>vec;

        for(ll i=0;i<n;i++){
            if(duplicate.find(nums[i])==duplicate.end()){
                ll bit=bitCount(nums[i]);
                vec.push_back({bit,nums[i]});
                duplicate[nums[i]]=1;
            }
        }
        sort(vec.begin(),vec.end());
        
        ll ans=0;
        for(int i=0;i<vec.size();i++){
            ll ind=bSearch(i,vec[i][1],vec,k);
            if(ind!=-1){
                ans+=(i-ind)*2;
                ans++;
            }
        }
        return ans;
    }

    ll bitCount(ll num){
        ll ans=0;
        for(int i=31;i>=0;i--){
            ll bit=(num)&(1<<i);
            if(bit)ans++;
        }
        return ans;
    }

    int bSearch(int end,int num,vector<vector<ll>>&vec,int &k){
        int left=0,right=end;

        ll ans=-1;
        while(left<=right){
            int mid=(left+right)/2;
            int cnt=fun(num,vec[mid][1]);
            if(cnt>=k){
                ans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return ans;
    }
    int fun(int num1,int num2 ){
        int cnt1=0,cnt2=0;
        for(int i=31;i>=0;i--){
            int bit1=num1&(1<<i);
            int bit2=num2&(1<<i);

            if(bit1 || bit2)cnt1++;
            if(bit1&& bit2)cnt2++;
        }
        return cnt1+cnt2;
    }
};