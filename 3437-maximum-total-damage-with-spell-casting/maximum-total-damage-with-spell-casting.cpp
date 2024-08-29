class Solution {
    using ll=long long;
public:
    long long maximumTotalDamage(vector<int>& power) {
        int n=power.size();
        unordered_map<int,int>map;

        for(auto p:power){
            map[p]++;
        }
        vector<pair<ll,ll>>vec;

        for(auto it : map){
            vec.push_back({it.first,it.second});
        }

        sort(vec.begin(),vec.end());

        vector<vector<ll>>dp(n+1,vector<ll>(4,-1));

        return fun(0,0,vec,dp);


    }

    ll fun(int ind,int skip,vector<pair<ll ,ll>>&vec,vector<vector<ll>>&dp){

        if(ind==vec.size()){
            return 0;
        }
        if(dp[ind][skip]!=-1)return dp[ind][skip];
        ll taken=0,not_taken=0;
        if(skip==0 || skip==3){
            taken=vec[ind].first*vec[ind].second+fun(ind+1,1,vec,dp);
            not_taken=fun(ind+1,skip,vec,dp);
        }
        else{
            int prevind=ind-skip;
            if(prevind>=0 && vec[prevind].first+1!=vec[ind].first 
            &&vec[prevind].first+2!=vec[ind].first){
                taken=vec[ind].first*vec[ind].second+fun(ind+1,1,vec,dp);
                not_taken=fun(ind+1,skip+1,vec,dp);
            }
            else{
                not_taken=fun(ind+1,skip+1,vec,dp);
            }
        }
        return dp[ind][skip]=max(taken,not_taken);
    }

    
};