class Solution {
public:
    int maxScore(string s) {
         int onecnt=0;
        int n=s.size();

        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                onecnt++;
            }
        }
        int zerocnt=0;
        int ans=0;

        for(int i=0;i<n;i++){
            if(s[i]=='0' && i!=n-1){
                zerocnt++;
            }
            else{
                onecnt--;
            }
            ans=max(ans,onecnt+zerocnt);
        }

        return ans;
    }
};