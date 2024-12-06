class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int ans=0;
        int currn=1;
        long long currSum=0;
        int i=0,size=banned.size();
        unordered_map<int,int>map;

        for(auto it : banned)map[it]++;

        while(currn<=n){
            if(map.find(currn)==map.end()){
                if(currSum+currn<=maxSum){
                    ans++;
                    currSum+=currn;
                }
                else{
                    break;
                }
            }
            currn++;
        }
        return ans;
    }
};