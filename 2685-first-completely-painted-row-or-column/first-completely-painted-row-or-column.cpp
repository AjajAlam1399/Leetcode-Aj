class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        
        unordered_map<int,vector<int>>map;
        unordered_map<int,int>row;
        unordered_map<int,int>col;

        int n=mat.size(),m=mat[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                map[mat[i][j]]={i,j};
            }
        }
        int ans=n*m;
        
        for(int i=0;i<arr.size();i++){
            auto it=map[arr[i]];
            
            if(row[it[0]]+1==m || col[it[1]]+1==n){
                ans=i;
                break;
            }
            row[it[0]]++;
            col[it[1]]++;
        }

        return ans;
    }
};