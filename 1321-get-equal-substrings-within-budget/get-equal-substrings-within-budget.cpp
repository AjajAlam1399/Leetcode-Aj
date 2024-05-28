class Solution {
public:
    int equalSubstring(string s, string t, int maxcost) {
        int n=s.size(),i=-1,j=-1,len=0,currcost=0,ans=0;

        while(true){

            bool f1=false;
            bool f2=false;

            while(i<n-1){
                f1=true;
                i++;
                currcost+=abs(s[i]-t[i]);
                if(currcost<=maxcost){
                    ans=max(ans,i-j);
                }
                else{
                    break;
                }
            }

            while(j<i){
                f2=true;
                j++;
                currcost-=abs(s[j]-t[j]);
                if(currcost<=maxcost){
                    break;
                }
            }
            if(!f1 && !f2){
                break;
            }
        }
        return ans;
    }
};