class Solution {
    using ll=long long;
    int dp[10][2][2];
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        
        unordered_set<int>set;
        for(int i=0;i<digits.size();i++){
            int dig=digits[i][0]-'0';
            set.insert(dig);
        }
        memset(dp,-1,sizeof(dp));
        string str=to_string(n);
        ll ans=fun(0,1,0,str,set);
        if(ans)ans--;
        return ans;
    }

    int fun(int ind,int tight,int isValidNum,string &str,unordered_set<int>&set){
        if(ind==str.size()){
            return 1;
        }
        int limit = tight ? str[ind]-'0':9;
        if(dp[ind][tight][isValidNum]!=-1)return dp[ind][tight][isValidNum];
        int ans=0;
        for(int d=0;d<=limit;d++){
            int newTight=tight && d==limit;

            if(d==0 && !isValidNum){
                ans+=fun(ind+1,newTight,0,str,set);
            }
            else{
                if(set.count(d)){
                    ans+=fun(ind+1,newTight,1,str,set);
                }
            }
        }

        return dp[ind][tight][isValidNum]=ans;
    }
};