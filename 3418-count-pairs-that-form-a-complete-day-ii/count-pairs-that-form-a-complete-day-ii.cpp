class Solution {
    using ll = long long;

public:
    long long countCompleteDayPairs(vector<int>& hours) {
        ll ans = 0;
        int n = hours.size();
        unordered_map<int, int> map;

        for (int i = 0; i < n; i++)
            map[hours[i] % 24]++;

        for (auto it : map) {
            int mod1 = it.first;
            ll cnt1 = it.second;
            if (mod1 == 12 || mod1 ==0) {
                cout<<mod1<<endl;
                ll currans = cnt1 * (cnt1 - 1);
                currans /= 2;
                ans += currans;
                continue;
            }
            int mod2 = 24 - mod1;

            if (map.find(mod2) != map.end()) {
                ll cnt2 = map[mod2];
                ans += cnt1 * cnt2;
                map[mod1]=0;
            }
        }
        return ans;
    }
};