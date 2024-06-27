class Solution {
public:
    int minFlips(string target) {
        int ans=0;
        for(int i=0;i<target.size();i++){
            if(target[i]=='1' && ans%2==0)ans++;
            else if(target[i]=='0' && ans%2!=0)ans++;
        }
        return ans;
    }
};