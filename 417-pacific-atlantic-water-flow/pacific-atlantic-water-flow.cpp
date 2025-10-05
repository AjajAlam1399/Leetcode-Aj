class Solution {
    int arr1[4]={-1,0,1,0};
    int arr2[4]={0,-1,0,1};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int n=heights.size();
        int m=heights[0].size();

        auto p=pacific(heights);
        auto a=atlantic(heights);

        vector<vector<int>>ans;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(p[i][j] && a[i][j]){
                    ans.push_back({i,j});
                }
            }
        }

        return ans;
    }
    
    vector<vector<bool>> pacific(vector<vector<int>> heights){
        int n=heights.size();
        int m=heights[0].size();

        vector<vector<bool>>ans(n,vector<bool>(m,false));

        queue<pair<int,int>>q;

        for(int i=0;i<n;i++){
            q.push({i,0});
            ans[i][0]=true;
        }

        for(int i=0;i<m;i++){
            q.push({0,i});
            ans[0][i]=true;
        }

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int x=it.first;
            int y=it.second;

            for(int k=0;k<4;k++){
                int newx=x+arr1[k];
                int newy=y+arr2[k];

                if(newx>=0 && newy>=0 && newx<n && newy<m && 
                !ans[newx][newy] && heights[newx][newy]>=heights[x][y]){
                    ans[newx][newy]=true;
                    q.push({newx,newy});
                }
            }
        }

        return ans;
    }

    vector<vector<bool>> atlantic(vector<vector<int>> heights){
        int n=heights.size();
        int m=heights[0].size();

        vector<vector<bool>>ans(n,vector<bool>(m,false));

        queue<pair<int,int>>q;

        for(int i=0;i<n;i++){
            q.push({i,m-1});
            ans[i][m-1]=true;
        }

        for(int i=0;i<m;i++){
            q.push({n-1,i});
            ans[n-1][i]=true;
        }

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int x=it.first;
            int y=it.second;

            for(int k=0;k<4;k++){
                int newx=x+arr1[k];
                int newy=y+arr2[k];

                if(newx>=0 && newy>=0 && newx<n && newy<m && 
                !ans[newx][newy] && heights[newx][newy]>=heights[x][y]){
                    ans[newx][newy]=true;
                    q.push({newx,newy});
                }
            }
        }

        return ans;
    }
};