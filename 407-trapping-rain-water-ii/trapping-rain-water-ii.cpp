class Solution {
    int arr1[4]={-1,0,1,0};
    int arr2 [4]={0,-1,0,1};
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n=heightMap.size(),m=heightMap[0].size();
        vector<vector<bool>>visted(n,vector<bool>(m,false));

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;

        for(int i=0;i<m;i++){
            pq.push({heightMap[0][i],0,i});
            pq.push({heightMap[n-1][i],n-1,i});
            visted[0][i]=true;
            visted[n-1][i]=true;
        }
        for(int i=0;i<n;i++){
            pq.push({heightMap[i][0],i,0});
            pq.push({heightMap[i][m-1],i,m-1});
            visted[i][0]=true;
            visted[i][m-1]=true;
        }

        int ans=0;

        while(!pq.empty()){
            auto it =pq.top();
            pq.pop();
            int i=it[1];
            int j=it[2];
            int curr=it[0];

            for(int k=0;k<4;k++){
                int newi=i+arr1[k];
                int newj=j+arr2[k];

                if(newi>=0 && newj>=0 && newi<n && newj<m && !visted[newi][newj]){
                    int newval=heightMap[newi][newj];
                    if(curr>newval){
                        ans+=curr-newval;
                        newval=curr;
                    }
                    visted[newi][newj]=true;
                    pq.push({newval,newi,newj});
                }
            }

        }

        return ans;

    }
};