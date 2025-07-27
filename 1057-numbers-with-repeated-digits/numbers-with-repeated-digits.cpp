class Solution {
    int dp[11][2][(1<<10)+1][2];
public:
    int numDupDigitsAtMostN(int n) {
        
        memset(dp,-1,sizeof(dp));
        string str=to_string(n);
        int curr=fun(0,1,0,0,str);

        return n+1-curr;
    }

    int fun(int ind,int tight,int bitMask,int isValidNum,string& str){

        if(ind==str.size()){
            return 1;
        }

        if(dp[ind][tight][bitMask][isValidNum]!=-1){
            return dp[ind][tight][bitMask][isValidNum];
        }

        int limit=tight ? str[ind]-'0':9;
        int ans=0;
        for(int d=0;d<=limit;d++){
            int newTight=tight && d==limit;

            if(d==0 && !isValidNum){
                ans+=fun(ind+1,newTight,bitMask,0,str);
            }
            else{
                if(!((bitMask)&(1<<d))){
                    ans+=fun(ind+1,newTight,bitMask|1<<d,1,str);
                }
            }

        }

        return dp[ind][tight][bitMask][isValidNum]=ans;
    }
};