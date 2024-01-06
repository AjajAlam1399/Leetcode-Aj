class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<vector<int>>job;

        for(int i=0;i<n;i++){
            job.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(job.begin(),job.end());
        vector<int>dp(n+1,-1);
        return fun(0,job,dp);
        // for(auto it  :job)cout<<it[0]<<" ";
        return 0;
    }

    int fun(int ind,vector<vector<int>>&job,vector<int>&dp){


        if(ind==job.size()){
            return 0;
        }

        if(dp[ind]!=-1)return dp[ind];

        int not_taken=fun(ind+1,job,dp);
        int nextind=nextTaken(job[ind][1],job);
        int taken=job[ind][2]+fun(nextind,job,dp);

        return dp[ind]=max(taken,not_taken);

    }

    int nextTaken(int st,vector<vector<int>>&job){
        int s=0,e=job.size()-1;
        int ans=job.size();

        while(s<=e){
            int mid=(s+e)/2;

            if(job[mid][0]>=st){
                ans=mid;
                e=mid-1;
            }
            if(job[mid][0]<st){
                s=mid+1;
            }
        }
        return ans;
    }
};