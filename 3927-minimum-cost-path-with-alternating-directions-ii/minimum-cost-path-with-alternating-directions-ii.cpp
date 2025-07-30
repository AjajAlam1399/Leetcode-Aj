typedef long long ll;

class Solution {
public:
    bool check(ll i, ll j, ll m, ll n) {
        return (i >= 0 && i < m && j >= 0 && j < n);
    }

    vector<ll> drow{0, 1}; 
    vector<ll> dcol{1, 0};

    ll minCost(int m, int n, vector<vector<int>>& waitCost) {
        priority_queue<
            pair<ll, pair<ll, ll>>,vector<pair<ll, pair<ll, ll>>>,
            greater<pair<ll, pair<ll, ll>>>>pq;


        vector<vector<ll>> cost(m, vector<ll>(n, LONG_MAX));
        cost[0][0] = 0;

        pq.push({1, {0, 0}}); 

        while (!pq.empty()) {
            ll cst = pq.top().first;
            ll x = pq.top().second.first;
            ll y = pq.top().second.second;
            pq.pop();

            for (ll k = 0; k < 2; k++) {
                ll r = x + drow[k];
                ll c = y + dcol[k];

                if (check(r, c, m, n)) {
                    ll temp = cst + (r + 1) * (c + 1);

                    if (r != m - 1 || c != n - 1)
                        temp += waitCost[r][c];

                    if (temp < cost[r][c]) {
                        cost[r][c] = temp;
                        pq.push({temp, {r, c}});
                    }
                }
            }
        }

        return cost[m - 1][n - 1];
    }
};