class Solution {
    using ll = long long;

public:
    string fractionAddition(string expression) {
        int sign = 1, num = 0, dem = 0, n = expression.size(), i = 0;

        if (expression[0] == '-') {
            sign = -1;
            i++;
            while (expression[i] != '/') {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            i++;
            while (i < n && expression[i] >= '0' && expression[i] <= '9') {
                dem = dem * 10 + (expression[i] - '0');
                i++;
            }
        } else {
            while (expression[i] != '/') {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            i++;
            while (i < n && expression[i] >= '0' && expression[i] <= '9') {
                dem = dem * 10 + (expression[i] - '0');
                i++;
            }
        }


        while (i < n) {
            int csign = 1, cnum = 0, cdem = 0;
            if (expression[i] == '-') {
                csign = -1;
                i++;
                while (expression[i] != '/') {
                    cnum = cnum * 10 + (expression[i] - '0');
                    i++;
                }
                i++;
                while (i < n && expression[i] >= '0' && expression[i] <= '9') {
                    cdem = cdem * 10 + (expression[i] - '0');
                    i++;
                }
            } else {
                i++;
                while (expression[i] != '/') {
                    cnum = cnum * 10 + (expression[i] - '0');
                    i++;
                }
                i++;
                while (i < n && expression[i] >= '0' && expression[i] <= '9') {
                    cdem = cdem * 10 + (expression[i] - '0');
                    i++;
                }
            }
            num = sign * num * cdem + csign * cnum * dem;
            dem = dem * cdem;
            if (num == 0) {
                dem = 1;
                sign = 1;
                continue;
            }
            if (num < 0) {
                sign = -1;
            }
            else{
                sign=1;
            }
            num = num < 0 ? -1 * num : num;
            int gcd = __gcd(num, dem);
            num = num / gcd;
            dem = dem / gcd;
        }
        string ans = "";
        if (sign < 0) {
            ans.push_back('-');
        }
        ans += to_string(num) + "/" + to_string(dem);
        return ans;
    }
};