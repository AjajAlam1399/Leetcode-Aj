class Solution {
    using ll=long long;
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n=events.size();
        sort(events.begin(),events.end());
        vector<vector<ll>>dp(n,vector<ll>(k+1,-1));
        return fun(0,k,events,dp);
    }

    ll fun(int ind,int k,vector<vector<int>>& events,vector<vector<ll>>&dp){
        if(ind==events.size()|| k==0)return 0;
        if(dp[ind][k]!=-1)return dp[ind][k];
        ll taken=events[ind][2]+fun(search(events[ind][1],events),k-1,events,dp);
        ll not_taken=fun(ind+1,k,events,dp);

        return dp[ind][k]=max(taken,not_taken);



    }

    int search(int end,vector<vector<int>>& events){
        int ind=events.size();

        int s=0,e=events.size()-1;

        while(s<=e){
            int mid=(s+e)/2;

            if(events[mid][0]>end){
                ind=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }

        return ind;
    }

};