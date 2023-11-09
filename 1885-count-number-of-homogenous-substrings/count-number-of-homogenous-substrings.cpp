class Solution {
    using ll=long long int;
    int mod=1e9+7;
public:
    int countHomogenous(string s) {
       int i=-1,j=-1;
       int n=s.size();
       ll ans=0;

       unordered_map<char,int>map;

       while(true){

           bool f1=false;
           bool f2=false;

           while(i<n-1){
               f1=true;
               i++;
               map[s[i]]++;
               if(map.size()>1){
                   map.erase(s[i]);
                   i--;
                   break;
               }
           }

           while(j<i){
               f2=true;
               if(map.size()==1){
                ans=(ans%mod+(i-j)%mod)%mod;
               }
               j++;
               if(map[s[j]]==1){
                   map.erase(s[j]);
               }
               else{
                   map[s[j]]--;
               }
               if(map.size()<1){
                    break;
               }
           }

           if(!f1 && !f2){
               break;
           }
       }
       
       return ans;
    }
};