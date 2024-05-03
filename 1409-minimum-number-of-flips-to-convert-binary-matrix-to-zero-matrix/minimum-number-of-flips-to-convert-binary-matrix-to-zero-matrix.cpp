class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        unordered_set<string>set;
        string ans,curr;
        int n=mat.size(),m=mat[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                curr+=to_string(mat[i][j]);
                ans+="0";
            }
        }

        queue<string>q;
        int level=0;
        q.push(curr);
        set.insert(curr);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto node=q.front();
                //  cout<<node<<endl;
                q.pop();
                if(node==ans)return level;
                for(int j=0;j<node.size();j++){
                    int r=j/m;
                    int c=j%m;
                    curr=node;
                    // changing current
                    curr[j]=curr[j]=='0'?'1':'0';
                    
                    //up
                    if(r-1>=0){
                        int nr=r-1;
                        int nc=c;
                        int ind=nr*m+nc;
                        curr[ind]=curr[ind]=='0'?'1':'0';
                    }

                    //left
                    if(c-1>=0){
                        int nr=r;
                        int nc=c-1;
                        int ind=nr*m+nc;
                        curr[ind]=curr[ind]=='0'?'1':'0';
                    }

                    //down
                    
                    if(r+1<n){
                        int nr=r+1;
                        int nc=c;
                        int ind=nr*m+nc;
                        curr[ind]=curr[ind]=='0'?'1':'0';
                    }

                    //right
                    if(c+1<m){
                        int nr=r;
                        int nc=c+1;
                        int ind=nr*m+nc;
                        curr[ind]=curr[ind]=='0'?'1':'0';
                    }
                   
                    if(set.find(curr)==set.end()){
                        set.insert(curr);
                        q.push(curr);
                    }

                }
            }
        level++;
        }
        return -1;
    }
};