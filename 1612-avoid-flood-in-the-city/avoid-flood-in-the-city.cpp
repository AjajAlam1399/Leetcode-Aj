class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {

        int n = rains.size();
        vector<int> ans(n, 1);
        set<int> set;
        unordered_map<int, int> map;

        for (int i = 0; i < rains.size(); i++) {
            if (rains[i]) {
                ans[i] = -1;
                if (map.find(rains[i])!=map.end()) {
                    auto it = set.lower_bound(map[rains[i]]);
                    if (it == set.end())
                        return {};
                    ans[*it]=rains[i];
                    set.erase(it);
                    map[rains[i]]--;
                }
                map[rains[i]]=i;
            } else {
                set.insert(i);
            }
        }
        return ans;
}
}
;