class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        map<int,int>map1;
        map<int,int>map2;
        int n1=nums1.size(),n2=nums2.size();
        int maxval=INT_MIN;
        for(int i=0;i<n1;i++){
            map1[nums1[i]]++;
            maxval=max(maxval,nums1[i]);
        }
        for(int i=0;i<n2;i++){
            map2[nums2[i]]++;
        }
        long long ans=0;

        for(auto it:map2){
            long long num=it.first*k;
            long long tempnum=it.first*k;
            long long cnt=it.second;
            long long i=2;
            while(tempnum<=maxval){
                long long cnt1=map1[tempnum];
                ans+=cnt*cnt1;
                tempnum=num*i;
                i++;
            }
        }
        return ans;
    }
};