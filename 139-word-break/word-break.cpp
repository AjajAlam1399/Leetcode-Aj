class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int>map;

        for(auto it : wordDict){
            map[it]++;
        }
        vector<int>dp(s.size(),-1);
        return fun(0,s,map,dp);
    }

    bool fun(int i,string &s,unordered_map<string,int>&map,vector<int>&dp){

        if(i>=s.size()){
            return true;
        }
        if(dp[i]!=-1)return dp[i];
        string str="";
        bool ans=false;
        for(int ind=i;ind<s.size();ind++){
            str.push_back(s[ind]);
            if(map.find(str)!=map.end()){
                ans|=fun(ind+1,s,map,dp);
            }
        }

        return dp[i]=ans;
    }
};