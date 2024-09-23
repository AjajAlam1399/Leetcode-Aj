class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string>set;
        int n=s.size();
        for(auto it :dictionary){
            set.insert(it);
        }
        vector<int>dp(n+1,-1);
        return fun(0,s,set,dp);
    }

    int fun(int ind,string &s,unordered_set<string>&set,vector<int>&dp){

        if(ind==s.size()){
            return 0;
        }

        string str="";
        int ans=s.size();
        if(dp[ind]!=-1)return dp[ind];
        for(int i=ind;i<s.size();i++){
            str.push_back(s[i]);
            int len=str.size();
            if(set.find(str)!=set.end()){
                ans=min(ans,0+fun(i+1,s,set,dp));
            }
            ans=min(ans,len+fun(i+1,s,set,dp));
        }
        return dp[ind]=ans;
    }
};