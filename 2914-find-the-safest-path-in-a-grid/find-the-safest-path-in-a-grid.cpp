class Solution {
    using pp=pair<int,pair<int,int>>;
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        // cout<<n<<endl;
        vector<vector<int>>gr(n,vector<int>(n,-1));
        queue<pp>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    gr[i][j]=0;
                    q.push({0,{i,j}});
                }
            }
        }

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int level=it.first;
            int i=it.second.first;
            int j=it.second.second;
            int arr1[]={-1,0,1,0};
            int arr2[]={0,-1,0,1};

            for(int k=0;k<4;k++){
                int newi=i+arr1[k];
                int newj=j+arr2[k];
                if(newi>=0 && newj>=0 && newi<n && newj<n && gr[newi][newj]==-1){
                    gr[newi][newj]=level+1;
                    q.push({level+1,{newi,newj}});
                }
            }
        }
        // cout<<n<<endl;
        vector<vector<int>>distance(n,vector<int>(n,0));
        priority_queue<pp>pq;
        pq.push({gr[0][0],{0,0}});
        distance[0][0]=gr[0][0];

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int dist=it.first;
            int i=it.second.first;
            int j=it.second.second;
            int arr1[]={-1,0,1,0};
            int arr2[]={0,-1,0,1};
            // cout<<distance[0][0]<<endl;
            for(int k=0;k<4;k++){
                int newi=i+arr1[k];
                int newj=j+arr2[k];
                if(newi>=0 && newj>=0 && newi<n && newj<n){
                    int currdist=min(dist,gr[newi][newj]);
                    // cout<<newi<<" "<<newj<<endl;
                    // cout<<dist[0][0]<<endl;
                    if(currdist>distance[newi][newj]){
                        distance[newi][newj]=currdist;
                        pq.push({currdist,{newi,newj}});
                    }
                }
            }

        }

        return distance[n-1][n-1];

    }
};