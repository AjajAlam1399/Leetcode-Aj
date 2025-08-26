class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n=dimensions.size();
        long long curr=0,ans=0;
        for(int i=0;i<n;i++){
            long long x=dimensions[i][0];
            long long y=dimensions[i][1];
            long long sq=x*x+y*y;
            if(sq>curr){
                ans=x*y;
                curr=sq;
            }
            else if(sq==curr){
                ans=max(ans,x*y);
            }
        }
        return ans;
    }
};