class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        
        int ans=0;

        unordered_map<int,int>map;

        for(int i=0;i<time.size();i++){
            int mod=time[i]%60;
            ans+=map[(60-mod)%60];
            map[mod]++;
        }

        return ans;
    }
};