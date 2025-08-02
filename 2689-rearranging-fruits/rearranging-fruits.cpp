class Solution {
    using ll = long long;
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> count1, count2;
        set<int> unique;

        for (int i = 0; i < basket1.size(); i++) {
            count1[basket1[i]]++;
            count2[basket2[i]]++;
            unique.insert(basket1[i]);
            unique.insert(basket2[i]);
        }

        vector<int> vec1, vec2;
        int globalMin = *min_element(unique.begin(), unique.end());

        for (int fruit : unique) {
            int total = count1[fruit] + count2[fruit];
            if (total % 2 != 0) return -1; 

            int diff = abs(count1[fruit] - count2[fruit]) / 2;
            if (count1[fruit] > count2[fruit]) {
                for (int i = 0; i < diff; i++) vec1.push_back(fruit);
            } else if (count2[fruit] > count1[fruit]) {
                for (int i = 0; i < diff; i++) vec2.push_back(fruit);
            }
        }

        if (vec1.size() != vec2.size()) return -1;

        sort(vec1.begin(), vec1.end());
        sort(vec2.rbegin(), vec2.rend()); 

        ll ans = 0;
        for (int i = 0; i < vec1.size(); i++) {
            ans += min((ll)min(vec1[i], vec2[i]), (ll)(2 * globalMin));
        }

        return ans;
    }
};
