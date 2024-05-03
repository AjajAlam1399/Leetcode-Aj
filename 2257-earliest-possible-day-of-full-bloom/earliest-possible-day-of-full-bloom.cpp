class Solution {
    using ll=long long;
    using pp=pair<ll,ll>;
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n=plantTime.size();
        vector<pp>vec;

        for(int i=0;i<n;i++){
            vec.push_back({growTime[i],plantTime[i]});
        }
        sort(vec.rbegin(),vec.rend());

        ll ans=0;
        ll next=0;

        for(int i=0;i<n;i++){
            next+=vec[i].second;
            ans=max(ans,next+vec[i].first);
        }
        return ans;
        
    }
};