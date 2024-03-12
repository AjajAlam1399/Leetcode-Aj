class Solution {
    int mod=1e9+7;
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        if(k==1){
            int ans=fun(arr,1);
            return max(0,ans)%mod;
        }
        long long sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            sum%=mod;
        }
        long long ans=fun(arr,2);
        return sum>0?(ans%mod+((k-2)*sum)%mod)%mod:ans%mod;
    }

    int fun(vector<int>&arr,int k){
        int n=arr.size();
        long long sum=0;
        long long  maxval=0;
        for(int i=0;i<n*k;i++){
            sum+=arr[i%n];
            if(sum>maxval){
                maxval=sum;
            }
            if(sum<0){
                sum=0;
            }
        }
        return maxval;
    }
};