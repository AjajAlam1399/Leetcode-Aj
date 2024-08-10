class Solution {
public:
    int minFlips(string target) {
        int cnt=0,n=target.size();

        for(int i=0;i<n;i++){
            int bit=target[i]-'0';
            int modval=cnt%2;
            if(modval!=bit){
                cnt++;
            }
        }
        return cnt;
    }
};