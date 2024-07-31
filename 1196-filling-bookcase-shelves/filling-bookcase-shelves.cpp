class Solution {
    using ll=long long ;
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n=books.size();
        vector<ll>dp(n+1,-1);
        return fun(0,books,shelfWidth,dp);
    }

    ll fun(int ind,vector<vector<int>>& books, int shelfWidth,vector<ll>&dp){

        if(ind==books.size())return 0;

        if(dp[ind]!=-1)return dp[ind];

        ll currwidth=0;
        ll currheigth=0;
        ll ans=1e9;
        ll maxva=-1e9;
        for(int i=ind;(i<books.size() && currwidth+books[i][0]<=shelfWidth);i++){
            ll curr=1e9;
            currwidth+=books[i][0];
            currheigth+=books[i][1];
            maxva=max(maxva,(ll)books[i][1]);
            if(maxva<=currheigth){
                curr=maxva+fun(i+1,books,shelfWidth,dp);
            }
            ans=min(ans,curr);
        }
        return dp[ind]=ans;
    }
};