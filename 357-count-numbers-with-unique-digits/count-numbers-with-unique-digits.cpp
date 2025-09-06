class Solution {
    int dp[10][10][1<<10+1][2];
public:
    int countNumbersWithUniqueDigits(int n) {
        string str="";

        for(int i=0;i<n;i++){
            str+=to_string(9);
        }
        memset(dp,-1,sizeof(dp));
        return fun(0,1,0,0,str);
    }

    int fun(int ind,int tight,int bitMask,int valid,string str){

        if(ind==str.size()){
            return 1;
        }

        if(dp[ind][tight][bitMask][valid]!=-1){
            return dp[ind][tight][bitMask][valid];
        }
        int ans=0;
        int limit=tight?str[ind]-'0':9;

        for(int d=0;d<=limit;d++){
            int newTight=tight && d==limit;
            if(d==0 && !valid){
                ans+=fun(ind+1,newTight,bitMask,valid,str);
            }
            else{
                if(!((bitMask)&(1<<d))){
                    ans+=fun(ind+1,newTight,bitMask|1<<d,1,str);
                }
            }
        }

        return dp[ind][tight][bitMask][valid]= ans;
    }
};