class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        for(int j=0;j<m;j++){
            for(int i=1;i<n;i++){
                if(matrix[i][j]==1){
                    matrix[i][j]+=matrix[i-1][j];
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            sort(matrix[i].begin(),matrix[i].end());
            int k=1;
            for(int j=m-1;j>=0;j--){
                ans=max(ans,matrix[i][j]*k);
                k++;
            }
        }


        return ans;
    }
};