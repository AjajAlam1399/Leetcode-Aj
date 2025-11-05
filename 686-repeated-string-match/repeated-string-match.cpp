class Solution {
    int p=31;
    int mod=1e9+7;
    using ll=long long;
public:
    int repeatedStringMatch(string a, string b) {
        string str=a;
        int cnt=1;
        while(str.size()<b.size()){
            str+=a;
            cnt++;
        }

        if(fun(str,b))return cnt;
        str+=a;
        if(fun(str,b))return cnt+1;
        return -1;
    }

    int fun(string a,string b){

        int n=a.size();
        vector<ll>power(n);
        power[0]=1;

        for(int i=1;i<n;i++){
            power[i]=(power[i-1]*p)%mod;
        }

        vector<ll>hash(n+1,0);

        for(int i=0;i<n;i++){
            hash[i+1]=(hash[i]+(a[i]-'a'+1)*power[i])%mod;
        }
        int hashVal=0;

        for(int i=0;i<b.size();i++){
            hashVal=(hashVal+(b[i]-'a'+1)*power[i])%mod;
        }

        for(int i=0;i+b.size()-1<n;i++){
            int val=(hash[i+b.size()]-hash[i]+mod)%mod;
            if(val==(hashVal*power[i])%mod){
                return true;
            }
        }

        return false;
    }
};