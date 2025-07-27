class Solution {
    int dp[33][2][2];
public:
    int findIntegers(int n) {
        
        string str="";

        for(int i=31;i>=0;i--){
            int bit=(n>>i)&(1);
            str.push_back('0'+bit);
        }
        memset(dp,-1,sizeof(dp));
        return fun(0,1,0,str);
    }

    int fun(int ind,int tight,bool ones,string &str){

        if(ind==str.size()){
            return 1;
        }

        if(dp[ind][tight][ones]!=-1){
            return dp[ind][tight][ones];
        }

        int limit=tight?str[ind]-'0':1;
        int ans=0;
        for(int d=0;d<=limit;d++){
            int newTight = tight && d==limit;

            if(d){
                if(!ones){
                    ans+=fun(ind+1,newTight,true,str);
                }
            }
            else{
                ans+=fun(ind+1,newTight,false,str);
            }
        }

        return dp[ind][tight][ones]=ans;
    }
};