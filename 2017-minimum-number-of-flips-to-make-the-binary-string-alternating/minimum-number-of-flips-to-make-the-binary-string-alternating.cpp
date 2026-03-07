class Solution {
public:
    int minFlips(string s) {

        string orgStr = s+s;
        string flipStr = s+s;
        int zans = fun(orgStr,flipStr,0);
        int oans = fun(orgStr,flipStr,1);

        return min(zans,oans);
    }

    int fun(string orgStr , string flipStr , int start){
        int curr=start;
        int cnt=0;
        int ans=INT_MAX;

        int s=0,e=0,n=orgStr.size();

        while(e<n){
            int indVa=orgStr[e]-'0';
            if(curr!=indVa){
                cnt++;
                flipStr[e]='0'+curr;
            }
            curr=!curr;
            if(e-s+1 == n/2){
                ans=min(ans,cnt);
                if(orgStr[s]!=flipStr[s]){
                    cnt--;
                }
                s++;
            }
            e++;
        }
        return ans;
    }
};