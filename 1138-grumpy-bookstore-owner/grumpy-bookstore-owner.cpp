class Solution {
    using ll=long long;
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=grumpy.size();
        ll ans=INT_MIN;
        ll curr=0;
        for(int i=0;i<n;i++){
            if(grumpy[i]==0)curr+=customers[i];
        }
        int s=0,e=0;
        ll sum=0;
        while(e<n){
            if(e-s+1<minutes){
                if(grumpy[e]==1)sum+=customers[e];
            }
            else if(e-s+1==minutes){
                if(grumpy[e]==1)sum+=customers[e];
                ans=max(ans,curr+sum);
                if(grumpy[s]==1)sum-=customers[s];
                s++;
            }
            e++;
        }
        return ans;
    }
};