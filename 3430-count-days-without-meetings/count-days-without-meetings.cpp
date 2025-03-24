class Solution {
    using ll=long long ;
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        ll ans=0;
        ll s=0;
        for(int i=0;i<meetings.size();i++){
            int currs=meetings[i][0];
            ll curre=meetings[i][1];

            if(currs>s){
                ans+=currs-1-s;
            }
            s=max(s,curre);
        }
        ans+=days-s;
        return ans;
    }
};