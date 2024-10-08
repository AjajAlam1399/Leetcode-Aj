class Solution {
public:
    int minSwaps(string s) {
        int op=0,co=0,n=s.size();

        for(int i=0;i<n;i++){
            if(s[i]=='['){
                op++;
            }
            else{
                if(op>0){
                    op--;
                }
                else{
                    co++;
                }
            }
        }
        int ans=0;
        if((co)%2==0){
            ans=(co)/2;
        }
        else{
            ans=(co)/2;
            ans++;
        }
        return ans;
    }
};