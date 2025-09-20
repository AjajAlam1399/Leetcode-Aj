class Solution {
    static long long cross(const vector<int>& o, const vector<int>& a,
                           const vector<int>& b) {
        return (long long)(a[0] - o[0]) * (b[1] - o[1]) -
               (long long)(a[1] - o[1]) * (b[0] - o[0]);
    }

public:
    vector<vector<int>> outerTrees(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 1)
            return points;

        sort(points.begin(), points.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[0] != b[0])
                     return a[0] < b[0];
                 return a[1] < b[1];
             });

        vector<vector<int>> lower;
        for (const auto& p : points) {
            while (lower.size() >= 2 &&
                   cross(lower[lower.size() - 2], lower.back(), p) < 0) {
                lower.pop_back();
            }
            lower.push_back(p);
        }
        vector<vector<int>> upper;
        for (int i = n - 1; i >= 0; --i) {
            const auto& p = points[i];
            while (upper.size() >= 2 &&
                   cross(upper[upper.size() - 2], upper.back(), p) < 0) {
                upper.pop_back();
            }
            upper.push_back(p);
        }
        vector<vector<int>> res = lower;
        res.insert(res.end(), upper.begin(), upper.end());
        sort(res.begin(), res.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[0] != b[0])
                     return a[0] < b[0];
                 return a[1] < b[1];
             });
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};
