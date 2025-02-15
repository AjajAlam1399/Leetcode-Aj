class Solution {
    using ll=long long ;
public:
    int punishmentNumber(int n) {

        ll ans=0;

        for(int i=1;i<=n;i++){
            ll sq=i*i;
            string str=to_string(sq);
            if(check(0,str,i,0)){
                ans+=sq;
            }
        }
        return ans;
    }

    bool check(int ind,string str,int ans,int curr){

        if(ind==str.size()){
            return curr==ans;
        }

        ll sum=0;
        for(int i=ind;i<str.size();i++){
            sum=sum*10+(str[i]-'0');
            if(check(i+1,str,ans,sum+curr)){
                return true;
            }
        }

        return false;
    }
};