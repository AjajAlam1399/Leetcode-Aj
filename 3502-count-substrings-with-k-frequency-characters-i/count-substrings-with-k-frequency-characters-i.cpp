class Solution {
public:
    int numberOfSubstrings(string s, int K) {
        
        
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            vector<int>vec(26,0);
            for(int j=i;j<n;j++){
                vec[s[j]-'a']++;
                bool flag=false;
                for(int k=0;k<26;k++){
                    if(vec[k]>=K){
                        flag=true;
                        break;
                    }
                }
                if(flag){
                    ans+=n-j;
                    break;
                }
            }
        }
        return ans;
    }
};