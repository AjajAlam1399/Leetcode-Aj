class Solution {
    int arr1[4]={-1,0,1,0};
    int arr2[4]={0,-1,0,1};
public:
    int minimumTime(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        if(grid[0][1]>1 && grid[1][0]>1)return -1;

        priority_queue<vector<int>,vector<vector<int>>,
        greater<vector<int>>>pq;

        dist[0][0]=0;
        pq.push({0,0,0});
        
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int currtime=it[0];
            int i=it[1];
            int j=it[2];
            
            for(int k=0;k<4;k++){
                int newi=i+arr1[k];
                int newj=j+arr2[k];

                if(newi>=0 && newj>=0 && newi<n && newj<m){
                    if(currtime+1>=grid[newi][newj]){
                        if(dist[newi][newj]>currtime+1){
                            dist[newi][newj]=currtime+1;
                            pq.push({currtime+1,newi,newj});
                        }
                    }
                    else{
                        int newtime;
                        int diff=grid[newi][newj]-currtime;
                        if(diff%2==0){
                            newtime=grid[newi][newj]+1;
                        }
                        else{
                            newtime=grid[newi][newj];
                        }
                        if(dist[newi][newj]>newtime){
                            dist[newi][newj]=newtime;
                            pq.push({newtime,newi,newj});
                        }
                    }
                }
            }
        }

        return dist[n-1][m-1];
    }
};