class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size();

        vector<vector<int>>vec(n,vector<int>(m,1e9));

        priority_queue<vector<int>,vector<vector<int>>,
        greater<vector<int>>>pq;

        pq.push({0,0,0,0});
        vec[0][0]=0;

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int currk=it[0];
            int currdist=it[1];
            int i=it[2];
            int j=it[3];

            int arr1[]={-1,0,1,0};
            int arr2[]={0,-1,0,1};

            for(int l=0;l<4;l++){
                int curri=i+arr1[l];
                int currj=j+arr2[l];
                int kl=currk;
                if(curri>=0 && currj>=0 && curri<n && currj<m &&
                kl<=k){
                    int gridval=grid[curri][currj];
                    if(gridval!=0){
                        kl++;
                    }
                    if(kl<=k && vec[curri][currj]>currdist+1){
                        vec[curri][currj]=currdist+1;
                        pq.push({kl,vec[curri][currj],curri,currj});
                    }
                }
            }
        }

        return vec[n-1][m-1]==1e9?-1:vec[n-1][m-1];

    }
};