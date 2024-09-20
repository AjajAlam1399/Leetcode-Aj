class Solution {

    int findLPS(string& str) {
        int n = str.size();
        vector<int> lps(n);
        int i = 1, len = 0;
        while (i < n) {
            if (str[i] == str[len]) {
                lps[i++] = ++len;
            } else {
                if (len > 0) {
                    len = lps[len - 1];
                } else {
                    i++;
                }
            }
        }
        return lps[n - 1];
    }

public:
    string shortestPalindrome(string s) {
        string reversed = s;
        reverse(reversed.begin(), reversed.end());
        string str = s + "#" + reversed;
        int L = findLPS(str);
        // cout<<L<<" ";
        string ans = s.substr(L);
        reverse(ans.begin(), ans.end());
        ans = ans + s;
        return ans;
    }
};