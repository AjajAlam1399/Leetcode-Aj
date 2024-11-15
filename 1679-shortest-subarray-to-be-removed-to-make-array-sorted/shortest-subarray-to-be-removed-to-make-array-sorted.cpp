class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n=arr.size();
        int s=0,e=n-1;
        for(int i=1;i<n;i++){
            if(arr[i]>=arr[i-1]){
                s=i;
            }
            else{
                break;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(arr[i]<=arr[i+1]){
                e=i;
            }
            else{
                break;
            }
        }
        int ans=INT_MAX;
        ans=min(ans,n-1-s);
        ans=min(ans,e);
        // cout<<s<<" "<<e<<endl;
        while(s>=0 && e>s){
            int ind=lower_bound(arr.begin()+e,arr.end(),arr[s])-arr.begin();
            // cout<<ind<<endl;
            if(ind<n&& arr[ind]>=arr[s]){
                ans=min(ans,ind-s-1);
            }
            else{
                while(ind<n && arr[ind]<arr[s]){
                    ind++;
                }
                ans=min(ans,ind-s);
            }
            s--;
        }
        return ans;
    }
};