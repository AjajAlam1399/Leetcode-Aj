class Solution {
public:
    int distinctPoints(string s, int k) {

        unordered_map<string, int> map;

        int l, r, u, d;
        l = r = u = d = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'L')
                l++;
            else if (s[i] == 'R')
                r++;
            else if (s[i] == 'U')
                u++;
            else
                d++;
        }

        int currL = 0, currR = 0, currU = 0, currD = 0;

        int i = 0, j = 0, n = s.size();

        while (j < n) {
            if (s[j] == 'L')
                currL++;
            else if (s[j] == 'R')
                currR++;
            else if (s[j] == 'U')
                currU++;
            else
                currD++;

            if (j - i + 1 == k) {
                int remL = l - currL;
                int remR = r - currR;
                int remU = u - currU;
                int remD = d - currD;
                int x=0,y=0;
                string str;
                x+=remR-remL;
                y+=remU-remD;
                str=to_string(x)+"#"+to_string(y);
                map[str]++;
                if (s[i] == 'L')
                    currL--;
                else if (s[i] == 'R')
                    currR--;
                else if (s[i] == 'U')
                    currU--;
                else
                    currD--;
                i++;
            }
            j++;
        }

        // for(auto it : map){
        //     cout<<it.first<<"-"<<it.second<<endl;
        // }

        return map.size();
    }
};