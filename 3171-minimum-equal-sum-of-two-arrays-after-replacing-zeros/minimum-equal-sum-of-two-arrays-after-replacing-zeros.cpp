class Solution {
    using ll=long long;
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        ll n1=nums1.size(),n2=nums2.size(),sum1=0,sum2=0,cnt1=0,cnt2=0;

        for(ll i=0;i<n1;i++){
            if(nums1[i]){
                sum1+=nums1[i];
            }
            else{
                cnt1++;
            }
        }

        for(ll i=0;i<n2;i++){
             if(nums2[i]){
                sum2+=nums2[i];
            }
            else{
                cnt2++;
            }
        }

        ll ans=max(sum1+cnt1,sum2+cnt2);

        ll diff1=ans-sum1,diff2=ans-sum2;

        bool flag1=true,flag2=true;

        if(diff1  && (!cnt1 || cnt1>diff1)){
            flag1=false;
        }
        if(diff2 && (!cnt2 || cnt2>diff2))flag2=false;

        return flag1 && flag2 ?ans:-1;

    }
};