class Solution {
public:
    bool canConstruct(string s, int k) {
        int n=s.size();
        if(n<k)return false;
        vector<int>vec(26,0);
        
        for(int i=0;i<n;i++)vec[s[i]-'a']++;
        int cnt=0;
        for(int i=0;i<26;i++){
            if(vec[i]%2!=0)cnt++;
        }
        return cnt<=k;
    }
};