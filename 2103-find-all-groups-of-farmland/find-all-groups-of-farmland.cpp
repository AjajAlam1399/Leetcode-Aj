class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n=land.size();
        int m=land[0].size();

        vector<vector<int>>ans;
        queue<pair<int,int>>q;
       
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(land[i][j]==1){
                    land[i][j]=0;
                    q.push({i,j});
                    int endi=i;
                    int endj=j;
                    while(!q.empty()){
                        auto node=q.front();
                        q.pop();
                        int curri=node.first;
                        int currj=node.second;
                        endi=max(curri,endi);
                        endj=max(currj,endj);
                        int arr1[]={-1,0,1,0};
                        int arr2[]={0,-1,0,1};

                        for(int dir=0;dir<4;dir++){
                            int newi=curri+arr1[dir];
                            int newj=currj+arr2[dir];

                            if(newi>=0 && newj>=0 && newi<n && newj<m && 
                            land[newi][newj]==1){
                                land[newi][newj]=0;
                                q.push({newi,newj});
                            }
                        }
                    }
                    ans.push_back({i,j,endi,endj});
                }
            }
        }
        return ans;
    }
};