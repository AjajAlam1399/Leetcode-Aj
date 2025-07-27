class Solution {
    using ll=long long;
    ll mod=1e9+7;
    int dp[101][2][11][2];
public:
    int countSteppingNumbers(string low, string high) {
        
        memset(dp,-1,sizeof(dp));
        ll h=fun(0,1,-1,0,high);
        memset(dp,-1,sizeof(dp));
        ll l=fun(0,1,-1,0,low);

        ll lowIn=1;

        for(int i=1;i<low.size();i++){
            int diff=abs(low[i]-low[i-1]);
            if(diff!=1){
                lowIn=0;
                break;
            }
        }
        if(lowIn)l--;

        return (h-l+mod)%mod;
    }

    ll fun(ll ind,bool tight,ll prev,bool isValidNum,string &str){

        if(ind==str.size()){
            return 1;
        }

        if(dp[ind][tight][prev+1][isValidNum]!=-1){
            return dp[ind][tight][prev+1][isValidNum];
        }

        ll ans=0;
        ll limit=tight?str[ind]-'0':9;

        for(ll d=0;d<=limit;d++){
            bool newTight=tight & d==limit;

            if(d==0 && !isValidNum){
                ans+=fun(ind+1,newTight,prev,0,str); 
            }
            else{
                if(prev==-1 || abs(prev-d)==1){
                ans+=fun(ind+1,newTight,d,1,str)%mod;
                ans%=mod;
            }
            }
        }

        return dp[ind][tight][prev+1][isValidNum] = ans;
    }
};