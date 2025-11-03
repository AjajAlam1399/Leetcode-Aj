class Solution {
public:
    string countAndSay(int n) {
        string str = "1";
        for (int i = 2; i <= n; i++) {
            str = fun(str);
            // cout<<str<<endl;
        }
        return str;
    }

    string fun(string str) {
        string ans = "";
        int n = str.size();
        int i = 0, cnt = 1;

        while (i < n) {
            char ch = str[i];
            while (i + 1 < n && str[i + 1] == ch) {
                i++;
                cnt++;
            }
            ans += to_string(cnt);
            ans.push_back(ch);
            cnt = 1;
            i++;
        }
        return ans;
    }
};