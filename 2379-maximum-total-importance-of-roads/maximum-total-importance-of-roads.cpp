class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long>vec(n+1,0);
        for(auto it:roads){
            vec[it[0]]++;
            vec[it[1]]++;
        }
        sort(vec.rbegin(),vec.rend());
        long long ans=0;
        int ind=0;
        for(int i=n;i>=0;i--){
            if(vec[ind]==0)break;
            ans+=vec[ind]*i;
            ind++;
        }
        return ans;
    }
};