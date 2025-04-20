class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n=answers.size();
        unordered_map<int,int>map;

        for(auto num : answers){
            map[num]++;
        }

        int ans=0;

        for(auto it : map){
            int type=it.first;
            int cnt=it.second;

            int part=(cnt)/(type+1);
            ans+=(type+1)*part;
            if(cnt%(type+1)!=0){
                ans+=type+1;
            }
        }
        return ans;
    }
};