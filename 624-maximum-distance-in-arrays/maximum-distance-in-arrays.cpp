class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int ans=INT_MIN,n=arrays.size();
        int a=arrays[0][0],b=arrays[0][arrays[0].size()-1];

        for(int i=1;i<n;i++){
            int ai=arrays[i][0];
            int bi=arrays[i][arrays[i].size()-1];
            ans=max(ans,abs(bi-a));
            ans=max(ans,abs(ai-b));
            a=min(ai,a);
            b=max(b,bi);
        }
        return ans;
    }
};