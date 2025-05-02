class Solution {
public:
    string pushDominoes(string dominoes) {

        string ans = dominoes;

        int i = 0, n = ans.size();

        while (i < n) {
            if (ans[i] == '.') {
                int l = i, r = i;
                while (i + 1 < n && ans[i + 1] == '.') {
                    i++;
                    r = i;
                }
                bool flag = true;
                while (l <= r && flag && (ans[l]=='.' ||ans[r]=='.')) {
                    flag = false;
                    auto L1 = l - 1 >= 0 ? ans[l - 1] : '.';
                    auto R1 = l + 1 < dominoes.size() ? ans[l + 1] : '.';
                    
                    auto L2 = r - 1 >= 0 ? ans[r - 1] : '.';
                    auto R2 = r + 1 < dominoes.size() ? ans[r + 1] : '.';

                    if (L1 == 'R' && R1!='L') {
                        ans[l] = 'R';
                        flag = true;
                        l++;
                    } else if (R1 == 'L' && L1!='R') {
                        ans[l] = 'L';
                        flag = true;
                        l++;
                    }
                    
                    if (L2 == 'R' && R2!='L') {
                        ans[r] = 'R';
                        flag = true;
                        r--;
                    } else if (R2 == 'L' && L2!='R') {
                        ans[r] = 'L';
                        flag = true;
                        r--;
                    }
                    
                    if(!flag)break;
                }
            }
            i++;
        }
        return ans;
    }
};