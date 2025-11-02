class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        
        int ans=n*m;

        vector<vector<int>>vec(m,vector<int>(n,0));

        unordered_set<int>row,col;

        for(int i=0;i<guards.size();i++){
            row.insert(guards[i][0]);
            col.insert(guards[i][1]);

            vec[guards[i][0]][guards[i][1]]=1;
        }

        for(int i=0;i<walls.size();i++){
            vec[walls[i][0]][walls[i][1]]=2;
        }

        ans-=guards.size();
        ans-=walls.size();

        for(auto it :row){
            int r=it;
            queue<int>q;
            bool isGuard=false;
            for(int i=0;i<n;i++){
                if(vec[r][i]==1){
                    ans-=q.size();
                    isGuard=true;
                    while(!q.empty()){
                        auto ind = q.front();
                        q.pop();
                        vec[r][ind]=-1;
                    }
                }
                else if(vec[r][i]==2){
                    while(!q.empty()){
                        q.pop();
                    }
                    isGuard=false;
                }
                else if(vec[r][i]==0){
                    if(isGuard){
                        ans--;
                        vec[r][i]=-1;
                    }
                    else{
                        q.push(i);
                    }
                }
            }
        }

         for(auto it :col){
            int c=it;
            queue<int>q;
            bool isGuard=false;
            for(int i=0;i<m;i++){
                if(vec[i][c]==1){
                    ans-=q.size();
                    isGuard=true;
                    while(!q.empty()){
                        auto ind = q.front();
                        q.pop();
                        vec[ind][c]=-1;
                    }
                }
                else if(vec[i][c]==2){
                    while(!q.empty()){
                        q.pop();
                    }
                    isGuard=false;
                }
                else if(vec[i][c]==0){
                    if(isGuard){
                        ans--;
                        vec[i][c]=-1;
                    }
                    else{
                        q.push(i);
                    }
                }
            }
        }

        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<vec[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        return ans;
    }
};