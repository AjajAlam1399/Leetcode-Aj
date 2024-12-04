class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.size();
        int i = 0;
        string ans;

        for (int j = 0; j < spaces.size(); j++) {
            string str = "";
            while (i < spaces[j]) {
                str.push_back(s[i]);
                i++;
            }
            ans += str + " ";

            if (i == s.size())
                break;
        }
        if (i < s.size()) {
            ans += s.substr(i, n - i);
        }
        if (ans.back() == ' ')
            ans.pop_back();
        return ans;
    }
};