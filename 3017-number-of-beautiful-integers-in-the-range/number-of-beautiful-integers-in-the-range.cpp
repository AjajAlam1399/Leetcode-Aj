class Solution {
    int k;
    int dp[10][2][10][10][21][2];
public:
    int numberOfBeautifulIntegers(int low, int high, int k) {
        
        this->k=k;
        memset(dp,-1,sizeof(dp));
        string str1=to_string(low-1);
        string str2=to_string(high);

        int h=fun(0,1,0,0,0,0,str2);
        memset(dp,-1,sizeof(dp));
        int l=fun(0,1,0,0,0,0,str1);

        return h-l;
    }

    int fun(int ind,bool tight,int oddcnt,int evencnt,int remainder,bool validNum,string &str){
        if(ind==str.size()){
            return oddcnt==evencnt && remainder==0;
        }

        if(dp[ind][tight][oddcnt][evencnt][remainder][validNum]!=-1){
            return dp[ind][tight][oddcnt][evencnt][remainder][validNum];
        }

        int limit=tight?str[ind]-'0':9;
        int ans=0;
        for(int d=0;d<=limit;d++){
            bool newTight = tight && d==limit;

            if(d==0 && !validNum){
                ans+=fun(ind+1,newTight,oddcnt,evencnt,remainder,0,str);
            }
            else if(d%2){
                ans+=fun(ind+1,newTight,oddcnt+1,evencnt,(remainder*10+d)%k,1,str);
            }
            else{
                ans+=fun(ind+1,newTight,oddcnt,evencnt+1,(remainder*10+d)%k,1,str);
            }
        }

        return dp[ind][tight][oddcnt][evencnt][remainder][validNum]= ans;
    }
};