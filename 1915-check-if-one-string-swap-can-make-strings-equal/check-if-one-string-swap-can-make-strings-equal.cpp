class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int cnt=0;
        char ch1,ch2,ch3,ch4;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                if(cnt==0){
                    ch1=s1[i];
                    ch2=s2[i];
                }
                else if(cnt==1){
                    ch3=s1[i];
                    ch4=s2[i];
                }
                else{
                    return false;
                }
                cnt++;
            }
        }
        if(cnt==0 || (cnt==2 && ch1==ch4 && ch2==ch3)) return true;
        return false;
    }
};