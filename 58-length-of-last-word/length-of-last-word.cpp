class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();
        int cnt=0;
        n--;
        while(s[n]==' '){
            n--;
        }
        while(n>=0 && s[n]!=' '){
            n--;
            cnt++;
        }

        return cnt;
    }
};