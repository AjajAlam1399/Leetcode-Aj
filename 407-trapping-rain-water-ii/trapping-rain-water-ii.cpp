class Solution {
    using pp= pair<int,pair<int,int>>;
    int arr1[4]={-1,0,1,0};
    int arr2[4]={0,-1,0,1};
public:
    int trapRainWater(vector<vector<int>>& map) {
        
        int n=map.size();
        int m=map[0].size();

        vector<vector<int>>visted(n,vector<int>(m,0));

        priority_queue<pp,vector<pp>,greater<pp>>pq;

        for(int i=0;i<m;i++){
            pq.push({map[0][i],{0,i}});
            visted[0][i]=true;
            pq.push({map[n-1][i],{n-1,i}});
            visted[n-1][i]=true;
        }

        for(int j=0;j<n;j++){
            pq.push({map[j][0],{j,0}});
            visted[j][0]=true;
            pq.push({map[j][m-1],{j,m-1}});
            visted[j][m-1]=true;
        }

        int ans=0;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int currVal=it.first;
            int x=it.second.first;
            int y=it.second.second;

            for(int k=0;k<4;k++){
                int newx=x+arr1[k];
                int newy=y+arr2[k];

                if(newx>=0 && newy>=0 && newx<n && newy<m && !
                visted[newx][newy]){
                    visted[newx][newy]=true;
                    if(currVal>map[newx][newy]){
                        ans+=currVal-map[newx][newy];
                    }
                    pq.push({max(currVal, map[newx][newy]), {newx, newy}});
                }
            }
        }

        return ans;
    }
};