class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime,
                    vector<int>& endTime) {
        vector<int> vec;

        int s = 0;

        for (int i = 0; i < startTime.size(); i++) {
            int curr = startTime[i] - s;
            vec.push_back(curr);
            s = endTime[i];
        }
        vec.push_back(eventTime - s);

        int i = 0, j = 0, ans = 0, curr = 0;

        while (j < vec.size()) {
            curr+=vec[j];
            while (j - i + 1 > k + 1) {
                curr -= vec[i];
                i++;
            }
            ans = max(ans, curr);
            j++;
        }
        return ans;
    }
};