class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.size();
        pair<char,int>prev={'1',1};
        int ans=0;

        for(int i=0;i<n;i++){
                if(prev.first==colors[i]){
                    if(prev.second<=neededTime[i]){
                        ans+=prev.second;
                       prev={colors[i],neededTime[i]};
                    }
                    else{
                        ans+=neededTime[i];
                    }
                }
                else{
                    prev={colors[i],neededTime[i]};
                }
        }
        return ans;
    }
};