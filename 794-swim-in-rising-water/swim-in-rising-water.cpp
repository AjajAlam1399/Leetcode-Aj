class Solution {
    int arr1[4]={-1,0,1,0};
    int arr2[4]={0,-1,0,1};
    using pp=pair<int,pair<int,int>>;
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pp,vector<pp>,greater<pp>>pq;
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));

        dist[0][0]=grid[0][0];
        pq.push({grid[0][0],{0,0}});


        while(!pq.empty()){

            auto it = pq.top();
            pq.pop();
            int curr=it.first;
            int x=it.second.first;
            int y=it.second.second;

            for(int k=0;k<4;k++){
                int newx=x+arr1[k];
                int newy=y+arr2[k];

                if(newx>=0 && newy>=0 && newx<n && newy<m){
                    int next=max(curr,grid[newx][newy]);
                    if(dist[newx][newy]>next){
                        dist[newx][newy]=next;
                        pq.push({next,{newx,newy}});
                    }
                } 
            }
        }

        return dist[n-1][m-1];
    }
};