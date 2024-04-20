class Solution {
    using ll=long long;
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        
        int n=nums1.size();
        unordered_map<int,int>map;
        ll maxval=LONG_MIN;
        for(int i=0;i<n;i++){
            ll diff=abs(nums1[i]-nums2[i]);
            if(diff!=0){
                map[diff]++;
                maxval=max(maxval,diff);
            }
        }

        ll dec=k1+k2;

        while(dec>0 && maxval>0){
            int cnt=map[maxval];

            if(dec>=cnt){
                maxval--;
                map[maxval]+=cnt;
                dec-=cnt;
            }
            else{
                map[maxval]-=dec;
                map[maxval-1]+=dec;
                dec=0;
            }
        }
        ll ans=0;
        while(maxval>0){
            if(map.find(maxval)!=map.end()){
                ans+=map[maxval]*pow(maxval,2);
            }
            maxval--;
        }
        return ans;
    }
};