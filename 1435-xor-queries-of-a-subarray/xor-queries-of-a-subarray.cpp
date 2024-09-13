class Solution {
    using ll=long long;
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector<ll>xorArr(n,0);
        ll xors=0;
        for(ll i=0;i<n;i++){
            xors^=arr[i];
            xorArr[i]=xors;
        }
        vector<int>ans;

        for(ll i=0;i<queries.size();i++){
            ll l=queries[i][0];
            ll r=queries[i][1];
            ll val=arr[l]^xorArr[l]^xorArr[r];
            ans.push_back(val);
        }
        return ans;
    }
};