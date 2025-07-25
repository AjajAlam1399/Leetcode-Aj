class Solution {
public:
    int maximumGain(string s, int x, int y) {
        
        if(y>x){
            reverse(s.begin(),s.end());
            swap(x,y);
        }

        return fun(s,x,y);
    }

    int fun(string s,int x,int y){

        int acnt=0,bcnt=0,n=s.size();
        int ans=0;

        for(int i=0;i<n;i++){
            if((s[i]-'a')>1){
                ans+=min(acnt,bcnt)*y;
                acnt=0;
                bcnt=0;
            }
            else{
                if(s[i]=='a'){
                    acnt++;
                }
                else{
                    if(acnt>0){
                        ans+=x;
                        acnt--;
                    }
                    else{
                        bcnt++;
                    }
                }
            }
        }

        ans+=min(acnt,bcnt)*y;

        return ans;
    }
};