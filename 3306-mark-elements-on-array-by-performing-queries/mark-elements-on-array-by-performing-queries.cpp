class Solution {
    using ll = long long;
    using pp = pair<ll,ll>;

public:
    vector<long long> unmarkedSumArray(vector<int>& nums,
                                       vector<vector<int>>& queries) {
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        ll sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            pq.push({nums[i], i});
        }
        unordered_set<int> set;
        vector<ll> ans;
        for (int i = 0; i < queries.size(); i++) {
            if (sum == 0) {
                ans.push_back(sum);
                continue;
            }
            int ind = queries[i][0];
            int k = queries[i][1];

            if (set.find(ind) == set.end()) {
                set.insert(ind);
                sum -= nums[ind];
            }
            while (!pq.empty() && k) {
                auto top = pq.top();
                pq.pop();
                ind = top.second;
                ll val = top.first;
                if (set.find(ind) == set.end()) {
                    set.insert(ind);
                    sum -= val;
                    k--;
                }
            }
            ans.push_back(sum);
        }
        return ans;
    }
};