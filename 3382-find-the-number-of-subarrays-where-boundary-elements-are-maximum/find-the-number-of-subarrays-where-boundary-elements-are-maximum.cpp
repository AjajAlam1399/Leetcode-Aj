class Solution {
    using ll=long long;

    class SegTree{
        vector<int>t;
        int n;

        public:
        SegTree(int n){
            this->n=n;
            t.resize(4*n);
        }
        void build(int ind,int s,int e,vector<int>&nums){
            if(s==e){
                t[ind]=nums[s];
                return ;
            }
            int mid=(s+e)/2;
            build(2*ind+1,s,mid,nums);
            build(2*ind+2,mid+1,e,nums);
            t[ind]=max(t[2*ind+1],t[2*ind+2]);
        }
        int query(int ind,int s,int e,int l,int r){
            if(s>r || e<l)return INT_MIN;
            if(s>=l && e<=r)return t[ind];
            int mid=(s+e)/2;
            int left=query(2*ind+1,s,mid,l,r);
            int right=query(2*ind+2,mid+1,e,l,r);
            return max(left,right);
        }
    };
public:
    long long numberOfSubarrays(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>>map;

        for(int i=0;i<n;i++){
            map[nums[i]].push_back(i);
        }

        ll ans=0;
        SegTree Seg(n);

        Seg.build(0,0,n-1,nums);

        for(auto it : map){
            ll num=it.first;
            auto vec=it.second;
            int s=0,e=0;

            while(e<vec.size()){
                ll maxElm=Seg.query(0,0,n-1,vec[s],vec[e]);
                if(maxElm<=num){
                    e++;
                }
                else{
                    ll cnt=e-s;
                    ans+=((cnt)*(cnt+1))/2;
                    s=e;
                }
            }
            ll cnt=e-s;
            ans+=((cnt)*(cnt+1))/2;
        }
        return ans;
    }
};