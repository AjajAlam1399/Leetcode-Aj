class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long result = 0;

        for (auto& q : queries) {
            long double l = q[0], r = q[1];
            long double total_steps = 0;

            long double lower = 1;
            for (int steps = 0; steps <= 32; ++steps) {
                long double upper = lower * 4 - 1;

                long double from = max(l, lower);
                long double to = min(r, upper);

                if (from > to) {
                    lower *= 4;
                    continue;
                }

                long double count = to - from + 1;
                total_steps += count * (steps + 1);

                lower *= 4;
            }

            result += (total_steps + 1) / 2;
        }

        return result;
    }
};
