class Solution {
    using ll=long long ;
public:
    int numberOfSubstrings(string s) {
        ll ans=0,n=s.size(),i=0,j=0;
        unordered_map<char,int>map;

        while(j<n){
            map[s[j]]++;
            if(map.size()==3){
                while(map.size()==3){
                    ans+=n-j;
                    if(map[s[i]]==1){
                        map.erase(s[i]);
                    }
                    else{
                        map[s[i]]--;
                    }
                    i++;
                }
            }
            j++;
        }
        return ans;
    }
};