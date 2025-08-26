class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int>ans;
        int n=mat.size(),m=mat[0].size();
        bool flag=true;
        for(int gap=0;gap<n;gap++){
            vector<int>vec;
            for(int i=gap,j=0;i>=0 && j<m;i--,j++){
                vec.push_back(mat[i][j]);
            }
            if(flag){
                ans.insert(ans.end(),vec.begin(),vec.end());
            }
            else{
                ans.insert(ans.end(),vec.rbegin(),vec.rend());
            }
            flag=!flag;
        }

        for(int gap=1;gap<m;gap++){
            vector<int>vec;
            for(int i=n-1,j=gap;j<m && i>=0;j++,i--){
                vec.push_back(mat[i][j]);
            }
            if(flag){
                ans.insert(ans.end(),vec.begin(),vec.end());
            }
            else{
                ans.insert(ans.end(),vec.rbegin(),vec.rend());
            }
            flag=!flag;
        }

        return ans;
    }
};