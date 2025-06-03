class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies,
                   vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes,
                   vector<int>& initialBoxes) {
        int n = candies.size();
        vector<vector<int>> graph(n);

        queue<int> q;

        unordered_map<int, int> map;

        int ans = 0;

        for (int i = 0; i < initialBoxes.size(); i++) {
            int curr = initialBoxes[i];
            if (status[curr]) {
                q.push(curr);
                ans += candies[curr];
            } else {
                map[curr] = 1;
            }
        }

        while (!q.empty()) {
            auto node = q.front();
            q.pop();

            if (node < n) {
                for (auto& key : keys[node]) {
                    status[key] = 1;
                    if (map.find(key) != map.end()) {
                        ans += candies[key];
                        map.erase(key);
                        q.push(key);
                    }
                }
            }

            for (auto& box : containedBoxes[node]) {
                if (status[box]) {
                    q.push(box);
                    ans += candies[box];
                } else {
                    map[box] = 1;
                }
            }
        }

        return ans;
    }
};