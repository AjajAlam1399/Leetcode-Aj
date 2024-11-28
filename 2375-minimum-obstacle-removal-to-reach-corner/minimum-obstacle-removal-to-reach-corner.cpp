class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>vec(n,vector<int>(m,1e9));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;

        vec[0][0]=0;
        pq.push({0,0,0});

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int i=it[1];
            int j=it[2];
            int dist=it[0];
            int arr1[]={-1,0,1,0};
            int arr2[]={0,-1,0,1};

            for(int k=0;k<4;k++){
                int newi=i+arr1[k];
                int newj=j+arr2[k];

                if(newi>=0 && newj>=0 && newi<n && newj<m && vec[newi][newj]>grid[newi][newj]+dist){
                    vec[newi][newj]=grid[newi][newj]+dist;
                    pq.push({vec[newi][newj],newi,newj});
                }
            }
        }

        return vec[n-1][m-1];
    }
};