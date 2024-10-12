class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        
        vector<pair<int,char>>vec;
        int n=intervals.size();

        for(auto it : intervals){
            vec.push_back({it[0],'x'});
            vec.push_back({it[1],'y'});
        }

        sort(vec.begin(),vec.end());
        int cnt=0;
        int ans=0;

        for(int i=0;i<vec.size();i++){
            if(vec[i].second=='x'){
                cnt++;
                ans=max(ans,cnt);
            }
            else{
                cnt--;
            }
        }
        return ans;
    }
};