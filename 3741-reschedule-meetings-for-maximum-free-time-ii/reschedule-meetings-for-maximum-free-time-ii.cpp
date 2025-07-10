class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime,
                    vector<int>& endTime) {
        vector<int> vec;

        int n = startTime.size();
        int s=0;
        for (int i = 0; i < startTime.size(); i++) {
            int curr = startTime[i] - s;
            vec.push_back(curr);
            vec.push_back(endTime[i]-startTime[i]);
            s = endTime[i];
        }
        vec.push_back(eventTime - s);

        vector<int>dp(2*n+1);
        
        int curr=0;
        for(int i=2*n-1;i>=1;i-=2){
            dp[i]=curr;
            curr=max(curr,vec[i+1]);
        }
        

        int ans=0;
        int left=0;
        for(int i=1;i<2*n+1;i+=2){
            if(max(left,dp[i])>=vec[i]){
                ans=max(ans,vec[i]+vec[i-1]+vec[i+1]);
            }
            else{
                ans=max(ans,vec[i-1]+vec[i+1]);
            }
            left=max(left,vec[i-1]);
        }

        return ans;
    }
};