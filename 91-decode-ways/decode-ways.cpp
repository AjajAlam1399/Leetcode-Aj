class Solution {
public:
    int numDecodings(string s) {
        int n=s.length();
        vector<int>dp(n+1,-1);
        return fun(0,s,dp);
    }

    int fun(int ind,string &s,vector<int>&dp){

        if(ind==s.size()){
            return 1;
        }
        if(dp[ind]!=-1)return dp[ind];
        int ans=0;
        for(int i=ind;i<s.size();i++){
            if(valid(ind,i,s)){
                ans+=fun(i+1,s,dp);
            }
        }
        return dp[ind]= ans;
    }

    bool valid(int i,int j,string s){
        if(j-i+1>=3)return false;
        if(s[i]=='0')return false;
        if(j-i+1==2){
            string st=s.substr(i,j-i+1);
            int num=stoi(st);
            if(num>26)return false;
            else return true;
        }
        return true;
    }
};