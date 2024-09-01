class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int size=original.size();

        if(size!=m*n){
            return {};
        }
        vector<vector<int>>ans(m,vector<int>(n));

        for(int i=0;i<size;i++){
            int row=i/n;
            int col=i%n;
            ans[row][col]=original[i];
        }
        return ans;
    }
};