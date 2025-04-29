class Solution {
    int N;
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        N=n;

        vector<int>ans;

        for(auto q : queries){
            int u=q[0];
            int v=q[1];
            int diff=0;
            int l=LCA(u,v);
            diff+=depth(u)+depth(v)-2*depth(l);
            ans.push_back(diff+1);
        }
        return ans;
    }

    int LCA(int u,int v){
        if(depth(u)>depth(v)){
            swap(u,v);
        }
        int diff=depth(v)-depth(u);
        v=kth(v,diff);
        if(u==v){
            return u;
        }

        for(int i=N;i>=0;i--){
            int newu=kth(u,i);
            int newv=kth(v,i);
            if(newu==newv){
                continue;
            }
            u=newu;
            v=newv;
        }
        return u/2;
    }
    int kth(int node,int k){
        return node>>k;
    }
    int depth(int n){
        return log2(n);
    }
};