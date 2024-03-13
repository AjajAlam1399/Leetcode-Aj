class Solution {
public:
    int minimumNumbers(int num, int k) {
        if(num==0){
            return 0;
        }
        if(k>num){
            return -1;
        }
        vector<int>vec;
        int cnt=k;
        while(cnt<=num){
            if(cnt==0){
                cnt+=10;
                continue;
            }
            vec.push_back(cnt);
            cnt+=10;
        }
        int n=vec.size();

        vector<vector<int>>dp(n+1,vector<int>(num+1,-1));

        int ans= fun(vec.size()-1,num,vec,dp);
        return ans>=3000?-1:ans;
    }

    int fun(int ind,int tar,vector<int>&vec,vector<vector<int>>&dp){

        if(ind<0){
            if(tar==0){
                return 0;
            }
            return 1e5;
        }

        if(dp[ind][tar]!=-1){
            return dp[ind][tar];
        }

        int not_taken=fun(ind-1,tar,vec,dp);
        int taken=1e7;
        if(tar-vec[ind]>=0){
            taken=1+fun(ind,tar-vec[ind],vec,dp);
        }
        return dp[ind][tar]= min(taken,not_taken);
    }
};