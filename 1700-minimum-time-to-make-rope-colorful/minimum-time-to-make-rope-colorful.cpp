class Solution {
public:
    int minCost(string colors, vector<int>& needTime) {
        int ans=0;
        int prev=0,n=colors.size();

        for(int i=1;i<n;i++){
            if(colors[i]==colors[prev]){
                if(needTime[i]>=needTime[prev]){
                    ans+=needTime[prev];
                    prev=i;
                }
                else{
                    ans+=needTime[i];
                }
            }
            else{
                prev=i;
            }
        }

        return ans;
    }
};