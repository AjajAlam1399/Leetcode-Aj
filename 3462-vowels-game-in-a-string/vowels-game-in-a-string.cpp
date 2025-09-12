class Solution {
public:
    bool doesAliceWin(string s) {
        int cnt=0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='o' || s[i]=='u' || s[i]=='i'){
                cnt++;
            }
        }

        if(cnt==0)return false;

        return true;
    }
};