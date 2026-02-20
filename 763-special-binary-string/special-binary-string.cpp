class Solution {
private :
    string ans = "";
public:
    string makeLargestSpecial(string s) {

        ans = s;
        int n = s.size();
        bool flag = false;
        string prev = "";
        for (int i = 0; i < n; i++) {
            string first = "";
            int ind = i, zcnt = 0, oncnt = 0;

            while (ind < n) {
                first.push_back(s[ind]);
                if (s[ind] == '0') {
                    zcnt++;
                } else {
                    oncnt++;
                }
                if (zcnt > oncnt) {
                    break;
                }
                if (zcnt == oncnt) {
                    string next = "";
                    int ind1 = ind+1, zcnt1 = 0, oncnt1 = 0;
                    // cout<<i<<"-"<<"enter1"<<endl;
                    while (ind1 < n) {
                        next.push_back(s[ind1]);
                        if (s[ind1] == '0') {
                            zcnt1++;
                        } else {
                            oncnt1++;
                        }
                        if (zcnt1 > oncnt1) {
                            break;
                        }
                        if(zcnt1==oncnt1){
                            string subans = prev+next+first+s.substr(ind1+1);
                            // cout<<subans<<endl;
                            int cmp = subans.compare(ans);
                            if(cmp>0){
                                ans=subans;
                               return  makeLargestSpecial(ans);

                            }
                        }
                        ind1++;
                    }
                }
                ind++;
            }
            prev.push_back(s[i]);
        }

        return ans;
    };
};