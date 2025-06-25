#define F first
#define S second
class Solution {
    using ll = long long;
    using pp = pair<ll, ll>;
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        ll n = intervals.size(), m = queries.size();
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        vector<pp> vec;

        for (ll i = 0; i < m; i++) {
            vec.push_back({queries[i], i});
        }

        sort(vec.begin(), vec.end());
        sort(intervals.begin(), intervals.end());

        int i = 0, j = 0;
        vector<int> ans(m, -1);

        while (j < m) {
            while (i < n && intervals[i][0] <= vec[j].F) {
                int len = intervals[i][1] - intervals[i][0] + 1;
                pq.push({len, intervals[i][1]});
                i++;
            }

            while (!pq.empty() && pq.top().S < vec[j].F) {
                pq.pop();
            }

            if (!pq.empty()) {
                ans[vec[j].S] = pq.top().F;
            }

            j++;
        }

        return ans;
    }
};
