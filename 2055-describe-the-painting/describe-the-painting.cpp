class Solution {
    using ll=long long;
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        vector<ll>vec(1e5+1);
        unordered_set<int>set;
        int maxind=0;
        for(auto it:segments){
            vec[it[0]]+=it[2];
            vec[it[1]]-=it[2];
            maxind=max(maxind,it[0]);
            maxind=max(maxind,it[1]);
            set.insert(it[0]);
            set.insert(it[1]);
        }
        ll ind=0,s=0;
        ll sum=0;
        while(!vec[s]){
            s++;
        }
        ind=s+1;
        sum+=vec[s];
vector<vector<ll>>ans;
        while(ind<=maxind){
            if(set.find(ind)!=set.end()){
                if(sum){
                    ans.push_back({s,ind,sum});
                }
                s=ind;
            }
            sum+=vec[ind++];
        }
        return ans;
    }
};