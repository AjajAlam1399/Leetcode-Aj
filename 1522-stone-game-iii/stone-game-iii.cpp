class Solution {
    int dp[50000+5][2];
public:
    string stoneGameIII(vector<int>& stoneValue) {
        memset(dp,-1,sizeof(dp));
        int totalSum=accumulate(stoneValue.begin(),stoneValue.end(),0);
        int alice=fun(0,1,stoneValue);
        int bob=totalSum-alice;
        if(alice==bob)return "Tie";
        else if(alice>bob)return "Alice";
        return "Bob";
    }

    int fun(int ind,int turn ,vector<int>& stoneValue){
        int n=stoneValue.size();
        if(ind==n)return 0;

        if(dp[ind][turn]!=-1)return dp[ind][turn];
        int ans=turn?INT_MIN:INT_MAX;
        int sum=0;

        for(int i=ind;i<min(n,ind+3);i++){
            sum+=stoneValue[i];
            if(turn){
                ans=max(ans,sum+fun(i+1,0,stoneValue));
            }
            else{
                ans=min(ans,fun(i+1,1,stoneValue));
            }
        }
        return dp[ind][turn] = ans;
    }
};