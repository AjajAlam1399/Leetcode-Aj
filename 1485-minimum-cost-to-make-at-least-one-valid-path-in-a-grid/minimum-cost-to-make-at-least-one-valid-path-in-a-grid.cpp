class Solution {
    int arr1[4]={-1,0,1,0};
    int arr2[4]={0,-1,0,1};
public:
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();

        vector<vector<int>>dist(n,vector<int>(m,1e9));

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;

        pq.push({0,0,0});
        dist[0][0]=0;

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int curr=it[0];
            int i=it[1];
            int j=it[2];
            vector<int>move=nextMove(i,j,grid[i][j]);

            for(int k=0;k<4;k++){
                int newi=i+arr1[k];
                int newj=j+arr2[k];

                if(newi>=0 && newj>=0 && newi<n && newj<m){
                    int nextdist=curr;
                    if(move[0]!=newi || move[1]!=newj){
                        nextdist++;
                    }
                    if(nextdist<dist[newi][newj]){
                        pq.push({nextdist,newi,newj});
                        dist[newi][newj]=nextdist;
                    }
                }
            }
        }

        return dist[n-1][m-1];
    }

    vector<int> nextMove(int i,int j,int val){
        int newi,newj;

        if(val==1){
            newi=i;
            newj=j+1;
        }
        else if(val==2){
            newi=i;
            newj=j-1;
        }
        else if(val==3){
            newi=i+1;
            newj=j;
        }
        else{
            newi=i-1;
            newj=j;
        }

        return {newi,newj};
    }
};   