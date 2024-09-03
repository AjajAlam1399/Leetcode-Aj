class Solution {
    using ll=long long ;
public:
    int getLucky(string s, int k) {
        int ans=0;
        string str="";
        for(int i=0;i<s.size();i++){
            int val=s[i]-'a'+1;
            str+=to_string(val);
        }
        while(k){
            
            int sum=0;
            for(int i=0;i<str.size();i++){
                sum+=str[i]-'0';
            }
            ans=sum;
            if(!ans){
                return ans;
            }
            str=to_string(sum);
            k--;
        }
        return ans;
    }
};