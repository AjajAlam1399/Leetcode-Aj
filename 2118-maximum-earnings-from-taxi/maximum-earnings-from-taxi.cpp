
class cmp{
    public:
    bool operator()(pair<long long,long long >&p1,pair<long long,long long>&p2){
        if(p1.first==p2.first){
            return p1.second>p2.second;
        }
        return p1.first<p2.first;
    }
};

class Solution {
    using ll=long long;
    using pp=pair<ll,ll>;
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        ll ans=0;

        for(int i=0;i<rides.size();i++){
            rides[i][2]+=rides[i][1]-rides[i][0];
        }

        sort(rides.begin(),rides.end());
        int m=rides.size();

        vector<ll>dp(m+1,-1);

        return fun(0,rides,dp);
    }

    ll fun(int ind,vector<vector<int>>& rides,vector<ll>&dp){

        if(ind==rides.size())return 0;

        if(dp[ind]!=-1){
            return dp[ind];
        }

        ll taken = rides[ind][2] + fun(search(rides[ind][1],rides),rides,dp);
        ll not_taken=fun(ind+1,rides,dp);

        return dp[ind]=max(taken,not_taken);
    }

    int search(int end,vector<vector<int>>&rides){
        int ans=rides.size();
        int s=0,e=rides.size()-1;

        while(s<=e){
            int mid=(s+e)/2;

            if(rides[mid][0]>=end){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};