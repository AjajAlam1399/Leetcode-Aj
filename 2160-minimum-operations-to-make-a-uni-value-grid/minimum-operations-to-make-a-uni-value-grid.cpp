class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>vec;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vec.push_back(grid[i][j]);
            }
        }
        int ans=INT_MAX;
        sort(vec.begin(),vec.end());
        if((n*m)%2==0){
            int mid1=(n*m)/2;
            int mid2=(mid1+1);
            int val1=vec[mid1-1],val2=vec[mid2-1];
            int ans1=0,ans2=0;

            for(int i=0;i<vec.size();i++){
                int diff=abs(vec[i]-val1);
                if(diff%x==0){
                    ans1+=diff/x;
                }
                else{
                    ans1=INT_MAX;
                    break;
                }
            }
            for(int i=0;i<vec.size();i++){
                int diff=abs(vec[i]-val2);
                if(diff%x==0){
                    ans2+=diff/x;
                }
                else{
                    ans2=INT_MAX;
                    break;
                }
            }
            ans=min(ans,ans1);
            ans=min(ans,ans2);
            
        }
        else{
            int mid=(n*m+1)/2;
            int val=vec[mid-1];
            int ans1=0;

            for(int i=0;i<vec.size();i++){
                int diff=abs(vec[i]-val);
                if(diff%x==0){
                    ans1+=diff/x;
                }
                else{
                    ans1=INT_MAX;
                    break;
                }
            }
            ans=min(ans,ans1);
        }
        return ans==INT_MAX?-1:ans;
    }
};