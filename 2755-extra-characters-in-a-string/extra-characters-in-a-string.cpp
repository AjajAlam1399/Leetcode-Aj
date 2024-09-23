class Solution {
public:
    int minExtraChar(string s, vector<string>& dict) {
        unordered_set<string>set;

        for(int i=0;i<dict.size();i++){
            set.insert(dict[i]);
        }

        vector<int>dp(s.size()+1,-1);

        return fun(0,s,set,dp);
    }

    int fun(int ind,string str,unordered_set<string>&set,vector<int>&dp){
        if(ind>=str.size()){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int ans=1e5;
        string st="";
        for(int i=ind;i<str.size();i++){
           st+=str[i];
            int currextr=0;
            if(set.find(st)==set.end()){
                currextr=st.size();;
            }
            int remaning=fun(i+1,str,set,dp);

            ans=min(ans,currextr+remaning);
        }

        return dp[ind]=ans;
    }
};