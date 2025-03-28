class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        vector<vector<int>>vec;

        for(int i=0;i<queries.size();i++){
            vec.push_back({queries[i],i});
        }
        sort(vec.begin(),vec.end());
        int n=grid.size(),m=grid[0].size();

        vector<vector<int>>visted(n,vector<int>(m,0));

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;

        pq.push({grid[0][0],0,0});
        visted[0][0]=true;

        vector<int>ans(queries.size());
        int curr=0,prev=0;
        for(int i=0;i<queries.size();i++){
            int maxV=vec[i][0];
            int ind=vec[i][1];
            int curr=0;
            while(!pq.empty()){
                auto it=pq.top();
                int x=it[1];
                int y=it[2];
                int gridV=it[0];
                if(maxV>gridV){
                    curr++;
                    pq.pop();
                }
                else{
                    break;
                }
                int arr1[]={-1,0,1,0};
                int arr2[]={0,-1,0,1};

                for(int k=0;k<4;k++){
                    int newx=x+arr1[k];
                    int newy=y+arr2[k];

                    if(newx>=0 && newy>=0 && newx<n && newy<m && 
                    !visted[newx][newy]){
                        visted[newx][newy]=1;
                        pq.push({grid[newx][newy],newx,newy});
                    }
                }
            }
            ans[ind]=prev+curr;
            prev=ans[ind];
        }
        return ans;
    }
};