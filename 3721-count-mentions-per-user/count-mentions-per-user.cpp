class Solution {
    static bool cmp(vector<string>& vec1, vector<string>& vec2) {
        int num1 = stoi(vec1[1]);
        int num2 = stoi(vec2[1]);

        if (num1 == num2) {
            return vec1[0][0] > vec2[0][0];
        }
        return num1 <= num2;
    }

public:
    vector<int> countMentions(int n, vector<vector<string>>& events) {
        vector<int> ans(n, 0);
        vector<int> avilable(n, -1);

        sort(events.begin(), events.end(), cmp);

        for (int i = 0; i < events.size(); i++) {
            int time = stoi(events[i][1]);
            if (events[i][0] == "OFFLINE") {
                int ind = stoi(events[i][2]);
                avilable[ind] = time + 60;
            } else {
                if (events[i][2] == "ALL") {
                    for (int j = 0; j < n; j++) {
                        ans[j]++;
                    }
                } else if (events[i][2] == "HERE") {
                    for (int j = 0; j < n; j++) {
                        if (avilable[j] <= time) {
                            ans[j]++;
                        }
                    }
                } else {
                    stringstream ss(events[i][2]);
                    string str;
                    while (getline(ss, str, ' ')) {
                        string index = str.substr(2);
                        int ind = stoi(index);
                            ans[ind]++;
                    }
                }
            }
        }

        return ans;
    }
};