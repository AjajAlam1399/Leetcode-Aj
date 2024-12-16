class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& balls) {
        unordered_map<int, int> map;

        for (auto ball : balls) {
            map[ball]++;
        }
        int e = balls.size();
        vector<int> vec;
        for (auto it : map) {
            vec.push_back(it.second);
            e = min(e, it.second);
        }
        int ans = 0;
        for (int size = e; size >= 1; size--) {
            int cnt = 0;
            bool flag = false;
            for (auto it : map) {
                int currcnt = it.second;
                if (currcnt == size || currcnt == size + 1) {
                    cnt++;
                } else {
                    int val = (currcnt) / (size + 1);
                    cnt += val;
                    int mod = (currcnt) % (size + 1);
                    int diff = size - mod;
                    if (mod) {
                        if (val >= diff)
                            cnt++;
                        else {
                            flag = true;
                            break;
                        }
                    }
                }
            }
            if (!flag) {
                ans = cnt;
                break;
            }
        }
        return ans;
    }
};