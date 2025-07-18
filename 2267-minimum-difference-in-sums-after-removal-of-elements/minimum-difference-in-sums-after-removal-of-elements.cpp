class Solution {
    using ll=long long;
public:
    long long minimumDifference(vector<int>& nums) {
        
        int n=nums.size();
        vector<ll>left(n,INT_MIN);
        vector<ll>right(n,INT_MAX);

        priority_queue<ll>maxHeap;
        priority_queue<ll,vector<ll>,greater<ll>>minHeap;

        ll sum=0;
        for(int i=0;i<n;i++){

            if(maxHeap.size()<n/3){
                sum+=nums[i];
                maxHeap.push(nums[i]);
            }
            else {
                if(maxHeap.top()>nums[i]){
                    sum-=maxHeap.top();
                    maxHeap.pop();
                    sum+=nums[i];
                    maxHeap.push(nums[i]);
                }
            }
            if(maxHeap.size()==n/3){
                left[i]=sum;
            }
        }
        sum=0;
        for(int i=n-1;i>=0;i--){
            if(minHeap.size()<n/3){
                sum+=nums[i];
                minHeap.push(nums[i]);
            }
            else {
                if(minHeap.top()<nums[i]){
                    sum-=minHeap.top();
                    minHeap.pop();
                    sum+=nums[i];
                    minHeap.push(nums[i]);
                }
            }

            if(maxHeap.size()==n/3){
                right[i]=sum;
            }
        }

        // for(int i=0;i<n;i++){
        //     cout<<left[i]<<"  "<<right[i]<<endl;
        // }

        ll ans=LONG_MAX;

        for(int i=(n/3)-1;i<=n-1-(n/3);i++){
            ans=min(ans,left[i]-right[i+1]);
        }

        return ans;

    }
};