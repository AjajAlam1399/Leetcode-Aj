class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);

        vector<int> count(n, 0);

        for (int i = 0; i < ratings.size(); i++) {
            int leftVal = i - 1 >= 0 ? ratings[i - 1] : INT_MIN;
            int rightVal = i + 1 < n ? ratings[i + 1] : INT_MIN;

            if (ratings[i] < leftVal) {
                graph[i].push_back(i - 1);
                indegree[i - 1]++;
            }
            if (ratings[i] <rightVal) {
                graph[i].push_back(i + 1);
                indegree[i + 1]++;
            }
        }
        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (!indegree[i]) {
                count[i] = 1;
                q.push(i);
            }
        }

        while (!q.empty()) {
            auto node = q.front();
            q.pop();

            for (auto adjNode : graph[node]) {
                indegree[adjNode]--;
                if (!indegree[adjNode]) {
                    count[adjNode] = count[node] + 1;
                    q.push(adjNode);
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans += count[i];
        }

        return ans;
    }
};