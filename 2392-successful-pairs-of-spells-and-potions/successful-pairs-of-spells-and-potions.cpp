class Solution {
    using ll=long long ;
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int n=spells.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            int ind=fun(potions,spells[i],success);
            ans[i]=potions.size()-ind;
        }

        return ans;

    }

    int fun(vector<int>&vec,int num,ll su){

        int n=vec.size();
        int s=0,e=n-1;
        int ans=n;

        while(s<=e){
            int mid=(s+e)/2;

            if(su<=1LL*num*vec[mid]){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }

        return ans;
    }
};