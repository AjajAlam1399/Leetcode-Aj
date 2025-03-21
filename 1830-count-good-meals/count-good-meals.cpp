class Solution {
    using ll = long long;
    int mod = 1e9 + 7;

public:
    int countPairs(vector<int>& deliciousness) {
        unordered_map<ll, ll> map;
        ll ans = 0;

        for (ll num : deliciousness) {
            map[num]++;
        }

        for (auto& it : map) {
            ll num1 = it.first;
            ll cnt1 = it.second;

            for (ll powerOfTwo = 1; powerOfTwo <= (1 << 21); powerOfTwo *= 2) {
                ll num2 = powerOfTwo - num1;

                if (map.count(num2)) {
                    ll cnt2 = map[num2];

                    if (num1 == num2) {
                        ans += (cnt1 * (cnt1 - 1)) / 2;
                    } else if (num2 > num1) {
                        ans += cnt1 * cnt2;
                    }

                    ans %= mod;
                }
            }
        }

        return ans;
    }
};
